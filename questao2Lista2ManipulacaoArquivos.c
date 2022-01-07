//questao 2 - lista 2 de manipulação de arquivos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[30];
    float salario;
    unsigned id;
} tipoDados;

void mostraArq(FILE *fp) {
    tipoDados pessoa;

    while(fread(&pessoa, sizeof(tipoDados), 1, fp) == 1) {
        printf("%s\n", pessoa.nome);
        printf("%.2f\n", pessoa.salario);
        printf("%u\n", pessoa.id);
    }
}

int main() {
    FILE *fp;
    tipoDados pessoa;

    fp = fopen("dados", "r+");
    if(fp == NULL) {
        printf("erro ao ler arquivo\n");
        exit(1);
    }

    while(fread(&pessoa, sizeof(tipoDados),1, fp) == 1) {
        fseek(fp, -sizeof(tipoDados), SEEK_CUR);
        pessoa.salario = pessoa.salario*1.1;
        fwrite(&pessoa, sizeof(tipoDados), 1, fp); //grava o valor ajustado

        mostraArq(fp);
    }

    fclose(fp);
}
