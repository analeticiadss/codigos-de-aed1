//aula 70: leitura de arquivos texto usando fscanf

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void criaLista(tipoLista *pLista) {
	pLista->primeiroLista = NULL;
}

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

void mostraLista(tipoLista *pLista) {
	tipoNo *aux;

	aux = pLista->primeiroLista;

	while(aux != NULL) {
		mostraAluno(aux->dado);
		aux = aux->proximoLista;
	}
}

void carregaLista(char *nomeArquivo, tipoLista *pLista) {
    tipoAluno aluno;
    FILE *fd;
    fd = fopen(nomeArquivo, "r"); //devolve um endereço

    if(nomeArquivo == NULL) {
        printf("Erro ao abrir arquivo");
        exit(1);
    }

    while(fscanf(fd, "%[^;]%*[; ] %[^;]%*[; ] %hhd%*[; ] %f%*c",
                aluno.nome, aluno.curso, &aluno.pibic, &aluno.coeficienteRendimento) == 4) {
        insereElementoLista(pLista, &aluno);
    }
    fclose(fd);
}

int main() {
    tipoAluno aluno;
    tipoLista listaAlunos;

    criaLista(&listaAlunos);
    carregaLista("arquivoAula.txt", &listaAlunos);
    mostraLista(&listaAlunos);

}
