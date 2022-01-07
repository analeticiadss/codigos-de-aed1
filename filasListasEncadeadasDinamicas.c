//AULA 61 - AED I - Filas com Filas encadeadas dinâmicas
// 25/05/2021

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
	struct tipoNo *proximoFila, *anteriorFila; //ponteiro pra outras variaveis do tipoNo
} tipoNo;

typedef struct  {
	tipoNo *primeiroFila, *ultimoFila; //ponteiro do tipoNo
} tipoFila;

void insereElementoInicioFila(tipoFila *pFila, tipoAluno *aluno) {
	tipoNo *aux;
	
	aux = (tipoNo *) malloc (sizeof(tipoNo));
	aux->dado = *aluno;
	aux->proximoFila = pFila->primeiroFila;
	if(pFila->primeiroFila == NULL) {
		pFila->ultimoFila = aux;
	}	
	pFila->primeiroFila = aux;
}

void insereElementoFinalFila(tipoFila *pFila, tipoAluno *aluno) {
	tipoNo *aux;
	
	aux = (tipoNo *) malloc (sizeof(tipoNo));
	aux->dado = *aluno;
	aux->proximoFila = NULL;
	if(pFila->ultimoFila != NULL) { // se a fila não estiver vazia
		pFila->ultimoFila->proximoFila = aux;
	}else { // caso esteja vazia
		pFila->primeiroFila = aux; // o prim aponta pra aux
	}
	pFila->ultimoFila = aux; // e o ult aponta pra aux também ja que aux é o unico elemento da Fila
}

int removeElementoFila(tipoFila *pFila, char *nome) {
	tipoNo *aux, *temp;
	
	if(pFila->primeiroFila) { //se tiver pelo menos um elemento na Fila
		if(strcmp(nome, pFila->primeiroFila->dado.nome) == 0) {
			temp = pFila->primeiroFila;
			pFila->primeiroFila = temp->proximoFila;
			if(pFila->primeiroFila == NULL) {
				pFila->ultimoFila = NULL;
			}
			free(temp);
			return 1;
		}
		aux = pFila->primeiroFila;
		while(aux->proximoFila) { //enquanto tiver um segundo elemento
			if(strcmp(nome, aux->proximoFila->dado.nome) == 0) {
				temp = aux->proximoFila;
				if(temp == pFila->ultimoFila) {
					pFila->ultimoFila = aux;
				}
				aux->proximoFila = temp->proximoFila;
				free(temp);
				return 1;
			}
			aux = aux->proximoFila;
		}
	}
	return 0;
}

void criaFila(tipoFila *pFila) {
	pFila->primeiroFila = NULL;
	pFila->ultimoFila = NULL;
}

unsigned alunosComecaLetraFila(tipoFila *pFila, char letra) {
	unsigned cont = 0;
	tipoNo *aux;
	
	aux = pFila->primeiroFila;
	while(aux) {
		if(aux->dado.nome[0] == letra) {
			cont++;
		}
		aux = aux->proximoFila;
	}
	return cont;
}

float mediaCoeficiente(tipoFila *pFila) {
	unsigned cont = 0;
	float soma = 0.0, media;
	tipoNo *aux;
	
	while(aux) {
		soma += aux->dado.coeficienteRendimento;
		cont ++;
		aux = aux->proximoFila;
	}
	if(cont > 0) {
		media = soma/cont;
	}
	return media;
	
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

void mostraFila(tipoFila *pFila) {
	tipoNo *aux;
	
	aux = pFila->primeiroFila;
	
	while(aux != NULL) {
		mostraAluno(aux->dado);
		aux = aux->proximoFila;
	}
}

int main() {
	tipoFila Fila1, Fila2;
	tipoAluno aluno, *pAluno;
	
	criaFila(&Fila1);;
	
	strcpy(aluno.nome, "Ana Leticia");
	strcpy(aluno.curso, "Engenharia da computacao");
	aluno.coeficienteRendimento = 8.0;
	aluno.pibic = 1;
	
	insereElementoInicioFila(&Fila1, &aluno);
	
	strcpy(aluno.nome, "Ian");
	strcpy(aluno.curso, "Medicina");
	aluno.coeficienteRendimento = 8.5;
	aluno.pibic = 1;
	
	insereElementoInicioFila(&Fila1, &aluno);
	
	strcpy(aluno.nome, "Henrique");
	strcpy(aluno.curso, "Administracao");
	aluno.coeficienteRendimento = 7.5;
	aluno.pibic = 0;
	
	insereElementoInicioFila(&Fila1, &aluno);
	
	strcpy(aluno.nome, "Bruna");
	strcpy(aluno.curso, "Ciencias Naturais");
	aluno.coeficienteRendimento = 8.5;
	aluno.pibic = 0;
	
	insereElementoInicioFila(&Fila1, &aluno);
	
	mostraFila(&Fila1);
}

