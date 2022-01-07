//questao 2 - prova 6 - posicao par da lista
//11/06/2021

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
void mostraPares(tipoLista *pLista) {
	tipoNo *aux;
	unsigned cont;
	
	if(pLista->prim) {
		cont = 1; //primeiro elemento da lista - cont == 1
		aux = pLista->prim;
		while(aux->prox) {
			cont++;
			if(cont%2 == 0) {
				printf("%s\n", aux->prox->d.nome);
				printf("%s\n", aux->prox->d.endereco);
				printf("%.2f\n", aux->prox->d.altura);
			}
			aux = aux->prox;
		}
	}
}

// FIM DO SEU CODIGO



void lerValoresParaLista(tipoLista *p, int tam) {
  tipoDados val;
 int x;
  for( x = 0; x< tam; x++) {
     scanf("%[^\n]%*c",val.nome);
     scanf("%[^\n]%*c",val.endereco);
     scanf("%f%*c",&val.altura);
    insereNaLista(p,&val);
  }
}



int main() {
  tipoLista l1;
  int tam;

  criaLista(&l1);
  scanf("%d%*c",&tam);
  lerValoresParaLista(&l1,tam);
  mostraPares(&l1);
  printf("FIM\n");
}


