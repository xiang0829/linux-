#include <stdio.h>

/* i386 架构下 getpid 的系统调用号 */
#define __NR_getpid 20

int main(void)
{
    int pid;

    /* 不经过 glibc 封装，直接把系统调用号放入 eax，用 int 0x80 陷入内核 */
    asm volatile("int $0x80"
                 : "=a"(pid)
                 : "a"(__NR_getpid));

    printf("[asm ] getpid() = %d\n", pid);

    return 0;
}
