#include <stdio.h>
#include <stdlib.h>
#include "TDAgrafo.h"

int main(int argc, char *argv[]){
	grafo *g;
	g = lee_grafo_nodirigido(argv[1]);	
	if (g != NULL){
		printf("Matriz de adyacencia: \n");
		imprime_matriz_grafo(g);
		printf("\n--------------\n");
		}
	
    int vertice_inicial = atoi(argv[2]);

    printf("\nRecorrido en anchura desde %d: \n", vertice_inicial);
    
	recorrido_anchura(g, vertice_inicial);
	
	printf("\n--------------\n");

    libera_grafo(g);

	return 0;
	}
