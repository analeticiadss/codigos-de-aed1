//questão 04 - aed I - lista I
//13/04/2021


int questao04(int vet[],unsigned tamVetor) {
	int menorAteEntao;
	unsigned cont;
	
	menorAteEntao = vet[0];
	for(cont = 1; cont < tamVetor; cont++) {
		if(vet[cont] >= menorAteEntao) {
			menorAteEntao = vet[cont]; 
		}
		else {
			return 0;
		}
	}
}

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
   if(questao04(vet,tamVetor)) {
     printf("VERDADEIRO\n");
   }
   else {
     printf("FALSO\n");
   }
   
}

