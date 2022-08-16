#!/bin/sh

if [[ -z $1 ]]; then
    echo "Type a message for commiting"
else

    FILES="main.cpp makefile run.sh"

    for file in $FILES; do
        git add $file
    done;

    git commit -m "$1";

fi