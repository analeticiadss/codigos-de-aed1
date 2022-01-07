//intercalação de dois vetores ordenados
//AULA 41 - 10/05/2021

#include <stdio.h>

void mergeSort(float vet[], float vetorAux[], unsigned inicio, unsigned fim) {
	unsigned meio, i, j, k;
	
	if(inicio < fim) {
		meio = (inicio+fim)/2;
		mergeSort(vet, vetorAux, inicio, meio);
		mergeSort(vet, vetorAux, meio+1, fim);
	
		i = inicio; k = inicio; j = meio+1;
	
		while(i <= meio && j <= fim) {
			if(vet[i] < vet[j]) {
				vetorAux[k] = vet[i];  //vetor aux
				i++;
			} else if(vet[j] < vet[i]){
				vetorAux[k] = vet[j];
				j++;
			}
			k++;
		}
		while(i <= meio) { //se não foi o vet1 que acabou
			vetorAux[k] = vet[i];
			i++; k++;
		}
		while(j <= fim) { //se não foi o vet2 que acabou
			vetorAux[k] = vet[j];
			j++; k++;
		}	
		for(k = inicio; k <= fim; k++) {
			vet[k] = vetorAux[k]; //copiando pro vetor original
		}
	}
}

void leVet(float vetor[], unsigned tamanhoVetor) {
	unsigned cont; 
	
	for(cont = 0; cont < tamanhoVetor; cont++) {
		scanf("%f%*c", &vetor[cont]);
	}
}

void mostraVetor(float vet[], unsigned tamVet) {
	unsigned cont;
	for(cont = 0; cont < tamVet; cont++) {
		printf("%.2f ", vet[cont]);
	}
}

int main() {
	unsigned tamVet;
	float vet[tamVet], vetAux[tamVet];
	
	printf("qual o tamanho do seu vetor?\n");
	scanf("%u%*c", &tamVet);
	
	printf("quais sao os numeros do seu vetor?\n");
	leVet(vet, tamVet);
	
	
	mergeSort(vet, vetAux, 0, tamVet-1);
	mostraVetor(vet, tamVet);
	
}
