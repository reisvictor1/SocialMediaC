#include <stdio.h>
#include <stdlib.h>
#include "tad_grafo.h"
#include "leArquivo.h"

int main(){

    int num_vertices;
    char nome[50];
    char aux[3];
    FILE * arq;
    printf("Insira o nome do bando de dados desejado!\n");
    scanf("%s", nome);
    arq =  fopen(nome, "r");
  
    if (arq == NULL)//arquivo nao existente
    {
        printf("Erro: FALHA NO PROCESSAMENTO DO ARQUIVO\n");
        return 0;
    }

    fscanf(arq,"%d", &num_vertices);
    fscanf(arq,"%[\r]s",aux);
    

    if (num_vertices <= 0)//arquivo invalido
    {
        printf("Erro: FALHA NO PROCESSAMENTO DO ARQUIVO\n");
        return 0;
    }

    Grafo* g = criaGrafo(num_vertices);
    le_arq_vertices(arq, g, num_vertices);
    system("clear");
    int v;
    int id;
    char user[50];
    char op1;
    int op2;

    do{
        printf("Você quer logar na rede social?(S/N)\n");
        scanf(" %c",&op1);
        system("clear");
        switch (op1){
            case 'S':
            case 's':
                printf("Qual é o seu usuário?\n");
                scanf("%s",user);
                id = verificaNome(g,user);
                system("clear");
                if(verificaUser(g,id)){
                   // verificaNovosAmigos(g,id);
                    do
                    {

                        printf("Quais das opções você quer?\n0)Listar seus amigos\n1) Fazer amizade\n2) Sugerir Amizade\n3) Detectar amizade falsa\n4) Encontrar namorado(a) ideal\n5)Sair\n");
                        scanf("%d",&op2);
                        system("clear");
                        switch(op2){
                            case 0:
                                
                                listaAmigos(g,id);
                                break;
                            case 1:
                               
                                printf("Com quem você quer fazer amizade?");
                                scanf("%s",user);
                                v = verificaNome(g,user);
                                
                                criaAresta(g,id,v);
                                if(v != id)
                                    criaAresta(g,v,id);
                                
                                break;
                            case 2:

                                sugerir_amizade(g, id);
                              
                                break;
                            case 3:
                                printf("Quem você quer retirar?");
                                scanf("%s",user);
                                int v = verificaNome(g,user);
                                desalocaAresta(g,id,v);
                                
                                break;
                            case 4:


                                system("clear");
                                break;
                        }

                    }while (op2 < 5);
                    
                }

                break;    
        }

    }while((op1 == 'S') || (op1 == 's'));

    fclose(arq);
    desalocaGrafo(g);
    free(g);
}
