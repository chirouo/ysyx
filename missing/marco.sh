#!/bin/bash
count=0
test_error() {
    n=$(( RANDOM % 100 ))
    if [[ n -eq 42 ]]; then
        echo "Something went wrong"
        >&2 echo "The error was using magic numbers"
        exit 1
    else 
        count=$((count + 1))
    fi
}
while true; do
    echo "count=$count"
    test_error
done
echo "Everything went according to plan"
