//Código do programa que fará o processamento dos arquivos.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

void cabecalho()
{
	printf("Universidade de Brasilia\n");
	printf("Docente : Nilton\n");
	printf("Disciplina : Estrutura de Dados e Algoritmos\n");
	printf("Aluno : Matheus Herlan dos Santos Ferraz\n\n");
}

void calcularSoma(float *vet1,float *vet2,float *vet3, int t, bool confirmReal)
{
    int i;

    FILE *arquivoSaida;
    arquivoSaida = fopen("Plus.txt","w");

    fprintf(arquivoSaida,"Tipo: Soma\n");
    fprintf(arquivoSaida,"Dimensao: %d\n", t);
    if(confirmReal)
    {
        fprintf(arquivoSaida,"Tipo: Real\n");
        for(i=0;i<t;i++)
        {
            vet3[i] = vet1[i] + vet2[i];
            fprintf(arquivoSaida,"%f\n",vet3[i]);
        }
    }
    else {
        fprintf(arquivoSaida,"Tipo: Inteiro\n");
        for(i=0;i<t;i++)
        {
            vet3[i] = vet1[i] + vet2[i];
            fprintf(arquivoSaida,"%d\n",(int)vet3[i]);
        }
    }

    fclose(arquivoSaida);
}

void calcularSubtracao(float *vet1,float *vet2,float *vet3, int t, bool confirmReal)
{
    int i;

    FILE *arquivoSaida;
    arquivoSaida = fopen("Minus.txt","w");

    fprintf(arquivoSaida,"Tipo: Subtracao\n");
    fprintf(arquivoSaida,"Dimensao: %d\n", t);
    if(confirmReal)
    {
        fprintf(arquivoSaida,"Tipo: Real\n");
        for(i=0;i<t;i++)
        {
            vet3[i] = vet1[i] - vet2[i];
            fprintf(arquivoSaida,"%f\n",vet3[i]);
        }
    }
    else {
        fprintf(arquivoSaida,"Tipo: Inteiro\n");
        for(i=0;i<t;i++)
        {
            vet3[i]= vet1[i] - vet2[i];
            fprintf(arquivoSaida,"%d\n",(int)vet3[i]);
        }
    }

    fclose(arquivoSaida);
}

void calcularMultiplicacao(float *vet1,float *vet2,float *vet3, int t, bool confirmReal)
{
    int i;

    FILE *arquivoSaida;
    arquivoSaida = fopen("Produto.txt","w");

    fprintf(arquivoSaida,"Tipo: MultPonto\n");
    fprintf(arquivoSaida,"Dimensao: %d\n", t);
    if(confirmReal)
    {
        fprintf(arquivoSaida,"Tipo: Real\n");
        for(i=0;i<t;i++)
        {
            vet3[i] = vet1[i] * vet2[i];
            fprintf(arquivoSaida,"%f\n",vet3[i]);
        }
    }
    else {
        fprintf(arquivoSaida,"Tipo: Inteiro\n");
        for(i=0;i<t;i++)
        {
            vet3[i]= vet1[i] * vet2[i];
            fprintf(arquivoSaida,"%d\n",(int)vet3[i]);
        }
    }

    fclose(arquivoSaida);
}

void calcularDivisao(float *vet1,float *vet2,float *vet3, int t, bool confirmReal)
{
    int i;

    FILE *arquivoSaida;
    arquivoSaida = fopen("Quociente.txt","w");

    fprintf(arquivoSaida,"Tipo: DivPonto\n");
    fprintf(arquivoSaida,"Dimensao: %d\n", t);
    if(confirmReal)
    {
        fprintf(arquivoSaida,"Tipo: Real\n");
        for(i=0;i<t;i++)
        {
            vet3[i] = vet1[i] / vet2[i];
            fprintf(arquivoSaida,"%f\n",vet3[i]);
        }
    }
    else {
        fprintf(arquivoSaida,"Tipo: Inteiro\n");
        for(i=0;i<t;i++)
        {
            vet3[i]= vet1[i] / vet2[i];
            fprintf(arquivoSaida,"%d\n",(int)vet3[i]);
        }
    }

    fclose(arquivoSaida);
}

main()
{
    cabecalho();

    FILE *entrada;
    char confirmation[7];
    char type[10];
    char operations[40];
    bool calcPlus, calcMinus, calcProd, calcQuo, confirmInteiro, confirmFloat;

    void (*vetorOperacoes[])(float *vet1,float *vet2,float *vet3, int t, bool confirmReal) = {calcularSoma,calcularSubtracao,calcularMultiplicacao,calcularDivisao};

    unsigned int dimension;
    int i = 0;

    entrada = fopen("EntradaA.txt","r");

    fscanf(entrada, "Tipo: %s",&confirmation);

    if(strcmp(confirmation,"Entrada") != 0)
    {
        printf("Este arquivo nao corresponde a uma categoria de entrada!\n");
        exit(EXIT_FAILURE);
    }
    printf("Seu arquivo foi encontrado em estado perfeito.\n");
    putchar('\n');

    fscanf(entrada, "\nDimensao: %4i",&dimension);

    fscanf(entrada, "\nTipo: %s", &type);

    if (strstr(type,"Inteiro") != NULL){
        confirmInteiro = true;
    }else if (strstr(type,"Real") != NULL)
    {
        confirmFloat = true;
    }else {
        printf("Informacao sobre tipo invalida!\n");
        exit(EXIT_FAILURE);
    }

    float *vetor1 = (float*) calloc (dimension,sizeof(float));
    float *vetor2 = (float*) calloc (dimension,sizeof(float));
    float *vetor3 = (float*) calloc (dimension,sizeof(float));

    fscanf(entrada, "\nSaidas: %[^\n]", &operations);

    if(strstr(operations,"Soma") != NULL){
        calcPlus = true;
    }if (strstr(operations,"Subtracao") != NULL){
       calcMinus = true;
    }if (strstr(operations,"MultPonto") != NULL){
       calcProd = true;
    }if (strstr(operations,"DivPonto") != NULL){
       calcQuo = true;
    }if(calcPlus || calcMinus || calcProd || calcQuo){
        printf("\n");
    }else{
        printf("Nao foi encontrada nenhuma operacao a ser feita com os dados do arquivo.\n");
    }

    if(confirmFloat){
        for(i=0;i<dimension;i++)
        {
            fscanf(entrada, "%f %f",&vetor1[i],&vetor2[i]);
            printf("%f %f\n",vetor1[i],vetor2[i]);
        }
    }else if(confirmInteiro){
        for(i=0;i<dimension;i++)
        {
            fscanf(entrada, "%f %f",&vetor1[i],&vetor2[i]);
            printf("%d %d\n",(int)vetor1[i],(int)vetor2[i]);
        }

    }
    putchar('\n');

    if(calcPlus)
    {
        vetorOperacoes[0](vetor1,vetor2,vetor3,dimension,confirmFloat);
    }
    if (calcMinus)
    {
        vetorOperacoes[1](vetor1,vetor2,vetor3,dimension,confirmFloat);
    }
    if (calcProd)
    {
        vetorOperacoes[2](vetor1,vetor2,vetor3,dimension,confirmFloat);
    }
    if (calcQuo)
    {
        vetorOperacoes[3](vetor1,vetor2,vetor3,dimension,confirmFloat);
    }

    free(vetor1);
    free(vetor2);
    free(vetor3);

    fclose(entrada);

    system("PAUSE");
}
