#include <stdio.h>
#include <unistd.h>

/*
 * /hello —— 被 execve 装载的目标可执行程序
 * 装载成功后它会打印自己的 pid/ppid/argv，然后常驻，
 * 这样它作为 PID 1 不会退出，内核不会 panic。
 */
int main(int argc, char *argv[], char *envp[])
{
    int i;

    printf("=== [hello] execve succeeded, this is the NEW program ===\n");
    printf("=== [hello] pid=%d ppid=%d ===\n", (int)getpid(), (int)getppid());
    printf("=== [hello] argc=%d ===\n", argc);
    for (i = 0; i < argc; i++)
        printf("=== [hello] argv[%d] = %s ===\n", i, argv[i]);

    printf("=== [hello] envp[0] = %s ===\n", envp[0] ? envp[0] : "(null)");
    fflush(stdout);

    for (;;)
        pause();

    return 0;
}
