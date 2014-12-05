//Programa para procurar um Nó na Lista

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
	No *ptr_lista;
	int valor_buscar, resultado_busca;
	int i;

	imprimir_cabecalho();

	printf("Informe o valor que deseja saber se existe na lista:\n");
	scanf("%d",&valor_buscar);
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

	resultado_busca = buscar_elemento(ptr_lista, valor_buscar);

	if((resultado_busca == 1))
		printf("O valor %d foi encontrado na lista.\n",valor_buscar);
	else
		printf("O valor %d nao foi encontrado na lista.\n",valor_buscar);


	printf("\n");
	printf("Obrigado por utilizar o programa.\n");

	free(ptr_lista);

	return 0;
}