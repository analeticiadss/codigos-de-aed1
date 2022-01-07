//questão 1 - lista de pilhas encadeadas e filas encadeadas
// ana leticia - 01/06/2021

#include <stdio.h>

typedef struct { 
		char nome[20];
	    int id;
} tipoDados;

typedef struct tipoNo {
 tipoDados d;
 struct tipoNo *prox;
} tipoNo;


typedef struct tipoPilha {
 tipoNo *topo;
} tipoPilha;

// Funcoes a serem feitas. 
// Coloque os includes necessários para seu para o seu 
// programa aqui
// SUAS FUNCOES DEVEM COMPLEMENTAR O PROGRAMA PRINCIPAL
// ELE JA TEM CHAMADAS PARA SUAS FUNCOES
#include <stdlib.h>
#include <string.h>

void criaPilha(tipoPilha *pPilha) {
	pPilha->topo = NULL;
}

void insereNaPilha(tipoPilha *pPilha, tipoDados pessoa) {
	tipoNo *aux;
	
	aux = (tipoNo *) malloc(sizeof(tipoNo));
	
	aux->prox = pPilha->topo; //o prox rcebe o endereço do antigo topo
	strcpy(aux->d.nome, pessoa.nome); //copia nome
	aux->d.id = pessoa.id; //copia id
	pPilha->topo = aux; //o topo recebe o endereço de aux
}

tipoDados removeDaPilha(tipoPilha *pPilha) {
	tipoNo *temp;
	tipoDados pessoa;
	
	temp = pPilha->topo;
	strcpy(pessoa.nome, temp->d.nome);
	pessoa.id = temp->d.id;
	pPilha->topo = temp->prox;
	free(temp);
	return pessoa;
}


// FIM DO SEI CODIGO


void mostraPilha(tipoPilha *p) {
 tipoNo *aux= p->topo;
	
	while(aux) {
	printf("%s\n",aux->d.nome);
	printf("%d\n",aux->d.id);
		aux = aux->prox;
	}
	
}

int  main() {
	tipoDados pessoa;
	tipoPilha p1;
	tipoPilha p2;
	
	
	criaPilha(&p1);
	criaPilha(&p2);
	
	scanf("%[^\n]%*c",pessoa.nome);
	scanf("%d%*c",&pessoa.id);
	insereNaPilha(&p1,pessoa);
	
	scanf("%[^\n]%*c",pessoa.nome);
	scanf("%d%*c",&pessoa.id);
	insereNaPilha(&p1,pessoa);
	
	pessoa = removeDaPilha(&p1);
	insereNaPilha(&p2,pessoa);
	
	scanf("%[^\n]%*c",pessoa.nome);
	scanf("%d%*c",&pessoa.id);
	insereNaPilha(&p1,pessoa);
	
	scanf("%[^\n]%*c",pessoa.nome);
	scanf("%d%*c",&pessoa.id);
	insereNaPilha(&p1,pessoa);
	
	pessoa = removeDaPilha(&p1);
	insereNaPilha(&p2,pessoa);
	
	mostraPilha(&p1);
	mostraPilha(&p2);
	
}
