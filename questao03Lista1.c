//QUESTÃO 03 - ANA LETICIA 12/04/2021

// PARTE A MODIFICAR
// INICIOFUNCAOALUNO
// ESCREVA NESSA ÁREA  A FUNCAO questao03 que deve atender ao enunciado do exercício. 
// função retorna void porque ela modifica diretamente o vetor e não precisa

void questao03 (int vet[], unsigned tamVetor) {
	unsigned cont1, cont2;
	int valorGuardado;
	
	cont2 = tamVetor-1;
	for(cont1 = 0; cont1 < cont2; cont1++) {
		valorGuardado = vet[cont1];
		vet[cont1] = vet[cont2];
		vet[cont2] = valorGuardado;
		cont2--;
	}
}

//ENDFUNCAOALUNO


// ABAIXO CODIGO USADO PARA TESTE DA FUNCAO. NÃO MOFIQUE!

#include <stdio.h>

// mostra dados de um vetor

void mostraVetor(int vet[], unsigned n) {
  unsigned x;

  for(x = 0; x< n; x++) {
    printf("%d ",vet[x]);
  }
  printf("\n");
}

int main() {
   unsigned tamVetor;
   unsigned x;

   scanf("%u%*c",&tamVetor);
   int vet[tamVetor];

   for(x = 0; x< tamVetor; x++) {
     scanf("%d%*c",&vet[x]);
   } 
   questao03(vet,tamVetor);
   mostraVetor(vet,tamVetor);
}


