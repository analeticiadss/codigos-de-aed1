//questão 6 - lista de ordenação e listas encadeadas
//10/06/2021

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




int listaVazia(tipoLista *p) {
	
	return p->prim == NULL;	
}


// COLOQUE AQUI SEU CODIGO
void destroiLista(tipoLista *pLista) {
	tipoNo *aux, *temp;
	
	if(pLista->prim) {
		aux = pLista->prim;
		while(aux->prox) {
			temp = aux->prox;
			aux->prox = temp->prox;	
			free(temp);
		}
		if(aux->prox == NULL) {
			temp = aux->prox;
			aux->prox = NULL;
			free(temp);
			aux = pLista->prim;
			pLista->prim = NULL;
			free(aux);
		}
	}
}


// FIM DO SEU CODIGO



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
  int tam;

  criaLista(&l1);
  scanf("%d%*c",&tam);
  lerValoresParaLista(&l1,tam);
  destroiLista(&l1);
  if(listaVazia(&l1)) {
	  printf("VAZIA\n");
  }
  else {
	  printf("NAO\n");
  }
}

