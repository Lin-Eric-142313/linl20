#! /bin/bash

for FILE_NAME in /usr/include/linux/*.h
do
        echo -n "In $FILE_NAME, the times that bug appeares is  "
        cat $FILE_NAME | grep "bug" | wc -l
done