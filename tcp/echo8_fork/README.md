signal(SIGCHLD, handle_sigchld);  to remove zombie process

void handle_sigchld(int sig)
{
    wait(NULL);
}

sudo netstat -anop  | grep tcp |  grep 5188