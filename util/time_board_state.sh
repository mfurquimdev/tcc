#!/bin/bash

echo "(P,D)	B_State	Seg"
for p in `seq 2 5`; do
	for d in `seq 2 9`; do
		START_SEC=$(date +%s)
		BOARD_STATES=$(./boards_state.out -d $d -p $p 2> boards_state.err)
		END_SEC=$(date +%s)

		ELAPSED_SEC=$(($END_SEC-$START_SEC))

		echo "($p,$d)	$BOARD_STATES	$ELAPSED_SEC"
	done
done
