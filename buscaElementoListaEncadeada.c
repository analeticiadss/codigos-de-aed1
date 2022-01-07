//aula 55 - busca em lista encadeada
//19/05/2021 - ana leticia

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

typedef struct tipoLista {
	tipoNo *primeiroLista; //ponteiro do tipoNo
} tipoLista;

void insereElementoLista(tipoLista *pLista, tipoAluno *aluno) {
	tipoNo *aux;
	
	aux = (tipoNo *) malloc (sizeof(tipoNo));
	aux->dado = *aluno;
	aux->proximoLista = pLista->primeiroLista;
	pLista->primeiroLista = aux;
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


void criaLista(tipoLista *pLista) {
	pLista->primeiroLista = NULL;
}

void mostraLista(tipoLista *pLista) {
	tipoNo *aux;
	
	aux = pLista->primeiroLista;
	
	while(aux != NULL) {
		mostraAluno(aux->dado);
		aux = aux->proximoLista;
	}
}

int buscaElementoListaVersao1(tipoLista *pLista, char *nome, tipoAluno *retorno) {
	tipoNo *aux;
	
	aux = pLista->primeiroLista;
	
	while(aux) {
		if(strcmp(nome, aux->dado.nome) == 0) {
			*retorno = aux->dado;
			return 1;
		}
		aux = aux->proximoLista;
	}
	return 0;
}

tipoAluno * buscaElementoListaVersao2(tipoLista *pLista, char *nome) {
	tipoNo *aux;
	
	aux = pLista->primeiroLista;
	
	while(aux) {
		if(strcmp(nome, aux->dado.nome) == 0) {
			return &(aux->dado);
		}
		aux = aux->proximoLista;
	}
	return NULL;
}

int main() {
	tipoLista lista1, lista2;
	tipoAluno aluno, *pAluno;
	
	criaLista(&lista1);;
	
	strcpy(aluno.nome, "Ana Leticia");
	strcpy(aluno.curso, "Engenharia da computacao");
	aluno.coeficienteRendimento = 8.0;
	aluno.pibic = 1;
	
	insereElementoLista(&lista1, &aluno);
	
	strcpy(aluno.nome, "Ian");
	strcpy(aluno.curso, "Medicina");
	aluno.coeficienteRendimento = 8.5;
	aluno.pibic = 1;
	
	insereElementoLista(&lista1, &aluno);
	
	strcpy(aluno.nome, "Henrique");
	strcpy(aluno.curso, "Administracao");
	aluno.coeficienteRendimento = 7.5;
	aluno.pibic = 0;
	
	insereElementoLista(&lista1, &aluno);
	
	mostraLista(&lista1);
	
	pAluno = buscaElementoListaVersao2(&lista1, "Ana Leticia");
	
	if(pAluno) {
		printf("Encontrado na lista:\n");
		mostraAluno(*pAluno);
	}
	else {
		printf("Aluno nao encontrado!\n");
	}
	
}
