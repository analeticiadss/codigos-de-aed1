//utilizando do...while
#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "");
	int n, maior, quantidade;
	
	printf("quantos n�meros voc� quer testar? ");
	scanf("%d%*c", &quantidade);
	
	printf("digite um n�mero: ");
	scanf("%d%*c", &n);
	maior = n;
	
	if(quantidade > 1){
		do{			
			printf("digite um n�mero: ");
			scanf("%d%*c", &n);
			if(n > maior){
				maior = n;
			}
			quantidade--;
		}while(quantidade > 1);
	}
	
	
	printf("o maior n�mero digitado foi: %d\n", maior);
	
	return 0;
}
