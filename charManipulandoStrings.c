// VETOR CHAR - 07/04/2021 - ANA LETICIA
//aula 18 - aedI

#include <stdio.h>
#include <string.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL,"");
	char string1[100];
	char string2[100];
	
	printf("digite uma string: ");
	scanf("%[^\n]%*c", string1);
	
	printf("digite outra string: ");
	scanf("%[^\n]%*c", string2);
	
	//compara strings
	if(strcmp(string1, string2) == 0) { //strcasecmp = maiusculos minusculos sao iguais
		printf("as strings são iguais\n");
	} else if (strcmp(string1, string2) > 0) {
		printf("%s vem antes de %s na ordem alfabética\n", string2, string1);
	} else {
		printf("%s vem antes de %s na ordem alfabética\n", string1, string2);
	}
	
	//copiar string
	strcpy(string1, string2); 
	//copia a string2 na string1
	//strcpy -> string1 = string2
	printf("a string1 é %s\n", string1);
	
	//strcat concatena as strings
	//strcat(string1, string2);
	printf("juntando os nomes, temos: %s\n", strcat(string1, string2));
	return 0;
}
