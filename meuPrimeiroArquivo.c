//aula 68 - arquivos

#include <stdio.h>
#include <stdlib.h>

/*w: cria arquivo. se o arquivo já existia, o arquivo é zerado.
    só pode escrever no artigo
    r: abre pra leitura, só abre se o arquivo já existe
    r+: leitura e escrita (só abre se já existe)
    w+: leitura e escrita, mas cria o arquivo e zera se já existe
    a: apenas para adicionar informação -> acrescenta informação*/

int main() {
    FILE *descritorDoArquivo;

    descritorDoArquivo = fopen("meuPrimeiroArquivo", "w"); //abre um arquivo

    if(descritorDoArquivo == NULL) { //deu errado a criação de um arquivo
        printf("Erro ao criar um arquivo\n");
        exit(1);
    }

    fprintf(descritorDoArquivo, "Minha primeira mensagem gravada em arquivo\n");
    fclose(descritorDoArquivo); //fecha o arquivo
}
