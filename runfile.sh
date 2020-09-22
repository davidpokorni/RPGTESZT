#!/bin/bash

IFS=$'\n';

for i in `cat input.txt`; do
    echo "$i" | ./$1 >> $2
 done