#-------------------------------------------------------------------------------
# Copyright (c) 2016 Mateus Furquim
#
# Baseado no Makefile de:
# Edson Alves da Costa Júnior [https://github.com/edsomjr]
# Leonn Ferreira <leonn.paiva@gmail.com>
#-------------------------------------------------------------------------------

TARGET = tcc.pdf
MKD_FILE = $(addsuffix .md, $(basename $(TARGET)))

CC=pandoc
FLAGS= --from=markdown_github --to=latex --indented-code-classes=numberLines --highlight-style=zenburn --smart --normalize --listings --ascii --atx-headers

#FLAGS= --from=markdown_github --to=latex --toc --indented-code-classes=numberLines --highlight-style=zenburn --toc-depth=4 --smart --normalize --chapters --listings -T $(TARGET) --ascii --atx-headers

.PHONY: all clean

all:
	@make $(TARGET)

$(TARGET): $(MKD_FILE)
	@echo [$@] Making... $(TARGET)
	$(CC) $(FLAGS) --output=$(TARGET) $<

clean:
	rm -vf *.log *.aux *.dvi *.pdf
