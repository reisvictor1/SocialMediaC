#include <stdio.h>
#include <stdlib.h>
#include "tad_grafo.h"
#define MAX_VERTICES 10

typedef struct aresta
{
    int v;
    float peso;
    int amigos;// 0 - nao sao amigos; 1- sao amigos
    struct aresta *prox;
}Aresta;

struct vertice
{
   int v;
   char nome[50];
   int idade;
   char cidade[50];
   char time[50];
   char gFilme[50];
   char fMusica[50];
   char comida[50];
   int numA;//numero de arestas desse vertice
   Aresta* cab;
};

struct grafo{

    int num_vertices;
    Vertice *v;

};

Grafo* criaGrafo(int v){

    Grafo* g = (Grafo*) malloc(sizeof(Grafo));
    g->num_vertices = v;
    g->v = (Vertice*) malloc(v*sizeof(Vertice));
   
    for (int i = 0; i < g->num_vertices; i++){
      g->v[i].cab = NULL;
      g->v[i].v = i;
      g->v[i].nome = "\0";
      g->v[i].idade = 0;
      g->v[i].cidade = "\0";
      g->v[i].time = "\0";
      g->v[i].gFilme = "\0";
      g->v[i].gMusica = "\0";
      g->v[i].numA = 0;
      g->v[i].comida = "\0";
    }
    
    return g;
}

int criaAresta(Grafo* g,int v1, int v2){

    if(!g) return 1;

    if((v2 < 0) || (v2 >= g->num_vertices)) return 1;
    if((v1 < 0) || (v1 >= g->num_vertices)) return 1;

    Aresta* novo = (Aresta*) malloc(sizeof(Aresta));
    novo->v = v2;
    novo->peso = 0;
    novo->amigos = 0;
    novo->prox = NULL;
    
    if(!(g->v[v1].cab)){
        g->v[v1].cab = novo;
    }
    else{
        Aresta *p = g->v[v1].cab;
        Aresta *ant;
        while(p){
            ant = p;
            p = p->prox;
        }

        ant->prox = novo;

    }

    return 0;
}


void imprimeGrafo(Grafo* g){
    for(int i = 0; i < g->num_vertices; i++){
        printf("Vertice: %d -> ",g->v[i].v);
        Aresta *p = g->v[i].cab;
       
        while(p){
            printf("%d ",p->v);
            p = p->prox;
        }
        
       printf("\n");
    }
}


int verificaUser(Grafo* g, int user){
    if(user < g->num_vertices) return 1;

    return 0;
}

void desalocaGrafo(Grafo* g){

    for(int i = 0; i < g->num_vertices; i++){
         Aresta *p = g->v[i].cab;
        if(p != NULL){
            Aresta *ant;
            while(p){
                ant = p;
                free(ant);
                p = p->prox;
            }
        }
    }

   free(g->v);
}

void inserir_vertice(Grafo * g,int i, vertice *aux);
{
	g->v[i].nome = aux.nome;
	g->v[i].idade = aux.idade;
	g->v[i].cidade = aux.cidade;
	g->v[i].time = aux.time;
	g->v[i].gFilme = aux.gFilme;
	g->v[i].gMusica = aux.gMusica;
	g->v[i].comida = aux.comida;

	free(aux);
}