#!/bin/bash

# Check if main executable does not exist
if [ ! -f ../build/main ]; then
    echo "main does not exist. Please run build.sh or build.bat."
    exit 1
fi

# Create log.txt if it doesn't exist
if [ ! -f ../tmp/log.txt ]; then
    mkdir -p ../tmp
    touch ../tmp/log.txt
fi

# Run main executable, redirecting output to log.txt
../build/main > ../tmp/log.txt 2>/dev/null
if [ $? -ne 0 ]; then
    echo "An error occurred while running main."
    exit 1
fi

echo "Run successful! Check log.txt for result."
