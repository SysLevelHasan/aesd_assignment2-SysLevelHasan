#!/bin/bash

# Check if both arguments are provided
if [ $# -ne 2 ]; then
    echo "Error: Two arguments required."
    echo "Usage: $0 <writefile> <writestr>"
    exit 1
fi

writefile=$1
writestr=$2

# Extract directory path from writefile
writedir=$(dirname "$writefile")

# Create directory path if it doesn’t exist
mkdir -p "$writedir"
if [ $? -ne 0 ]; then
    echo "Error: Failed to create directory '$writedir'"
    exit 1
fi

# Create/overwrite the file with writestr
echo "$writestr" > "$writefile"
if [ $? -ne 0 ]; then
    echo "Error: Failed to write to file '$writefile'"
    exit 1
fi

exit 0
