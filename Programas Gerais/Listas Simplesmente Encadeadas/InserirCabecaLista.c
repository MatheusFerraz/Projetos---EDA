//Programa para inserção de um novo Nó na cabeça da Lista

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
	int valor_insercao;
	int i;

	imprimir_cabecalho();

	printf("Informe o valor que deseja inserir na cabeca da lista:\n");
	scanf("%d",&valor_insercao);
	putchar('\n');

	ptr_lista = (No*)malloc(sizeof(No));
	iniciar_lista(ptr_lista);

	for(i = 0; i < 5; i ++)
	{
		inserir_cabeca(ptr_lista, i);
	}

	printf("Ate o presente momento, a lista possui os seguintes valores:\n");
	putchar('\n');

	imprimir_lista(ptr_lista);

	printf("Com o valor que voce informou, a lista esta da seguinte maneira:\n");
	putchar('\n');

	inserir_cabeca(ptr_lista,valor_insercao);

	imprimir_lista(ptr_lista);

	printf("Obrigado por utilizar o programa.\n");
	putchar('\n');

	free(ptr_lista);

	return 0;
}