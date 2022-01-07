//aula síncrona dia 16/06/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoPessoa {
    char nome[30];
    char endereco[30];
    float altura;
} tipoPessoa;

int main () {
    FILE *fd;
    tipoPessoa *lista;
    int tam;

    fd = fopen("entrada.txt", "r");

    fscanf(fd, "%d%*c",&tam);
    lista = (tipoPessoa*) malloc(sizeof(tipoPessoa)*tam);

    if(fd == NULL) {
        printf("erro ao ler arquivo\n");
        exit(1);
    }
    for(unsigned x = 0; x < tam; x++) {
        fscanf(fd, "[^\n]%*c", lista[x].nome);
        fscanf(fd, "[^\n]%*c", lista[x].endereco);
        fscanf(fd, "%f%*c", &lista[x].altura);
    }
    fclose(fd);

    for(unsigned i = 0; i < tam; i++) {
        printf("Nome: %s\n", lista[i].nome);
        printf("Endereco: %s\n", lista[i].endereco);
        printf("Altura: %.2f\n", lista[i].altura);
    }
}
