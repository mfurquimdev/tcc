TARGET=main.tex
SOURCES=forma_extensa.tex pesquisa.tex introducao.tex jogo.tex  \
	solucao.tex referencial.tex resultados.tex consideracoes.tex

all:$(TARGET)
	pdflatex $(TARGET) $(SOURCES)
	pdflatex $(TARGET) $(SOURCES)

clean:
	rm -v *.nav *.snm *.toc *.vrb *.out *.log *.aux
