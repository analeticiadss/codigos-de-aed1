//terceira prova - 07/05/2021
//ana leticia

#include <stdio.h>
#include <string.h>


typedef struct tipoCidade {
  char designacao[100];
  unsigned populacao;
  float pib;
  float arrecadacaoAnual;
} tipoCidade;

// ESQUEVA AQUI AS DUAS FUNCOES QUE ESTAO FALTANDO. 
//NAO MODIFIQUE O CÓDIGO ANTES OU DEPOIS DESTE TRECHO.

int buscaBinaria (tipoCidade vet[], unsigned tamVet, char nome[]) {
	unsigned cont;
	int inicio, meio, fim;
	
	inicio = 0;
	fim = tamVet-1;
	
	while(inicio <= fim) {
		meio = (inicio+fim)/2;
		if(strcmp(nome, vet[meio].designacao) > 0) {
			inicio = meio+1;
		} else if(strcmp(nome, vet[meio].designacao) < 0) {
			fim = meio -1;
		} else {
			return meio;
		}
	}
	return -1;
}

void ordenaCidades(tipoCidade vet[], unsigned tamVet) {
	int i, j;
	tipoCidade pivot;
	
	for(i = 1; i < tamVet; i++) {
		pivot = vet[i];
		j = i-1;
		
		while(j >= 0 && strcmp(vet[j].designacao, pivot.designacao) > 0) {
			vet[j+1] = vet[j];
			j--;
		}
		vet[j+1] = pivot;
	}
}

// NAO MODIFIQUE O RESTANTE DO PROGRAMA:


void mostraCidade(tipoCidade cidade) {
  printf("Designação : %s\n",cidade.designacao);
  printf("Populacao  : %d\n",cidade.populacao);
  printf("Pib:       : R$ %.2f\n",cidade.pib);
  printf("Arrecadação: R$ %.2f\n",cidade.arrecadacaoAnual);
}

void leCidades(tipoCidade v[], unsigned tam) {
  int x;

  for(x = 0; x< tam; x++) {
    scanf("%[^\n]%*c",v[x].designacao);
    scanf("%d%*c",&v[x].populacao);
    scanf("%f%*c",&v[x].pib);
    scanf("%f%*c",&v[x].arrecadacaoAnual);
  }
}



int main() {
  int pos;
  char nome[100];
  unsigned tam;

  scanf("%d%*c",&tam);

  tipoCidade v[tam];

  leCidades(v,tam);
  ordenaCidades(v,tam);

  scanf("%[^\n]%*c",nome);

  pos = buscaBinaria(v,tam,nome);
  if(pos != -1) {
    mostraCidade(v[pos]);
  }
  else {
    printf("%s Não consta na base de dados\n",nome);
  }
  scanf("%[^\n]%*c",nome);
  
  pos = buscaBinaria(v,tam,nome);
  if(pos != -1) {
    mostraCidade(v[pos]);
  }
  else {
    printf("%s Não consta na base de dados\n",nome);
  }

  printf("\nBase de Dados Ordenada:\n");
  for(pos = 0; pos < tam; pos++) {
    mostraCidade(v[pos]);

  }


}

