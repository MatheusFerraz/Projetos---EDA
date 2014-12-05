//Funções e Procedimentos para Manipulação de Vetores

/*Procedimento para Calcular a Soma entre os Números armazenados em Vetores,
escrevendo resultados em um arquivo*/
void calcularSoma(float *vet1, float *vet2, float *vet3, int t, bool confirmReal)
{
	int i;

	FILE *arquivoSaida;
	arquivoSaida = fopen("Plus.txt","w");

	fprintf(arquivoSaida,"Tipo : Soma\n");
	if(confirmReal)
	{
		fprintf(arquivoSaida,"Tipo dos Dados : Real\n");
		for(i=0;i<t;i++)
		{
			vet3[i] = vet1[i] + vet2[i];
			fprintf(arquivoSaida,"%f\n",vet3[i]);
		}
	}
	else{
		fprintf(arquivoSaida,"Tipo dos Dados : Inteiro\n");
		for(i=0;i<t;i++)
		{
			vet3[i] = vet1[i] + vet2[i];
			fprintf(arquivoSaida,"%d\n",(int)vet3[i]);
		}
	}

	fclose(arquivoSaida);
}

/*Procedimento para Calcular a Diferença entre os Números armazenados em Vetores,
escrevendo resultados em um arquivo*/
void calcularSubtracao(float *vet1, float *vet2, float *vet3, int t, bool confirmReal)
{
	int i;

	FILE *arquivoSaida;
	arquivoSaida = fopen("Minus.txt","w");

	fprintf(arquivoSaida,"Tipo : Subtracao\n");
	if(confirmReal)
	{
		fprintf(arquivoSaida,"Tipo dos Dados : Real\n");
		for(i=0;i<t;i++)
		{
			vet3[i] = vet1[i] - vet2[i];
			fprintf(arquivoSaida,"%f\n",vet3[i]);
		}
	}
	else{
		fprintf(arquivoSaida,"Tipo dos Dados : Inteiro\n");
		for(i=0;i<t;i++)
		{
			vet3[i] = vet1[i] - vet2[i];
			fprintf(arquivoSaida,"%d\n",(int)vet3[i]);
		}
	}

	fclose(arquivoSaida);
}

/*Procedimento para Calcular o Produto entre os números armazenados em Vetores,
escrevendo resultados em um arquivo*/
void calcularMultiplicacao(float *vet1, float *vet2, float *vet3, int t, bool confirmReal)
{
	int i;

	FILE *arquivoSaida;
	arquivoSaida = fopen("Produto.txt","w");

	fprintf(arquivoSaida,"Tipo: MultPonto\n");
	fprintf(arquivoSaida,"Dimensao: %d\n",t);
	if(confirmReal)
	{
		fprintf(arquivoSaida,"Tipo: Real\n");
		for(i=0;i<t;i++)
		{
			vet3[i] = vet1[i] * vet2[i];
			fprintf(arquivoSaida,"%f\n",vet3[i]);
		}
	}
	else{
		fprintf(arquivoSaida,"Tipo: Inteiro\n");
		for(i=0;i<t;i++)
		{
			vet3[i] = vet1[i] * vet2[i];
			fprintf(arquivoSaida,"%d\n",(int)vet3[i]);
		}
	}

	fclose(arquivoSaida);
}

/*Procedimento para Calcular o Divisão entre os números armazenados em Vetores,
escrevendo resultados em um arquivo*/
void calcularDivisao(float *vet1, float *vet2, float *vet3, int t, bool confirmReal)
{
	int i;

	FILE *arquivoSaida;
	arquivoSaida = fopen("Quociente.txt","w");

	fprintf(arquivoSaida,"Tipo: DivPonto\n");
	fprintf(arquivoSaida,"Dimensao: %d\n",t);
	if(confirmReal)
	{
		fprintf(arquivoSaida,"Tipo: Real\n");
		for(i=0;i<t;i++)
		{
			vet3[i] = vet1[i] / vet2[i];
			fprintf(arquivoSaida,"%f\n",vet3[i]);
		}
	}
	else{
		fprintf(arquivoSaida,"Tipo: Inteiro\n");
		for(i=0;i<t;i++)
		{
			vet3[i] = vet1[i] / vet2[i];
			fprintf(arquivoSaida,"%d\n",(int)vet3[i]);
		}
	}

	fclose(arquivoSaida);
}

//Função que retorna um ponteiro para alocação de dados do tipo int
int *vetorDeInteiros(int qtdElementos)
{
	int *vetor;
	vetor = (int*)calloc(qtdElementos,sizeof(int));
	return vetor;
}

//Função que retorna um ponteiro para alocação de dados do tipo float
float *vetorDeFloats(int qtdElementos)
{
	float *vetor;
	vetor = (float*)calloc(qtdElementos,sizeof(float));
	return vetor;
}

//Procedimento que ordena os elementos de um vetor - Algoritmo Bolha
void algoritmoBolha(int sizeVet, int *vetor)
{
	int final, cont;
	for(final = sizeVet-1; final > 0; final --)
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
void algoritmoBolhaFloat(int sizeVet, float *vetor)
{
	int final, cont;
	for(final = sizeVet-1; final > 0; final --)
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
