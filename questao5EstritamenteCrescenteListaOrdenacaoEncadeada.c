//questão 5 - lista de ordenação e listas encadeadas
//12/06/2021

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// SO pra manter o costume de colocar os dados da pilha com tipoDados
// aqui tipoDados vai ser mesma coisa que int

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


void lerValoresParaLista(tipoLista *p, int tam) {
  int val;

  for(int x = 0; x< tam; x++) {
    scanf("%d%*c",&val);
    insereNaLista(p,&val);
  }
}

// ALTERE APENAS O TRECHO ABAIXO
// INICIO DO SEU CODIGO
int estritamenteCrescente(tipoLista *pLista) {
	tipoNo *aux, *seguinte;

	aux = pLista->prim;
	if(aux == NULL || aux->prox == NULL) {
		return 1; //verdadeiro para listas vazias ou listas com um elemento
	}
	else if (aux->prox) { //tem mais de um elemento na lista
		while(aux->prox) {
			if((aux->d) < (aux->prox->d)) {
                aux = aux->prox;
			} else {
			    return 0;
			}
		}
	}
	return 1;
}
// FIM DO TRECHO DE CÓDIGO


int main() {
  tipoLista l1;
  int tam;

  criaLista(&l1);
  scanf("%d%*c",&tam);
  lerValoresParaLista(&l1,tam);
  printf("%d\n",estritamenteCrescente(&l1));
}
