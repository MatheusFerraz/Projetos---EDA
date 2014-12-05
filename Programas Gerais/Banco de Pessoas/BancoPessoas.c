//Programa para gerenciamento de um banco de pessoas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LibListasDupEncadeadas.h"

int main(int argc, char *argv[])
{
	No *ptr_lista;
	int escolha;

	ptr_lista = (No*)malloc(sizeof(No));

	iniciar_lista(ptr_lista);

	imprimir_cabecalho();
	
	do {
		imprimir_menu();

		printf("Informe sua opcao: \n");
		scanf("%d",&escolha);
		putchar('\n');

		switch(escolha)
		{
			case 1:
			{
				int codigo;
				char *nome, *telefone;
				nome = (char*)calloc(30,sizeof(char));
				telefone = (char*)calloc(11,sizeof(char));

				printf("Entre com o codigo da pessoa: \n");
				scanf("%d", &codigo);
				printf("Entre com o nome da pessoa: \n");
				scanf("%s",nome);
				printf("Entre com o telefone da pessoa: \n");
				scanf("%s",telefone);
				printf("\n\n");

				ptr_lista = inserir_cabeca(ptr_lista, codigo, nome, telefone);
				break;
			}
			case 2:
				printf("Seu banco de pessoas.\n\n");

				imprimir_lista(ptr_lista);
				printf("\n\n");
				break;
			case 3:
			{
				int chave_exclusao;
				No *ptr_lista_final;

				printf("Informe o codigo inerente a pessoa que deve ser excluida: \n");
				scanf("%d",&chave_exclusao);

				ptr_lista_final = excluir_elemento(ptr_lista,chave_exclusao);

				printf("Pessoa com codigo [%d] excluida com sucesso da lista.\n",chave_exclusao);
				printf("\n\n");
				break;
			}
		}
	} while((escolha == 1) || (escolha == 2) || (escolha == 3));

	printf("\n\n");

	printf("Obrigado por utilizar o programa.\n");
	putchar('\n');

	free(ptr_lista);

	return 0;
}