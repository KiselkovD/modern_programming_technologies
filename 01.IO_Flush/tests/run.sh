#!/bin/bash

# Set project path to the parent directory of the script
PROJ_PATH="$(dirname "$(realpath "$0")")/.."

# Check if main executable does not exist
if [ ! -f "$PROJ_PATH/build/main" ]; then
    echo "main does not exist. Please run build.sh or build.bat."
    exit 1
fi

# Create log.txt if it doesn't exist
if [ ! -f "$PROJ_PATH/tmp/log.txt" ]; then
    mkdir -p "$PROJ_PATH/tmp"
    touch "$PROJ_PATH/tmp/log.txt"
fi

# Run main executable, redirecting output to log.txt
"$PROJ_PATH/build/main" > "$PROJ_PATH/tmp/log.txt" 2>&1
if [ $? -ne 0 ]; then
    echo "An error occurred while running main."
    exit 1
fi

echo "Run successful! Check log.txt for result." 
