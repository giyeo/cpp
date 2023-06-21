#!/bin/bash

# Run the program and capture its output
output=$(./run)
echo $output
# Check if the output is sorted
if [[ "$(echo "$output" | sort)" == "$output" ]]; then
    echo "The output is sorted."
else
    echo "The output is not sorted."
fi

number_count=$(echo "$output" | grep -oE '[0-9]+' | wc -l)
echo "Number count: $number_count"
