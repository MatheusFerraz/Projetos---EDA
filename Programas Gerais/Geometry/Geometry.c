#include <stdio.h>
#include <stdlib.h>
#include "Geometry.h"

void print_options_menu()
{
	printf("--  Escolha uma opcao a seguir --\n");
	printf("--  1 - Area de um Triangulo ----\n");
	printf("--  2 - Area de um Retangulo ----\n");
	printf("--  3 - Area de um Quadrado -----\n");
	printf("--  4 - Area de um Trapezio -----\n");
	printf("--  5 - Area de um Circulo ------\n\n");
}

int main()
{
	float (*array_pointer_vector[])(float *measures) = {calculate_triangle_area, calculate_rectangle_area, calculate_square_area, calculate_trapeze_area, calculate_circle_area};
	int user_choice;
	float *measure_array, area_value = 0.0;

	printf("Bem vindo ao programa de calculo de areas de figuras geometricas.\n\n");

	print_options_menu();

	printf("Informe a opcao desejada: \n");
	scanf("%d",&user_choice);
	putchar('\n');

	switch(user_choice)
	{
		case 1:
		{
			measure_array = (float*)calloc(2,sizeof(float));
			printf("Informe a medida da base do triangulo, em centimetros: \n");
			scanf("%f",measure_array);
			printf("Informe a medida da altura do triangulo, em centimetros: \n");
			scanf("%f",measure_array + 1);
			area_value = array_pointer_vector[0](measure_array);
			printf("A area do triangulo, em centimetros, e igual a %.2f.\n",area_value);
			free(measure_array);
			break;
		}
		case 2:
		{
			measure_array = (float*)calloc(2,sizeof(float));
			printf("Informe a medida da base do retangulo, em centimetros: \n");
			scanf("%f",measure_array);
			printf("Informe a medida da altura do retangulo, em centimetros: \n");
			scanf("%f",measure_array + 1);
			area_value = array_pointer_vector[1](measure_array);
			printf("A area do retangulo, em centimetros, e igual a %.2f.\n",area_value);
			free(measure_array);
			break;
		}
		case 3:
		{
			measure_array = (float*)malloc(sizeof(float));
			printf("Informe a medida do lado do quadrado, em centimetros: \n");
			scanf("%f",measure_array);
			area_value = array_pointer_vector[2](measure_array);
			printf("A area do quadrado, em centimetros, e igual a %.2f.\n",area_value);
			free(measure_array);
			break;
		}
		case 4:
		{
			measure_array = (float*)calloc(3,sizeof(float));
			printf("Informe a medida da base maior do trapezio, em centimetros: \n");
			scanf("%f",measure_array);
			printf("Informe a medida da base menor do trapezio, em centimetros: \n");
			scanf("%f",measure_array + 1);
			printf("Informe a medida da altura do trapezio, em centimetros: \n");
			scanf("%f",measure_array + 2);
			area_value = array_pointer_vector[3](measure_array);
			printf("A area do trapezio, em centimetros, e igual a %.2f.\n",area_value);
			free(measure_array);
			break;
		}
		case 5:
		{
			measure_array = (float*)malloc(sizeof(float));
			printf("Informe a medida do raio do circulo, em centimetros: \n");
			scanf("%f",measure_array);
			area_value = array_pointer_vector[4](measure_array);
			printf("A area do circulo, em centimetros, e igual a %.2f.\n",area_value);
			free(measure_array);
			break;
		}
		default:
			printf("Nao foi realizada uma escolha valida.\n");
	}

	printf("Fim do programa.\n");

	return 0;
}