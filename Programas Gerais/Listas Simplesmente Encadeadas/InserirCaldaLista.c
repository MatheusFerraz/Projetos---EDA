//Programa para inserir um Nó na calda da Lista

#include <stdio.h>
#include <stdlib.h>
#include "LibListasEncadeadas.h"

void imprimir_cabecalho()
{
	printf("Universidade de Brasilia\n");
	printf("Curso: Engenharia de Software\n\n");
}

int main(int argc, char *argv[])
{
	No *ptr_lista, *ptr_lista_final;
	int valor_inserir;
	int i;

	imprimir_cabecalho();

	printf("Informe o valor que deseja inserir na calda da lista:\n");
	scanf("%d",&valor_inserir);
	putchar('\n');

	ptr_lista = (No*)malloc(sizeof(No));
	iniciar_lista(ptr_lista);

	for(i = 0; i < 5; i ++)
	{
		inserir_cabeca(ptr_lista, i);
	}

	printf("Lista com os valores preenchidos pelo laco.\n");
	putchar('\n');

	imprimir_lista(ptr_lista);
	printf("\n");

	printf("A lista, com o valor inserido na calda, fica da seguinte maneira: \n");
	putchar('\n');

	ptr_lista_final = inserir_calda(ptr_lista,valor_inserir);

	imprimir_lista(ptr_lista_final);

	printf("\n");

	free(ptr_lista);

	return 0;
}