//buscando por sele��o
//ana leticia

#include <stdio.h>

void ordenaSelecao(int vet[], unsigned tamVet) {
	unsigned i, cont, posMenor;
	int guardaValor, menor;

	/*n�o pode usar i na comparacao vet[cont] < vet[i]
 	porque no fim ficaria vet[i] > vet[i] */

	for(i = 0; i < tamVet -1; i++) {
		posMenor = i;
	//incio o vetor, pego a primeira posicao para comparar com as seguintes
			for(cont = i+1; cont < tamVet; cont++) {
				//seleciono o resto do vetor e vejo quem � o menor
				if(vet[cont] < vet[posMenor]) {
					//o que for menor, eu pego a sua posicao
					posMenor = cont;
				}
			}
	/*se o primeiro elemento do vetor for
	 maior que o menor elemento no vetor inteiro,
	 eu troco os valores para que o menor elemento esteja
	 na primeira posi��o do vetor */
		if(vet[i] > vet[posMenor]) {
			guardaValor = vet[i];
			vet[i] = vet[posMenor];
			vet[posMenor] = guardaValor;
		}

	}
}

void mostraVetor (int vet[], unsigned tamVet) {
	unsigned cont;

	printf("vetor: [");
	for (cont = 0; cont < tamVet; cont++) {
		if(cont != tamVet-1) {
			printf("%d, ", vet[cont]);
		} else {
			printf("%d]", vet[cont]);
		}
	}
}

void leVetor(int vet[], unsigned tamVet) {
	unsigned cont;
	printf("digite os valores do vetor: ");
	for(cont = 0; cont < tamVet; cont++) {
		scanf("%d%*c", &vet[cont]);
	}
}

int main() {
	unsigned tamVet;
	int vet[tamVet];

	printf("qual o tamanho do vetor? ");
	scanf("%u%*c", &tamVet);

	leVetor(vet, tamVet);
	ordenaSelecao(vet, tamVet);
	mostraVetor(vet, tamVet);
}
