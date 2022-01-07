// VETOR CHAR - 07/04/2021 - ANA LETICIA

#include <stdio.h>

int main() {
	char nome[100];
	
	printf("digite o seu nome: ");
	scanf("%[^\n]%*c", nome); 
	//%[] é pra ler string e ^\n é pra não aceitar o enter
	//^ é a negação, [] lê tudo se fosse vazio
	//mas como tem ^ (nao aceite) \n (o enter)
	printf("%s\n", nome);
	
	
	return 0;
}
