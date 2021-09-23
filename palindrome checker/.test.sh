#!/bin/bash

echo 'racecar' | ./checker &> /dev/null;
val=$?;

if [ $val -ne 0 ]; then
	echo "Failed first test: racecar";
	exit 1;
fi

echo 'notapalindrome' | ./checker &> /dev/null;
val=$?;
if [ $val -eq 0 ]; then
	echo "Failed second test: notapalindrome";
	exit 1;
fi

echo "Passes simple tests. Now testing the advanced tests"

echo 'A man, a plan, a canal, panama!' | ./checker &> /dev/null;
val=$?

if [ $val -ne 0 ]; then
	echo 'Failed advanced test: A man, a plan, a canal, panama!';
	exit 1;
fi

echo "Passed the basic AND advanced test"
exit $val
