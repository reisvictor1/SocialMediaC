all: exec

exec: fila.o tad_grafo.o  leArquivo.o grafos_trabalho.o 
		gcc fila.o tad_grafo.o  leArquivo.o grafos_trabalho.o -o exec

fila.o: fila.c
		gcc -c fila.c

tad_grafo.o: tad_grafo.c
			 gcc -c tad_grafo.c

leArquivo.o: leArquivo.c
			 gcc -c leArquivo.c

grafos_trabalho.o: grafos_trabalho.c
				   gcc -c grafos_trabalho.c
