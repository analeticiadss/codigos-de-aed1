//questão 2 - lista de manipulação de arquivos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoDados {
    char palavra[50];
    unsigned freq;
} tipoDados;

typedef struct tipoNo {
	tipoDados dado;
	struct tipoNo *prox; //ponteiro pra outras variaveis do tipoNo
} tipoNo;

typedef struct tipoLista {
    unsigned qtdElementos;
	tipoNo *prim, *ult; //ponteiro do tipoNo
} tipoLista;

/*void ordenaInsercao (tipoDados *vet, unsigned tamVet) {
	int i, j;
	unsigned pivot;

	for(i = 1; i < tamVet; i++) {
		pivot = vet[i].freq;
		j = i-1;
		while(j >= 0 && (vet[j].freq > pivot)) {
			vet[j+1].freq = vet[j].freq;
			strcpy(vet[j+1].palavra = vet[j].palavra);
			j--;
		}
		vet[j+1].freq = pivot;
	}
}*/

void criaLista(tipoLista *pLista) {
	pLista->prim = NULL;
	pLista->qtdElementos = 0;
	pLista->prim->dado.freq = 0;
}

void insereElementoFinalLista(tipoLista *pLista, tipoDados *palavra) {
	tipoNo *aux;

	aux = (tipoNo *) malloc (sizeof(tipoNo));
	aux->dado = *palavra;
	aux->prox = NULL;
	pLista->qtdElementos++;
	if(pLista->ult != NULL) {
		pLista->ult->prox = aux;
	}else {
		pLista->prim = aux;
	}
	pLista->ult = aux;
}

void carregaLista(char *nomeArq, tipoLista *pLista) {
    FILE *fp;
    tipoDados palavra;

    unsigned cont = 0;

    fp = fopen(nomeArq, "r");

    if(fp == NULL) {
        printf("erro\n");
        exit(1);
    }

    while(fscanf(fp, "%[^\n]%*c", palavra) == 1) {
        insereElementoFinalLista(pLista, &palavra);
    }

    fclose(fp);

}

void freqLista(tipoLista *pLista, tipoLista *listaAux) {
    tipoNo *aux, *temp;
    tipoDados palavraCopia;

    temp = pLista->prim;
    aux = listaAux->prim;

    while(temp->prox != NULL) {
        while(aux->prox != NULL) {
            if(strcmp(aux->dado.palavra, temp->dado.palavra) == 0) {
                aux->dado.freq++;
            }
            else {
                strcpy(palavraCopia, temp->dado.palavra);
                insereElementoFinalLista(listaAux, &palavraCopia);
                aux->dado.freq++;
            }
            aux = aux->prox;
        }
        if(aux == NULL) {
          strcpy(palavraCopia, temp->dado.palavra);
          insereElementoFinalLista(listaAux, &palavraCopia);
          aux->dado.freq++;
		 }
        temp = temp->prox;
    }
}

void mostra(tipoLista *listaAux) {
    tipoNo *aux;
    unsigned cont = 0;

    aux = listaAux->prim;
    while(cont < 5){
        printf("%s %u\n", aux->dado.palavra, aux->dado.freq);
        cont++;
        aux = aux->prox;
    }
}
int main () {
    tipoLista lista;
    tipoLista listaAux;


    criaLista(&lista);
    carregaLista("palavras", &lista);

    criaLista(&listaAux);
    freqLista(&lista, &listaAux);
//    ordenaInsercao(listaAux->prim.dado, lista.qtdElementos);
    mostra(&listaAux);

}
