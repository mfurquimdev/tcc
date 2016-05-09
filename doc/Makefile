#-------------------------------------------------------------------------------
# Copyright (c) 2016 Mateus Furquim
#
# Baseado no Makefile de:
# Edson Alves da Costa Júnior [https://github.com/edsomjr]
# Leonn Ferreira <leonn.paiva@gmail.com>
#-------------------------------------------------------------------------------

TARGET = tcc.pdf
MKD_FILE = $(addsuffix .md, $(basename $(TARGET)))
TEX_FILE = $(addsuffix .tex, $(basename $(TARGET)))

CC=pandoc
FLAGS= --from=markdown --to=latex --indented-code-classes=numberLines --highlight-style=zenburn --smart --normalize --listings --ascii --atx-headers --number-sections --base-header-level=1 --latex-engine=xelatex

#FLAGS= --from=markdown_github --to=latex --toc --indented-code-classes=numberLines --highlight-style=zenburn --toc-depth=4 --smart --normalize --chapters --listings -T $(TARGET) --ascii --atx-headers

.PHONY: all clean tex

all:
	@make $(TARGET)

$(TARGET): $(MKD_FILE)
	@echo [$@] Making... $(TARGET)
	$(CC) $(FLAGS) --output=$@ $<

tex: $(TEX_FILE)

$(TEX_FILE): $(MKD_FILE)
	@mkdir -pv tex
	@echo [$@] Making... $(TARGET)
	iconv -t utf-8 $< | $(CC) $(FLAGS) --output=tex/$@
	cat tex/beg.tex > tex/tmp.tex
	cat tex/$@ >> tex/tmp.tex
	cat tex/end.tex >> tex/tmp.tex
	pdflatex tex/tmp.tex
	mv tmp.pdf tex/$(TARGET)
	rm -vf *.log *.aux *.dvi

clean:
	rm -vf *.log *.aux *.dvi tex/*.pdf $(TARGET)
