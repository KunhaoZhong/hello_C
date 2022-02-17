#!/bin/bash

#a: add usage
if [ $# -ne 2 ];then
	echo "usage: ./prettyprint.sh "string" n, the script will print n+1 lines of the string, with each line cutting the first charactor of the previous string " || exit 1
fi

#b if -1 is passed, use the length of the string as number of lines
count=$2

if [ $count -eq -1 ];then
	count=${#1}
fi


for i in $(seq 0 ${count})
do
  echo "${1:$i:${#1}}"
done
