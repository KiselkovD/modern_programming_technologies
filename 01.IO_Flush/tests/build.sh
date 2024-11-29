#!/bin/bash

# Set project path to the parent directory of the script
PROJ_PATH="$(dirname "$(realpath "$0")")/.."

# Check if gcc is installed
if ! command -v gcc &> /dev/null; then
    echo "GCC is not installed. Please install it first."
    exit 1
fi

# Create build directory if it doesn't exist
mkdir -p "$PROJ_PATH/build"

# Compile main.c to create main
gcc -o "$PROJ_PATH/build/main" "$PROJ_PATH/src/main.c"

# Check if the compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

echo "Compilation successful! Executable created: build/main"
