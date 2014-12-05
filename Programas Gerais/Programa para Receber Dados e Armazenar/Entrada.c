//Código Fonte do Programa para entrada dos Conjuntos Numéricos.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void cabecalho()
{
	printf("Universidade de Brasilia\n");
	printf("Docente : Nilton\n");
	printf("Disciplina : Estrutura de Dados e Algoritmos\n");
	printf("Aluno : Matheus Herlan dos Santos Ferraz\n\n");
}

void menuTiposNumericos()
{
	printf("--------------------------------------------------------\n");
	printf("|   Escolha um dos tipos de dados para armazenamento   |\n");
	printf("|                       1 - Inteiros                   |\n");
	printf("|                        2 - Reais                     |\n");
	printf("--------------------------------------------------------\n\n");
}

void menuOperacoes()
{
	printf("---------------------------------------------------------\n");
	printf("|                     soma - Soma                        |\n");
	printf("|                 subtracao - Subtracao                     |\n");
	printf("|                 MultPonto - MultPonto                     |\n");
	printf("|                  divisao - DivPonto                      |\n");
	printf("---------------------------------------------------------\n\n");
}
int main()
{
	cabecalho();

	menuTiposNumericos();

	menuOperacoes();

	FILE *arquivo;
	int i,j;//Contadores
	int quantidade;
	int tipoNumerico;
	char tipoOperacao [20];

	printf("Informe o numero inerente ao tipo de numeros que serao armazenados em cada lista : \n");
	scanf("%d",&tipoNumerico);
	putchar('\n');

	printf("Informe a quantidade de numeros que serao armazenados em cada lista : \n");
	scanf("%d",&quantidade);
	putchar('\n');

	printf("Informe a opcao de operacao desejada : \n");
	scanf(" %19[^\n]",tipoOperacao);

	arquivo = fopen("dadosT.txt","w");

	fprintf(arquivo, "%s\n",tipoOperacao);
	fprintf(arquivo, "Quantidade de numeros de cada lista : %d\n", quantidade);
	fprintf(arquivo, "Tipo de Arquivo : Entrada\n");

	if(tipoNumerico == 1)
{
		int *vet1;
		vet1 = (int*) calloc (quantidade,sizeof(int));

		int *vet2;
		vet2 = (int*) calloc (quantidade,sizeof(int));

		fprintf(arquivo, "Tipo de dados : Inteiros\n");

		for(i = 0; i < quantidade; i++)
	{
			printf("Informe o elemento [%d] da lista 1 : \n",i+1);
			scanf("%d",&vet1[i]);

			fprintf(arquivo, "%10i\n", vet1[i]);
	}

		fprintf(arquivo, "\n");

		for(j = 0; j < quantidade; j++)
	{
			printf("Informe o elemento [%d] da lista 2 : \n",j+1);
			scanf("%d",&vet2[j]);

			fprintf(arquivo, "%10i\n", vet2[j]);
	}

}

	if(tipoNumerico == 2)
{
		float *vet1;
		vet1 = (float*) calloc (quantidade,sizeof(float));

		float *vet2;
		vet2 = (float*) calloc (quantidade,sizeof(float));

		fprintf(arquivo, "Tipo de Dados : Reais\n");

		for(i = 0; i < quantidade; i++)
	{
			printf("Informe o elemento [%d] da lista 1 : \n",i+1);
			scanf("%f",&vet1[i]);

			fprintf(arquivo,"%8.2f\n",vet1[i]);
	}

        fprintf(arquivo, "\n");

		for(j = 0; j < quantidade; j++)
	{
			printf("Informe o elemento [%d] da lista 2 : \n",j+1);
			scanf("%f",&vet2[j]);

			fprintf(arquivo,"%8.2f\n",vet2[j]);
	}
}

	fclose(arquivo);

	return 0;
}

