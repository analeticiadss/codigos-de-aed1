//aula 69 - exemplo para ler dados de arquivo texto usando fscanf

#include <stdio.h>
#include <stdlib.h>

typedef struct tipoAluno {
    char nome[30];
    char curso[30];
    char pibic;
} tipoAluno;

int main () {
    FILE *fd;
    int x = 5;
    tipoAluno aluno;

    fd = fopen("arquivoAlunos", "r");
    //nome do arquivo e o tipo de manipulação que quer fazer
    //no caso é pra abrir para ler o arquivo

    if(fd == NULL) {
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }

    while(fscanf(fd, "%[^\n]%*c", aluno.nome) == 1) {
        printf("%s\n", aluno.nome);
        fscanf(fd, "%hhd%*c", &aluno.pibic);
        printf("%hhd\n", aluno.pibic);
        fscanf(fd, "%[^\n]%*c", &aluno.curso);
        printf("%s\n", aluno.curso);
    }
    fclose(fd);
}
