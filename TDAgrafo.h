#include <stdio.h>
#include <stdlib.h>
#include "TDAcola.h"

/*------------- estructura de datos -------------*/
// TDA grafo de números enteros

typedef struct{
	int cvertices;
	int **adyacencias;
	}grafo;


/*----------------- operaciones -----------------*/

// crea_grafo_vacio() retorna un grafo vacío representado como matriz de adyacencia
// orden de complejidad: O(n^2)
grafo* crea_grafo_vacio(int vertices);


// imprime_matriz_grafo() imprime matriz de adyacencia
// orden de complejidad: O(n^2)
void imprime_matriz_grafo(grafo *g);


// lee_grafo_nodirigido(archivo) lee desde un archivo un grafo no dirigido
// el formato del archivo registra las aristas
// orden de complejidad: O(|E|)
grafo* lee_grafo_nodirigido(char *nombre_archivo);


// obtener_adyacentes(g, v) retorna una lista con los vértices adyacentes de v en el grafo g  
// orden de complejidad: O(n)
lista* obtener_adyacentes(grafo *g, int vertice);


// libera la memoria asignada al grafo g
void libera_grafo(grafo *g);


/*------------- actividad 1 -------------*/
void recorrido_anchura(grafo *g, int vertice);




