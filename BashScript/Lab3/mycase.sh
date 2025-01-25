#!/bin/bash

read -p "Enter a character: " char

case "$char" in
    [A-Z]) echo "Upper Case" ;;
    [a-z]) echo "Lower Case" ;;
    [0-9]) echo "Number" ;;
    *) echo "Invalid" ;;
esac
