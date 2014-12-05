//Programa para utilização das funções e procedimentos da biblioteca de manipulação de matrizes.

#include <stdio.h>
#include <stdlib.h>
#include "Matrizes.h"

int main(int argc, char *argv[]) {

    int l1, c1, l2, c2;
    int **matriz1, **matriz2, **matriz3;
    int i,j;

    printf("Bem vindo ao programa de soma matrizes. Informe os dados solicitados.\n");
    putchar('\n');

    printf("Informe o numero de linhas da matriz 1: \n");
    scanf("%d",&l1);
    putchar('\n');

    printf("Informe o numero de colunas da matriz 1: \n");
    scanf("%d",&c1);
    putchar('\n');

    do {
        printf("Informe o numero de linhas da matriz 2: \n");
        scanf("%d",&l2);
        putchar('\n');
    }while(l2 != l1);

    do {
        printf("Informe o numero de colunas da matriz 2: \n");
        scanf("%d",&c2);
        putchar('\n');
    }while(c2 != c1);

    matriz1 = alocaMemoria(l1,c1);
    matriz2 = alocaMemoria(l2,c2);
    matriz3 = alocaMemoria(l1,c1);

    printf("Agora, informe os dados da primeira matriz.\n");
    putchar('\n');

    for(i = 0; i < l1; i ++) {
        for(j = 0; j < c1; j ++) {
            printf("Informe o elemento [%d][%d] da matriz 1: \n",i+1,j+1);
            scanf("%d",&matriz1[i][j]);
        }
    }

    printf("\n\n");
    printf("Agora, informe os dados da segunda matriz.\n");
    putchar('\n');

    for(i = 0; i < l1; i ++) {
        for(j = 0; j < c1; j ++) {
            printf("Informe o elemento [%d][%d] da matriz 2: \n",i+1,j+1);
            scanf("%d",&matriz2[i][j]);
        }
    }

    for(i = 0; i < l1; i ++) {
        for(j = 0; j < c1; j ++) {
            matriz3[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    printf("Apresentacao das matrizes.\n");
    putchar('\n');

    for(i = 0; i < l1; i ++) {
        for(j = 0; j < c1; j ++) {
            printf("%d\t",matriz1[i][j]);
        }
    }

    printf("\n\n");

    for(i = 0; i < l1; i ++) {
        for(j = 0; j < c1; j ++) {
            printf("%d\t",matriz2[i][j]);
        }
    }

    printf("\n\n");
    printf("A soma entre as matrizes informadas e igual a: \n");
    putchar('\n');

    for(i = 0; i < l1; i ++) {
        for(j = 0; j < c1; j ++) {
            printf("%d\t",matriz3[i][j]);
        }
    }

    printf("\n\n");
    printf("Obrigado por utilizar o programa!\n");
    putchar('\n');

    desalocaMemoria(l1,c1,matriz1);
    desalocaMemoria(l2,c2,matriz2);
    desalocaMemoria(l1,c1,matriz3);

    return 0;
}
