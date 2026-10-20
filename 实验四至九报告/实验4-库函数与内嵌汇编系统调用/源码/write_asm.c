#include <stdio.h>
#include <string.h>

/* i386 架构下 write 的系统调用号为 4 */
#define __NR_write 4

static int my_write(int fd, const char *buf, int len)
{
    int ret;

    /* 参数按约定放入 ebx/ecx/edx，系统调用号放入 eax，然后 int 0x80 */
    asm volatile("int $0x80"
                 : "=a"(ret)
                 : "a"(__NR_write), "b"(fd), "c"(buf), "d"(len));

    return ret;
}

int main(void)
{
    const char *msg = "hello from inline asm write(4)\n";
    int n;

    n = my_write(1, msg, (int)strlen(msg));
    printf("my_write() returned %d bytes\n", n);

    return 0;
}
