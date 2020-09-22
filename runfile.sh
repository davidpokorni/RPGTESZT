#!/bin/bash

IFS=$'\n';

rm output.txt
for i in `cat input.txt`; do
    echo "Fajl neve: $i"
    echo "$i" | ./a.out >> output.txt
 done