#ifndef MYMATH_EXPORT_H
#define MYMATH_EXPORT_H

/* 20262822 姚翔
 * 生成 DLL 时定义 MYMATH_EXPORTS，函数被导出；
 * 调用方不定义该宏，函数按导入方式声明。
 */
#ifdef MYMATH_EXPORTS
#define MYMATH_API __declspec(dllexport)
#else
#define MYMATH_API __declspec(dllimport)
#endif

#endif /* MYMATH_EXPORT_H */
