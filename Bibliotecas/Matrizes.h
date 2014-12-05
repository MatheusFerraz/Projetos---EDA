//Funções e Procedimentos para manipulação de matrizes.

#include <stdio.h>
#include <stdlib.h>

//Função para realização de alocação de memória
int **alocaMemoria(int lines, int columns) {

  int **matriz;
  int i;

  if ((lines < 1) || (columns < 1)) {
    printf ("** Erro: Parametro invalido **\n");
    return (NULL);
  }

  matriz = (int**)malloc(lines*sizeof(int*));

  if (matriz == NULL) {
    printf ("** Erro: Memoria Insuficiente **");
    return (NULL);
  }

  for(i = 0; i < lines; i ++) {
      matriz[i] = (int*)malloc(columns*sizeof(int));

      if (matriz[i] == NULL) {
        printf ("** Erro: Memoria Insuficiente **");
        return (NULL);
      }
  }
  return (matriz);
}


//Função para realizar desalocação de memória
int **desalocaMemoria(int lines, int columns, int **matriz) {

  int  i;
  if (matriz == NULL)
	  return (NULL);

  if (lines < 1 || columns < 1) {
    printf ("** Erro: Parametro invalido **\n");
    return (matriz);
  }

  for (i = 0; i < lines; i ++) {
    free (matriz[i]);
  }

  free (matriz);

  return (NULL);
}
