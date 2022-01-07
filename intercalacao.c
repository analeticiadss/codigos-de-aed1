//intercalação de dois vetores ordenados
//AULA 41 - 10/05/2021

#include <stdio.h>

void intercalacao(int vet1[], unsigned tamVet1, int vet2[],
			unsigned tamVet2, int auxiliar[]) {
	unsigned i, j, k, cont;
	
	i = 0; j = 0; k = 0;
	
	while(i < tamVet1 && j < tamVet2) {
		if(vet1[i] < vet2[j]) {
			auxiliar[k] = vet1[i];
			i++;
		} else if(vet2[j] < vet1[i]){
			auxiliar[k] = vet2[j];
			j++;
		}
		k++;
	}
	while(i < tamVet1) { //se não foi o vet1 que acabou
		auxiliar[k] = vet1[i];
		i++; k++;
	}
	while(j < tamVet2) { //se não foi o vet2 que acabou
		auxiliar[k] = vet2[j];
		j++; k++;
	}	
}

void leVet(int vetor[], unsigned tamanhoVetor) {
	unsigned cont; 
	
	for(cont = 0; cont < tamanhoVetor; cont++) {
		scanf("%d%*c", &vetor[cont]);
	}
}

void mostraVetor(int vet[], unsigned tamVet) {
	unsigned cont;
	for(cont = 0; cont < tamVet; cont++) {
		printf("%d ", vet[cont]);
	}
}

int main() {
	unsigned tamVet1, tamVet2, cont, tamAux;
	int vet1[tamVet1], vet2[tamVet2], auxiliar[tamVet1 + tamVet2];
	
	printf("qual o tamanho do seu vetor 1?\n");
	scanf("%u%*c", &tamVet1);
	
	printf("quais sao os numeros do seu vetor 1?\n");
	leVet(vet1, tamVet1);
	
	printf("qual o tamanho do seu vetor 2?\n");
	scanf("%u%*c", &tamVet2);
	printf("quais sao os numeros do seu vetor 2?\n");
	leVet(vet2, tamVet2);
	
	tamAux = tamVet1 + tamVet2;
	intercalacao(vet1, tamVet1, vet2, tamVet2, auxiliar);
	mostraVetor(auxiliar, tamAux);
	
}
