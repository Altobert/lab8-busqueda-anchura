#include <stdio.h>
#include <stdlib.h>
#include "TDAgrafo.h"



/*----------------- implementación operaciones -----------------*/

grafo* crea_grafo_vacio(int vertices){
	grafo *g = (grafo*)malloc(sizeof(grafo));
	g->cvertices = vertices;
	g->adyacencias = (int**)malloc(vertices * sizeof(int*));
	int i, j;
	for (i = 0; i < vertices; i++){
		g->adyacencias[i] = (int*)malloc(vertices * sizeof(int));
		//Inicializa en cero
		for(j = 0; j < vertices; j++){
			g->adyacencias[i][j] = 0;
			}	
		}
	return g;
	}


void imprime_matriz_grafo(grafo *g){
	int i, j;	
	for (i = 0; i < g->cvertices; i++){
		for (j = 0; j < g->cvertices; j++){
			printf("%d ", g->adyacencias[i][j]);
			}
		printf("\n");
		}
	}


grafo* lee_grafo_nodirigido(char *nombre_archivo){
	FILE *pf;
	pf = fopen(nombre_archivo, "r");
	int n_vertices, m_aristas;
	int i,j,k;
	if (pf == NULL){
		printf("Error de archivo\n");
		return NULL;
		}
	else{
		fscanf(pf, "%d %d", &n_vertices,&m_aristas); 		
		grafo *G = crea_grafo_vacio(n_vertices);	
		for(k = 0; k < m_aristas; k++){
			fscanf(pf,"%d %d",&i, &j);
			G->adyacencias[i - 1][j - 1] = 1;
			G->adyacencias[j - 1][i - 1] = 1;
			}
		fclose(pf);
		return  G;	
		}
	}


int adyacencia_nodos(grafo * g, int vert_a, int vert_b){
	if (g->adyacencias[vert_a - 1][vert_b - 1] == 1){
		return 1;
		}
	return 0;
	}


lista* obtener_adyacentes(grafo *g, int vertice){
	if(vertice > g->cvertices)
		return NULL;
	lista *l = nueva_lista();
	for(int i = 0; i < g->cvertices; ++i){
		if(adyacencia_nodos(g, vertice, i + 1)){
			inserta_inicio(l, i + 1);
			}
		}
	return(l);
	}


void libera_grafo(grafo *g){
	for(int i = 0; i < g->cvertices; ++i){
		free(g->adyacencias[i]);
		}
	free(g->adyacencias);
	free(g);
	}


void recorrido_anchura(grafo *g, int vertice){	
	
	//construir arreglo
	//int arreglo[g->cvertices];
	int *arreglo = (int*)malloc(g->cvertices * sizeof(int));

	//se crea cola vacia
	cola *colaAnchura = crea_cola_vacia();	
	
	encolar(colaAnchura, vertice);

	for(int i =0; i < g->cvertices; i++){
		arreglo[i] = 0;
	}

	//marcar_visitado
	printf("visitado: ");
	arreglo[vertice-1] = 1;
	for(int j=0; j < g->cvertices; j++){
		printf("%d ",arreglo[j]);
	}	
	printf("\n");

	// a medida que voy visitando voy imprimiendo.
	while (!es_cola_vacia(colaAnchura)){

		int w  = frente(colaAnchura)->dato;
		//int w = colaAnchura->n_frente->dato;
		printf("cola anchura %d",w);
		printf("\n");

		descolar(colaAnchura);

		//lista *l = obtener_adyacentes(g, w);
		  lista *l = obtener_adyacentes(g, w);
		
		//nodo *ptr = l -> inicio;
		nodo *ptr = l -> inicio;

		while (ptr != NULL){
			//Si no esta visitado
			if (arreglo[ptr->dato-1] == 0){

				encolar(colaAnchura, ptr->dato);
				arreglo[ptr->dato-1] = 1;
				
			}
			ptr = ptr->siguiente;			
		}
		//mostrar los marcados
		printf("visitado: ");
		for(int j=0; j < g->cvertices; j++){
			printf("%d ",arreglo[j]);
		}
		
	}

		 
}
	



