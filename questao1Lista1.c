//qustão 1 lista 1 de exercicio aed1 - 10/04/2021- ana letiica


unsigned long questao01(long int valor) {
	long produto = 1, cont;
	
	//printf("quantos numeros positivos voce quer calcular? ");
	//scanf("%d%*c", &valor);
	
	// se valor <= 0
	if (valor <= 0) {
		return 1;
	}
	
	for(cont = 2; cont <= valor*2; cont += 2) { //n*2 pra alcançar até o ultimo numero positivo
	//exemplo: n = 3 -> numeros pares positivos = 2, 4, 6
	//n = 4 -> numeros pares positivos = 2, 4, 6, 8
	//n = 5 -> numeros pares positivos = 2, 4, 6, 8, 10 
		produto *= cont;
	}
	return produto;
	//printf("o produto: %li\n", produto);
}

#include <stdio.h>
int main () {
	long int valor;

   scanf("%d%*c",&valor);
   printf("%d\n", questao01(valor));
  // int n;
  // produtoParesPositivos(n);

}
