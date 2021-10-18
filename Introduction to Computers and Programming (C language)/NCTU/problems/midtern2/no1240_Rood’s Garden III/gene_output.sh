#!/bin/bash
for i in $(seq 1 5);do
	file_path=./input_1/$i.in
	printf "\n["$i"]";
	./rood2 < $file_path > ./output_1/$i.out
done

for i in $(seq 1 7);do
	file_path=./input_2/$i.in
	printf "\n["$i"]";
	./rood2 < $file_path > ./output_2/$i.out
done

