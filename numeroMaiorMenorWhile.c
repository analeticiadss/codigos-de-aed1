//maior e menor numero

#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "");
	int quantidade, menor, maior, numero;
	
	printf("quantos n�meros voc� quer testar? ");
	scanf("%d%*c", &quantidade);
	
	printf("digite um n�mero: ");
	scanf("%d%*c", &numero);
	maior = numero;
	menor = numero;
	
	while(quantidade > 1) {
		printf("digite outro n�mero: ");
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
	printf("o maior n�mero � %d e o menor n�mero � %d\n", maior, menor);

	
	
	return 0;
}
