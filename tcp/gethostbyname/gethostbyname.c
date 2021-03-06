#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define ERR_EXIT(m) \
    do \
    { \
        perror(m); \
        exit(EXIT_FAILURE); \
    } while(0)

int main(int argc, char **argv) {
    char host[100] = {0};
    if (gethostname(host, sizeof(host)) < 0) {
        ERR_EXIT("gethostname");
    }
    struct hostent *hp;
    if ((hp = gethostbyname(host)) == NULL) {
        ERR_EXIT("gethostbyname");
    }
    int i = 0;
    while (hp->h_addr_list[i] != NULL) {
        printf("%s\n", inet_ntoa(*(struct in_addr *) hp->h_addr_list[i]));
        i++;
    }


    return EXIT_SUCCESS;

}