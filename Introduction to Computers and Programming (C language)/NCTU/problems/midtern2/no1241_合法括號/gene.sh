#!/bin/bash
# generate input
for i in $(seq 1 12)
do
	printf "${i}\n" > ./input/${i}.in
done
printf "input done\n"

# generate output
for i in $(seq 1 12)
do
	./a.out < ./input/${i}.in > ./output/${i}.out
done
printf "output done\n"

