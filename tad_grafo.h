#ifndef TAD_GRAFO_H
#define TAD_GRAFO_H

typedef struct grafo Grafo;
typedef struct aresta Aresta;
typedef struct vertice Vertice;

Grafo* criaGrafo(int v);
int criaAresta(Grafo* g,int v1, int v2);
int desalocaAresta(Grafo* g, int v1, int v2);
void imprimeGrafo(Grafo* g);
int verificaUser(Grafo* g, int user);
void desalocaGrafo(Grafo* g);
float geraPeso(Grafo * g,int A, int B);
int getAmigoSimi(Grafo * g,int A, int B);

#endif