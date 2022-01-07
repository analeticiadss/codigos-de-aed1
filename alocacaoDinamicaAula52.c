//AULA 52 - ALOCA��O DINAMICA

#include <stdio.h>
#include <stdlib.h>

void mostraVetor(int vet[], unsigned tamVet) {
	unsigned cont;
	for(cont = 0; cont < tamVet; cont++) {
		printf("%d\n",vet[cont]);
	}
}

int main () {
	int *vet;
	int z;
	z = 5;
	
	vet = (int*) malloc(z*sizeof(int)); //aloca, reserva 20 bytes, 5 inteiros
	if(vet == NULL) {
		printf("Erro de alocacao de memoria\n");
		exit(1); //acaba o programa
	}
	
	free(vet); 
	/*libera o espa�o e precisa ter o mesmo
	 endere�o que o malloc retornou */
	
}
