//questao 09 - terceiro bloco de questoes - aed I
//29/04/2021 - ana leticia

#include <stdio.h>
#include <string.h>

int palindromo(char nome[]) {
	unsigned tamVet, i, j;
	
	tamVet = strlen(nome);
	char nomeInvertido[tamVet];
	
	i = tamVet-1;
	
	for(j = 0; j < tamVet; j++) {
		nomeInvertido[j] = nome[i];
		i--;
	}
	
	if(strcmp(nome, nomeInvertido) == 0) {
		return 1;
	} else {
		return 0;
	}
}



int main() {
	char nome[100];
	
	scanf("%[^\n]%*c",nome);
    if(palindromo(nome)) {
		printf("SIM");
	}
	else {
		printf("NAO");	
	}
}
	
