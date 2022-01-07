// FUNÇÃO VETOR GENERICA
// AULA 22 AED I - 10/04/2021 - ANA LETICIA

#include <stdio.h>

float menorElementoVetor(float vetor[], unsigned tamanhoVetor) {
	unsigned cont;
	float menor;
	
	menor = vetor[0];
	for(cont = 1; cont < tamanhoVetor; cont++) {
		if (vetor[cont] < menor) {
			menor = vetor[cont];
		}
	}
	return menor;
}

float maiorElementoVetor(float vetor[],unsigned tamanhoVetor) {
	unsigned cont;
	float maior;
	
	maior = vetor[0];
	for(cont = 1; cont < tamanhoVetor; cont++) {
		if (vetor[cont] > maior) {
			maior = vetor[cont];
		}
	}
	return maior;
}

float mediaElementoVetor(float vetor[],unsigned tamanhoVetor) {
	float soma = 0, media = 0;
	unsigned cont;
	
	for(cont = 0; cont < tamanhoVetor; cont++) {
		soma = soma + vetor[cont];
	}
	media = soma/cont;
	
	return media;
}

int main () {
	unsigned tamanhoVetor, cont;
	float vetor[tamanhoVetor], maior, menor, media;
	
	printf("qual eh o tamanho do seu vetor? ");
	scanf("%u%*c", &tamanhoVetor);
	
	printf("digite %u numeros:\n", tamanhoVetor);
	for(cont = 0; cont < tamanhoVetor; cont++) {
		scanf("%f%*c", &vetor[cont]);
	}
	
	menor = menorElementoVetor(vetor,tamanhoVetor);
	maior = maiorElementoVetor(vetor,tamanhoVetor);
	media = mediaElementoVetor(vetor,tamanhoVetor);
	
	printf("o menor numero do vetor eh: %.2f\n", menor);
	printf("o maior numero do vetor eh: %.2f\n", maior);
	printf("a media do vetor eh: %.2f\n\n", media);
	printf("vetor = {");
		for(cont = 0; cont < tamanhoVetor; cont++) {
			if (cont < tamanhoVetor-1) {
				printf("%.2f, ", vetor[cont]);
			}else if (cont = tamanhoVetor - 1) {
				printf("%.2f}", vetor[cont]);
			}
		}
	
	
	
	return 0;
}
