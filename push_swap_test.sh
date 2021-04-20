#!/bin/bash
file="1"
fir=""
sec=""
thi=""
for=""
fiv=""
a=1
for var in $(cat $file)
do
	if [ $a -eq 1 ]
	then
	fir=$var
	elif [ $a -eq 2 ]
	then
	sec=$var
	elif [ $a -eq 3 ]
	then
	thi=$var
	elif [ $a -eq 4 ]
	then
	for=$var
	elif [ $a -eq 5 ]
	then
	fiv=$var
	./push_swap "$fir" "$sec" "$thi" "$for" "$fiv"
	a=0
	fi
	a=$(( $a + 1 ))
done