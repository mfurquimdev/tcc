#-------------------------------------------------------------------------------
# Copyright (c) 2016 Mateus Furquim
#
# Baseado no Makefile de:
# Edson Alves da Costa Júnior [https://github.com/edsomjr]
# Leonn Ferreira <leonn.paiva@gmail.com>
#-------------------------------------------------------------------------------

TARGET = tcc.pdf
MKD_FILE = ../$(addsuffix .md,  $(basename $(TARGET)))
TEX_FILE =    $(addsuffix .tex, $(basename $(TARGET)))
AUX_FILE =    $(addsuffix .aux, $(basename $(TARGET)))

BIBTEX = bibtex
LATEX  = pdflatex

FIXOS_DIR = fixos
FIXOS_FILES = ${wildcard $(FIXOS_DIR)/*.tex}

EDITAVEIS_DIR = editaveis
EDITAVEIS_FILES = ${wildcard $(EDITAVEIS_DIR)/*.tex}

MAIN_FILE = main.tex
DVI_FILE  = $(addsuffix .dvi, $(basename $(MAIN_FILE)))
AUX_FILE  = $(addsuffix .aux, $(basename $(MAIN_FILE)))
PS_FILE   = $(addsuffix .ps,  $(basename $(MAIN_FILE)))
PDF_FILE  = $(addsuffix .pdf, $(basename $(MAIN_FILE)))

SOURCES = $(TEX_FILE) $(FIXOS_FILES) $(EDITAVEIS_FILES)

CC=pandoc
FLAGS= --filter pandoc-eqnos --filter pandoc-tablenos --from=markdown --to=latex --indented-code-classes=numberLines --highlight-style=zenburn --parse-raw --smart --normalize --listings --ascii --atx-headers --number-sections --base-header-level=1

.PHONY: all clean tex pdf

all:
	@make tex
	@make pdf

tex:
	@iconv -t utf-8 $(MKD_FILE) | $(CC) $(FLAGS) --output=$(TEX_FILE)

pdf: $(SOURCES) bibliografia.bib
	$(LATEX)  $(MAIN_FILE) $(SOURCES)
	$(BIBTEX) $(AUX_FILE)
	$(LATEX)  $(MAIN_FILE) $(SOURCES)
	$(LATEX)  $(MAIN_FILE) $(SOURCES)
	@cp -v $(PDF_FILE) ../$(TARGET)
	@rm -vf *.brf *.lol *.idx *.lof *.lot *.toc *.bbl *.blg *.log *.aux *.dvi

clean:
	@rm -vf *.brf *.lol *.idx *.lof *.lot *.toc *.bbl *.blg *.log *.aux *.dvi tmp.tex $(TEX_FILE) $(PDF_FILE) ../$(TARGET)
