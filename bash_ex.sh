#!/bin/bash

for FILE_NAME in /usr/include/linux/*.h
do
        echo -n "In $FILE_NAME, the number of times that "bug", "bugs", and "buggy" appeared is  "
        cat $FILE_NAME | grep 'bug\|bugs\|buggy' | wc -l
done