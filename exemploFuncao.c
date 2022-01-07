//exemplo da aula 20 funções
//ANA LETÍCIA - 08/04/2021

#include <stdio.h>


unsigned long fatorial (unsigned numero) {
	unsigned fat = 1; 
	unsigned contador;
	
	for (contador = numero; contador > 1; contador--) {
		//exemplo, n = 4! -> 1*4*3*2
		fat *= contador;
		printf("%u, %u\n", contador, fat);
	}
	return fat;
}
	
int main() {
	
	unsigned numero;
	unsigned long fact;
	
	printf("digite um numero: ");
	scanf("%u%*c", &numero);
	
	fact = fatorial(numero);
	printf("o fatorial: %lu\n", fact);
	
	
	return 0;
}
