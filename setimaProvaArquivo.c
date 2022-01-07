#include <stdio.h>
#include <stdlib.h>

typedef struct tipoAluno {

   char nome[30];

   unsigned turma;

   unsigned matricula;

} tipoAluno;

// FAÇA AQUI SUAS FUNÇÕES
// COLOQUE AQUI OS INCLUDES A MAIS QUE ACHAR NECESSÁRIO
#include <string.h>
void gravaEmTexto(char *nomeArq, tipoAluno *vet, unsigned tam) {
    FILE *fp;
    fp = fopen(nomeArq, "w");

    if(fp == NULL) {
        printf("erro ao criar o arquivo\n");
        exit(1);
    }

    for(unsigned x = 0; x < tam; x++) {
        fprintf(fp, "(%s;", vet[x].nome);
        fprintf(fp, "%u;", vet[x].turma);
        fprintf(fp,"%u)\n", vet[x].matricula);
    }
    fclose(fp);
}

tipoAluno* leVetor(FILE *fp, unsigned *numElementos) {
    tipoAluno dados;
    tipoAluno *vet;
    unsigned tamanho = 0;
    numElementos = &tamanho;
    fseek(fp, 0, SEEK_SET);

    while(fscanf(fp, "%*[(]%[^;]%*[;] %u%*[;] %u%*[;)]",
                     dados.nome, dados.turma, dados.matricula) == 3) {
        tamanho++;
    }

    vet = (tipoAluno *) malloc(sizeof(tipoAluno)*tamanho);

    for(unsigned x = 0; x < tamanho; x++) {
        while(fscanf(fp, "%*[(]%[^;]%*[;] %u%*[;] %u%*[;)]",
                     dados.nome, dados.turma, dados.matricula) == 3) {
            strcpy(vet[x].nome, dados.nome);
            vet[x].turma = dados.turma;
            vet[x].matricula = dados.matricula;
        }
    }

    return *vet;
}


// FIM DA SOLUÇÃO

// NAO ALTERE o CODIGO ABAIXO. NÃO PRECISA EXECUTAR A FUNCAO!


int main() {
 int n;

printf("1\n");



}
