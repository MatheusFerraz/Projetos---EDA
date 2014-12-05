//Programa para processar arquivos com estrutura do tipo MovimentoVendas.txt

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

void imprimirCabecalho()
{
    printf("Universidade de Brasilia\n");
    printf("Professor: Nilton\n");
    printf("Disciplina: Estrutura de Dados e Algoritmos\n");
    printf("Aluno: Matheus Herlan dos Santos Ferraz\n\n");
}

int main()
{
    typedef struct {
        int codigoVendedor;
        float salarioBaseVendedor;
        float valorDeVendasVendedor;
        float comissaoVendedor;
        float salarioFinalVendedor;
    } Vendedor;

    FILE *arquivoEntrada, *arquivoSaida;
    Vendedor *vendedores;
    int i;
    int qtdVendedores = 50;
    char camposcabecalho[60];
    char nomeArquivoEntrada[61];
    char nomeArquivoSaida[61];
    float mediaVendas;

    imprimirCabecalho();

    printf("Bem vindo ao sistema de processamento de arquivos de venda da empresa.\n");
    putchar('\n');

    printf("Informe o nome do arquivo que contem o codigo, salario base e valor de vendas de cada vendedor, incluindo a extensao (.txt por exemplo):\n");
    scanf(" %60[^\n]",nomeArquivoEntrada);
    putchar('\n');

    printf("Informe o nome do arquivo de saida, que contera as informacoes da folha de pagamento, incluindo a extensao (.txt por exemplo): \n");
    scanf(" %60[^\n]",nomeArquivoSaida);
    putchar('\n');

    arquivoSaida = fopen(nomeArquivoSaida, "w");
    arquivoEntrada = fopen(nomeArquivoEntrada, "r");
    if (arquivoEntrada == NULL )
    {
        puts ("Não foi possivel abrir o arquivo!!!");
        exit(0) ;
    }

    fscanf(arquivoEntrada, "Codigo %[^\n]", &camposcabecalho);

    vendedores = (Vendedor*)calloc(qtdVendedores, sizeof(Vendedor));

    for(i = 0; i < qtdVendedores; i ++)
    {
        fscanf(arquivoEntrada, "%d %f %f",&vendedores[i].codigoVendedor, &vendedores[i].salarioBaseVendedor, &vendedores[i].valorDeVendasVendedor);
        printf("%d %.2f %.2f\n",vendedores[i].codigoVendedor,vendedores[i].salarioBaseVendedor,vendedores[i].valorDeVendasVendedor);
    }

    float soma = 0;
    for(i = 0; i < qtdVendedores; i ++)
    {
        soma += vendedores[i].valorDeVendasVendedor;
    }

    mediaVendas = (soma/qtdVendedores);
    printf("%f",mediaVendas);

    for(i = 0; i < qtdVendedores; i ++)
    {
        if(((vendedores[i].valorDeVendasVendedor) < mediaVendas) || ((vendedores[i].valorDeVendasVendedor)== mediaVendas)) {
            vendedores[i].comissaoVendedor = (0.03*vendedores[i].valorDeVendasVendedor);
        } else {
            vendedores[i].comissaoVendedor = (0.05*vendedores[i].valorDeVendasVendedor);
        }
    }

    for(i = 0; i < qtdVendedores; i ++)
    {
        vendedores[i].salarioFinalVendedor = (vendedores[i].comissaoVendedor + vendedores[i].salarioBaseVendedor);
    }

    int contFinal, cont;
	for(contFinal = qtdVendedores-1; contFinal > 0; contFinal --)
	{
		for(cont = 0; cont < contFinal; cont ++)
		{
			if(vendedores[cont].codigoVendedor > vendedores[cont + 1].codigoVendedor){
				Vendedor temp = vendedores[cont];
				vendedores[cont] = vendedores[cont + 1];
                vendedores[cont + 1] = temp;
			}
		}
	}

    fprintf(arquivoSaida, "Informações de folha de pagamento dos vendedores.\n");
    for(i = 0; i < qtdVendedores; i ++)
    {
        fprintf(arquivoSaida, "%10i %8.2f %8.2f %8.2f %8.2f\n",vendedores[i].codigoVendedor, vendedores[i].salarioBaseVendedor, vendedores[i].valorDeVendasVendedor, vendedores[i].comissaoVendedor, vendedores[i].salarioFinalVendedor);
    }

    fclose(arquivoEntrada);
    fclose(arquivoSaida);
    free(vendedores);

    return 0;
}
