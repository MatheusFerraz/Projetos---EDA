#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Lib_Fila.h"

main (){
	
	int escolha_opcao;
	TFila *ptr_fila;
	
	ptr_fila = (TFila*)malloc(sizeof(TFila));
	
	esvaziar(ptr_fila);

	imprimir_cabecalho();
	
	do {
		
		imprimir_menu();

		printf("Informe o numero inerente a operacao desejada.\n");
		scanf("%d", &escolha_opcao);
		putchar('\n');
		
		switch(escolha_opcao)
		{
			case 1:
			{
				if(ptr_fila->tamanho <= 5){
				
					TElemento elemento;
					int resultado_verificacao;
					
					printf("Entre com a senha do cliente: \n");
					scanf(" %5[^\n]", elemento.senha_cliente);
					printf("Entre com a opcao de atendimento: \n");
					scanf(" %c", &elemento.tipo_atendimento);
					
					resultado_verificacao = enfileirar(ptr_fila, &elemento);
				
				} else {
					printf("Nao e mais possivel enfileirar, pois a fila ja esta cheia.\n");
				}
				break;
			}
				
			case 2:
			{
				TElemento *ptr_elemento;
				
				ptr_elemento = desenfileirar(ptr_fila);
				printf("\nO elemento subseguinte ao primeiro tornara a ser o primeiro.\n");
				break;
			}
				
			case 3:
			{
				esvaziar(ptr_fila);

				printf("A fila foi esvaziada.\n");
				break;
			}
		}
	}while(escolha_opcao != 4);

	printf("\n");
	printf("Obrigado por utilizar o programa.\n");
	putchar('\n');

	free(ptr_fila);

	return 0;
}