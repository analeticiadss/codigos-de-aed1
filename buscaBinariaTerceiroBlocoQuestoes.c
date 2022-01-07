//questao 10 - terceiro bloco de questoes - aed1
//29/04/2021 - ana leticia

#include <stdio.h>

int buscarBinaria(int vet[], unsigned tamVet, int chave) {
	int inicio, meio, fim, i;
	int indice, cont = 0;
	
	inicio = 0;
	fim = tamVet-1;
	
	while(inicio <= fim) {
		meio = (inicio+fim)/2;
		
		if(chave > vet[meio]) {
			inicio = meio + 1;
		} 
		else if (chave < vet[meio]) {
			fim = meio - 1;
		} 
		else { //chave == vet[meio]
			cont += 1;
			fim = meio-1;
			
		}
	}
	
	inicio = 0;
	fim = tamVet-1;
	
	while(inicio <= fim) {
		meio = (inicio+fim)/2;
		
		if(chave > vet[meio]) {
			inicio = meio + 1;
		} 
		else if (chave < vet[meio]) {
			fim = meio - 1;
		} 
		else { //chave == vet[meio]
			cont += 1;
			inicio = meio+1;
			
		}
	}
	
	if (cont > 0) {
		cont = cont-1; // porque vai ser identificado o numero comum 2 vezes
	}
	
	if(cont == 1) {
		return 1;
	}
	else {
		return 0;
	}
}

void ler(int v[], unsigned tamanhoVetor) {
  unsigned cont;
  for(cont = 0; cont < tamanhoVetor; cont++) {
    scanf("%d%*c",&v[cont]);
  }
} 


int main() {
  unsigned tamanhoVetor;
  int chave;
  scanf("%d%*c",&chave);
  scanf("%u%*c",&tamanhoVetor);
  int vet[tamanhoVetor];
  ler(vet,tamanhoVetor);
  if(buscarBinaria(vet,tamanhoVetor,chave)) {
    printf("SIM");
  }
  else {
 printf("NAO");
  }
}

