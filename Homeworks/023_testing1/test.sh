#! /bin/bash
for i in $(seq -1 0); 
do
	./isPrime-broken4 $i
	./isPrime-correct $i
done
