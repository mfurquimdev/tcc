#!/bin/bash

$(./total_boards.py)

for c in {2..4}; do
	for d in {2..4}; do
		if [ -f $c"_"$d".csv" ]; then
			while IFS='' read -r num_states || [[ -n "$num_states" ]]; do
				num_lines=$(wc -l $c"_"$d".csv" | cut -d ' ' -f 1)
				num_states=$(echo $num_states | cut -d '.' -f 1)
#				echo "Num states:" $num_states
#				echo "Num lines:" $num_lines
				if [ $num_lines -eq $num_states ]; then
					echo "Ook"
				else
					echo -en "Not Ook\t"
					mkdir -p "incomplete"
					mv -v $c"_"$d".csv" "incomplete"
				fi
			done < $c"_"$d".txt"
		fi;
	done;
done;

rm -f *.txt
