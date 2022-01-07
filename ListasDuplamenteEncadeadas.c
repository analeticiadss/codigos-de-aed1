//aula 64 - listas duplamente encadeadas

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tipoAluno {
	char nome[30];
	char pibic; //verdadeiro ou falso
	char curso[30];
	float coeficienteRendimento;
} tipoAluno;

typedef struct tipoNo {
	tipoAluno dado;
	struct tipoNo *prox, *anterior; //ponteiro pra outras variaveis do tipoNo
} tipoNo;

typedef struct tipoLista {
	tipoNo *prim, *ult; //ponteiro do tipoNo
} tipoListaCircular;

void criaListaCircular(tipoLista *pLista) {
	pLista->prim = NULL;
	pLista->ult = NULL;
}

void insereListaDuplamente(tipoLista *pLista) {
	tipoNo *aux;
	
	aux = (tipoNo *) malloc(sizeof(tipoNo));
	aux->dado = dado;
	
	if(pLista->prim != NULL) {
		aux->prox = pLista->prim;
		pLista->prim->anterior = aux; //ou aux->prox->ant = aux; pLista->prim é o antigo primeiro da lista
		aux->anterior = NULL;
		pLista->prim = aux;
	}
	else {
		aux->prox = NULL;
		aux->anterior = NULL;
		pLista->prim = aux;
		pLista->ult = aux;
	}
	
}
