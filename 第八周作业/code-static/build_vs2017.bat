@echo off
setlocal enabledelayedexpansion
cd /d "%~dp0"
title mymath_20262822 build helper

echo ============================================================
echo  mymath.lib  static library  -  build helper  (20262822)
echo ============================================================
echo.

set "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
if not exist "%VSWHERE%" (
    echo [ERROR] vswhere.exe not found.
    echo         Visual Studio 2017 / Build Tools is not installed on this machine.
    goto :end
)

set "VSDIR="
for /f "usebackq tokens=*" %%i in (`"%VSWHERE%" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "VSDIR=%%i"
if not defined VSDIR (
    for /f "usebackq tokens=*" %%i in (`"%VSWHERE%" -latest -products * -property installationPath`) do set "VSDIR=%%i"
)
if not defined VSDIR (
    echo [ERROR] No Visual Studio with C++ toolset found.
    echo         Please install "Desktop development with C++" workload.
    goto :end
)
echo [INFO] Visual Studio : %VSDIR%

set "MSBUILD=%VSDIR%\MSBuild\15.0\Bin\MSBuild.exe"
if not exist "%MSBUILD%" set "MSBUILD=%VSDIR%\MSBuild\15.0\Bin\amd64\MSBuild.exe"
if not exist "%MSBUILD%" (
    echo [ERROR] MSBuild.exe not found under "%VSDIR%".
    goto :end
)
echo [INFO] MSBuild       : %MSBUILD%
echo.

echo [BUILD] Debug ^| x64 ...
"%MSBUILD%" mymath_20262822.sln /p:Configuration=Debug /p:Platform=x64 /v:minimal /nologo
if errorlevel 1 goto :fail

echo.
echo [DONE] artifacts:
if exist "mymath_lib\x64\Debug\mymath.lib" echo        %CD%\mymath_lib\x64\Debug\mymath.lib
if exist "mymath_lib\x64\Debug\mymath.pdb" echo        %CD%\mymath_lib\x64\Debug\mymath.pdb
if exist "mymath_app\x64\Debug\mymath_test.exe" echo        %CD%\mymath_app\x64\Debug\mymath_test.exe
echo.
echo [RUN] mymath_test.exe
echo ------------------------------------------------------------
"mymath_app\x64\Debug\mymath_test.exe"
echo ------------------------------------------------------------
goto :end

:fail
echo.
echo [FAIL] build failed, see messages above.

:end
echo.
pause
endlocal
