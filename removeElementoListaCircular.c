//removendo elemento lista circular
//aula 64
//05/06/2021

int removeListaCircular (tipoListaCircular *pLista, char *nome) {
	tipoNo *aux, *seguinte;
	
	aux = pLista->atual;
	
	if(aux) {
		seguinte = aux->proximoLista;
		while(seguinte != aux) { // enquanto o seguinte for diferente de pLista->atual
			if(strcmp(seguinte->dado.nome, nome) == 0) {
				aux->proximoLista = seguinte->proximoLista;
				free(seguinte);
				return 1;
			}
			aux = seguinte; //aux = aux->prox
			seguinte = seguinte->proximoLista;
		}
		if(strcmp(seguinte->dado.nome, nome) == 0) {
			/* se o elemento que queremos remover é o unico da lista*/
			if(aux == seguinte) { //pLista->atual == pLista->atual->prox
				pLista->atual = NULL; //removendo, o &atual == NULL <-> lista vazia
			}
			else { //se o elemento que queremos remover é o atual
				aux->proximoLista = seguinte->proximoLista;
				pLista->atual = seguinte->proximoLista; //atualiza o atual
			}
			free(seguinte);
			return 1;
		}
		
	}
	return 0;
}
