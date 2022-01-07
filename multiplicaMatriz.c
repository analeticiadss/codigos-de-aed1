//AULA 46 - multiplicação de matrizes
//13/05/2021 - ana leticia

#include <stdio.h>
#include <stdlib.h>
#define LINHAS 3
#define COLUNAS 3

void multiplicaMatriz(int matA[LINHAS][COLUNAS], int matB[LINHAS][COLUNAS],
					int matC[LINHAS][COLUNAS]) {
						
		unsigned lin, col, z = 0;
		
		/* ESSE JEITO TÁ CERTO MAS A FORMA ABAIXO DESSA É MAIS GENÉRICA
		
		for(lin = 0; lin < LINHAS; lin++) {
			for(col = 0; col < COLUNAS; col++) {
				matC[lin][col] = matA[lin][col]*matB[lin][col]+
								matA[lin][col+1]*matB[lin+1][col]+
								matA[lin][col+2]*matB[lin+2][col];
			}
		}*/
		for(lin = 0; lin < LINHAS; lin++) {
			for(col = 0; col < COLUNAS; col++) {
				matC[lin][col] = 0;
				while(z < LINHAS) {
					matC[lin][col] += matA[lin][z]*matB[z][col];
					z++;
				}
				z = 0;
			}
		}
}

void preencheMatriz(int mat[LINHAS][COLUNAS]) {
	unsigned lin, col;
	
	for(lin = 0; lin < LINHAS; lin++) {
		for(col = 0; col < COLUNAS; col++) {
			mat[lin][col] = rand()%10;
		}
	}
}


void mostraMatriz(int mat[LINHAS][COLUNAS]) {
	unsigned lin, col;
	
	for(lin = 0; lin < LINHAS; lin++) {
		for(col = 0; col < COLUNAS; col++) {
			printf(" %2d ", mat[lin][col]);
		}
		printf("\n");
	}
}

int main () {
	int matrizA[LINHAS][COLUNAS], matrizB[LINHAS][COLUNAS], matrizC[LINHAS][COLUNAS];
	
	printf("Matriz A:\n");
	preencheMatriz(matrizA);
	mostraMatriz(matrizA);
	printf("Matriz B:\n");
	preencheMatriz(matrizB);
	mostraMatriz(matrizB);
	printf("Multiplicacao das matrizes:\n");
	multiplicaMatriz(matrizA, matrizB, matrizC);
	mostraMatriz(matrizC);
	
	
}
