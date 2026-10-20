#include <stdio.h>
#include <dlfcn.h>

/*
 * 方式二：运行时动态链接（run-time dynamic linking）
 * 编译时完全不依赖 libmyhello.so，程序运行时由 dlopen() 主动装载，
 * 再用 dlsym() 找到函数地址后调用。
 *
 *   gcc -o main_runtime main_runtime.c -ldl
 *   ./main_runtime
 */
int main(void)
{
    void *handle;
    void (*fn)(void);
    int (*add)(int, int);
    char *err;

    printf("[main_runtime] before dlopen\n");

    handle = dlopen("./libmyhello.so", RTLD_NOW);
    if (!handle) {
        printf("[main_runtime] dlopen failed: %s\n", dlerror());
        return 1;
    }
    printf("[main_runtime] dlopen OK, handle = %p\n", handle);

    dlerror();
    fn = (void (*)(void)) dlsym(handle, "hello_from_lib");
    err = dlerror();
    if (err) {
        printf("[main_runtime] dlsym hello_from_lib failed: %s\n", err);
        dlclose(handle);
        return 1;
    }
    fn();

    add = (int (*)(int, int)) dlsym(handle, "add");
    printf("[main_runtime] add(20, 22) = %d\n", add(20, 22));

    dlclose(handle);
    printf("[main_runtime] done\n");
    return 0;
}
