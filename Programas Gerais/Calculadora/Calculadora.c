//Programa Prático de EDA - Ponteiro para Função

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void cabecalho()
{
	printf("Universidade de Brasilia\n");
	printf("Aluno : Matheus Herlan dos Santos Ferraz\n");
	printf("Curso : Engenharia de Software\n\n");
}

void imprimirMenu()
{
	printf("------------------------------------------------\n");
	printf("|     Bem vindo ao Programa da Calculadora     |\n");
	printf("|                 1 - Soma                     |\n");
	printf("|               2 - Subtracao                  |\n");
	printf("|                3 - Produto                   |\n");
	printf("|                4 - Divisao                   |\n");
	printf("------------------------------------------------\n\n");
}

int calcSoma(int n1, int n2)
{
	return (n1 + n2);
}

int calcSubtracao(int n1, int n2)
{
	if(n1 > n2)
	return (n1 - n2);
	else
	return (n2 - n2);
}

int calcProduto(int n1, int n2)
{
	return (n1 * n2);
}

int calcDivisao(int n1,int n2)
{
	return (n1 / n2);
}

int main()
{

	cabecalho();

	imprimirMenu();

	int num1,num2,escolha,soma,diferenca,produto,divisao;
	int (*ptr)(int n1, int n2);

	printf("Informe o primeiro numero para realizacao da operacao desejada : \n");
	scanf("%d",&num1);
	putchar('\n');

	printf("Informe o segundo numero para realizacao da operacao desejada : \n");
	scanf("%d",&num2);
	putchar('\n');

	printf("Informe o numero inerente a operacao desejada : \n");
	scanf("%d",&escolha);
	putchar('\n');

	switch(escolha)
{
		case 1 : 
			ptr = calcSoma;
			soma = ptr(num1,num2);
			printf("A soma entre os numeros informados e igual a %d.\n",soma); break;
	
		case 2 : 
			ptr = calcSubtracao;
			diferenca = ptr(num1,num2);
			printf("A diferenca entre os numeros informados e igual a %d.\n",diferenca); break;
		case 3 : 
			ptr = calcProduto;
			produto = ptr(num1,num2);
			printf("O produto entre os numeros informados e igual a %d.\n",produto); break;
		case 4 : 
			ptr = calcDivisao;
			divisao = ptr(num1,num2);
			printf("A divisao entre os dois numeros e igual a %d.\n",divisao); break;
		default : printf("O usuario nao escolheu nenhuma operacao valida!\n");
}

	return 0;

}
