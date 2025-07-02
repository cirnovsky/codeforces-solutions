#!/bin/bash

i=1
while true; do
    echo "Test #$i"

    # Generate input
    ./gen.out > in.txt

    # Run solution and standard
    ./sol.out < in.txt > sol.txt
    ./std.out < in.txt > std.txt

    # Compare outputs
    if ! diff -q sol.txt std.txt > /dev/null; then
        echo "Mismatch found on test #$i"
        echo "Input:"
        cat in.txt
        echo "Your Output:"
        cat sol.txt
        echo "Expected Output:"
        cat std.txt
        exit 1
    else
        echo "Test #$i passed."
    fi

    ((i++))
done
