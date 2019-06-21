all:
	gcc leArquivo.c tad_grafo.c fila.c grafos_trabalho.c -o main -lm -Wall -g

run:
	./main
