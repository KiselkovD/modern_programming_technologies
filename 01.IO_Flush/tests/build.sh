#!/bin/bash

# Check if gcc is installed
if ! command -v gcc &> /dev/null; then
    echo "GCC is not installed. Please install it first."
    exit 1
fi

# Create build directory if it doesn't exist
mkdir -p ../build

# Compile main.c to create main
gcc -o ../build/main ../src/main.c

# Check if the compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

echo "Compilation successful! Executable created: build/main"
