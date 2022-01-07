//questão 3 quarto bloco de exercicios aed1
//ana leticia - 11/05/2021

#include<stdio.h>

#define N 5

// FAÇA AQUI A FUNCAO SOLICITADA
void preencheMatriz(unsigned char matriz[N][N]) {
	unsigned lin, col;
	
	for(lin = 0; lin < N; lin++) {
		for(col = 0; col < N; col++) {
			if(lin == 0) {
				
				if(matriz[lin][col] == 19) {
					
					if(matriz[lin][col-1] != 19) {
						matriz[lin][col-1] += 1;
					}
					if(matriz[lin][col+1] != 19) {
						matriz[lin][col+1] += 1;
					}
					if(matriz[lin+1][col] != 19) {
						matriz[lin+1][col] +=1;
					}
					if(matriz[lin+1][col-1] != 19) {
						matriz[lin+1][col-1] += 1;
					}
					if(matriz[lin+1][col+1] != 19) {
						matriz[lin+1][col+1] += 1;
					}
				}
			}
			else if (lin > 0 && lin < N) {
			
				if(matriz[lin][col] == 19) {
					if (matriz[lin-1][col] != 19) { //em cima
						matriz[lin-1][col] += 1;
					}
					
				
					if(matriz[lin-1][col-1] != 19 ) { //canto superior esquerdo
						matriz[lin-1][col-1] += 1;
					}
					
					if(matriz[lin-1][col+1] != 19 ) { //canto superior direito
						matriz[lin-1][col+1] += 1;
					}
					
					if(matriz[lin+1][col] != 19) { //embaixo
						matriz[lin+1][col] += 1;
					}
					
					if(matriz[lin][col-1] != 19) { //lado esquerdo
						matriz[lin][col-1] += 1;
					}
					
					if(matriz[lin][col+1] != 19) { //lado direito
						matriz[lin][col+1] += 1;
					}
					
					if(matriz[lin+1][col-1] != 19) { //canto inferior esquerdo
					 	matriz[lin+1][col-1] += 1;
					}
					
					if(matriz[lin+1][col+1] != 19) //canto inferior direito
						matriz[lin+1][col+1] += 1;
					}
				}
				else { //linha == 5
					if(matriz[lin][col] == 19) {
						
						if(matriz[lin][col-1] != 19) {
							matriz[lin][col-1] += 1;
						}
						if(matriz[lin][col+1] != 19) {
							matriz[lin][col+1] += 1;
						}
						if(matriz[lin-1][col] != 19) {
							matriz[lin-1][col] += 1;
						}
						if(matriz[lin-1][col-1] != 19) {
							matriz[lin-1][col-1] += 1;
						}
						if(matriz[lin-1][col+1] != 19) {
							matriz[lin-1][col+1] += 1;
						}
					}
				}
			}
		}
	}
	

//ANDA DE LINHA EM LINHA - IDEIA 
//FIM DA SUA FUNCAO. NAO ALTERE O CÓDIGO A SEGUIR


void imprimeMatriz(unsigned char mat[N][N]) {
unsigned x,y;
	
	printf("\n");
	for( x = 0; x< N; x++) {
		
		for(y=0; y <N; y++) {
			printf("%02hhd ",mat[x][y]);
		}
		printf("\n");
	}
}
			
int main() {
	int x,y;
		unsigned char mat[N][N];
	
		for(x=0; x<N; x++) {
				for(y=0; y<N; y++) {
					scanf("%hhu%*c",&mat[x][y]);
				}
		}

	preencheMatriz(mat);
	imprimeMatriz(mat);
}
