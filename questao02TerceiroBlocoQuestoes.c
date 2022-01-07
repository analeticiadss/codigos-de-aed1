//questão 11 - Terceiro bloco de qustoes - 27/04/2021
//ana leticia

//questão 07 - lista 1 - terceiro bloco de questoes
//27/04/2021 - ana leticia


#include <stdio.h>

void questao11 (int vet[], int delta, unsigned tamVet) {
	unsigned cont;
	
	for(cont = 0; cont < tamVet; cont++) {
		vet[cont] = vet[cont] - delta;
	}
}


void leVetor (int vet[], unsigned tamVet) {
	unsigned cont;
	printf("digite os valores do vetor:\n");
	for(cont = 0; cont < tamVet; cont++) {
		scanf("%d%*c", &vet[cont]);
	}
}

void mostraVetor(int vet[], unsigned tamVet) {
	unsigned cont;
	for(cont = 0; cont < tamVet; cont++) {
		printf("%d ", vet[cont]);
	}
}

int main () {
	unsigned tamVet, cont;
	int vet[tamVet], delta;
	
	printf("qual o delta? ");
	scanf("%d%*c", &delta);
	
	printf("qual o tamanho do vetor? ");
	scanf("%u%*c", &tamVet);
	
	
	leVetor(vet, tamVet);
	questao11(vet, delta, tamVet);
	mostraVetor(vet, tamVet);
	
}
