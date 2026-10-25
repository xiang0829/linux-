#include <stdio.h>
#include <unistd.h>

#define __NR_getpid 20

int main(void)
{
    int pid_asm;
    int pid_libc;

    /* 方式一：库函数封装 */
    pid_libc = (int)getpid();

    /* 方式二：内嵌汇编直接 int 0x80 */
    asm volatile("int $0x80"
                 : "=a"(pid_asm)
                 : "a"(__NR_getpid));

    printf("libc getpid = %d\n", pid_libc);
    printf("asm  getpid = %d\n", pid_asm);
    printf("same process? %s\n", (pid_libc == pid_asm) ? "YES" : "NO");

    return 0;
}
