//acumuladores

#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL,"");
	int quantidade, numero, soma = 0;
	
	printf("quantos n�meros voc� quer somar? ");
	scanf("%d%*c", &quantidade);
	
	for(quantidade; quantidade > 0; quantidade--) {
		printf("digite um n�mero: ");
		scanf("%d%*c", &numero);
		
		soma += numero;
		
	}
	printf("a soma dos n�meros que voc� digitou �: %d\n", soma);
	
	return 0;
}
