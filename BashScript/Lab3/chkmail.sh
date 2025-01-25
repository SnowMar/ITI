#!/bin/bash

while true; do
    if [ -f "/var/mail/$USER" ]; then
        echo "New mail"
    els
        echo "No new mail"
    fi
    sleep 3600
done
