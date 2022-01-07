//aula 68 - arquivos

#include <stdio.h>
#include <stdlib.h>

/*w: cria arquivo. se o arquivo j� existia, o arquivo � zerado.
    s� pode escrever no artigo
    r: abre pra leitura, s� abre se o arquivo j� existe
    r+: leitura e escrita (s� abre se j� existe)
    w+: leitura e escrita, mas cria o arquivo e zera se j� existe
    a: apenas para adicionar informa��o -> acrescenta informa��o*/

int main() {
    FILE *descritorDoArquivo;

    descritorDoArquivo = fopen("meuPrimeiroArquivo", "w"); //abre um arquivo

    if(descritorDoArquivo == NULL) { //deu errado a cria��o de um arquivo
        printf("Erro ao criar um arquivo\n");
        exit(1);
    }

    fprintf(descritorDoArquivo, "Minha primeira mensagem gravada em arquivo\n");
    fclose(descritorDoArquivo); //fecha o arquivo
}
