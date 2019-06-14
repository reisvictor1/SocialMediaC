#include <stdio.h>
#include <stdlib.h>
#include "tad_grafo.h"

vertice * le_vert(FILE * arq)
{
	if (arq == NULL)
	{
		printf("arquivo nao encontrado ou corrompido\n");
		return;
	}

	vertice * aux =  malloc(sizeof(vertice));
	int aux1;
	char *aux2 = malloc(sizeof(char) * 100);
	char aux3;

	fread(&aux3, sizeof(char),1, arq);//le a virgula
	fscanf(arq,"%s",aux2);//le o nome ate o \0
	aux.nome =  aux2;

	fread(&aux3, sizeof(char),1, arq);//le a virgula
	fscanf(arq,"%s",aux2);//le cidade ate o \0
	aux.cidade = aux2;

	fread(&aux3, sizeof(char),1, arq);//le a virgula
	fscanf(arq,"%s",aux2);//le time ate o \0
	aux.time = aux2;

	fread(&aux3, sizeof(char),1, arq);//le a virgula
	fscanf(arq,"%s",aux2);//le genero de Filme ate o \0
	aux.gFilme = aux2;

	fread(&aux3, sizeof(char),1, arq);//le a virgula
	fscanf(arq,"%s",aux2);//le genero de musica ate o \0
	aux.gMusica = aux2;

	fread(&aux3, sizeof(char),1, arq);//le a virgula
	fscanf(arq,"%s",aux2);//le comida ate o \0
	aux.comida = aux2;
	fread(&aux3, sizeof(char),1, arq);//le o\n

	return aux;
}

void le_arq_vertices(FILE * arq, Grafo * g, int numv)
{
	if (arq == NULL)
	{
		printf("arquivo nao encontrado ou corrompido\n");
		return;
	}

	if (g == NULL)
	{
		printf("Grafo não encontrado\n");
		return;
	}

	Vertice * aux;

	for (int i = 0; i < numV; i++)
	{
		aux =  le_vert(arq);//le o proximo vertice do arquivo
		inserir_vertice(g, i, aux);
	}
}