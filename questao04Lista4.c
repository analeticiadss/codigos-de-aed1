//mostra tabuleiro - AED1 - quarta questao quarto bloco de exercicios
//12/05/2021 - ana leticia

#include<stdio.h>

#define N 5

// FACA SUA FUNCAO AQUI
void mostraTabuleiro(unsigned char matriz[N][N]) {
	unsigned lin, col;
	for(lin = 0; lin < N; lin++) {
		for(col = 0; col < N; col++) {
			if(matriz[lin][col] >= 10 && matriz[lin][col <= 19]) {
				printf("#? ", matriz[lin][col]);
			}
			else if(matriz[lin][col] == 9) {
				printf("** ", matriz[lin][col]);
			}
			else{
				printf("%02hhu ", matriz[lin][col]);
				
			}
		}
		printf("\n");
	}
	
}

// FIM DA SUA FUNCAO


int main() {
	int x,y;
		unsigned char mat[N][N];
	
		for(x=0; x<N; x++) {
				for(y=0; y<N; y++) {
					scanf("%hhu%*c",&mat[x][y]);
				}
		}
  mostraTabuleiro(mat);
}
