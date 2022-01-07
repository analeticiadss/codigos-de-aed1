//questão 1 - ordenação e listas encadeadas
//07/06/2021

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char nome[20];
	char endereco[40];
	int id;
} tipoDados;

void leDados(tipoDados *dados, unsigned num) {
	unsigned i;
	
	for(i = 0; i < num; i++) {
		scanf("%[^\n]%*c", dados[i].nome);
		scanf("%[^\n]%*c", dados[i].endereco);
		scanf("%d%*c", &dados[i].id);
	}
}

void mergeSortR(tipoDados *dados, tipoDados *aux, unsigned inicio, unsigned fim) {
	unsigned meio, i, j, k;
	
	if(inicio < fim) {
		meio = (inicio + fim)/2;
		mergeSortR(dados, aux, inicio, meio);
		mergeSortR(dados, aux, meio+1, fim);
		
		i = inicio; j = meio+1; k = inicio;
		
		while(i <= meio && j <= fim) {
			if(strcmp(dados[i].nome, dados[j].nome) > 0) {
				strcpy(aux[k].nome, dados[i].nome);
				strcpy(aux[k].endereco, dados[i].endereco);
				aux[k].id = dados[i].id;
				i++;
			}else {
				strcpy(aux[k].nome, dados[j].nome);
				strcpy(aux[k].endereco, dados[j].endereco);
				aux[k].id = dados[j].id;
				j++;
			}
			k++;
		}
		while(i <= meio) {
			strcpy(aux[k].nome, dados[i].nome);
			strcpy(aux[k].endereco, dados[i].endereco);
			aux[k].id = dados[i].id;
			i++; k++;
		}
		while(j <= fim) {
			strcpy(aux[k].nome, dados[j].nome);
			strcpy(aux[k].endereco, dados[j].endereco);
			aux[k].id = dados[j].id;
			j++; k++;
		}
		
		for(k = inicio; k < fim+1; k++) {
			strcpy(dados[k].nome, aux[k].nome);
			strcpy(dados[k].endereco, aux[k].endereco);
			dados[k].id = aux[k].id;
		}
	}
	
}

void mergeSort(tipoDados *dados, unsigned numElementos) {
	tipoDados *aux;
	aux = (tipoDados *) malloc(sizeof(tipoDados)*numElementos);
	mergeSortR(dados, aux, 0, numElementos-1);
	free(aux);
}

void mostraDados(tipoDados *dados, unsigned num) {
	unsigned i;
	for(i = 0; i < num; i++) {
		printf("%s\n", dados[i].nome);
		printf("%s\n", dados[i].endereco);
		printf("%d\n", dados[i].id);
	}
}

int main () {
	unsigned numElementos;
	tipoDados *dados;
	
	scanf("%u%*c", &numElementos);
	
	dados = (tipoDados *) malloc(sizeof(tipoDados) * numElementos);
	
	leDados(dados, numElementos);
	mergeSort(dados, numElementos);
	mostraDados(dados, numElementos);
}
