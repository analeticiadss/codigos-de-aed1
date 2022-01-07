//questao 1 - lista 2 manipulação de arquivos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[30];
    float salario;
    unsigned id;
} tipoDados;

typedef struct tipoNo {
	tipoDados dado;
	struct tipoNo *prox; //ponteiro pra outras variaveis do tipoNo
} tipoNo;

typedef struct tipoLista {
	tipoNo *prim, *ult; //ponteiro do tipoNo
} tipoLista;

void criaLista(tipoLista *pLista) {
	pLista->prim = NULL;
}

void insereElementoFinalLista(tipoLista *pLista, tipoDados *palavra) {
	tipoNo *aux;

	aux = (tipoNo *) malloc (sizeof(tipoNo));
	aux->dado = *palavra;
	aux->prox = NULL;
	if(pLista->ult != NULL) {
		pLista->ult->prox = aux;
	}else {
		pLista->prim = aux;
	}
	pLista->ult = aux;
}

void mostraLista(tipoLista *pLista) {
	tipoNo *aux;

	aux = pLista->prim;

	while(aux != NULL) {
        printf("%s\n", aux->dado.nome);
        printf("%.2f\n", aux->dado.salario);
        printf("%u\n", aux->dado.id);
		aux = aux->prox;
	}
}

void leBinario(char *nomeArquivo, tipoLista *pLista) {
    tipoDados pessoa;
    tipoNo *aux;
    FILE *fp;

    aux = pLista->prim;
    fp = fopen(nomeArquivo, "r");
    if(fp == NULL) {
        printf("erro ao ler o arquivo\n");
        exit(1);
    }

    while(fread(&pessoa, sizeof(tipoDados),1, fp) == 1) {
        insereElementoFinalLista(pLista, &pessoa);
    }
    fclose(fp);
}

int main() {
    tipoLista lista;

    criaLista(&lista);
    leBinario("dados", &lista);
    mostraLista(&lista);
}
