//questao 02 quarto bloco de exercicios
//06/05/2021 - ana leticia
#include <stdio.h>

//BEGINFUNCAOALUNO
void decodifica(int vet[], unsigned tamVet) {
	unsigned cont;
	int soma[tamVet];
	
	soma[0] = vet[0];
	for(cont = 1; cont < tamVet; cont++) {
		soma[cont] = vet[cont] + soma[cont-1];
	}
	for(cont = 0; cont < tamVet; cont++) {
		vet[cont] = soma[cont];
	}
}



//ENDFUNCAOALUNO



void ler(int v[], unsigned tamanhoVetor) {
  unsigned cont;
  for(cont = 0; cont < tamanhoVetor; cont++) {
    scanf("%d%*c",&v[cont]);
  }
} 


void mostrar(int v[], unsigned tamanhoVetor) {
  unsigned cont;
  for(cont = 0; cont < tamanhoVetor -1; cont++) {
    printf("%d ",v[cont]);
  }
  if(tamanhoVetor) { 
	 printf("%d",v[cont]);
  }
} 



int main() {
  unsigned tamanhoVetor;
 
  scanf("%u%*c",&tamanhoVetor);
  int vet[tamanhoVetor];
  ler(vet,tamanhoVetor);
  decodifica(vet,tamanhoVetor);
  mostrar(vet,tamanhoVetor);
}

