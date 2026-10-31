#include <stdio.h>
#include <unistd.h>
#include <sched.h>

/*
 * sched_test.c —— 作为 initramfs 的 init
 *
 * 目的：制造可观察的进程调度。
 *   1) fork 出父子两个可运行(R)进程，双方都反复调用 sched_yield()
 *      → 触发 sys_sched_yield() → schedule()，prev->state 仍是 TASK_RUNNING，
 *        于是会发生真正的"进程切换"（不是睡眠后唤醒）。
 *   2) 最后双方都 pause() 常驻，保证 init 不退出（否则内核 panic）。
 */

static void work(const char *who, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("[%s] step=%d pid=%d\n", who, i, (int)getpid());
        fflush(stdout);
        sched_yield();          /* → sys_sched_yield() → schedule() */
    }
}

int main(void)
{
    pid_t pid;

    printf("=== [sched] init pid=%d, start ===\n", (int)getpid());
    fflush(stdout);

    pid = fork();
    if (pid == 0) {
        printf("=== [sched] child pid=%d created ===\n", (int)getpid());
        fflush(stdout);
        work("child", 4);
    } else {
        printf("=== [sched] parent pid=%d child=%d ===\n", (int)getpid(), (int)pid);
        fflush(stdout);
        work("parent", 4);
    }

    printf("=== [sched] pid=%d goes to sleep (pause) ===\n", (int)getpid());
    fflush(stdout);

    for (;;)
        pause();

    return 0;
}
