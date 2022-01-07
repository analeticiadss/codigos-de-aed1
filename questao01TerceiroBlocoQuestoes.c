//quest�o 07 - lista 1 - terceiro bloco de questoes
//27/04/2021 - ana leticia


#include <stdio.h>

void ordenaInsercao (int vet[], unsigned tamVet) {
	int i = 1, j, pivot;
	unsigned cont;
	
	while(i < tamVet) {
		pivot = vet[i];
		j = i-1;
		
		while((j >= 0) && (vet[j] < pivot)) {
			vet[j+1] = vet[j];
			j--;
		}
		vet[j+1] = pivot;
		i++;
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
	int vet[tamVet];
	
	printf("qual o tamanho do vetor? ");
	scanf("%u%*c", &tamVet);
	
	leVetor(vet, tamVet);
	ordenaInsercao(vet, tamVet);
	mostraVetor(vet, tamVet);
	
}
