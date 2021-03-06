#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <asm/errno.h>
#include <errno.h>

#define ERR_EXIT(m) \
    do \
    { \
        perror(m); \
        exit(EXIT_FAILURE); \
    } while(0)

ssize_t readn(int fd, void *buf, size_t count)
{
    size_t nleft = count;
    ssize_t nread;
    char *bufp = (char *)buf;
    while(nleft > 0)
    {
        if ((nread = read(fd, bufp, nleft)) < 0)
        {
            if (errno == EINTR)
            {
                continue;
            }
            return -1;
        }
        else if (nread == 0)
        {
            return count - nleft;
        }

        bufp += nread;
        nleft -= nread;
    }
    return count;
}

ssize_t writen(int fd, const void *buf, size_t count)
{
    size_t nleft = count;
    ssize_t nwritten;
    char *bufp = (char *)buf;
    while(nleft > 0)
    {
        if ((nwritten = write(fd, bufp, nleft)) < 0)
        {
            if (errno == EINTR)
            {
                continue;
            }
            return -1;
        }
        else if (nwritten == 0)
        {
            continue;
        }

        bufp += nwritten;
        nleft -= nwritten;
    }
    return count;
}

void do_service(int conn)
{
    char recvbuf[1024];
    while(1) {
        memset(recvbuf, 0, sizeof(recvbuf));
        int ret = readn(conn, recvbuf, sizeof(recvbuf));
        if (ret == 0)
        {
            printf("client close\n");
            break;
        } else if(ret == -1)
        {
            ERR_EXIT("read");
        }
        fputs(recvbuf, stdout);
        writen(conn, recvbuf, ret);
    }
}
int main(int argc, char** argv)
{
    int listenfd;
    /* if ((listenfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) */
    if ((listenfd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
    {
        ERR_EXIT("socket");
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(5188);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    // servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    // inet_aton("127.0.0.1", &servaddr.sin_addr);

    int on = 1;
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)
    {
        ERR_EXIT("setsocketopt");
    }

    if (bind(listenfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0 )
    {
        ERR_EXIT("bind");
    }

    if (listen(listenfd, SOMAXCONN) < 0) {
        ERR_EXIT("listen");
    }

    struct sockaddr_in peeraddr;
    socklen_t peerlen = sizeof(peeraddr);
    int conn;
    pid_t pid;
    while(1) {
        if ((conn = accept(listenfd, (struct sockaddr *) &peeraddr, &peerlen)) < 0) {
            ERR_EXIT("accept");
        }

        printf("ip=%s port=%d\n", inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port));
        pid = fork();
        if (pid == -1) {
            ERR_EXIT("fork");
        } else if (pid == 0) {
            close(listenfd);
            do_service(conn);
            exit(EXIT_SUCCESS);
        } else {
            close(conn);
        }
    }

    return EXIT_SUCCESS;

}