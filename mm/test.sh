#!/bin/bash

N=$1;
var=1
if [ "$N" = "" ];
then
	exit
fi

while [ "$N" != "$var" ]
do
	var=$((var + 1))
	ruby -e "puts (1..100).to_a.shuffle" 2> err | xargs ./push_swap | wc -l
done
