//Funções e Procedimentos para Manipulação de Vetores

/*Procedimento para Calcular a Soma entre os Números armazenados em Vetores,
escrevendo resultados em um arquivo*/
void calcular_soma(float *vetor_um, float *vetor_dois, float *vetor_resultante, int tamanho_vetor, bool confirm_real)
{
	int i;

	FILE *arquivo_saida;
	arquivo_saida = fopen("Soma.txt","w");

	fprintf(arquivo_saida,"Tipo : Soma\n");
	if(confirm_real)
	{
		fprintf(arquivo_saida,"Tipo dos Dados : Real\n");
		for(i=0;i<t;i++)
		{
			vetor_resultante[i] = vetor_um[i] + vetor_dois[i];
			fprintf(arquivo_saida,"%f\n",vetor_resultante[i]);
		}
	}
	else{
		fprintf(arquivo_saida,"Tipo dos Dados : Inteiro\n");
		for(i=0;i<t;i++)
		{
			vetor_resultante[i] = vetor_um[i] + vetor_dois[i];
			fprintf(arquivo_saida,"%d\n",(int)vetor_resultante[i]);
		}
	}

	fclose(arquivo_saida);
}

/*Procedimento para Calcular a Diferença entre os Números armazenados em Vetores,
escrevendo resultados em um arquivo*/
void calcular_subtracao(float *vetor_um, float *vetor_dois, float *vetor_resultante, int tamanho_vetor, bool confirm_real)
{
	int i;

	FILE *arquivo_saida;
	arquivo_saida = fopen("Diferenca.txt","w");

	fprintf(arquivo_saida,"Tipo : Subtracao\n");
	if(confirm_real)
	{
		fprintf(arquivo_saida,"Tipo dos Dados : Real\n");
		for(i=0;i<t;i++)
		{
			vetor_resultante[i] = vetor_um[i] - vetor_dois[i];
			fprintf(arquivo_saida,"%f\n",vetor_resultante[i]);
		}
	}
	else{
		fprintf(arquivo_saida,"Tipo dos Dados : Inteiro\n");
		for(i=0;i<t;i++)
		{
			vetor_resultante[i] = vetor_um[i] - vetor_dois[i];
			fprintf(arquivo_saida,"%d\n",(int)vetor_resultante[i]);
		}
	}

	fclose(arquivo_saida);
}

/*Procedimento para Calcular o Produto entre os números armazenados em Vetores,
escrevendo resultados em um arquivo*/
void calcular_multiplicacao(float *vetor_um, float *vetor_dois, float *vetor_resultante, int tamanho_vetor, bool confirm_real)
{
	int i;

	FILE *arquivo_saida;
	arquivo_saida = fopen("Produto.txt","w");

	fprintf(arquivo_saida,"Tipo: MultPonto\n");
	fprintf(arquivo_saida,"Dimensao: %d\n",tamanho_vetor);
	if(confirm_real)
	{
		fprintf(arquivo_saida,"Tipo: Real\n");
		for(i=0;i<t;i++)
		{
			vetor_resultante[i] = vetor_um[i] * vetor_dois[i];
			fprintf(arquivo_saida,"%f\n",vetor_resultante[i]);
		}
	}
	else{
		fprintf(arquivo_saida,"Tipo: Inteiro\n");
		for(i=0;i<t;i++)
		{
			vetor_resultante[i] = vetor_um[i] * vetor_dois[i];
			fprintf(arquivo_saida,"%d\n",(int)vetor_resultante[i]);
		}
	}

	fclose(arquivo_saida);
}

/*Procedimento para Calcular o Divisão entre os números armazenados em Vetores,
escrevendo resultados em um arquivo*/
void calcular_divisao(float *vetor_um, float *vetor_dois, float *vetor_resultante, int tamanho_vetor, bool confirm_real)
{
	int i;

	FILE *arquivo_saida;
	arquivo_saida = fopen("Quociente.txt","w");

	fprintf(arquivo_saida,"Tipo: DivPonto\n");
	fprintf(arquivo_saida,"Dimensao: %d\n",tamanho_vetor);
	if(confirm_real)
	{
		fprintf(arquivo_saida,"Tipo: Real\n");
		for(i=0;i<t;i++)
		{
			vetor_resultante[i] = vetor_um[i] / vetor_dois[i];
			fprintf(arquivo_saida,"%f\n",vetor_resultante[i]);
		}
	}
	else{
		fprintf(arquivo_saida,"Tipo: Inteiro\n");
		for(i=0;i<t;i++)
		{
			vetor_resultante[i] = vetor_um[i] / vetor_dois[i];
			fprintf(arquivo_saida,"%d\n",(int)vetor_resultante[i]);
		}
	}

	fclose(arquivo_saida);
}

//Função que retorna um ponteiro para alocação de dados do tipo inteiro
int *aloca_vetor_inteiros(int qtd_elementos)
{
	int *vetor;
	vetor = (int*)calloc(qtd_elementos,sizeof(int));
	return vetor;
}

//Função que retorna um ponteiro para alocação de dados do tipo float
float *aloca_vetor_float(int qtd_elementos)
{
	float *vetor;
	vetor = (float*)calloc(qtd_elementos,sizeof(float));
	return vetor;
}

//Procedimento que ordena os elementos de um vetor de inteiros - Algoritmo Bolha
void bubble_sort_int(int tamanho_vetor, int *vetor)
{
	int final, cont;
	for(final = tamanho_vetor-1; final > 0; final --)
	{
		for(cont = 0; cont < final; cont ++)
		{
			if(vetor[cont] > vetor[cont + 1]){
				int temp = vetor[cont];
				vetor[cont] = vetor[cont + 1];
				vetor[cont + 1] = temp;
			}
		}
	}
}

//Procedimento que ordena os elementos de um vetor - Algoritmo Bolha para Float
void bubble_sort_float(int tamanho_vetor, float *vetor)
{
	int final, cont;
	for(final = tamanho_vetor-1; final > 0; final --)
	{
		for(cont = 0; cont < final; cont ++)
		{
			if(vetor[cont] > vetor[cont + 1]){
				float temp = vetor[cont];
				vetor[cont] = vetor[cont + 1];
				vetor[cont + 1] = temp;
			}
		}
	}
}
