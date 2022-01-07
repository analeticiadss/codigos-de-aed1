//AULA 39 - COMPARAÇÃO ENTRE ORDENAÇÃO POR INSERÇÃO E QUICKSORT
//04/05/2021

#include <stdio.h>

void copiaVetor(float vetGrande1, float vetGrande2, unsigned tamVet) {
	unsigned cont;
	for(cont = 0; cont < tamVet; cont++) {
		vetGrande1[cont] = vetGrande2[cont]; //copia o segundo parametro pro primeiro
	}
}

int estaOrdenado (float vetGrande1, unsigned tamVet) {
	unsigned cont;
	for(cont = 0; cont < tamVet-1; cont++) {
		if(vetGrande1[cont] > vetGrande1[cont +1]) {
			return 0; //não tá ordenado
		}
	}
	return 1; //tá ordenado
}

void buscaBinaria (float vet[], float chave, unsigned tamVet, ) {
	float inicio, fim, meio;
	unsigned cont;
	inicio = 0;
	fim = tamVet-1;
	
	while(inicio <= fim) {
		meio = (inicio+fim)/2;
		
		if(vetGrande1[cont] < vetGrande2[meio]) {
			fim = meio -1;
		}
		else if (vetGrande1[cont] > vetGrande2[meio]) {
			inicio = meio +1;
		}
		else {
			return 1;
		}
	}	
	return 0;
}

int contemMesmosElementos(float vetGrande1[],
							float vetGrande2[],
						 	unsigned tamVet) {
						 		
	float inicio, fim, meio;
	unsigned cont;
		
		for(cont = 0; cont < tamVet; cont++) {
			if(buscaBinaria(vetGrande2, vetGrande1[cont], tamVet) == 0) {
				return 0; //não encontrou
			}
		}
		return 1;
	}	
}
