// VETOR CHAR - 07/04/2021 - ANA LETICIA

#include <stdio.h>

int main() {
	char nome[100];
	
	printf("digite o seu nome: ");
	scanf("%[^\n]%*c", nome); 
	//%[] � pra ler string e ^\n � pra n�o aceitar o enter
	//^ � a nega��o, [] l� tudo se fosse vazio
	//mas como tem ^ (nao aceite) \n (o enter)
	printf("%s\n", nome);
	
	
	return 0;
}
