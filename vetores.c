// VETORES - AED I - 07/04/2021 ANA LET�CIA

#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "");
	int vetInt[5], i;
	
	for(i = 0; i < 5; i++) {
		printf("entre com um valor: ");
		scanf("%d%*c", &vetInt[i]);
	}
	
	printf("\n");
	
	for(i = 0; i < 5; i++){
		printf("o n�mero da posi��o %d �: %d\n", i, vetInt[i]);
	}
	
	return 0;
}
