//prova 2
//30/04/2021 - ana leticia

#include <stdio.h>

int LD(float vet1[], float vet2[], unsigned tamVet) {
	unsigned cont;
	float div;
	
	div = vet1[0]/vet2[0];
	
	for(cont = 0; cont < tamVet; cont++) {
		if(div*vet2[cont] != vet1[cont]) {
			return 0;
		}
	}
	return 1;
}


int main() {
   unsigned tamVetor;
   unsigned x;

   scanf("%u%*c",&tamVetor);
   float vet1[tamVetor], vet2[tamVetor];

   for(x = 0; x< tamVetor; x++) {
     scanf("%f%*c",&vet1[x]);
   }
   for(x = 0; x< tamVetor; x++) {
     scanf("%f%*c",&vet2[x]);
   }	
	
	
   if(LD(vet1, vet2, tamVetor)) {
     printf("1\n");
   }
   else {
     printf("0\n");
   }

}

