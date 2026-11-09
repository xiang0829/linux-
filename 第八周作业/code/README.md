# 第八周作业代码：mymath.dll

配套报告：[`../20262822-姚翔-第八周实验报告-动态链接库.md`](../20262822-姚翔-第八周实验报告-动态链接库.md)

## 目录结构

| 路径 | 说明 |
|---|---|
| `mymath_dll_20262822.sln` | 解决方案，包含两个工程 |
| `mymath_dll/` | 动态库工程，输出 `mymath.dll` 与导入库 `mymath.lib` |
| `mymath_dll_app/` | 调用工程，只有 `test.c` 与头文件，输出 `mymath_dll_test.exe` |

四个运算模块（`add.c`、`subtract.c`、`multiply.c`、`divide.c`）只存在于 `mymath_dll/` 中，调用工程里没有任何实现代码——这正是动态库"只给接口和二进制"的效果。

## 生成与运行

1. 用 Visual Studio 2017 打开 `mymath_dll_20262822.sln`，配置选择 `Debug | x64`；
2. 生成解决方案（`F7`）；
3. 在解决方案资源管理器里把 `mymath_dll_test` 设为启动项目，按 `F5` 运行；
   也可以直接双击 `mymath_dll_app\x64\Debug\mymath_dll_test.exe`。

正常输出：

```text
==============================================
  mymath.dll 动态链接库调用演示
  学号：20262822      姓名：姚翔
==============================================

[PASS] add
[PASS] add with negative
[PASS] subtract
[PASS] multiply
[PASS] divide
[PASS] divide by zero returns NAN
6/6 tests passed
```

## 三个容易踩的点

1. **导出**：`mymath_export.h` 用 `MYMATH_EXPORTS` 切换 `__declspec(dllexport)` 与 `__declspec(dllimport)`。库工程在"预处理器定义"里加了 `MYMATH_EXPORTS`，调用工程没有，所以同一个头文件两边都能用。
2. **导入库不是静态库**：调用工程在"附加依赖项"里链接的 `mymath.lib` 只有 2 KB 左右，是导入表；函数体在运行时才从 `mymath.dll` 加载。
3. **运行期要带 DLL**：调用工程的生成后事件用 `xcopy /Y /D "$(SolutionDir)mymath_dll\$(Platform)\$(Configuration)\mymath.dll" "$(OutDir)"` 把 DLL 复制到 exe 旁边，否则运行报 0xc000007b。

## 编码说明

`mymath_export.h` 与 `test.c` 在仓库中保存为 **UTF-8 带 BOM**，MSVC 会据此按 UTF-8 读取，中文注释和字符串都不会触发 C4819。如果另存成"无 BOM 的 UTF-8"，编译器会退回 ANSI(GBK) 解析并报 C4819——这也是实验报告里记录过的问题。

## 条件断点

在 `mymath_dll/add.c` 第 5 行 `return a + b;` 上按 `F9` 下断点，再右键断点选择"条件"，表达式填 `a < 0`。`add` 被调用两次：第一次 `add(2.5, 1.25)` 条件不成立直接跑过，第二次 `add(-2.5, 1.25)` 才停下，此时局部变量 `a = -2.5`。
