#ifndef FILA_H
#define FILA_H FILA_H

typedef struct no no;
typedef struct fila fila;

int vazia(fila * f);
fila * cria_fila();
void criar_no(fila * f, int v, float priori);
void inserir(fila *f, no *n);
int remover(fila *f);
void atualiza(fila *f, float *prioridaes);
void liberaFila(fila *f);

#endif