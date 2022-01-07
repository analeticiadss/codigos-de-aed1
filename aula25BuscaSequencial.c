//aula 25 - 17/04/2021
//ana leticia

/* Faça uma função que receba como parâmetro um vetor de número reais e chave
de busca. A função deve retornar verdadeiro (qualquer valor diferente de 0)
caso a chave não ocorra no vetor e falso (zero) em caso contrário */

#include <stdio.h>

int buscarSequencialmente(float vetor[], unsigned tamanhoVetor, float chave) {
	unsigned cont;
	
	for(cont = 0; cont < tamanhoVetor; cont++) {
		if(vetor[cont] == chave) {
			return 1; //retorna verdadeiro
		}
	}
	return 0;	
}

void lerValoresVetores(float vet[], unsigned tamVetor, char nomeVetor[]) {
	unsigned cont;
	
	printf("Digite os valores para o %s:\n", nomeVetor);
	for(cont = 0; cont < tamVetor; cont++) {
		printf("%s[%u] = ", nomeVetor, cont);
		scanf("%f%*c", &vet[cont]);
	}
}

void mostrarVetores (float vet[], unsigned tamVetor) {
	unsigned cont;
	
	printf("[");
	for(cont = 0; cont < tamVetor; cont++) {
		if(cont == tamVetor-1) {
			printf("%.2f]\n", vet[cont]);
		} else {
			printf("%.2f, ", vet[cont]);
		}
	}
}


int main () {
	unsigned tamVet, cont;
	float vet1[tamVet], vet2[tamVet], vet3[tamVet];
	float valorChave;
	
	printf("qual o tamanho dos vet1, vet2, vet3? ");
	scanf("%u%*c", &tamVet);
	
	
	lerValoresVetores(vet1, tamVet, "vet1");
	lerValoresVetores(vet2, tamVet, "vet2");
	lerValoresVetores(vet3, tamVet, "vet3");
	
	printf("Entre com uma chave de busca: ");
	scanf("%f%*c", &valorChave);
	
	if(buscarSequencialmente(vet1, tamVet, valorChave)) {
		printf("Chave encontrada no vetor 1\n");
	} if(buscarSequencialmente(vet2, tamVet, valorChave)) {
		printf("Chave encontrada no vetor 2\n");
	} if(buscarSequencialmente(vet3, tamVet, valorChave)) {
		printf("Chave encontrada no vetor 3\n");
	}
	else {
		printf("Chave nao encontrada no vetor \n");
	}
	
	mostrarVetores(vet1, tamVet);
	mostrarVetores(vet2, tamVet);
	mostrarVetores(vet3, tamVet);
	
	
	
	
	return 0;
}
