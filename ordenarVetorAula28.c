// ordernar vetor por seleção - aula 29
// 27.04.2021 - ana leticia

#include <stdio.h>

void ordenaSelecao (int vet[], unsigned tamVet) {
	int menorPosicao, guardaValor;
	unsigned cont;
	
	for(i = 0; i < tamVetor - 1; i++) {
		menorPosicao = i;
		for(cont = i+1; cont < tamVetor; cont++) {
			if(vet[cont] < vet[menorPosicao]) {
				menorPosicao = cont;
			}
		}
		//trocar primeira posicao com a posicao do menor;
		guardaValor = vet[i];
		vet[i] = vet[menorPosicao];
		vet[menorPosicao] = guardaValor;
		}
	}

void leVetor (int vet[], unsigned tamVet) {
	unsigned cont;
	printf("digite os valores do vetor\n");
	for(cont = 0; cont < tamVet; cont++) {
		scanf("%f%*c", &vet[cont]);
	}
}


int main () {
	unsigned tamVet, cont;
	int vet[tamVet], vetOrdenado[tamVet];
	
	printf("qual o tamanho do vetor? ");
	scanf("%u%*c", &tamVet);
	
	leVetor(vet, tamVet);
	
}
