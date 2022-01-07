//AULA 53: Manipulando structs com ponteiros
//17/05/2021 - ana leticia

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tipoAluno {
	char nome[30];
	char pibic;
	char curso[30];
	float coeficienteRendimento;
} tipoAluno;

void mostraVersao1 (tipoAluno *tipoAluno) {
	printf("Nome: %s\n", (*tipoAluno).nome);
	printf("Curso: %s\n", (*tipoAluno).curso);
	printf("Coeficiente: %.2f\n", (*tipoAluno).coeficienteRendimento);
	if((*tipoAluno).pibic == 1) {
		printf("Aluna de PIBIC\n");
	} else {
		printf("Nao eh aluna de PIBIC\n");
	}
}

void mostraVersao2 (tipoAluno *tipoAluno) {
	printf("Nome: %s\n", tipoAluno->nome); //tipoAluno-> IGUAL A (*tipoAluno).
	printf("Curso: %s\n", tipoAluno->curso);
	printf("Coeficiente: %.2f\n", tipoAluno->coeficienteRendimento);
	if(tipoAluno->pibic == 1) {
		printf("Aluno de PIBIC\n");
	} else {
		printf("Nao eh aluno de PIBIC\n");
	}
}

void mostraVersao3 (tipoAluno aluno) {
	printf("Nome: %s\n", aluno.nome); //tipoAluno-> IGUAL A (*tipoAluno).
	printf("Curso: %s\n", aluno.curso);
	printf("Coeficiente: %.2f\n", aluno.coeficienteRendimento);
	if(aluno.pibic == 1) {
		printf("Aluno de PIBIC\n");
	} else {
		printf("Nao eh aluno de PIBIC\n");
	}
}

int main() {
	tipoAluno aluno, aluno2, aluno3;
	
	strcpy(aluno.nome, "Ana Leticia");
	strcpy(aluno.curso, "Engenharia da computacao");
	aluno.coeficienteRendimento = 8.0;
	aluno.pibic = 1;
	
	strcpy(aluno2.nome, "Ian");
	strcpy(aluno2.curso, "Medicina");
	aluno2.coeficienteRendimento = 8.5;
	aluno2.pibic = 1;
	
	strcpy(aluno3.nome, "Henrique");
	strcpy(aluno3.curso, "Administracao");
	aluno3.coeficienteRendimento = 7.5;
	aluno3.pibic = 0;
	
	
	mostraVersao1 (&aluno); //mostraV1(ENDEREÇOaluno == ponteiro)
	printf("\n");
	mostraVersao2(&aluno2);
	printf("\n");
	mostraVersao3(aluno3);
	
}
