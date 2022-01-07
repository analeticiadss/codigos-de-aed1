//aula 27 - busca binaria - 24/04/2021
//ana leticia

#include <stdio.h>

int buscaBinaria(long vetor[], unsigned tamanhoVetor, long chave) {
	unsigned cont = 0;
	int inicio, fim, meio;
	
	inicio = 0;
	fim = tamanhoVetor -1;
	
	while(inicio <= fim) {
		meio = (inicio+fim)/2;
		if(chave < vetor[meio]) {
			fim = meio - 1;
		}
		else if(chave > vetor[meio]) {
			inicio = meio + 1;
		}
		else { //se for igual, encontrou a chave
			return 1;
		}
	}
	return 0;	
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
