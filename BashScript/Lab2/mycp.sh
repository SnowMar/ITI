#!/bin/bash

if [ "$#" -lt 2 ]; then
  echo "Usage: $0 <file(s)> <destination>"
  exit 1
fi

destination="${@: -1}"

if [ -d "$destination" ]; then

  cp "${@:1:$#-1}" "$destination"
else

  cp "$1" "$destination"
fi

echo "Copy operation completed."
