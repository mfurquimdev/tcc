.PHONY: all clean tex pdf

all:
	$(MAKE) -C tex all
	convert tcc.pdf -append tcc%d.png &> /dev/null &
	apvlv tcc.pdf &> /dev/null &

png:
	convert tcc.pdf -append tcc%d.png &> /dev/null &

tex:
	$(MAKE) -C tex tex

pdf:
	$(MAKE) -C tex pdf

clean:
	$(MAKE) -C tex clean
