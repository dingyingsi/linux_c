#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <asm/errno.h>
#include <errno.h>
#include <signal.h>

#define ERR_EXIT(m) \
    do \
    { \
        perror(m); \
        exit(EXIT_FAILURE); \
    } while(0)

int main(int argc, char** argv)
{
    int count = 0;
    while(1) {
        int sock;
        if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
            sleep(4);
            ERR_EXIT("socket");
        }
        struct sockaddr_in servaddr;
        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(5188);
        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

        if (connect(sock, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
            ERR_EXIT("connect");
        }
        struct sockaddr_in localaddr;
        socklen_t addrlen = sizeof(localaddr);
        if (getsockname(sock, (struct sockaddr *) &localaddr, &addrlen) < 0) {
            ERR_EXIT("getsockname");
        }
        printf("ip=%s port=%d count=%d\n", inet_ntoa(localaddr.sin_addr), ntohs(localaddr.sin_port), ++count);
    }
    return EXIT_SUCCESS;
}