//prova I- 23/04/2021
#include<stdio.h>


int concava(float vet[], unsigned tamVetor) {
	float maior, menor;
	unsigned cont, cont2;
	unsigned meioVetor = tamVetor/2;
	
	maior = vet[0];
	menor = vet[meioVetor];
	for(cont = 1; cont < meioVetor; cont++) {
		if(maior < vet[cont]) {
			return 0;
		}
	}
	for (cont2 = meioVetor; cont2 < tamVetor; cont2++) {
		if(vet[cont2] < menor) {
				return 0;
		}
	}
	return 1;
}



int main() {
   unsigned tamVetor;
   unsigned x;

   scanf("%u%*c",&tamVetor);
   float vet[tamVetor];

   for(x = 0; x< tamVetor; x++) {
     scanf("%f%*c",&vet[x]);
   }
   if(concava(vet,tamVetor)) {
     printf("1\n");
   }
   else {
     printf("0\n");
   }

}
