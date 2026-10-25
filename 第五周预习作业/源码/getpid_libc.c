#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    pid_t pid;

    pid = getpid();
    printf("[libc] getpid() = %d\n", (int)pid);

    return 0;
}
