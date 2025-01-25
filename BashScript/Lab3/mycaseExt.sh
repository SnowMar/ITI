#!/bin/bash

read -p "Enter a string: " str

if [[ "$str" =~ ^[A-Z]+$ ]]; then
    echo "Upper Cases"
elif [[ "$str" =~ ^[a-z]+$ ]]; then
    echo "Lower Cases"
elif [[ "$str" =~ ^[0-9]+$ ]]; then
    echo "Numbers"
elif [[ "$str" =~ ^[A-Za-z0-9]+$ ]]; then
    echo "Mix"
else
    echo "Nothing"
fi
