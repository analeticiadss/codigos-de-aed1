//numero maior usando FOR

#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "");
	int quantidade, numero, maior;
	
	printf("quantos números você quer testar? ");
	scanf("%d%*c", &quantidade);
	
	printf("digite um número: ");
	scanf("%d%*c", &numero);
	maior = numero;
	
	for(quantidade == quantidade; quantidade > 1; quantidade--) {
		printf("digite outro número: ");
		scanf("%d%*c", &numero);
		
		if(numero > maior){
			maior = numero;
		}
	}
	printf("o maior número digitado é: %d\n", maior);
	
	
	return 0;
}
