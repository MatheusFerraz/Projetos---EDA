//Programa para auxílio do controle de notas de alunos.

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

	FILE *arquivoEntrada;
	Aluno a;
	int i, qtdAlunos;
	char nomeArquivoEntrada [41];

	printf("Informe o nome do arquivo onde deseja salvar as informacoes dos alunos: \n");
	scanf(" %40[^\n]",nomeArquivoEntrada);
	putchar('\n');

	arquivoEntrada = fopen(nomeArquivoEntrada,"w");

	printf("Informe a quantidade de alunos que deseja entrar com informaoes para salvar no arquivo: \n");
	scanf("%d",&qtdAlunos);
	putchar('\n');

	for(i=0;i<qtdAlunos;i++)
	{
		printf("Registro %d.\n",i+1);
		printf("Informe o numero do aluno: \n");
		scanf("%d",&a.idAluno);
		printf("Informe a media do aluno: \n");
		scanf("%f",&a.media);

		fprintf(arquivoEntrada,"%10i %8.2f\n",a.idAluno,a.media);
	}

	printf("OK. Suas informacoes foram gravadas com sucesso. Agora, execute o outro programa para leitura e separacao dos aprovados e reprovados.\n");

	fclose(arquivoEntrada);

	return 0;

}
