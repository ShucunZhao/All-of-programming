#!/bin/bash
run_test() {
    prog="$1"
    testfile="$2"
    IFS=$'\n'
    for line in `cat $testfile`
    do
	IFS=" " correct=`/home/ShucunZhao/Codes/C++/All_of_programming/Duke-ECE551/Homeworks/048_tests_rot_matrix/rot_matrix/rotateMatrix $line 2>&1`
	IFS=" " broken=`$prog $line 2>&1`
	if [ "$broken" != "$correct" ]
	then
	    return 0
	fi
    done
    return 1
}

for i in /home/ShucunZhao/Codes/C++/All_of_programming/Duke-ECE551/Homeworks/048_tests_rot_matrix/rot_matrix/rotateMatrix*
do
    if [ "$i" != "/home/ShucunZhao/Codes/C++/All_of_programming/Duke-ECE551/Homeworks/048_tests_rot_matrix/rot_matrix/rotateMatrix" ]
    then
	echo "Checking `basename $i`"
	run_test $i tests.txt
	x="$?"
	if [ "$x" != "0" ]
	then
	    echo "***Your tests failed to show that `basename $i` was broken!"
	fi
    fi
done
