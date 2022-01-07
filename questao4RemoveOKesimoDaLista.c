//questão 4 - lista de ordenação e listas encadeadas
//10/06/2021

#include <stdio.h>
#include <string.h>
#include <stdlib.h>




typedef int tipoDados;


typedef struct tipoNo {
  tipoDados d;
  struct tipoNo *prox;
} tipoNo;

typedef struct tipoList {
  tipoNo *prim;
} tipoLista;



void mostraLista(tipoLista *pLista) {
  tipoNo *aux;

  aux = pLista->prim;

  while(aux) {
    printf("%d\n",aux->d);
    aux = aux->prox;
  }
}



void insereNaLista(tipoLista *pLista, tipoDados *al) {

  tipoNo *aux;
  aux = (tipoNo *) malloc (sizeof(tipoNo) );
  aux->d = *al;
  aux->prox = pLista->prim;
  pLista->prim = aux;
}



void criaLista(tipoLista *pLista) {
  pLista->prim = NULL;
}


// FACA AQUI SUA FUNCAO
void removeDaLista(tipoLista *pLista, int k) {
	int cont = 1;
	tipoNo *aux, *temp;
	
	aux = pLista->prim;
	if(aux) { //se pLista->prim != NULL, se não estiver vazia
		if(cont == k) {
			pLista->prim = aux->prox;
			free(aux);
		}
		while(aux->prox) { //enquanto pLista->prim->prox != NULL
			cont++; //conta os elementos da lista
			if(cont == k) {
				temp = aux->prox;
				aux->prox = temp->prox;
				free(temp);
			}
			aux = aux->prox;
		}
		
	}
	
}

// FIM DA SUA FUNCAO

void lerValoresParaLista(tipoLista *p, int tam) {
  int val;
 int x;
  for( x = 0; x< tam; x++) {
    scanf("%d%*c",&val);
    insereNaLista(p,&val);
  }
}





int main() {
  tipoLista l1;
  int k;
  int tam;

  criaLista(&l1);
  scanf("%d%*c",&tam);
  lerValoresParaLista(&l1,tam);
  scanf("%d%*c",&k);

  mostraLista(&l1);
  printf("Removendo a posicao %d\n",k);
  removeDaLista(&l1,k);
  scanf("%d%*c",&k);
  mostraLista(&l1);
  printf("Removendo a posicao %d\n",k);
  removeDaLista(&l1,k);
  mostraLista(&l1);
}

