//aula síncrona 18/06/2021

#include <stdio.h>
#include <stdlib.h>

typedef struct tipoProduto {
    char descricao[50];
    char supermercado[50];
    float preco;
} tipoProduto;

int main () {
    FILE *fp;
    unsigned cont = 0, x = 0;
    char ch;
    tipoProduto *vetProdutos;

    fp = fopen("arquivo.dat", "r");


    while(fscanf(fp, "%c", &ch) == 1) {
        if(ch == '\n'){ //contador de elementos
            cont++;
        }
    }
    fclose(fp);

    vetProdutos = (tipoProduto *) malloc(sizeof(tipoProduto)*cont);

    fp = fopen("arquivo.dat", "r");

    while(fscanf(fp, "%[^:]%*[ :] %f%*[^ :] %[^\n]%*c",
                 vetProdutos[x].descricao,
                 &vetProdutos[x].preco,
                 vetProdutos[x].supermercado) == 3) {
            x++;
    } //ler os dados com o while vazio

    for(x = 0; x < cont; x++) {
        printf("%s\n", vetProdutos[x].descricao);
        printf("%.2f\n", vetProdutos[x].preco);
        printf("%s\n", vetProdutos[x].supermercado);
    }
    fclose(fp);
}
