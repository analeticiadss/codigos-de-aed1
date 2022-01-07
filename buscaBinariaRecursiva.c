//busca binaria recursiva - aed I - aula 34
//01/05/2021 - ana leticia

#include <stdio.h>

int buscaBinariaRecursiva (long vet[], int inicio, unsigned tamVet, long chave) {
	int meio;

	tamVet--;
	
	if(inicio <= tamVet) {
		meio = (inicio + tamVet)/2;
		if(chave < meio) {
			return buscaBinaria(vet, inicio, meio-1, chave);
		}
		else if (chave > meio) {
			return buscaBinaria(vet, meio +1, tamVet, chave);
		}
		else {
			return 1;
		}
	}
	return 0;
}

int buscaBinaria(long vetor[], unsigned tamanhoVetor, long chave) {
	int inicio = 0;
	return buscaBinariaRecursiva(vet, inicio, tamanhoVetor, chave);
}


void leVet(long vetor[], unsigned tamanhoVetor) {
	unsigned cont; 
	
	for(cont = 0; cont < tamanhoVetor; cont++) {
		scanf("%lu%*c", &vetor[cont]);
	}
}

int main() {
	unsigned tamVet, cont;
	long vet[tamVet];
	long chave;
	int busca;
	
	
	printf("qual o tamanho do seu vetor?\n");
	scanf("%u%*c", &tamVet);
	
	printf("quais sao os numeros do seu vetor?\n");
	leVet(vet, tamVet);
	
	printf("agora entre com uma chave para fazer uma busca binaria: ");
	scanf("%lu%*c", &chave);
	
	busca = buscaBinaria(vet, tamVet, chave);
	if(busca == 1) {
		printf("numero encontrado!\n");
	} else {
		printf("numero nao encontrado.\n");
	}
}
