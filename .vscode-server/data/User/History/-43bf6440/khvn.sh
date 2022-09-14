#! /bin/bash

for FILE_NAME in /usr/include/*.h
do
    cat $FILE_NAME | grep extern | wc -l
done