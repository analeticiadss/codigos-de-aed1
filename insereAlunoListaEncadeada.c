#include <stdio.h>
#include <stdlib.h>

typedef struct tipoAluno {
	char nome[30];
	char curso[30];
	int periodo;
	float coeficienteRendimento;
} tipoAluno;

typedef struct tipoNo {
	tipoAluno dado;
	struct tipoNo *proxLista;
} tipoNo;

typedef struct tipoLista {
	tipoNo *primLista;
} tipoLista;

void criaLista(tipoLista *pLista) {
	pLista->primLista = NULL;
}

void insereAlunoLista (tipoLista *pLista, tipoAluno *aluno) {
	tipoNo *aux;
	
	aux = (tipoNo*) malloc(sizeof(tipoNo));
	aux->dado = *aluno;
	aux->proxLista = pLista->primLista;
	pLista->primLista = aux;
}

void mostraAluno (tipoAluno aluno) {
	printf("\nNome: %s\n", aluno.nome);
	printf("Curso: %s\n", aluno.curso);
	printf("Periodo: %d\n", aluno.periodo);
	printf("Coeficiente de Rendimento: %.2f\n", aluno.coeficienteRendimento);
}

void mostraLista(tipoLista *pLista) {
	tipoNo *aux; //conteudo da variavel apontada por aux
	
	aux = pLista->primLista; //vai receber o endereço de primLista
	
	while(aux != NULL) {
		mostraAluno(aux->dado); //aux->dado é o campo onde tem as infos do aluno
		aux = aux->proxLista; //anda na lista pra pegar o endereço do proxLista
	}
}


int main() {
	tipoLista lista1;
	tipoAluno aluno;
	
	criaLista(&lista1);
	
	printf("qual o nome do aluno?\n");
	scanf("%[^\n]%*c", aluno.nome);
	
	printf("qual o curso?\n");
	scanf("%[^\n]%*c", aluno.curso);
	
	printf("qual o periodo em que esta?\n");
	scanf("%d%*c", &aluno.periodo);
	
	printf("qual o coeficiente de rendimento?\n");
	scanf("%f%*c", &aluno.coeficienteRendimento);
	
	insereAlunoLista(&lista1, &aluno);
	mostraLista(&lista1);
	
}
