#! /bin/bash

for FILE_NAME in /usr/include/linux/*.h
do
        echo -n "In $FILE_NAME, the times that bug appeares is  "
        cat $FILE_NAME | grep "bug" | wc -l
        cat $FILE_NAME | grep "debug" | wc -l
        num1 = 2
        num2 = 3
        echo "$(($num1+$num2))"
        echo -n "In $FILE_NAME, the times that bugs appeares is  "
        cat $FILE_NAME | grep "bugs" | wc -l
        echo -n "In $FILE_NAME, the times that buggy appeares is  "
        cat $FILE_NAME | grep "buggy" | wc -l
done