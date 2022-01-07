//AULA 63 - LISTAS CIRCULARES
//03/06/2021

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
	struct tipoNo *proximoLista; //ponteiro pra outras variaveis do tipoNo
} tipoNo;

typedef struct tipoListaCircular {
	tipoNo *atual; //ponteiro do tipoNo
} tipoListaCircular;

void criaListaCircular(tipoListaCircular *pLista) {
	pLista->atual = NULL;
}

void insereElementoListaCircular(tipoListaCircular *pLista, tipoAluno *aluno) {
	tipoNo *aux;
	
	aux = (tipoNo *) malloc (sizeof(tipoNo));
	aux->dado = *aluno;
	if(pLista->atual != NULL) {
		aux->proximoLista = pLista->atual->proximoLista;
		pLista->atual->proximoLista = aux;
	} else {
		pLista->atual = aux;
		aux->proximoLista = aux; //ele mesmo porque é circular
	}
}

void proximoDaVez (tipoListaCircular *pLista) {
	if(pLista->atual != NULL) { // se tem mais de um elemento
		pLista->atual = pLista->atual->proximoLista;
	}
}

void mostraAluno(tipoAluno aluno) {
	printf("Nome: %s\n", aluno.nome);
	printf("Curso: %s\n", aluno.curso);
	printf("Coeficiente: %.2f\n", aluno.coeficienteRendimento);
	if(aluno.pibic == 1) {
		printf("Aluno de PIBIC\n");
	} else {
		printf("Nao eh aluno de PIBIC\n");
	}
	printf("\n");
}

void mostraListaCircular(tipoListaCircular *pLista) {
	tipoNo *aux;
	
	if(pLista->atual) { // pLista->atual <-> pLista->atual != NULL, ou seja, se a lista NÃO está vazia
		printf("Jogador da vez:\n");
		aux = pLista->atual;
		mostraAluno(aux->dado);
		printf("\n");
		aux = aux->proximoLista;
		while(aux != pLista->atual) {
			mostraAluno(aux->dado);
			printf("\n");
			aux = aux->proximoLista;
		}
	}
}

int main() {
	tipoListaCircular lista1, lista2;
	tipoAluno aluno, *pAluno;
	
	criaListaCircular(&lista1);;
	
	strcpy(aluno.nome, "Ana Leticia");
	strcpy(aluno.curso, "Engenharia da computacao");
	aluno.coeficienteRendimento = 8.0;
	aluno.pibic = 1;
	
	insereElementoListaCircular(&lista1, &aluno);
	
	strcpy(aluno.nome, "Ian");
	strcpy(aluno.curso, "Medicina");
	aluno.coeficienteRendimento = 8.5;
	aluno.pibic = 1;
	
	insereElementoListaCircular(&lista1, &aluno);
	
	strcpy(aluno.nome, "Joao");
	strcpy(aluno.curso, "Engenharia de Petroleo e Gas");
	aluno.coeficienteRendimento = 7.5;
	aluno.pibic = 0;
	
	insereElementoListaCircular(&lista1, &aluno);
	
	strcpy(aluno.nome, "Bruna");
	strcpy(aluno.curso, "Ciencias Naturais");
	aluno.coeficienteRendimento = 8.5;
	aluno.pibic = 0;
	
	insereElementoListaCircular(&lista1, &aluno);
	mostraListaCircular(&lista1);
	int x;
	for(x = 0; x < 4; x++) {
		proximoDaVez(&lista1);
		mostraListaCircular(&lista1);
		fgetc(stdin);
	}
}
