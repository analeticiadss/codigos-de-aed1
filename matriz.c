//MATRIZES - AULA 43
//aed1 - 11/05/2021 - ana leticia

#include <stdio.h>
#define linhas 3
#define colunas 5

void zeraMatriz(int matriz[linhas][colunas]) {
	unsigned lin, col;
	
	for(lin = 0; lin < linhas; lin++) {
		for(col = 0; col < colunas; col++) {
			matriz[lin][col] = 0;
		}
	}
}


int main() {
	int matriz[linhas][colunas];
	unsigned lin, col;
	
	for(lin = 0; lin < linhas; lin++) {
		for(col = 0; col < colunas; col++) {
			scanf("%d%*c", &matriz[lin][col]);
		}
	}
	
	zeraMatriz(matriz);
	
	for(lin = 0; lin < linhas; lin++) {
		for(col = 0; col < colunas; col++) {
			printf("%d", matriz[lin][col]);
		}
	}
}
