//RECURSIVIDADE - AED I - AULA 33
//01/05/2021 ana leticia

#include <stdio.h>

unsigned long fat(unsigned x) {
	
	if(x > 1) {
		return fat(x-1)*x;
	}
	return 1;
}


int main () {
	unsigned valor;
	
	valor = fat(9);
	printf("o fatorial de 9: %lu\n", valor);
}
