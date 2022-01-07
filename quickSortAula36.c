//AULA 35 E 36 - QUICKSORT - AED I
// ana leticia - 03/05/2021

#include <stdio.h>

void quickSortR(float vet[], int inicio, int fim) {
	float pivot, guardaValor;
	int i, j;
	
	if(inicio < fim) {
		pivot = vet[(inicio+fim)/2]; //divide o vetor ao meio
		i = inicio;
		j = fim;
		
		while(i <= j) {
			while(vet[i] < pivot) { //elementos menores que o pivot
				i++;
			}
			while(vet[j] > pivot) {//elementos maiores que o pivot
				j--;
			}
		
		/* só vai acontecer o if se não entrar nos whiles, ou seja,
		se vet[i] > pivot ou vet[j] < pivot	*/
			if(i <= j) {
				guardaValor = vet[i];
				vet[i] = vet[j];
				vet[j] = guardaValor;
				i++;
				j--;
			}
		}
		quickSortR(vet, inicio, j);
		quickSortR(vet, i, fim);
	}
}

void quickSort(float vet[], int tamVet) {
	quickSortR(vet, 0, tamVet-1);
}

void leVet(float vetor[], int tamanhoVetor) {
	int cont; 
	
	for(cont = 0; cont < tamanhoVetor; cont++) {
		scanf("%f%*c", &vetor[cont]);
	}
}

void mostraVetor(float vet[], int tamVet) {
	int cont;
	for(cont = 0; cont < tamVet; cont++) {
		printf("%.1f ", vet[cont]);
	}
}

int main() {
	int tamVet, cont;
	float vet[tamVet];
	
	printf("qual o tamanho do seu vetor?\n");
	scanf("%d%*c", &tamVet);
	
	printf("quais sao os numeros do seu vetor?\n");
	leVet(vet, tamVet);
	
	quickSort(vet, tamVet);
	mostraVetor(vet, tamVet);
	
}
