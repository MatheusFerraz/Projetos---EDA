//Programa para inserir um elemento antes de uma chave na Lista

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
	int valor_inserir, valor_chave;
	int i;

	imprimir_cabecalho();

	printf("Informe o valor que deseja inserir na lista:\n");
	scanf("%d",&valor_inserir);
	putchar('\n');

	printf("Informe a chave do no onde o elemento sera inserido antes: \n");
	scanf("%d",&valor_chave);
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

	printf("Lista com o valor %d incluso antes do %d.\n",valor_inserir, valor_chave);
	putchar('\n');

	ptr_lista_final = incluir_elemento(ptr_lista, valor_chave, valor_inserir);

	imprimir_lista(ptr_lista_final);
	printf("\n");

	printf("Obrigado por utilizar o programa.\n");
	printf("\n");

	free(ptr_lista);

	return 0;
}