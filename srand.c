//aula 38 - rand e srand - numeros aleatorios

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
	
	srand(10); //semente
	srand( time(NULL) ); //gera numeros de segundos desde 1970
	
	
	unsigned cont;
	for(cont = 0; cont < 10; cont++) {
		printf("%d ", rand());
	}

}
