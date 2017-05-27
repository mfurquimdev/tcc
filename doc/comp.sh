apvlv tcc.pdf &> /dev/null &
START=`stat -c %Y tcc.md`
while :;
do
	END=`stat -c %Y tcc.md`
	if [ "$END" -gt "$START" ]; then
		make &> /dev/null
		START=`stat -c %Y tcc.md`
	fi;
	sleep 1
done;

