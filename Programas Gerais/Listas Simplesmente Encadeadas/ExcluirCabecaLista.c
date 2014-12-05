//Programa para exclusão de um nó na cabeça da Lista

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
	No *ptr_lista, *novo_ptr_lista;
	int i;

	imprimir_cabecalho();

	ptr_lista = (No*)malloc(sizeof(No));
	iniciar_lista(ptr_lista);

	for(i = 0; i < 5; i ++)
	{
		inserir_cabeca(ptr_lista, i);
	}

	printf("Ate o presente momento, a lista possui os seguintes valores:\n");
	putchar('\n');

	imprimir_lista(ptr_lista);

	novo_ptr_lista = excluir_cabeca(ptr_lista);

	printf("Apos chamada do metodo de exclusao da cabeca, a lista esta da seguinte maneira:\n");
	putchar('\n');

	imprimir_lista(novo_ptr_lista);

	printf("Obrigado por utilizar o programa.\n");
	putchar('\n');

	free(ptr_lista);
	free(novo_ptr_lista);

	return 0;
}