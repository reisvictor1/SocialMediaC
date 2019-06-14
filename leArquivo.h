#ifndef LEARQUIVO_H
#define LEARQUIVO_H

#include <stdio.h>
#include <stdlib.h>
#include "tad_grafo.h"

	Vertice * le_vert(FILE * arq);
	void le_arq_vertices(FILE * arq, Grafo * g, int numv);


#endif