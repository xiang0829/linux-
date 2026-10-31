#include <stdio.h>

/*
 * 方式一：装载时动态链接（load-time dynamic linking）
 * 编译时链接 libmyhello.so，生成的 ELF 中记录 DT_NEEDED，
 * 由动态链接器 ld-linux.so 在 execve 装载程序时一并把这个 .so 映射进来。
 *
 *   gcc -o main_linktime main_linktime.c -L. -lmyhello
 *   readelf -d main_linktime | grep NEEDED
 *   ./main_linktime            (需要 LD_LIBRARY_PATH=.)
 */
extern void hello_from_lib(void);
extern int add(int a, int b);

int main(void)
{
    printf("[main_linktime] before calling library function\n");
    hello_from_lib();
    printf("[main_linktime] add(3, 4) = %d\n", add(3, 4));
    return 0;
}
