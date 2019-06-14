#include <stdio.h>
#include <stdlib.h>
#include "tad_grafo.h"
#include <math.h>
#define MAX_VERTICES 10

typedef struct aresta
{
    int v;
    float peso;
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

};

struct grafo{

    int num_vertices;
    Vertice *v;

};

Grafo* criaGrafo(int v){

    Grafo* g = (Grafo*) malloc(sizeof(Grafo));
    g->num_vertices = v;
    g->v = (vertice*) malloc(v*sizeof(Vertice));
   
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

    if(v1 == v2){
        printf("Você está fazendo amizade com você mesmo!!\n");
        return 1;
    }

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

int desalocaAresta(Grafo* g, int v1, int v2){

    Aresta* p = g->v[v1].cab;
    Aresta* aux = NULL;
    while(p){

        if(p->v == v2){

            if(p == g->v[v1].cab){
                g->v[v1].cab = NULL;
            }
            else{
                aux->prox = p->prox;
            }

            free(p);
            return 0;
        }

        aux = p;
        p = p->prox;
    }

    return 1;
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

float geraPeso(Grafo * g,int A, int B)
{
	float p = 0;
	
	int dif = abs(g->v[A].idade - g->v[B].idade);//recebe a diferenca de idade
	if (dif <= 3)
	{
		p += 9;
	}
	else if (dif <= 6 )
	{
		p+= 5;
	}
	else
	{
		p += 2;
	}

	if (strcmp(g->v[A].cidade, g->v[B].cidade) == 0)
		p += 5;
	
	if (strcmp(g->v[A].time, g->v[B].time) == 0)
		p+= 5;

	if (strcmp(g->v[A].gFilme, g->v[B].gFilme) == 0)
		p+= 5;
	
	if (strcmp(g->v[A].gMusica, g->v[B].gMusica) == 0)
		p+= 5;
	
	if (strcmp(g->v[A].comida, g->v[B].comida) == 0)
		p+= 5;
	
	if (g->v[A].numA <= g->v[B].numA)
		p += getAmigoSimi(A, B);		
	else
		p += getAmigoSimi(B, A);

	p = 1/p;

	return p;
}

int getAmigoSimi(Grafo * g,int A, int B)
{	
	aresta * aux =  g->v[A].lista.cab;
	aresta * cmp;
	int count = 0;
	while(aux != NULL)
	{
		if (saoAmigos(aux))
		{
			cmp = g->v[B].lista.cab;
			while(cmp != NULL)
			{
				if (aux.v ==  cpm.v)
				{
					if (saoAmigos(cmp))
					{
						count++;
						break
					}
				}
				cmp = cmp->prox;
			}
		}

		aux = aux->prox;
	}
	count * 3; //multiplica o numero de amigos por 3 pois esse é o valor no peso de uma amisade em comum

	return count;
}