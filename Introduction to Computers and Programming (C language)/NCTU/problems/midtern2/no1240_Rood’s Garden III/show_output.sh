#!/bin/bash
#time_format=%E real,\t%U user,\t%S sys
printf "===== [ Easy version ] =====\n"
for i in $(seq 1 5);do
	file_path=./input_1/$i.in
	printf "\n["$i"]\n";
	printf "fail: "
	time ./fail < $file_path
	printf "rood: "
	time ./rood2 < $file_path
done
printf "===== [ Normal version ] =====\n"
for i in $(seq 1 7);do
	file_path=./input_2/$i.in
	printf "\n["$i"]\n";
	printf "fail: "
	time ./fail < $file_path
	printf "rood: "
	time ./rood2 < $file_path
done

