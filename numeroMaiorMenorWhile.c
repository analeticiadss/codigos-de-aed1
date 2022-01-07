//maior e menor numero

#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "");
	int quantidade, menor, maior, numero;
	
	printf("quantos números você quer testar? ");
	scanf("%d%*c", &quantidade);
	
	printf("digite um número: ");
	scanf("%d%*c", &numero);
	maior = numero;
	menor = numero;
	
	while(quantidade > 1) {
		printf("digite outro número: ");
		scanf("%d%*c", &numero);
		
		if(numero > maior) {
			maior = numero;
		} else{
			if(numero < menor) {
				menor = numero;	
			}
		}
		
		quantidade--;
	}
	printf("o maior número é %d e o menor número é %d\n", maior, menor);

	
	
	return 0;
}
