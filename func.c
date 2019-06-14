#include "tad_grafo.h"


float * geraPeso(vertice * A, vertice * B)
{
	float p = 0;
	
	int dif = abs(A.idade - B.idade);//recebe a diferenca de idade
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

	if (strcmp(A.cidade, B.cidade) == 0)
		p += 5;
	

	if (strcmp(A.time, B.time) == 0)
		p+= 5;
	

	if (strcmp(A.gFilme, B.gFilme) == 0)
		p+= 5;
	

	if (strcmp(A.gMusica, B.gMusica) == 0)
		p+= 5;
	

	if (strcmp(A.comida, B.comida) == 0)
		p+= 5;
	
	if (A.numA <= B.numA)
	{
		p += getAmigoSimi(A, B);		
	}
	else
	{
		p += getAmigoSimi(B, A);
	}
	

	p = 1/p;

	return p;
}


int getAmigoSimi(vertice * A, vertice * B)
{	
	aresta * aux =  A.lista.cab;
	aresta * cmp;
	int count = 0;
	while(aux != NULL)
	{
		if (saoAmigos(aux))
		{
			cmp = B.lista.cab;
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