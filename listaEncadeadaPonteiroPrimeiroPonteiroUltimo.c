//AED I - AULA 59
//24/05/2021

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
	tipoNo *primeiroLista, *ultimoLista; //ponteiro do tipoNo
} tipoLista;

void insereElementoInicioLista(tipoLista *pLista, tipoAluno *aluno) {
	tipoNo *aux;
	
	aux = (tipoNo *) malloc (sizeof(tipoNo)); //cria um novo tipoNo com um outro endereço
	aux->dado = *aluno; //recebe os valores de aluno
	aux->proximoLista = pLista->primeiroLista; //o campo ProxLista recebe agora o endereço do antigo PrimLista
	if(pLista->primeiroLista == NULL) {
		pLista->ultimoLista = aux;
	}	
	pLista->primeiroLista = aux; //o campo PrimLista recebe o endereço do novo tipoNo
}

void insereElementoFinalLista(tipoLista *pLista, tipoAluno *aluno) {
	tipoNo *aux;
	
	aux = (tipoNo *) malloc (sizeof(tipoNo));
	aux->dado = *aluno;
	aux->proximoLista = NULL;
	if(pLista->ultimoLista != NULL) {
		pLista->ultimoLista->proximoLista = aux;
	}else {
		pLista->primeiroLista = aux;
	}
	pLista->ultimoLista = aux;
}

int removeElementoLista(tipoLista *pLista, char *nome) {
	tipoNo *aux, *temp;
	
	if(pLista->primeiroLista) { //se tiver pelo menos um elemento na lista
		if(strcmp(nome, pLista->primeiroLista->dado.nome) == 0) {
			temp = pLista->primeiroLista;
			pLista->primeiroLista = temp->proximoLista;
			if(pLista->primeiroLista == NULL) {
				pLista->ultimoLista = NULL;
			}
			free(temp);
			return 1;
		}
		aux = pLista->primeiroLista;
		while(aux->proximoLista) { //enquanto tiver um segundo elemento
			if(strcmp(nome, aux->proximoLista->dado.nome) == 0) {
				temp = aux->proximoLista;
				if(temp == pLista->ultimoLista) {
					pLista->ultimoLista = aux;
				}
				aux->proximoLista = temp->proximoLista;
				free(temp);
				return 1;
			}
			aux = aux->proximoLista;
		}
	}
	return 0;
}

void criaLista(tipoLista *pLista) {
	pLista->primeiroLista = NULL;
	pLista->ultimoLista = NULL;
}

unsigned alunosComecaLetraLista(tipoLista *pLista, char letra) {
	unsigned cont = 0;
	tipoNo *aux;
	
	aux = pLista->primeiroLista;
	while(aux) {
		if(aux->dado.nome[0] == letra) {
			cont++;
		}
		aux = aux->proximoLista;
	}
	return cont;
}

float mediaCoeficiente(tipoLista *pLista) {
	unsigned cont = 0;
	float soma = 0.0, media;
	tipoNo *aux;
	
	while(aux) {
		soma += aux->dado.coeficienteRendimento;
		cont ++;
		aux = aux->proximoLista;
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

void mostraLista(tipoLista *pLista) {
	tipoNo *aux;
	
	aux = pLista->primeiroLista;
	
	while(aux != NULL) {
		mostraAluno(aux->dado);
		aux = aux->proximoLista;
	}
}

int main() {
	tipoLista lista1, lista2;
	tipoAluno aluno, *pAluno;
	
	criaLista(&lista1);;
	
	strcpy(aluno.nome, "Ana Leticia");
	strcpy(aluno.curso, "Engenharia da computacao");
	aluno.coeficienteRendimento = 8.0;
	aluno.pibic = 1;
	
	insereElementoInicioLista(&lista1, &aluno);
	
	strcpy(aluno.nome, "Ian");
	strcpy(aluno.curso, "Medicina");
	aluno.coeficienteRendimento = 8.5;
	aluno.pibic = 1;
	
	insereElementoInicioLista(&lista1, &aluno);
	
	strcpy(aluno.nome, "Henrique");
	strcpy(aluno.curso, "Administracao");
	aluno.coeficienteRendimento = 7.5;
	aluno.pibic = 0;
	
	insereElementoInicioLista(&lista1, &aluno);
	
	strcpy(aluno.nome, "Bruna");
	strcpy(aluno.curso, "Ciencias Naturais");
	aluno.coeficienteRendimento = 8.5;
	aluno.pibic = 0;
	
	insereElementoFinalLista(&lista1, &aluno);
	
	mostraLista(&lista1);
	
	
}
