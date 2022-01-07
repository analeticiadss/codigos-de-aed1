//questao 02 lista de matrizes - aed I
//18/05/2021 - ana leticia

#include<stdio.h>

#define N 5

// FACA SUA FUNCAO AQUI
int menor (int mat[N][N]) {
	int menor;
	unsigned lin, col;
	
	menor = mat[0][0];
	for(lin = 0; lin < N; lin++) {
		for(col = 0; col < N; col++) {
			if(mat[lin][col] < menor) {
				menor = mat[lin][col];
			}
		}
	}
	return menor;
}

  
// FIM DA SUA FUNCAO


int main() {
  int x,y;
    int mat[N][N];
    int valor;
    
    for(x=0; x<N; x++) {
      for(y=0; y<N; y++) {
	scanf("%d%*c",&mat[x][y]);
      }
    }
  
      printf("%d\n",menor(mat));
  
  }


