#!/bin/sh

if [[ -z $1 ]]; then
    echo "Type a message for commiting"
else

    FILES="main.cpp Date.cpp Date.hpp makefile commit.sh run.sh"

    for file in $FILES; do
        git add $file
    done;

    git commit -m "$1";

fi