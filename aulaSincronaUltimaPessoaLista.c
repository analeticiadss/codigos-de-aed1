#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef  struct {
 char nome[30]; 
 char endereco[20];
float altura; 
           } tipoDados;


typedef struct tipoNo {
tipoDados d;
struct tipoNo *prox;
} tipoNo;

typedef struct tipoLista {
tipoNo *prim;
}  tipoLista;

void ultimaPessoa(tipoLista *pLista) {
	tipoNo *aux;
	if(pLista->prim) {
		aux = pLista->prim;
		while(aux->prox) {
			aux = aux->prox;
		}
		printf("%s\n", aux->d.nome);
	}
	
}
