//numero maior usando FOR

#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "");
	int quantidade, numero, maior;
	
	printf("quantos n�meros voc� quer testar? ");
	scanf("%d%*c", &quantidade);
	
	printf("digite um n�mero: ");
	scanf("%d%*c", &numero);
	maior = numero;
	
	for(quantidade == quantidade; quantidade > 1; quantidade--) {
		printf("digite outro n�mero: ");
		scanf("%d%*c", &numero);
		
		if(numero > maior){
			maior = numero;
		}
	}
	printf("o maior n�mero digitado �: %d\n", maior);
	
	
	return 0;
}
