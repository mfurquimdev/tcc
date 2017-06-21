#!/bin/bash

asciinema rec

xdotool --delay 100 "#Testando o rec com script" Enter

make

D=2
C=2

echo -n "($C,$D)"
./st.out -d $D -c $C > $C\_$D.csv

D=3
C=2

echo -n "($C,$D)"
./st.out -d $D -c $C > $C\_$D.csv

D=2
C=3

echo -n "($C,$D)"
./st.out -d $D -c $C > $C\_$D.csv

D=3
C=3

echo -n "($C,$D)"
./st.out -d $D -c $C > $C\_$D.csv

D=4
C=2

echo -n "($C,$D)"
./st.out -d $D -c $C > $C\_$D.csv

D=2
C=4

echo -n "($C,$D)"
./st.out -d $D -c $C > $C\_$D.csv

D=4
C=3

echo -n "($C,$D)"
./st.out -d $D -c $C > $C\_$D.csv

D=3
C=4

echo -n "($C,$D)"
./st.out -d $D -c $C > $C\_$D.csv

D=4
C=4

echo -n "($C,$D)"
./st.out -d $D -c $C > $C\_$D.csv

D=2
C=5

echo -n "($C,$D)"
./st.out -d $D -c $C > $C\_$D.csv

D=5
C=2

echo -n "($C,$D)"
./st.out -d $D -c $C > $C\_$D.csv

D=5
C=3

echo -n "($C,$D)"
./st.out -d $D -c $C > $C\_$D.csv

D=3
C=5

echo -n "($C,$D)"
./st.out -d $D -c $C > $C\_$D.csv

D=4
C=5

echo -n "($C,$D)"
./st.out -d $D -c $C > $C\_$D.csv

D=5
C=4

echo -n "($C,$D)"
./st.out -d $D -c $C > $C\_$D.csv

