#include <stdio.h>

/* 共享库实现：libmyhello.so */
void hello_from_lib(void)
{
    printf("[libmyhello.so] hello, I am a shared library function\n");
}

int add(int a, int b)
{
    return a + b;
}
