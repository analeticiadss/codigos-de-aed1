//acumulador, fatorial

#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL,"");
	int numero, fatorial = 1;
	
	//fatorial de 3! por exemplo = 3.2.1
	//fatorial de 4! = 4.3.2.1
	
	printf("qual n�mero voc� quer saber o fatorial? ");
	scanf("%d%*c", &numero);
	
	for(numero; numero > 1; numero--) {
		/* exemplo: numero = 4
		fatorial = 1*4 = 4
			numero -- = 3
		fatorial = 4*3
			numero -- = 2
		fatorial = 4*3*2
			numero -- = 1
		programa para porque j� foi multiplicado por 1 no in�cio */
		
		fatorial *= numero;
		
	}
	printf("o fatorial do n�mero �: %d\n", fatorial);
	
	return 0;
}
