#!/bin/bash

backup_dir="$HOME/backup"
mkdir -p "$backup_dir"
find "$HOME" -maxdepth 1 -type f -exec cp {} "$backup_dir" \;