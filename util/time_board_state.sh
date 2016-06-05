#!/bin/bash

echo "(P,D)	B_State	S.nseg"
for p in `seq 2 5`; do
	for d in `seq 2 9`; do
		START_SEC=$(date +%s)
		START_NSEC=$(date +%N | sed -e 's/000$//' -e 's/^0//')
#		echo "Start	$START_SEC.$START_NSEC"
		BOARD_STATES=$(./boards_state.out -d $d -p $p 2> boards_state.err)
		END_NSEC=$(date +%N | sed -e 's/000$//' -e 's/^0//')
		END_SEC=$(date +%s)
#		echo "Start	$END_SEC.$END_NSEC"

		if [[ $END_NSEC < $START_NSEC ]]; then
			END_SEC=$(($END_SEC-1))
			END_NSEC=$(($END_NSEC+1000000000))
		fi

		ELAPSED_SEC=$(($END_SEC-$START_SEC))
		ELAPSED_NSEC=$(echo $(($END_NSEC-$START_NSEC)) | sed -e 's/000$//' -e 's/^0//')

		echo "($p,$d)	$BOARD_STATES	$ELAPSED_SEC.$ELAPSED_NSEC"
	done
done
