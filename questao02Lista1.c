//ANA LETICIA QUEST�O 2 LISTA DE EXERC�CIOS AED I ABRIL/2021

// PARTE A MODIFICAR
// INICIOFUNCAOALUNO

// ESCREVA NESSA �REA  A FUNCAO questao02 que deve atender ao enunciado do exerc�cio. 
// fun��o retorna void porque ela modifica diretamente o vetor e n�o precisa
void questao02(int vet[], unsigned tamVetor) {
	unsigned cont;
	
	for(cont = 0; cont < tamVetor; cont++) {
		if(vet[cont] <= 0) {
			vet[cont] = -2;
		}else if(vet[cont] >= 1 && vet[cont] <= 5) {
			vet[cont] = -1;
		}else {
			vet[cont] = 0;
		}
	}
	
}

//ENDFUNCAOALUNO

// ABAIXO CODIGO USADO PARA TESTE DA FUNCAO. N�O MOFIQUE!

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
   questao02(vet,tamVetor);
   mostraVetor(vet,tamVetor);
}



