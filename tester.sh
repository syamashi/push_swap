#!/bin/bash

COUNT=200
if [ $1 != 0 ]
then
	COUNT=$1
fi
INDEX=0
MAX5=0
MAX100=0
MAX500=0
TMP=0
RESULT=0
FILE0="max_arg5.txt"
FILE1="max_arg100.txt"
FILE2="max_arg500.txt"
FILE_ERROR="Error_arg.txt"
RED=$'\e[1;31m'
GREEN=$'\e[1;32m'
END=$'\e[0m'
AVG5=0
AVG100=0
AVG500=0

while [ "$INDEX" -lt "$COUNT" ]
do

ARG=`jot -r -s " " 5 -2147483648 2147483647`
RESULT=`./push_swap $ARG 2>/dev/null | ./checker $ARG 2>&1`
TMP=`./push_swap $ARG 2>/dev/null | wc -l`
if [ $TMP -gt $MAX5 ] ; then
    MAX5=$TMP
    echo $ARG > $FILE0
fi
if [ "$RESULT" == "OK" ]
then
	echo -n "${GREEN}[OK]   ${END}"
elif [ "$RESULT" == "KO" ] ; then
	echo "${RED}[KO]   ${END}"
    echo $ARG > $FILE_ERROR;
	echo "./push_swap \`cat $FILE_ERROR\` | wc -l"
	exit 0;
else
	echo "${RED}[Error]${END}"
    echo $ARG > $FILE_ERROR;
	echo "./push_swap \`cat $FILE_ERROR\` | wc -l"
	exit 0;
fi
echo -n "$TMP  "
let AVG5+=TMP 

ARG=`jot -r -s " " 100 -2147483648 2147483647`
RESULT=`./push_swap $ARG 2>/dev/null | ./checker $ARG 2>&1`
TMP=`./push_swap $ARG 2>/dev/null | wc -l`
if [ $TMP -gt $MAX100 ] ; then
    MAX100=$TMP
    echo $ARG > $FILE1
fi
if [ "$RESULT" == "OK" ]
then
	echo -n "${GREEN}[OK]   ${END}"
elif [ "$RESULT" == "KO" ] ; then
	echo "${RED}[KO]   ${END}"
	echo $ARG > $FILE_ERROR;
	echo "./push_swap \`cat $FILE_ERROR\` | wc -l"
	exit 0;
else
	echo "${RED}[Error]${END}"
	echo $ARG > $FILE_ERROR;
	echo "./push_swap \`cat $FILE_ERROR\` | wc -l"
	exit 0;
fi
echo -n "$TMP  "
let AVG100+=TMP 

ARG=`jot -r -s " " 500 -2147483648 2147483647`
RESULT=`./push_swap $ARG 2>/dev/null | ./checker $ARG 2>&1`
TMP=`./push_swap $ARG 2>/dev/null | wc -l`
if [ $TMP -gt $MAX500 ] ; then
    MAX500=$TMP
    echo $ARG > $FILE2
fi
if [ "$RESULT" == "OK" ]
then
	echo -n "${GREEN}[OK]   ${END}"
elif [ "$RESULT" == "KO" ] ; then
	echo "${RED}[KO]   ${END}"
	echo $ARG > $FILE_ERROR;
	echo "./push_swap \`cat $FILE_ERROR\` | wc -l"
	exit 0;
else
	echo "${RED}[Error]${END}"
	echo $ARG > $FILE_ERROR;
	echo "./push_swap \`cat $FILE_ERROR\` | wc -l"
	exit 0;
fi

echo "$TMP"
let AVG500+=TMP 

let INDEX++
done
echo
echo "${RED}[ARG   5]${END}  [MAX = " $MAX5]   "[AVG. = $(($AVG5 / $INDEX))]"
echo "${RED}[ARG 100]${END}  [MAX = " $MAX100] "[AVG. = $(($AVG100 / $INDEX))]"
echo "${RED}[ARG 500]${END}  [MAX = " $MAX500] "[AVG. = $(($AVG500 / $INDEX))]"
echo
echo "cat $FILE0"
echo "cat $FILE1"
echo "cat $FILE2"
echo
echo "./push_swap \`cat $FILE0\` | wc -l"
echo "./push_swap \`cat $FILE1\` | wc -l"
echo "./push_swap \`cat $FILE2\` | wc -l"
echo
