//acumuladores

#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL,"");
	int quantidade, numero, soma = 0;
	
	printf("quantos números você quer somar? ");
	scanf("%d%*c", &quantidade);
	
	for(quantidade; quantidade > 0; quantidade--) {
		printf("digite um número: ");
		scanf("%d%*c", &numero);
		
		soma += numero;
		
	}
	printf("a soma dos números que você digitou é: %d\n", soma);
	
	return 0;
}
