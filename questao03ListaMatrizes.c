//questao 03 lista matrizes
//18/05/2021 - ana leticia

#include<stdio.h>

#define N 5

// FACA SUA FUNCAO AQUI
int soma(int mat[N][N]) {
	unsigned lin, col;
	int resultado = 0;
	
	col = N-1;
	for(lin = 0; lin < N; lin++) {
		resultado += mat[lin][col];
		col--;
	}
	return resultado;
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
  
      printf("%d\n",soma(mat));
  
  }


