//AULA 19 - AED I - Criando registros
//Ana Let�cia - 07/04/2021

#include <stdio.h>
#include <locale.h>

//estrutura de dados para guardar informa��es
	struct tipoFuncionario {
		char nome[30]; //cada vari�vel � um campo da minha struct
		float salario; //um outro campo com salario
		char funcao[40];
		char setor[30];
	};
	
	struct tipoEspecieArvore {
		char nomeCientifico[30];
		char nomePopular[30];
	};
	
	/* posso criar um typedef que vai criar uma vari�vel, ent�o
	n�o vou precisar criar uma vari�vel no int main */
	typedef struct tipoArvoreCatalogada {
		struct tipoEspecieArvore especie;
		unsigned short int idade;
		float altura;
		float diametroTronco;
	} tipoArvoreCatalogada; //nome da vari�vel precisa ser igual ao nome do novo tipo
	

int main() {
	setlocale(LC_ALL, "");
	struct tipoFuncionario x, y, z;
	 
	/*x ocupa um local na mem�ria, 
	ent�o se eu uso x, eu t� botando dados de um funcion�rio em x;
	em y, eu boto os dados de outro funcionario e assim por diante */
	
	printf("qual o nome do funcionario? ");
	scanf("%[^\n]%*c", x.nome); 
	/*n�o preciso botar o & porque � um vetor e o nome da vari�vel (x.nome)
	j� � o endere�o do vetor */
	
	printf("quanto o funcionario recebe? ");
	scanf("%f%*c", &x.salario); //precisa do endere�o por ser tipo float
	
	printf("qual a fun��o do funcionario? ");
	scanf("%[^\n]%*c", x.funcao);
	
	printf("o funcionario trabalha em que setor? ");
	scanf("%[^\n]%*c", x.setor);
	
	//copiar struct: y = x (y recebe *todos* os dados de x)
	
	printf("\nO formulario da(o) funcionario %s eh:\n%s\n%.2f\n%s\n%s\n\n", x.nome, x.nome, x.salario, x.funcao, x.setor);
	
	tipoArvoreCatalogada minhaArvore;
	
	printf("nome cientifico da arvore: ");
	scanf("%[^\n]%*c", minhaArvore.especie.nomeCientifico);
	
	printf("nome popular: ");
	scanf("%[^\n]%*c", minhaArvore.especie.nomePopular);
	
	printf("A arvore catalogada tem o nome cient�fico %s e nome popular como %s\n", minhaArvore.especie.nomeCientifico, minhaArvore.especie.nomePopular);
	
	return 0;
}
