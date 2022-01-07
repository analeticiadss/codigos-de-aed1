//aula 73: busca binaria em arquivos

unsigned tamanhoArquivo (FILE *fp) {
    struct stat buf;
    fstat(fileno(fp), &buf);
    return buf.st_size;
}

void buscaBinaria(FILE *fp, unsigned chave, tipoAluno *aluno) {
    long int inicio, fim, meio;
    inicio = 0;
    fim = (tamanhoArquivo(fp)/sizeof(tipoAluno))-1;

    while(inicio <= fim) {
        meio = (inicio+fim)/2;
        fseek(fp, meio*sizeof(tipoAluno), SEEK_SET);
        fread(al, sizeof(tipoAluno), 1, fp);
        if(chave > aluno->id) {
            inicio = meio+1;
        }
        else if(chave < aluno->id) {
            fim = meio-1;
        }
        else {
            return 1;
        }
    }
    return 0;
}
