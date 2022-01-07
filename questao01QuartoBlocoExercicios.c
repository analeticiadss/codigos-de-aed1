//aed I - quarto bloco de exercicios
//06/05/2021 - ana leticia

#include <stdio.h>

//BEGINFUNCAOALUNO

// faca a funcao questaol41 aqui! Não modifique outras partes do programa
void quetaol41(int vet[], unsigned tamVet) {
	unsigned cont;
	int diferenca[tamVet];
	
	diferenca[0] = vet[0];
	for(cont = 1; cont < tamVet; cont++) {
		diferenca[cont] = vet[cont] - vet[cont-1];
	}
	for (cont = 0; cont < tamVet; cont++) {
		vet[cont] = diferenca[cont];
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
  quetaol41(vet,tamanhoVetor);
  mostrar(vet,tamanhoVetor);
}

