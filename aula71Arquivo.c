//aula 71 - leitura e escrita em formatos de texto e formato binário.

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

void gravaListaEmBinario (cha *nomeArquivo, tipoLista *pLista) {
    tipoNo *aux;
    FILE *fp;

    aux = pLista->primeiroLista;
    fp = fopen(nomeArquivo, "w");
    if(fp == NULL) {
        printf("nao foi possivel criar o arquivo %s\n", nomeArquivo);
        exit(1);
    }

    while(aux) {
        //grava os dados da memoria ram pro arquivo
        if(fwrite(&aux->dado, sizeof(tipoAluno), 1, fp) != 1) {
            printf("erro de gravacao\n");
            exit(1);
        }

        aux = aux->proximoLista;
    }
    fclose(fp);
}

void gravaListaEmTexto (cha *nomeArquivo, tipoLista *pLista) {
    tipoNo *aux;
    FILE *fp;

    aux = pLista->primeiroLista;
    fp = fopen(nomeArquivo, "w");
    if(fp == NULL) {
        printf("nao foi possivel criar o arquivo %s\n", nomeArquivo);
        exit(1);
    }

    while(aux) {
        //grava os dados da memoria ram pro arquivo
        fprintf(fp, "nome: %s\n", aux->dado.nome);
        fprintf(fp, "pibic: %hhd\n", aux->dado.pibic);
        fprintf(fp, "curso: %s\n", aux->dado.curso);
        fprintf(fp, "coeficiente: %.2f\n", aux->dado.coeficienteRendimento);

        aux = aux->proximoLista;
    }
    fclose(fp);
}

void leTexto(char *nomeArquivo, tipoLista *pLista) {
    tipoAluno aluno;
    FILE *fp;

    fp = fopen(nomeArquivo, "r");
    if(fp == NULL) {
        printf("erro ao ler o arquivo\n");
        exit(1);
    }

    while(fscanf(fp, "%*[^ ]*c%[^\n]%*c", aluno.nome) == 1) {
        fscanf(fp, "%*[^ ]*c%hhd%*c", &aluno.pibic);
        fscanf(fp, "%*[^ ]*c%[^\n]%*c", aluno.curso);
        fscanf(fp, "%*[^ ]*c%f%*c", &aluno.coeficienteRendimento);
        insereElementoLista(pLista, &aluno);
    }
    fclose(fp);
}

void leBinario(char *nomeArquivo, tipoLista *pLista) {
    tipoAluno aluno;
    tipoNo *aux;
    FILE *fp;

    aux = pLista->primeiroLista;
    fp = fopen(nomeArquivo, "r");
    if(fp == NULL) {
        printf("erro ao ler o arquivo\n");
        exit(1);
    }

    while(fread(&aluno, sizeof(tipoAluno),1, fp) == 1) {
        insereElementoLista(pLista, &aluno);
    }
    fclose(fp);
}

int main() {
    tipoAluno aluno;
    tipoLista listaAlunos;

    criaLista(&listaAlunos);
    gravaListaEmBinario("arquivoAula.txt", &listaAlunos);
    gravaListaEmTexto("arquivo2.txt", &listaAlunos);

    mostraLista(&listaAlunos);

}
