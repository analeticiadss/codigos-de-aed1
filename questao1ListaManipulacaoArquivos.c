//questao 1 lista de manipulação de arquivos

#include <stdio.h>
#include <stdlib.h>


// FACA AQUI SUA FUNCAO MOSTRA PALAVRAS
#include <string.h>

void mostraPalavras(FILE *fp) {
    char palavra[100];
    unsigned x = 0;

    while(fscanf(fp, "%[^ ]%*[ ]", palavra) == 1) {
        if(palavra[strlen(palavra)-1] == ','
           || palavra[strlen(palavra)-1] == '!'
           || palavra[strlen(palavra)-1] == '.') {
            palavra[strlen(palavra)-1] = '\0';
        }
        printf("%s\n", palavra);

    }
}
// FIM DA FUNCAO


int main() {
  char nomeArq[30];
  char linha[2000];
  FILE *fp;

  scanf("%[^\n]",nomeArq);
  fp = fopen(nomeArq,"r");
  mostraPalavras(fp);
}
