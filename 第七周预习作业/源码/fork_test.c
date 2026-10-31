#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid;

    printf("=== before fork, pid=%d ===\n", (int)getpid());
    fflush(stdout);

    pid = fork();

    if (pid == 0) {
        printf("=== child : pid=%d ppid=%d ===\n", (int)getpid(), (int)getppid());
        fflush(stdout);
        _exit(0);
    } else {
        printf("=== parent: pid=%d child=%d ===\n", (int)getpid(), (int)pid);
        fflush(stdout);
        wait(NULL);
    }

    printf("=== fork test done, init stays alive ===\n");
    fflush(stdout);

    for (;;)
        pause();

    return 0;
}
