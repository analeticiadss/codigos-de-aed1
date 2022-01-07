//mergesort com ponteiros

void mergeSort(float vet[], unsigned tamVet) {
	float *vetAux;
	
	vetAux = (float*) malloc(sizeof(float)*tamVet);
	mergeSortR(vet, vetAux, 0, tamVet-1);
	free(vetAux);
}
