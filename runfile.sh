#!/bin/bash

IFS=$'\n';

for i in `cat input.txt`; do
    echo "Fajl neve: $i"
    echo "$i" | ./a.out
 done