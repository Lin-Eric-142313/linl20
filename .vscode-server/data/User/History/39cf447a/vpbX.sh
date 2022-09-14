#! /bin/bash

cat /usr/include/math.h | grep extern | wc -l
cat /usr/include/string.h | grep extern | wc -l
cat /usr/include/glob.h | grep extern | wc -l