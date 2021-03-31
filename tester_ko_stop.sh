#!/bin/bash

COUNT=200

INDEX=0
MAX100=0
MAX500=0
TMP=0
FILE1="max_arg100.txt"
ERROR_FILE="something_wrong.txt"

while [ "$INDEX" -lt "$COUNT" ]
do

ARG=`jot -r -s " " 100 -2147483648 2147483647`
RES=$(./push_swap $ARG | ./checker $ARG | xargs echo -n)
echo $RES
TMP=`./push_swap $ARG | wc -l`
if [ $TMP -gt $MAX100 ] ; then
    MAX100=$TMP
    echo $ARG > $FILE1
fi
echo " $TMP  "
if [ $(echo $RES | grep "KO") ] ; then
	echo $ARG > $ERROR_FILE
	echo "SOMETHING WRONG"
	exit 1
fi
if [ $TMP -gt 5500 ] ; then
	echo "YOU FAILED"
	exit 1
fi

let INDEX++
done
echo
echo "[ARG 500]  MAX = " $MAX100
echo
echo "cat $FILE1"
echo
echo "./push_swap \`cat $FILE1\` | wc -l"
echo
