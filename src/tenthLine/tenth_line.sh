#!/bin/bash

# use sed
# -n：仅打印匹配模式的行
# p：表示打印
sed -n '10p' file.txt


# use awk
awk '{if (NR == 10) print $0}' file.txt
# or awk 'NR == 10' file.txt

# use shell，逐行读文件
count=0
while read LINE
do
    count=$[$count+1]
    if [ $count -eq 10 ]
    then
        echo $LINE
    fi
done < file.txt
