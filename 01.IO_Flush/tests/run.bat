@echo off

REM Set project path to the parent directory of the script
set PROJ_PATH=%~dp0..

REM check if it doesn't exist 
if not exist "%PROJ_PATH%\build\main.exe" (
    echo main is not exist. Please run buil.sh or buil.bat.
    exit /b
)

REM create if it doesn't exist
if not exist "%PROJ_PATH%\tmp" (
    mkdir "%PROJ_PATH%\tmp"
)
if not exist "%PROJ_PATH%\tmp\log.txt" (
    echo. > "%PROJ_PATH%\tmp\log.txt"
)

REM run main.exe, output in log.txt
"%PROJ_PATH%\build\main" > "%PROJ_PATH%\tmp\log.txt"
if %errorlevel% neq 0 (
    echo An error occurred while running main.exe.
    exit /b
)

echo run successful! Check log.txt for result
