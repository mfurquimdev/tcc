#-------------------------------------------------------------------------------
# Copyright (c) 2016 Mateus Furquim
#
# Baseado no Makefile de:
# Edson Alves da Costa Júnior [https://github.com/edsomjr]
# Leonn Ferreira <leonn.paiva@gmail.com>
#-------------------------------------------------------------------------------

TARGET = tcc.pdf
PDF_FILE = main.pdf
MKD_FILE = ../$(addsuffix .md,  $(basename $(TARGET)))
TEX_FILE =    $(addsuffix .tex, $(basename $(TARGET)))
AUX_FILE =    $(addsuffix .aux, $(basename $(PDF_FILE)))
MAIN_TEX_FILE = $(addsuffix .tex, $(basename $(PDF_FILE)))

CC=pandoc
FLAGS= --filter pandoc-eqnos --filter pandoc-tablenos --from=markdown --to=latex --indented-code-classes=numberLines --highlight-style=zenburn --parse-raw --smart --normalize --listings --ascii --atx-headers --number-sections --base-header-level=1
#FLAGS= --from=markdown_github --to=latex --toc --indented-code-classes=numberLines --highlight-style=zenburn --toc-depth=4 --smart --normalize --chapters --listings -T $(TARGET) --ascii --atx-headers

.PHONY: all clean tex pdf

all:
	@make tex
	@make pdf

#$(TARGET): $(MKD_FILE)
#	@echo [$@] Making... $(TARGET)
#	$(CC) $(FLAGS) --output=$@ $<

tex:
	iconv -t utf-8 $(MKD_FILE) | $(CC) $(FLAGS) --output=$(TEX_FILE)

pdf:
	pdflatex main.tex bibliografia.bib
	bibtex main.aux
	pdflatex main.tex
	pdflatex main.tex
	cp $(PDF_FILE) ../$(TARGET)
	rm -vf *.brf *.idx *.lof *.lot *.toc *.bbl *.blg *.log *.aux *.dvi

clean:
	rm -vf *.brf *.idx *.lof *.lot *.toc *.bbl *.blg *.log *.aux *.dvi tmp.tex $(TEX_FILE) $(TARGET) ../$(TARGET)
