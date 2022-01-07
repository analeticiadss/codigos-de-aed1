//ler o maior número com laço de repetição while
#include<stdio.h>
#include <locale.h>

int main() {
	int n, maior;
	setlocale(LC_ALL, "");
	
	printf("digite um número: ");
	scanf("%d%*c", &n);
	maior = n;
	
	printf("digite um número: ");
	scanf("%d%*c", &n);
	
	while(n > maior) {
		maior = n;
		printf("digite um número: ");
		scanf("%d%*c", &n);
	}
	
	printf("o maior número é: %d\n", maior);
	
	return 0;
}
