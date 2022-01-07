//questao 01 - lista de matrizes
// ana leticia - 18/05/2021

#include<stdio.h>

#define N 5

// FACA SUA FUNCAO AQUI
int contaQuatro(int mat[N][N], int k) {
	unsigned cont = 0, lin, col;
	
	for(lin = 0; lin < N; lin++) {
		for(col = 0; col < N; col++) {
			if(mat[lin][col] == k) {
				cont++;
			}
		}
	}
	
	if(cont == 4) {
		return 1;
	} else {
		return 0;
	}
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
    scanf("%d%*c",&valor);	
    if(contaQuatro(mat,valor)) {
      printf("verdadeiro\n");
    }
    else {
      printf("falso\n");
    }
  }

