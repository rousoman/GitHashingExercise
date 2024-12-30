#!/bin/bash

# Check if exactly one argument is passed
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <4-digit-integer>"
    exit 1
fi

# Validate that the input is a 4-digit integer
if ! [[ $1 =~ ^[0-9]{4}$ ]]; then
    echo "Error: Input must be a 4-digit integer."
    exit 1
fi

# Compute the hash using SHA-256
input=$1
hash=$(echo -n "$input" | sha256sum | awk '{print $1}')

# Define the output filename
output_file="hash_output.txt"

# Save the hash to the output file
echo "$hash" > "$output_file"

echo "Hash has been computed and saved to $output_file."

