//numero menor de todos
//ana leticia

#include <stdio.h>

int menorNumero (int vet[], unsigned tamVet) {
	unsigned cont;
	int menor;
	menor = vet[0];
	for(cont = 1; cont < tamVet; cont++) {
		if(vet[cont] < menor) {
			menor = vet[cont];
		}
	}
	return menor;
}

void mostraVetor (int vet[], unsigned tamVet) {
	unsigned cont;
	
	printf("vetor: [");
	for (cont = 0; cont < tamVet; cont++) {
		if(cont != tamVet-1) {
			printf("%d, ", vet[cont]);
		} else {
			printf("%d]", vet[cont]);
		}
	}
}

void leVetor(int vet[], unsigned tamVet) {
	unsigned cont;
	printf("digite os valores do vetor: ");
	for(cont = 0; cont < tamVet; cont++) {
		scanf("%d%*c", &vet[cont]);
	}
}

int main() {
	unsigned tamVet;
	int vet[tamVet], menor;
	
	printf("qual o tamanho do vetor? ");
	scanf("%u%*c", &tamVet);
	
	leVetor(vet, tamVet);
	menor = menorNumero(vet, tamVet);
	printf("%d\n", menor);
	
}
