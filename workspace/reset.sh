#!/bin/bash

if [ $# -eq 0 ]
then
    echo "usage: ./reset.sh BASENAME1, BASENAME2, ..."
    echo "reset BASENAME1.cpp BASENAME2.cpp ..."
fi

for bn in $@; do
    fn=$bn".cpp"
    cat ../template.cpp > $fn
done
