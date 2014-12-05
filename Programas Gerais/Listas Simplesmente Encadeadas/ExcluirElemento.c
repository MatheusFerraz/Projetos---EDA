//Programa para excluir um elemento na Lista

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
	int valor_chave;
	int i;

	imprimir_cabecalho();

	printf("Informe a chave que representa o no a ser excluido: \n");
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

	printf("Lista com o valor %d excluido.\n",valor_chave);
	putchar('\n');

	ptr_lista_final = excluir_elemento(ptr_lista, valor_chave);

	imprimir_lista(ptr_lista_final);
	printf("\n");

	printf("Obrigado por utilizar o programa.\n");
	printf("\n");

	free(ptr_lista);

	return 0;
}