#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


typedef struct no
{
	int v;
	float prioridade;
	no * prox;
}no;


typedef struct fila
{
	int tam;
	no * inicio;
}fila;

int vazia(fila * f){
	return f->tam;
}

fila * cria_fila(){
	fila *f = malloc(sizeof(fila));
	f->tam = 0;
	f->inicio = NULL;

	return f;
}


void criar_no(fila * f, int v, float priori){

	no *n = malloc(sizeof(no));
	n->v = v;
	n->prioridade = priori;
	inserir(f, n);
}


void inserir(fila *f, no *n){
	if (f->tam == 0 )//inserir no inicio
	{
		n->prox = NULL;
		f->inicio = n;
	}

	no *aux1;
	no *aux2;

	aux1 = f->inicio;

	while(aux1->prioridade < n->prioridade){

		aux2 = aux1;
		aux1 = aux1->prox;
	}

	n->prox = aux1;
	aux2->prox = n;
	f->tam++;
}

int remover(fila *f){
	no *aux = f->inicio;
	f->inicio = aux->prox;
	f->tam--;

	int v = aux->v;
	free(aux);
	return v;
}


void atualiza(fila *f, float *prioridades){
	fila *atualizada = cria_fila();
	no *aux = f->inicio;
	f->inicio = aux->prox;

	while(aux != NULL){
		printf("%d\n",aux->v);
		aux->prioridade = prioridades[aux->v];
		inserir(atualizada, aux);//insere o no na nova fila de prioridade com as distancias atualizadas

		aux = f->inicio;//retira no do inicio da fila de prioridade antiga
		if (f->tam == 1)
			f->inicio = aux->prox;//atualiza o inicio da fila de prioridade antiga
	}

	free(f);
	f = atualizada;
}

void liberaFila(fila *f){
	while(f->tam != 0){
		remover(f);
	}

	free(f);
}