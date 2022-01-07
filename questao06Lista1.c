// questao06 aed I
//ana leticia

#include <stdio.h>

int main () {
	unsigned linha, coluna, dimensao;
	
	printf("escreva a dimensao: ");
	scanf("%u%*c", &dimensao);
	
	for(linha = 0; linha < dimensao ; linha++) {
		for(coluna = 0; coluna < dimensao; coluna++) {
			if(linha == 0 || linha == dimensao-1) {
				printf("1");
			}
			else if (linha > 0 && linha < dimensao-1) {	
				if(coluna == 0 || coluna == dimensao-1) {
					/* bota o 1 no inicio e fim de cada linha
					na coluna 0 e coluna = dimensao-1 */
					printf("1");
				}
				else if(linha == coluna) {
					printf("1");
				}
				else if(linha + coluna == dimensao-1) {
					printf("1");
				}
				else {
					printf("o");
				}
			}
			else {
				printf("o");
			}
		}
		printf("\n");
		
	}
}

