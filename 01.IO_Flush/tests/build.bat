@echo off
REM Check if gcc is installed
where gcc >nul 2>nul
if %errorlevel% neq 0 (
    echo GCC is not installed. Please install MinGW or another GCC distribution.
    exit /b
)

REM Create build directory if it doesn't exist
if not exist ..\build (
    mkdir ..\build
)

REM Compile main.c to create main.exe
gcc -o ..\build\main.exe ..\src\main.c

REM Check if the compilation was successful
if %errorlevel% neq 0 (
    echo Compilation failed.
    exit /b
)

echo Compilation successful! Executable created: build\main.exe
