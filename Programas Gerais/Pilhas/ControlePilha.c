#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Lib_Pilha.h"

main (){
	
	int escolha_opcao, quant_bytes, endereco_memo;

	TPilha *ptr_pilha;
	
	ptr_pilha = (TPilha*)malloc(sizeof(TPilha));
	
	esvaziar_inicializar_pilha(ptr_pilha);

	imprimir_cabecalho();
	
	do {
		
		imprimir_menu();

		printf("Informe o numero inerente a opcao desejada: \n");
		scanf("%d", &escolha_opcao);
		putchar('\n');
		
		switch(escolha_opcao)
		{
			case 1:
			{
				printf("Entre com o Tamanha do Arquivo: \n");
				scanf("%d", &quant_bytes);
				printf("Entre com o Endereco: \n"); 
				scanf("%d", &endereco_memo);
				empilhar_elemento(ptr_pilha, quant_bytes, endereco_memo);
				break;
			}
			
			case 2:
			{
				TElemento *ptr_elemento;
				ptr_elemento = desempilhar_elemento(ptr_pilha);
				printf("O topo da pilha foi atualizado.\n\n");
				break;
			}
			case 3:
			{
				if (verificar_se_esta_vazia(ptr_pilha)) {
					printf("Fim do programa.\n");
					exit(EXIT_FAILURE);
				} else {
					TElemento *ptr_elemento;
					int quantidade_bytes;
					int endereco_memoria;

					ptr_elemento = consultar_topo(ptr_pilha);
					quantidade_bytes = ptr_elemento->quantidade_bytes;
					endereco_memoria = ptr_elemento->endereco_memoria;

					printf("O ultimo elemento armazenado na pilha de controle de chamadas foi: %d - bytes %d - endereco.\n\n",quantidade_bytes, endereco_memoria);
					putchar('\n');
					break;
				}
			}
		}
	}while((escolha_opcao == 1) || (escolha_opcao == 2) || (escolha_opcao == 3));

	printf("\n");
	printf("Obrigado por utilizar o programa.\n");
	putchar('\n');

	free(ptr_pilha);

	return 0;
}