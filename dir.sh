#!/bin/bash

DIR=$1
clear
printf " \e[36m[ Compiling...]\n\n\e[0m"
./comp
sleep 1
#$MAX = ll $DIR | wc -l
$COUNT = 0

for FILE in $( ls $DIR)
do
	printf "\n \e[36m[ Running... ]\n\n\e[33m"
	printf "\e[2J\e[0;0H\e[90m[\e[32m$COUNT\e[90m / \e[33m32\e[90m]\e[0m\n\e[90m[ $FILE ]\e[0m\n" >> /dev/ttys005
	let "COUNT++"
	time ./test_gnl $DIR/$FILE > out
	printf "\n   \e[32m[ CORRECT OUTPUT ]                    \e[31m[ GNL OUTPUT ]\n\n\e[33m"
	pr -mto3 -w75 $DIR/$FILE ./out
	printf "<\n \e[34m[ DIFF OUTPUT ]\n\n\e[33m"
	diff $DIR/$FILE ./out
	printf "<\n \e[34m[ END ]\n\n\e[33m"
	#mv $FILE ./test/.done/
	rm out
done
