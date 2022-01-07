void insereElementoNoFinal(tipoListaDeProdutos *pl, tipoDado d) {
	tipoNo *aux, *no;
	
	no = (tipoNo *) malloc(sizeof(tipoNo));
	no->dados = d;
	no->prox = NULL;
	
	aux = pl->prim;
	if(aux)	{
		while(aux->prox) {
			aux = aux->prox;
		}
		aux->prox = no;
	}
	else {
		pl->prim = no;
	}
}

//COM PONTEIRO PRA ULT

	
	if(p1->ult) { // se pl->ult != NULL <-> tem mais de um elemento na lista
		pl->ult->prox = no;
	}
	else { // só tem um elemento na lista
		p1->prim = no;
	}
	pl->ult = no;
