#include <stdio.h>

typedef struct tipoAluno {
  char nome[30];
  unsigned matricula;
} tipoAluno;

#include <string.h>
#include <stdlib.h>

int tamanhoArquivo(FILE *fp) {
    struct stat buf;
    fstat(fileno(fp), &buf);
    return buf.st_size;
}

void buscaBinaria(FILE *fp, char *chave, tipoAluno *aluno) {
    int inicio, fim, meio;
    inicio = 0;
    fim = (tamanhoArquivo(fp)/sizeof(tipoAluno))-1;

    while(inicio <= fim) {
        meio = (inicio+fim)/2;
        fseek(fp, meio*sizeof(tipoAluno), SEEK_SET);
        fread(aluno, sizeof(tipoAluno), 1, fp);
        if(strcmp(chave, aluno->nome) > 0) {
            inicio = meio+1;
        }
        else if(strcmp(chave, aluno->nome) < 0) {
            fim = meio-1;
        }
        else {
            return 1;
        }
    }
    return 0;
}

void mostraAluno (tipoAluno aluno) {
    printf("%s\n", aluno.nome);
    printf("%u\n", aluno.matricula);
}

int main () {
    FILE *fp;
    char nome1[30], nome2[30], nome3[30], nomeArq[20];
    tipoAluno aluno;

    fp = fopen(nomeArq, "r");
    if(fp == NULL) {
        printf("erro ao ler arquivo\n");
        exit(1);
    }

    scanf("%[^\n]%*c", nome1);
    if(buscaBinaria(fp, nome1, &aluno)) {
        mostraAluno(aluno);
    }
    else {
        printf("-1");
    }

    scanf("%[^\n]%*c", nome2);
    if(buscaBinaria(fp, nome2, &aluno)) {
        mostraAluno(aluno);
    }
    else {
        printf("-1");
    }

    scanf("%[^\n]%*c", nome3);
    if(buscaBinaria(fp, nome3, &aluno)) {
        mostraAluno(aluno);
    }
    else {
        printf("-1");
    }

    fclose(fp);
}
