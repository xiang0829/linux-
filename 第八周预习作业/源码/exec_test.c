#include <stdio.h>
#include <unistd.h>

/*
 * /init —— 作为 initramfs 的 init，用 execve 装载 /hello。
 * 观察点：execve 返回后，这个进程"变成"了 /hello，
 * 用户态 IP 跳到了 /hello 的 ELF 入口（elf_entry）。
 */
int main(void)
{
    char *argv[] = { "/hello", "arg1", "arg2", NULL };
    char *envp[] = { "HOME=/", "PATH=/bin:/sbin", NULL };

    printf("=== [init] before execve, pid=%d ===\n", (int)getpid());
    printf("=== [init] calling execve(\"/hello\", ...) now ===\n");
    fflush(stdout);

    execve("/hello", argv, envp);

    /* 只有 execve 失败才会走到这里 */
    printf("=== [init] execve FAILED ===\n");
    fflush(stdout);

    for (;;)
        pause();

    return 0;
}
