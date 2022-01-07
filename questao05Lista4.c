	//AED 1 - questao 05 - lista 4
	//ana leticia - 13/05/2021
	
	#include<stdio.h>
	
	#define N 5
	
	// MODIFIQUE O PROGRAMA APENAS AQUI
	// E TERMINE A FUNCAO JOGA
	
	int joga(unsigned char mat[N][N],int lin, int col) {
		int posLin, posCol;
		
		if(mat[lin][col] >= 1 && mat[lin][col] <= 8) {
			return 3; //jogada invalida
		}
		else if(mat[lin][col] == 19) {
			mat[lin][col] -= 10;
			return 0; //jogada valida e o jogador perde porque revelou uma bomba
		}
		else if(mat[lin][col] >= 11 && mat[lin][col] <= 18) {
			mat[lin][col] -= 10;
			
			for(lin = 0; lin < N; lin++) {
				for(col = 0; col < N; col++) {
					if(mat[lin][col] == 19){
						if(lin == 0) {	
							if((mat[lin][col-1] >= 11 &&	mat[lin][col-1] <= 18) ||
								(mat[lin][col+1] >= 11 && mat[lin][col+1] <= 18) || 
								(mat[lin+1][col] >= 11 && mat[lin+1][col] <= 18) ||
								(mat[lin+1][col-1] >= 11 && mat[lin+1][col-1] <= 18) ||
								(mat[lin+1][col+1] >= 11 && mat[lin+1][col+1] <= 18)){
								return 2;
							}
						}
					
						else if (lin > 0 && lin < N) {
							
							if((mat[lin-1][col-1] >= 11 &&	mat[lin-1][col-1] <= 18) ||
								(mat[lin-1][col] >= 11 &&	mat[lin-1][col] <= 18) ||
								(mat[lin-1][col+1] >= 11 &&	mat[lin-1][col+1] <= 18) ||
								(mat[lin][col-1] >= 11 &&	mat[lin][col-1] <= 18) ||
								(mat[lin][col+1] >= 11 && mat[lin][col+1] <= 18) || 
								(mat[lin+1][col] >= 11 && mat[lin+1][col] <= 18) ||
								(mat[lin+1][col-1] >= 11 && mat[lin+1][col-1] <= 18) ||
								(mat[lin+1][col+1] >= 11 && mat[lin+1][col+1] <= 18)) {
									return 2;
								}
					
						
						}
						else { //linha == 5
							if((mat[lin-1][col-1] >= 11 &&	mat[lin-1][col-1] <= 18) ||
								(mat[lin-1][col] >= 11 &&	mat[lin-1][col] <= 18) ||
								(mat[lin-1][col+1] >= 11 &&	mat[lin-1][col+1] <= 18) ||
								(mat[lin][col-1] >= 11 &&	mat[lin][col-1] <= 18) ||
								(mat[lin][col+1] >= 11 && mat[lin][col+1] <= 18)) {
									return 2;
							}
						}
					}
				}
			}
			return 1;
		}
	}
	
	
	// FIM DA SUA FUNCAO. NAO ALTERE O RESTO DO CÓDIGO
	
	void imprimeMatriz(unsigned char mat[N][N]) {
	unsigned x,y;
		
		for( x = 0; x< N; x++) {
			for(y=0; y <N; y++) {
				printf("%02hhd ",mat[x][y]);
			}
			printf("\n");
		}
	}
				
	int main() {
		unsigned lin,col;
		unsigned res;
		int x,y;
			unsigned char mat[N][N];
		
		scanf("%u%*c",&lin);
		scanf("%u%*c",&col);
		
		
			for(x=0; x<N; x++) {
					for(y=0; y<N; y++) {
						scanf("%hhu%*c",&mat[x][y]);
					}
			}
	
		res=joga(mat,lin,col);
		imprimeMatriz(mat);
		printf("%u\n",res);
	}
