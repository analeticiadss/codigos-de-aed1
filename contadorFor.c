//contador pra contar de 0 até n-1

#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL,"");
	
	int contador, numero;
	
	printf("digite um número: ");
	scanf("%d%*c", &numero);
	
	for(contador = 0; contador < numero; contador++) {
		printf("%d ", contador);
	}
	
	return 0;
}
