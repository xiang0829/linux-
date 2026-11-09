# 第八周作业代码（静态库版）：mymath.lib

配套报告：[`../20262822-姚翔-第八周实验报告-静态链接库.md`](../20262822-姚翔-第八周实验报告-静态链接库.md)  
动态库版代码见 [`../code/`](../code/)。

## 目录结构

| 路径 | 说明 |
|---|---|
| `mymath_20262822.sln` | 解决方案，包含两个工程 |
| `mymath_lib/` | 静态库工程，输出 `mymath.lib` 与 `mymath.pdb` |
| `mymath_app/` | 调用工程，只有 `test.c` 与头文件，输出 `mymath_test.exe` |
| `build_vs2017.bat` | 一键构建脚本（用 vswhere 定位 VS2017 并调用 MSBuild） |

四个运算模块只存在于 `mymath_lib/`，调用工程里没有任何实现代码。

## 生成与运行

1. 用 Visual Studio 2017 打开 `mymath_20262822.sln`，配置 `Debug | x64`；
2. 生成解决方案（`F7`），或双击 `build_vs2017.bat`；
3. 把 `mymath_test` 设为启动项目后按 `F5`，或直接运行 `mymath_app\x64\Debug\mymath_test.exe`。

正常输出：

```text
==============================================
  mymath.lib 静态链接库调用演示
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

## 要点

1. **不需要导出声明**：静态库的代码最终和调用方在同一个 exe 里，头文件只写普通声明即可，这一点和动态库的 `__declspec(dllexport)` 不同。
2. **链接靠三处配合**：项目引用勾选 `mymath`、附加库目录 `$(SolutionDir)mymath_lib\$(Platform)\$(Configuration)`、附加依赖项 `mymath.lib`；也可以在 `test.c` 里用 `#pragma comment(lib, "mymath.lib")` 代替第三项。
3. **源文件必须是 `.c`**：写成 `.cpp` 会按 C++ 规则修饰函数名，链接时报 LNK2019。
4. **调试符号**：`mymath.pdb` 要和 `mymath.lib` 同目录，否则源码断点会变成空心圆。

## 条件断点

在 `mymath_lib/add.c` 第 5 行 `return a + b;` 上按 `F9`，再右键断点选"条件"，表达式填 `a < 0`。`add` 被调用两次：第一次 `add(2.5, 1.25)` 直接跑过，第二次 `add(-2.5, 1.25)` 停下，此时 `a = -2.5`。

## 编码说明

`mymath_app/test.c` 在仓库中保存为 UTF-8 带 BOM（原文含中文横幅，本地为 GBK）。MSVC 依据 BOM 按 UTF-8 读取，中文不会触发 C4819。
