//ler o maior n�mero com la�o de repeti��o while
#include<stdio.h>
#include <locale.h>

int main() {
	int n, maior;
	setlocale(LC_ALL, "");
	
	printf("digite um n�mero: ");
	scanf("%d%*c", &n);
	maior = n;
	
	printf("digite um n�mero: ");
	scanf("%d%*c", &n);
	
	while(n > maior) {
		maior = n;
		printf("digite um n�mero: ");
		scanf("%d%*c", &n);
	}
	
	printf("o maior n�mero �: %d\n", maior);
	
	return 0;
}
