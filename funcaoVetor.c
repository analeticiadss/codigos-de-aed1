// FUNÇÕES VETORES - AULA 22 - AED I
//ANA LETICIA

#include <stdio.h>

float menorElementoVetor(float vetor[4]) {
	unsigned cont = 0;
	float menor;
	
	menor = vetor[0];
	for (cont = 1; cont < 4; cont++) {
		if(vetor[cont] < menor){
			menor = vetor[cont];
		}
	}
	return menor;
}

float maiorElementoVetor(float vetor[4]) {
	unsigned cont = 0;
	float maior;
	
	maior = vetor[0];
	for (cont = 1; cont < 4; cont++) {
		if(vetor[cont] > maior){
			maior = vetor[cont];
		}
	}
	return maior;
}

float mediaElementoVetor(float vetor[4]) {
	unsigned cont = 0;
	float media = 0;
	
	for (cont = 0; cont < 4; cont++) {
		media = media + vetor[cont];
	}
	media = media/cont;
	
	return media;
}


int main() {
	float vetor[4];
	float menor, maior, media;
	
	vetor[0] = 5;
	vetor[1] = 3.7;
	vetor[2] = 8.9;
	vetor[3] = 9.5;
	
	menor = menorElementoVetor(vetor);
	maior = maiorElementoVetor(vetor);
	media = mediaElementoVetor(vetor);
	
	printf("o menor elemento do vetor: %.2f\n", menor);
	printf("o maior elemento do vetor: %.2f\n", maior);
	printf("a media dos vetores: %.2f\n", media);
	
	return 0;
}
