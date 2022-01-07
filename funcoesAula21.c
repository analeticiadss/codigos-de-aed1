//AULA 21 - FUN��ES - AED I - 08/04/2021
//ANA LET�CIA

#include <stdio.h>

unsigned x; //variavel global

int funcaoDeTeste(int valor) {
	static int cont = 0; 
	// a variavel static � apenas vis�vel no escopo em que foi declarada
	// a variavel static n�o morre, desde o in�cio do programa at� o fim
	
	x = 10 + valor;
	return x;
}


int main () {
	int z;
	x = 5;
	
	scanf("%d%*c", &z);
	z = funcaoDeTeste(z);
	printf("valor de x: %u\nvalor de z: %d\n", x, z);
	
	return 0;
}
