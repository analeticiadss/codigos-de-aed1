//carrega lista em binario

void carregaListaEmBinario (char *nomeArquivo, tipoLista *pLista) {
    tipoAluno al;
    FILE *fp;

    fp = fopen(nomeArquivo, "r");

    fseek(fp, sizeof(tipoAluno), SEEK_SET); //navega no cursor
    fseek(fp, sizeof(tipoAluno), SEEK_CUR); //anda a partir da posição atual
    fseek (fp, sizeof(tipoAluno), SEEK_END); //movimentacao pro fim do arquivo

    while(fread(&al, sizeof(tipoAluno), 1, fp) == 1) {
        printf("posicao do cursor: %lu\n", ftell(fp));
        insereElementoInicioLista(pLista, &al);
    }
    fclose(fp);
}

//TAMANHO ARQUIVO, indica quantos bytes tenho no arquivo

int tamanhoArquivo(FILE *f) {
    struct stat buf;
    fstat(fileno(f), &buf);
    return buf.st_size;
}

int tamanhoArquivoAlternativa(FILE *f){
    unsigned long tmp, tamanho;

    tmp = ftell(f); // pra descobrir onde eu tava no arquivo
    fseek(f, 0, SEEK_END); //vai pra depois da posicao q acaba o arquivo
    tamanho = ftell(f);
    fseek(f, tmp, SEEK_SET);
    return tamanho;
}


tipoAluno * carregaVetorEmBinario (char *nomeArq) {
    tipoAluno al;
    FILE *fp;
    tipoAluno *tmp;
    unsigned long tamArq, numRegistros;

    fp = fopen(nomeArq, "r");

    if(fp == NULL) {
        printf("erro\n");
        exit(1);
    }

    tamArq = tamanhoArquivo(fp);

    tmp = (tipoAluno *) malloc(tipoAluno*tamArq);
    numRegistros = tamanho/sizeof(tipoAluno);
    fread(tmp, tamArq, 1, fp);
    //ou fread(tmp, sizeof(tipoAluno), numRegistros, fp);
    return tmp;
}
