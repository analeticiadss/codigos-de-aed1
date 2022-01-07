//prova 5 - 28/05/2020

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tipoPessoa {
	char telefone[20];
	char nome[25];
	char endereco[60];
} tipoPessoa;

void lerDados(tipoPessoa *pessoa, int num) {
	unsigned i;
	
	for(i = 0; i < num; i++) {
		scanf("%[^\n]%*c", pessoa[i].nome);
		scanf("%[^\n]%*c", pessoa[i].endereco);
		scanf("%[^\n]%*c", pessoa[i].telefone);
	}
}

void quickSortR(tipoPessoa *pessoa, int inicio, int fim) {
	tipoPessoa aux, pivot;
	int i, j, meio;
	
	if(inicio < fim) {
		meio = (inicio+fim)/2;
		pivot = pessoa[meio];
		
		i = inicio;
		j = fim;
		
		while(i <= j) {
			while(strcmp(pessoa[i].nome, pivot.nome) < 0) {
				i++;
			}
			while(strcmp(pessoa[j].nome, pivot.nome) > 0) {
				j--;
			}
			if(i <= j) {
				strcpy(aux.nome, pessoa[i].nome); 
				strcpy(aux.endereco, pessoa[i].endereco);
				strcpy(aux.telefone, pessoa[i].telefone);
				
				strcpy(pessoa[i].nome, pessoa[j].nome);
				strcpy(pessoa[i].endereco, pessoa[j].endereco);
				strcpy(pessoa[i].telefone, pessoa[j].telefone);
				
				strcpy(pessoa[j].nome, aux.nome);
				strcpy(pessoa[j].endereco, aux.endereco);
				strcpy(pessoa[j].telefone, aux.telefone);
				
				i++; j--;
			}
		}
		quickSortR(pessoa, inicio, j);
		quickSortR(pessoa, i, fim);
	}
}

void quickSort(tipoPessoa *pessoa, int num) {
	quickSortR(pessoa, 0, num-1);
}

void mostraAgenda(tipoPessoa *pessoa, int num) {
	unsigned i;
	for(i = 0; i < num; i++) {
		printf("%s\n", pessoa[i].nome);
		printf("%s\n", pessoa[i].endereco);
		printf("%s\n", pessoa[i].telefone);
	}
}

int main() {
	tipoPessoa *pessoa;
	int numPessoas;
	
	scanf("%d%*c", &numPessoas);
	
	pessoa = (tipoPessoa*) malloc(numPessoas*sizeof(tipoPessoa)); //vai criar um vetor de nPessoas do tipoPessoas
	
	lerDados(pessoa, numPessoas);
	quickSort(pessoa, numPessoas);
	//printf("%s\n", pessoa[3].nome);
	mostraAgenda(pessoa, numPessoas);
	
	free(pessoa);
	
}
