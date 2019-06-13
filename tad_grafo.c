#include <stdio.h>
#include <stdlib.h>
#include "tad_grafo.h"
#define MAX_VERTICES 10

typedef struct aresta
{
    int v;
    struct aresta *prox;
}Aresta;

struct vertice
{
   int v;

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
    }
    
    return g;
}

int criaAresta(Grafo* g,int v1, int v2){

    if(!g) return 1;

    if((v2 < 0) || (v2 >= g->num_vertices)) return 1;
    if((v1 < 0) || (v1 >= g->num_vertices)) return 1;

    Aresta* novo = (Aresta*) malloc(sizeof(Aresta));
    novo->v = v2;
    
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