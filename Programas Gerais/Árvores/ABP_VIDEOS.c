#include <stdio.h>
#include <stdlib.h>
#include "LIB_ABP.h"
#define MAXIMO 40

int main(int argc, char *argv[])
{
	TNo *ptr_arvore;
	char nome_arquivo[MAXIMO];
	int escolha_opcao;

	imprimir_cabecalho();
	
	printf("Entre com o nome do arquivo que sera lido: \n");
	scanf("%s", nome_arquivo);

	do
	{
		imprimir_menu();

		printf("Informe o numero inerente a opcao desejada de operacao: \n");
		scanf("%d",&escolha_opcao);

		switch(escolha_opcao)
		{
			case 1:
				ler_arquivo(nome_arquivo, &ptr_arvore);
				printf("Arquivo lido e armazenado com sucesso.\n\n");
				break;
			case 2:
			{
				char codigo_buscar[7];
				printf("Informe o codigo do filme que deseja buscar (Letras maiúsculas): \n");
				scanf("%s",codigo_buscar);
				imprimir_informacoes(ptr_arvore, codigo_buscar);
				break;
			}	
			case 3:
				gravar_saida(nome_arquivo, ptr_arvore);
				printf("\nArquivo Videos_Codigo.txt gerado com sucesso.\n");
				break;
		}
	}while((escolha_opcao == 1) || (escolha_opcao == 2) || (escolha_opcao == 3));

	printf("\n\n");
	printf("Obrigado por utilizar o programa.\n");
	putchar('\n');

	free(ptr_arvore);

	return 0;	
}