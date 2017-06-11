.PHONY: all clean tex pdf

all:
	$(MAKE) -C tex all
	convert tcc.pdf -append tcc%d.png &> /dev/null &
	apvlv tcc.pdf

png:
	convert tcc.pdf -append tcc%d.png &> /dev/null &

tex:
	$(MAKE) -C tex tex

pdf:
	$(MAKE) -C tex pdf
	apvlv tcc.pdf

clean:
	$(MAKE) -C tex clean
