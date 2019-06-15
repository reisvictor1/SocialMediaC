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
void inserir_vertice(Grafo * g,int i, Vertice *aux);
void listaAmigos(Grafo* g, int v);
float verificaCompatibilidade(Grafo*g, int v1, int v2);
int verificaDiferenca(Grafo* g, int n1, int n2);
