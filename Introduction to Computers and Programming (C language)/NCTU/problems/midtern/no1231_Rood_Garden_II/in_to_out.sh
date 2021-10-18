#!/bin/bash
for i in $(seq 1 5);do
	printf "\n"$i"\n";
	./a.out < ./input_2/$i.in > ./output_2/$i.out
done

