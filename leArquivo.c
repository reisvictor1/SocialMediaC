#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad_grafo.h"

Vertice * le_vert(FILE * arq)
{
	if (arq == NULL)
	{
		printf("arquivo nao encontrado ou corrompido\n");
		return NULL;
	}

	Vertice *aux = (Vertice*)malloc(sizeof(Vertice) * 1);
	int aux1;
	char *aux2 = malloc(sizeof(char) * 100);
	char aux3;

	
	fscanf(arq,"%s",aux2);//le o nome ate o \0
	strcpy(aux->nome, aux2);

	fread(&aux3, sizeof(char),1, arq);//le a virgula
	fscanf(arq,"%d", &aux1);
	aux->idade = aux1;

	fread(&aux3, sizeof(char),1, arq);//le a virgula
	fscanf(arq,"%s",aux2);//le cidade ate o \0
	strcpy(aux->cidade, aux2);

	fread(&aux3, sizeof(char),1, arq);//le a virgula
	fscanf(arq,"%s",aux2);//le time ate o \0
	strcpy(aux->time, aux2);

	fread(&aux3, sizeof(char),1, arq);//le a virgula
	fscanf(arq,"%s",aux2);//le genero de Filme ate o \0
	strcpy(aux->gFilme, aux2);

	fread(&aux3, sizeof(char),1, arq);//le a virgula
	fscanf(arq,"%s",aux2);//le genero de musica ate o \0
	strcpy(aux->gMusica, aux2);

	fread(&aux3, sizeof(char),1, arq);//le a virgula
	fscanf(arq,"%s",aux2);//le comida ate o \0
	strcpy(aux->comida, aux2);
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

	Vertice *aux;

	for (int i = 0; i < numv; i++)
	{
		aux =  le_vert(arq);//le o proximo vertice do arquivo
		inserir_vertice(g, i, aux);
	}
}