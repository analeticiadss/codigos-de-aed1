// FUNÇÕES -- AED I
//ANA LETÍCIA - 08/04/2021

#include <stdio.h>
#include <locale.h>

unsigned long fatorial (unsigned numero) {
	unsigned fat = 1; //variavel local pra ser usada dentro da função apenas
	unsigned contador; //variavel local
	
	for (contador = numero; contador = 2; contador--) {
		//exemplo, n = 4! -> 1*4*3*2
		fat = numero * fat;
	}
	return fat; //a função para instantaneamente quando há o comando return
}

/*unsigned somaNumerosNaturais (unsigned numeroNatural) {
	unsigned soma = 0;
	unsigned contador;
	
	for(contador = 1; contador = numeroNatural; contador++ ) {
		soma += contador;
	}
	return soma;
}
*/

int main() {
	setlocale(LC_ALL, "");
	
	unsigned numero;
	
	printf("digite um número: ");
	scanf("%u%*c", &numero);
	
	printf("o fatorial de %u é: %lu\n", numero, fatorial(numero));
	
	
	return 0;
}

