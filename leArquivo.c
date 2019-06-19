#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad_grafo.h"

typedef struct aresta
{
    int v;
    float peso;
    int amigos;//0 -nao sao amigos; 1- sao amigos
    struct aresta *prox;
}Aresta;

typedef struct vertice
{
   int v;
   char nome[50];
   int idade;
   char cidade[50];
   char time[50];
   char gFilme[50];
   char gMusica[50];
   char comida[50];
   int numA;//numero de arestas desse vertice
   Aresta * cab;

}Vertice;

struct grafo{

    int num_vertices;
    Vertice *v;

};

Vertice* le_vert(FILE * arq)
{
	if (arq == NULL)
	{
		printf("arquivo nao encontrado ou corrompido\n");
		return NULL;
	}	

	Vertice *aux = (Vertice*) malloc(sizeof(Vertice));
	int aux1;
	char *aux2 = malloc(sizeof(char) * 100);

	char aux3[3];

	fscanf(arq,"%[^,]s",aux2);//le o nome ate o \0
	strcpy(aux->nome, aux2);

	fscanf(arq,"%[,]s",aux3);
	fscanf(arq,"%d", &aux1);
	aux->idade = aux1;
	
	fscanf(arq,"%[,]s",aux3);//le a virgula
	fscanf(arq,"%[^,]s",aux2);//le cidade ate o \0
	strcpy(aux->cidade, aux2);

	fscanf(arq,"%[,]s",aux3);//le a virgula
	fscanf(arq,"%[^,]s",aux2);//le time ate o \0
	strcpy(aux->time, aux2);

	fscanf(arq,"%[,]s",aux3);//le a virgula
	fscanf(arq,"%[^,]s",aux2);//le genero de Filme ate o \0
	strcpy(aux->gFilme, aux2);

	fscanf(arq,"%[,]s",aux3);//le a virgula
	fscanf(arq,"%[^,]s",aux2);//le genero de musica ate o \0
	strcpy(aux->gMusica, aux2);

	fscanf(arq,"%[,]s",aux3);//le a virgula
	fscanf(arq,"%[^\n\r]s",aux2);//le comida ate o \0

	strcpy(aux->comida, aux2);
	fscanf(arq,"%[\r\n]s",aux3);//le o\n

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
	char c = '?';
	fscanf(arq,"%c", &c);//le o \n

	Vertice *aux;

	for (int i = 0; i < g->num_vertices; i++)
	{
		aux =  le_vert(arq);//le o proximo vertice do arquivo
		inserir_vertice(g, i, aux);
	}
}