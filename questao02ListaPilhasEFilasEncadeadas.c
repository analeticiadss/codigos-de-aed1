//questão 2 - lista de pilhas e filas encadeadas
//01/06/2021

#include <stdio.h>

typedef struct { 
		char nome[20];
	    int id;
} tipoDados;

typedef struct tipoNo {
 tipoDados d;
 struct tipoNo *prox;
} tipoNo;


typedef struct tipoFila {
 tipoNo *prim;
 tipoNo *ult;
} tipoFila;

// Funcoes a serem feitas. 
// Coloque os includes necessários para seu para o seu 
// programa aqui
// SUAS FUNCOES DEVEM COMPLEMENTAR O PROGRAMA PRINCIPAL
// ELE JA TEM CHAMADAS PARA SUAS FUNCOES
#include <stdlib.h>
#include <string.h>

void criaFila(tipoFila *p1) {
	p1->prim = NULL;
	p1->ult = NULL;
}

void insereNaFila(tipoFila *p1, tipoDados pessoa) {
	tipoNo *aux;
	
	aux = (tipoNo*) malloc(sizeof(tipoNo));
	aux->prox = NULL; //porque aux vai ser o ultimo da fila
	strcpy(aux->d.nome, pessoa.nome);
	aux->d.id = pessoa.id;
	if(p1->ult != NULL) {
		p1->ult->prox = aux;
	}else {
		p1->prim = aux;
	}
	p1->ult = aux;
}

tipoDados removeDaFila(tipoFila *p1) {
	tipoDados pessoa;
	tipoNo *temp;
	
	//como eu sei que temp VAI ser diferente de NULL, não preciso do if (temp)
	temp = p1->prim; //o primeiro da fila
	strcpy(pessoa.nome, temp->d.nome); //pega o nome de p1->prim
	pessoa.id = temp->d.id; //pega o id de p1->prim
	p1->prim = temp->prox; //p1->prim agora recebe o endereço de temp->prox
	free(temp);
	return pessoa;
	
}


// FIM DO SEI CODIGO


void mostraFila(tipoFila *p) {
 tipoNo *aux= p->prim;
	
	while(aux) {
	printf("%s\n",aux->d.nome);
	printf("%d\n",aux->d.id);
	aux = aux->prox;
	}
	
}

int  main() {
	tipoDados pessoa;
	tipoFila p1;
	tipoFila p2;
	
	
	criaFila(&p1);
	criaFila(&p2);
	
	scanf("%[^\n]%*c",pessoa.nome);
	scanf("%d%*c",&pessoa.id);
	insereNaFila(&p1,pessoa);
	
	scanf("%[^\n]%*c",pessoa.nome);
	scanf("%d%*c",&pessoa.id);
	insereNaFila(&p1,pessoa);
	
	pessoa = removeDaFila(&p1);
	insereNaFila(&p2,pessoa);
	
	scanf("%[^\n]%*c",pessoa.nome);
	scanf("%d%*c",&pessoa.id);
	insereNaFila(&p1,pessoa);
	
	scanf("%[^\n]%*c",pessoa.nome);
	scanf("%d%*c",&pessoa.id);
	insereNaFila(&p1,pessoa);
	
	pessoa = removeDaFila(&p1);
	insereNaFila(&p2,pessoa);
	
	printf("\nfila 1:\n");
	mostraFila(&p1);
	printf("fila 2:\n");
	mostraFila(&p2);
	
}

