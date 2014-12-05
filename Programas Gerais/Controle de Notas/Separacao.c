//Programa para leitura e separação dos aprovados e reprovados.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void cabecalho()
{
	printf("Universidade de Brasilia\n");
	printf("Aluno: Matheus Herlan dos Santos Ferraz\n");
	printf("Curso: Engenharia de Software\n\n");
}

int main()
{
	cabecalho();
	
	typedef struct 
	{
		int idAluno;
		float media;
	} Aluno;

	FILE *arquivoEntrada, *arquivoAprovados, *arquivoReprovados;
	Aluno a;
	char nomeArquivoEntrada [41];

	printf("Bem vindo ao programa de separacao de informacoes.\n");

	printf("Informe o nome do arquivo que contem o numero e a media dos seus alunos: \n");
	scanf(" %40[^\n]",nomeArquivoEntrada);
	putchar('\n');

	arquivoEntrada = fopen(nomeArquivoEntrada,"r");
	arquivoAprovados = fopen("AlunosAprovados.txt","w");
	arquivoReprovados = fopen("AlunosReprovados.txt","w");

	while((fscanf(arquivoEntrada," %i %f",&a.idAluno, &a.media)) != EOF)
	{
		if(a.media >= 5){
			fprintf(arquivoAprovados,"%10i %8.2f\n",a.idAluno,a.media);
		}else {
			fprintf(arquivoReprovados,"%10i %8.2f\n",a.idAluno,a.media);
		}
	}

	printf("Suas informacoes foram separadas com sucesso. Olhe os arquivos para verificar os Alunos aprovados e reprovados.\n");

	fclose(arquivoEntrada);
	fclose(arquivoAprovados);
	fclose(arquivoReprovados);

	return 0;
}
