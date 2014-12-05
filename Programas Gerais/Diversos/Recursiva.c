//Programa para implementação da equação recursiva do problema 2.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void imprimirCabecalho()
{
    printf("Universidade de Brasilia\n");
    printf("Aluno: Matheus Herlan dos Santos Ferraz\n");
    printf("Disciplina: Estrutura de Dados e Algoritmos\n\n");
}

float T(int n)
{
    if(n <= 1) {
        return 1;
    } else {
        return (((T(n/2)) + (sqrt(n))));
    }
}

int main(int argc, char *argv[])
{
    int numeroEntrada;
    float resultadoFuncao;

    imprimirCabecalho();

    printf("Informe um numero para entrada na funcao recursiva: \n");
    scanf("%d",&numeroEntrada);
    putchar('\n');

    resultadoFuncao = T(numeroEntrada);

    printf("O resultado retornado pela funcao para o numero [%d] e igual a %.2f.\n",numeroEntrada,resultadoFuncao);
    putchar('\n');

    printf("Obrigado por utilizar o programa!\n");
    putchar('\n');

    return 0;
}
