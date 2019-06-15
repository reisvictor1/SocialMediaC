#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad_grafo.h"
#include <math.h>
#define MAX_VERTICES 10

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

Grafo* criaGrafo(int v){

    Grafo* g = (Grafo*) malloc(sizeof(Grafo));
    g->num_vertices = v;
    g->v = (Vertice*) malloc(v*sizeof(Vertice));
   
    for (int i = 0; i < g->num_vertices; i++){
    	g->v[i].cab = NULL;
    	g->v[i].v = i;
    	strcpy(g->v[i].nome,"\0");
		g->v[i].idade = 0;
		strcpy(g->v[i].cidade, "\0");
		strcpy(g->v[i].time, "\0");
		strcpy(g->v[i].gFilme, "\0");
		strcpy(g->v[i].gMusica, "\0");
		strcpy(g->v[i].comida, "\0");
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
            if(p->v == v2){
                printf("Você já tem essa pessoa como amigo!\n");
                return 1;
            }
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

    if(v1 == v2){
        printf("Vejo que está com raiva de seu espírito interior!\n");
        return 1;
    }

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

    printf("Putz... Você não sabe quem são seus amigos?\n");
    return 1;
}

void listaAmigos(Grafo* g, int v){
    printf("Seus amigos são:\n");
    Vertice amg;
    Aresta *p = g->v[v].cab;
    while(p){
        amg = g->v[p->v];
        printf("%s, ",amg.nome);
    }
    printf("\n");
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

void inserir_vertice(Grafo * g,int i, Vertice *aux)
{
	strcpy(g->v[i].nome,aux->nome);
	g->v[i].idade = aux->idade;
	strcpy(g->v[i].cidade, aux->cidade);
	strcpy(g->v[i].time, aux->time);
	strcpy(g->v[i].gFilme, aux->gFilme);
	strcpy(g->v[i].gMusica, aux->gMusica);
	strcpy(g->v[i].comida, aux->comida);

	free(aux);
}

int getAmigoSimi(Grafo * g,int A, int B)
{	
	Aresta * aux =  g->v[A].cab;
	Aresta * cmp;
	int count = 0;
	while(aux != NULL)
	{
		if (aux->amigos == 1)
		{
			cmp = g->v[B].cab;
			while(cmp != NULL)
			{
				if (aux->v ==  cmp->v)
				{
					if (cmp->amigos == 1)
					{
						count++;
						break;
					}
				}
				cmp = cmp->prox;
			}
		}

		aux = aux->prox;
	}
	count *=  3; //multiplica o numero de amigos por 3 pois esse é o valor no peso de uma amisade em comum

	return count;
}

int verificaDiferenca(Grafo* g, int n1, int n2){
    int p;
  	int dif = abs(n1 - n2);//recebe a diferenca de idade
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

    return p;
}

float geraPeso(Grafo * g,int A, int B)
{
	float p = 0;
	
    p+= verificaDiferenca(g,g->v[A].idade,g->v[B].idade);

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
		p += getAmigoSimi(g,A, B);		
	else
		p += getAmigoSimi(g,B, A);

	p = 1/p;

	return p;
}


float verificaCompatibilidade(Grafo*g, int v1, int v2){
    int total = 0;
    total += verificaDiferenca(g,g->v[v1].idade,g->v[v2].idade);
    if (g->v[A].numA <= g->v[B].numA)
		total += getAmigoSimi(g,A, B);		
	else
		total += getAmigoSimi(g,B, A);

    total+= 25;
    
    float p = 1/geraPeso(g,v1,v2);
    return (p/(float) total)*100;
}