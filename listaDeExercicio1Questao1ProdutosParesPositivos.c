//qustão 1 lista 1 de exercicio aed1 - 10/04/2021- ana letiica

#include <stdio.h>
void produtoParesPositivos(int n) {
	long produto = 1, cont;
	
	printf("quantos numeros positivos voce quer calcular? ");
	scanf("%d%*c", &n);
	
	// se n < 0
	if (n <= 0) {
		printf("1\n");
		return;
	}
	
	for(cont = 2; cont <= n*2; cont += 2) { //n*2 pra alcançar até o ultimo numero positivo
	//exemplo: n = 3 -> numeros pares positivos = 2, 4, 6
	//n = 4 -> numeros pares positivos = 2, 4, 6, 8
	//n = 5 -> numeros pares positivos = 2, 4, 6, 8, 10 
		produto *= cont;
	}
	printf("o produto: %li\n", produto);
}


int main () {
	/*long int valor;

   scanf("%d%*c",&valor);
   printf("%d\n", questao01(valor)); */
   int n;
   //scanf("%u%*c", &n);
   produtoParesPositivos(n);

}
