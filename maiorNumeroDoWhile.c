//utilizando do...while
#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "");
	int n, maior, quantidade;
	
	printf("quantos números você quer testar? ");
	scanf("%d%*c", &quantidade);
	
	printf("digite um número: ");
	scanf("%d%*c", &n);
	maior = n;
	
	if(quantidade > 1){
		do{			
			printf("digite um número: ");
			scanf("%d%*c", &n);
			if(n > maior){
				maior = n;
			}
			quantidade--;
		}while(quantidade > 1);
	}
	
	
	printf("o maior número digitado foi: %d\n", maior);
	
	return 0;
}
