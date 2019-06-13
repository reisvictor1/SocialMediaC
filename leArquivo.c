#include <stdio.h>
#include <stdlib.h>
#include "trab_grafo.h"

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

	fread(&aux1, sizeof(int), 1, arq);//le o id do vertice
	aux.id = aux1;

	fread(&aux3, sizeof(char),1, arq);//le a virgula
	fscanf(arq,"%s",aux2);//le o nome;
	aux.nome =  aux2;

	fread(&aux3, sizeof(char),1, arq);//le a virgula
	fscanf(arq,"%s",aux2);//le cidade
	aux.cidade = aux2;

	fread(&aux3, sizeof(char),1, arq);//le a virgula
	fscanf(arq,"%s",aux2);//le time
	aux.time = aux2;

	fread(&aux3, sizeof(char),1, arq);//le a virgula
	fscanf(arq,"%s",aux2);//le genero de Filme
	aux.gFilme = aux2;

	fread(&aux3, sizeof(char),1, arq);//le a virgula
	fscanf(arq,"%s",aux2);//le genero de musica
	aux.gMusica = aux2;

	fread(&aux3, sizeof(char),1, arq);//le a virgula
	fscanf(arq,"%s",aux2);//le comida
	aux.comida = aux2;
	fread(&aux3, sizeof(char),1, arq);//le o\n

	return aux;
}

void le_arq_vertices(FILE * arq, grafo * g)
{
	if (arq == NULL)
	{
		printf("arquivo nao encontrado ou corrompido\n");
		return;
	}

	int numV = 0;
	vertice * aux;
	fread(&numV, sizeof(int),1, arq);//le o numero de vertices contido no arquivo

	for (int i = 0; i < numV; i++)
	{
		aux =  le_vert(arq);//le o proximo vertice do arquivo
		inserir_vertice(g, aux);//insere o vertice lido no grafo
	}
}