//questão 08 - terceiro bloco de questões - aedI
//29/04/2021 - ana letícia


unsigned contaLetras(char nome[], char letra) {
	unsigned i = 0, tamanhoVet = 0, indice = 0, cont = 0;
	
	while(nome[i] != '\0') {
		tamanhoVet += 1;
		i++;
	}
	
	while(indice < tamanhoVet) {
		if(nome[indice] == letra 
		|| nome[indice] == letra+32 
		|| nome[indice]+32 == letra) {
			cont += 1;
		}
		indice++;
	}
	return cont;
}


#include <stdio.h>
#include <stdlib.h>

int main() {
 
	char nome[300];
	char letra;

	scanf("%[^\n]%*c",nome);
	scanf("%c%*c",&letra);
	printf("%u", contaLetras(nome,letra) );
}

