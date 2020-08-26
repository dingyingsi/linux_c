
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <asm/errno.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define ERR_EXIT(m) \
    do \
    { \
        perror(m); \
        exit(EXIT_FAILURE); \
    } while(0)

void echo_srv(int sock) {
    char recvbuf[1024] = {0};
    struct sockaddr_in peeraddr;
    socklen_t  peerlen;
    int n;
    while(1) {
        peerlen = sizeof(peeraddr);
        memset(recvbuf, 0, sizeof(recvbuf));
        n = recvfrom(sock, recvbuf, sizeof(recvbuf), 0, (struct sockaddr*)&peeraddr, &peerlen);
        if (n == -1) {
            if (errno == EINTR) {
                continue;
            } else {
                ERR_EXIT("recvfrom");
            }
        } else if (n > 0) {
            fputs(recvbuf, stdout);
            sendto(sock, recvbuf, n, 0, (struct sockaddr *)&peeraddr, peerlen);
        }
    }
    close(sock);
}

int main(int argc, char** argv) {
    int sock;
    if ((sock = socket(PF_INET, SOCK_DGRAM, 0)) < 0) {
        ERR_EXIT("socket");
    }
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(5188);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sock, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        ERR_EXIT("bind");
    }
    echo_srv(sock);

    return EXIT_SUCCESS;
}