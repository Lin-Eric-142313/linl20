#! /bin/bash

for FILE_NAME in /usr/include/*.h
do
    echo -n "processing file $FILE_NAME number of externs is "
    cat $FILE_NAME | grep extern | wc -l
done
echo "done"