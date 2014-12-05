//Programa para verificar se uma palavra é palíndromo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimirCabecalho()
{
    printf("Universidade de Brasilia\n");
    printf("Aluno: Matheus Herlan dos Santos Ferraz\n");
    printf("Disciplina: Estrutura de Dados e Algoritmos\n\n");
}

int verificarPalindromo(char *palavra)
{
    int i, j;
    for(i = 0, j < (strlen(palavra)-1); i < j; i ++, j--)
        if(palavra[i] != palavra[j])
            return 0;
    return 1;
}

int main(int argc, char *argv[])
{
    char palavraAVerificar;
    int resultadoVerificacao;

    imprimirCabecalho();

    printf("Informe a palavra desejada para verificar se e um palindromo: \n");
    scanf(" %20[^\n]",palavraAVerificar);
    putchar('\n');

    resultadoVerificacao = verificarPalindromo(palavraAVerificar);

    if(resultadoVerificacao == 0) {
        printf("A palavra informada nao e uma palindromo.\n");
    } else {
        printf("A palavra informada e um palindromo.\n");
    }

    printf("\n");
    printf("Obrigado por utilizar o programa.\n\n");

    return 0;
}
