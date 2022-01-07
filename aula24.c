//aula 24 - aed I - assistida no dia 15/04/2021
//ana leticia

//dado 3 vetores, faça a soma do segundo com o terceiro e coloque no primeiro

#include <stdio.h> 


void lerValoresVetores(float vet[], unsigned tamVetor, char nomeVetor[]) {
	unsigned cont;
	
	printf("Digite os valores para o %s:\n", nomeVetor);
	for(cont = 0; cont < tamVetor; cont++) {
		printf("%s[%u] = ", nomeVetor, cont);
		scanf("%f%*c", &vet[cont]);
	}
}

void somarVetores(float vetSoma[], float vet2[], float vet3[], unsigned tamVetor) {
	unsigned cont;
	
	for(cont = 0; cont < tamVetor; cont++) {
		vetSoma[cont] = vet2[cont] + vet3[cont];
	}
}

void mostrarVetores (float vet[], unsigned tamVetor) {
	unsigned cont;
	
	printf("[");
	for(cont = 0; cont < tamVetor; cont++) {
		if(cont == tamVetor-1) {
			printf("%.2f]", vet[cont]);
		} else {
			printf("%.2f, ", vet[cont]);
		}
	}
}


int main () {
	unsigned tamVet, cont;
	float vet1[tamVet], vet2[tamVet], vet3[tamVet];
	
	printf("qual o tamanho dos vet1, vet2, vet3? ");
	scanf("%u%*c", &tamVet);
	
	lerValoresVetores(vet1, tamVet, "vet1");
	lerValoresVetores(vet2, tamVet, "vet2");
	lerValoresVetores(vet3, tamVet, "vet3");
	
	somarVetores(vet1, vet2, vet3, tamVet);
	
	mostrarVetores(vet1, tamVet);
	mostrarVetores(vet2, tamVet);
	mostrarVetores(vet3, tamVet);
	
	
	
	
	return 0;
}
