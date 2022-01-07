//tipoPilhaEncadeada outra versao
//31/05/2021

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
	struct tipoNo *proximoPilha, *anteriorPilha; //ponteiro pra outras variaveis do tipoNo
} tipoNo;

typedef struct tipoPilha {
	tipoNo *topoPilha; //ponteiro do tipoNo
} tipoPilha;

void insereElementoInicioPilha(tipoPilha *pPilha, tipoAluno aluno) {
	tipoNo *aux;
	
	aux = (tipoNo *) malloc (sizeof(tipoNo));
	aux->dado.coeficienteRendimento = aluno.coeficienteRendimento;
	strcpy(aux->dado.curso, aluno.curso);
	strcpy(aux->dado.nome, aluno.nome);
	aux->dado.pibic = aluno.pibic;
	aux->proximoPilha = pPilha->topoPilha;	
	pPilha->topoPilha = aux;
}

int removetopoElementoPilha (tipoPilha *pPilha, tipoAluno res) {
	tipoNo *temp;
	
	temp = pPilha->topoPilha;
	if(temp != NULL) {
		pPilha->topoPilha = temp->proximoPilha;
		res.coeficienteRendimento = temp->dado.coeficienteRendimento;
		strcpy(res.curso, temp->dado.curso);
		strcpy(res.nome, temp->dado.nome);
		res.pibic = temp->dado.pibic;
		free(temp);
		return 1;
	}
	return 0;
}

void criaPilha(tipoPilha *pPilha) {
	pPilha->topoPilha = NULL;
}

unsigned alunosComecaLetraPilha(tipoPilha *pPilha, char letra) {
	unsigned cont = 0;
	tipoNo *aux;
	
	aux = pPilha->topoPilha;
	while(aux) {
		if(aux->dado.nome[0] == letra) {
			cont++;
		}
		aux = aux->proximoPilha;
	}
	return cont;
}

float mediaCoeficiente(tipoPilha *pPilha) {
	unsigned cont = 0;
	float soma = 0.0, media;
	tipoNo *aux;
	
	while(aux) {
		soma += aux->dado.coeficienteRendimento;
		cont ++;
		aux = aux->proximoPilha;
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

void mostraPilha(tipoPilha *pPilha) {
	tipoNo *aux;
	
	aux = pPilha->topoPilha;
	
	while(aux != NULL) {
		mostraAluno(aux->dado);
		aux = aux->proximoPilha;
	}
}

int main() {
	tipoPilha Pilha1, Pilha2;
	tipoAluno aluno, *pAluno;
	
	criaPilha(&Pilha1);;
	
	strcpy(aluno.nome, "Ana Leticia");
	strcpy(aluno.curso, "Engenharia da computacao");
	aluno.coeficienteRendimento = 8.0;
	aluno.pibic = 1;
	
	insereElementoInicioPilha(&Pilha1, aluno);
	
	strcpy(aluno.nome, "Ian");
	strcpy(aluno.curso, "Medicina");
	aluno.coeficienteRendimento = 8.5;
	aluno.pibic = 1;
	
	insereElementoInicioPilha(&Pilha1, aluno);
	
	strcpy(aluno.nome, "Henrique");
	strcpy(aluno.curso, "Administracao");
	aluno.coeficienteRendimento = 7.5;
	aluno.pibic = 0;
	
	insereElementoInicioPilha(&Pilha1, aluno);
	
	strcpy(aluno.nome, "Bruna");
	strcpy(aluno.curso, "Ciencias Naturais");
	aluno.coeficienteRendimento = 8.5;
	aluno.pibic = 0;
	
	insereElementoInicioPilha(&Pilha1, aluno);
	removeElementoPilha(&Pilha1, aluno);
	
	mostraPilha(&Pilha1);
	
	/*if(removeElementoPilha(&Pilha1, aluno) == 1) {
		printf("Aluno removido!");
	} else {
		printf("Aluno não removido!");
	}
	mostraPilha(&Pilha1);*/
	
	
}
