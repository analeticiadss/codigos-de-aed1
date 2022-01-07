//questao05 - 22/04/2021 lista 1

#include <string.h>

char questao05(char texto[], char padrao[]) {
	unsigned cont, cont2, tamVetorTexto, tamVetorPadrao, len = 0;
	tamVetorTexto = strlen(texto);
	tamVetorPadrao = strlen(padrao);
	
	cont2 = 0;
	for(cont = 0; cont < tamVetorTexto; cont++) {
		if(texto[cont] == padrao[cont2]) {
			cont2++;
			len++;
			if(len == tamVetorPadrao) {
				return 1;
			}
		}
		else {
			cont2 = 0; //reiniciar a contagem pela primeira letra
			len = 0;
		}
	}
	return 0;
	
}

#include <stdio.h>

int main() {
  char texto[2000]; // texto onde vamos buscar a string de consulta
  char padrao[100]; // string de consulta
   unsigned tamVetor;

   unsigned x;
	
   scanf("%[^#]%*c",texto);
   scanf("%[^#]%*c",padrao);

   if(questao05(texto,padrao)) {
     printf("VERDADEIRO\n");
   }
   else {
     printf("FALSO\n");
   }
   
}
