@echo off
REM check if it doesn't exist
if not exist ..\build\main.exe (
    echo main is not exist. Please run buil.sh or buil.bat.
    exit /b
)

REM create if it doesn't exist
if not exist ..\tmp (
    mkdir ..\tmp
)
if not exist ..\tmp\log.txt (
    echo. > ..\tmp\log.txt
)

REM run main.exe, output in log.txt
..\build\main > ..\tmp\log.txt 
if %errorlevel% neq 0 (
    echo An error occurred while running main.exe.
    exit /b
)

echo run successful! Check log.txt for result
