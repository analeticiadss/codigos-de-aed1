//PROVA 5
//14/05/2021 - AEDI
//ana leticia
#include<stdio.h>

#define N 5

// FA�A AQUI A FUNCAO SOLICITADA (retorno � unsigned)
unsigned contaBombas(unsigned char matriz[N][N]) {
	unsigned lin, col, cont;
	
	for(lin = 0; lin < N; lin++) {
		for(col = 0; col < N; col++) {
			if(matriz[lin][col] == 19 || matriz[lin][col] == 9) {
				cont += 1;
			}
		}
	}
	return cont;
}
	

//FIM DA SUA FUNCAO. NAO ALTERE O C�DIGO A SEGUIR



	
int main() {
	int x,y;
		unsigned char mat[N][N];
	
		for(x=0; x<N; x++) {
				for(y=0; y<N; y++) {
					scanf("%hhu%*c",&mat[x][y]);
				}
		}

	printf("%u",contaBombas(mat));
	
}

