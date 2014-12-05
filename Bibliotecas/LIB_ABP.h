//Biblioteca com Funções e Procedimentos para Manipulação de ABP (Árvore Binária de Pesquisa)

#include <string.h>

/*Definição do Tipo de Dado para os Nós da Árvore
 *Somente o campo código e linha de ocorrência
*/
struct TNo
{
    char  codigo_video[7];
    int   linha_arquivo;
    TNo  *esquerda;
    TNo  *direita;
};

//Procedimento para realizar inserção de informação na Árvore Binária de Pesquisa
void inserir_arvore(TNo **ptr_no, TNo *ptr_dado)
{    
    if(*ptr_no == NULL) {
        ptr_dado->esquerda = NULL;
        ptr_dado->direita = NULL;
        *ptr_no = ptr_dado;
    } else {
        if(strcmp(ptr_dado->codigo_video,(*ptr_no)->codigo_video) <= 0)
            inserir_arvore(&(*ptr_no)->esquerda, ptr_dado);
        else
            inserir_arvore(&(*ptr_no)->direita, ptr_dado);
    }
}

//Procedimento para varredura e escrita da Árvore Binária de Pesquisa  - Esquerda - Direita
void pre_fix_esquerda(TNo *ptr_arvore, char *nome_arquivo)
{	
    FILE *arquivo_saida, *arquivo_entrada;
    char linha_auxiliar[100];

    if((ptr_arvore != NULL) && (ptr_arvore->linha_arquivo > 0)) {
        
	    pre_fix_esquerda(ptr_arvore->esquerda, nome_arquivo);
        arquivo_entrada = fopen(nome_arquivo, "r");
        arquivo_saida = fopen("Videos_Codigo.txt","a");
		
        int i;
        for(i = 0; i < ptr_arvore->linha_arquivo; i ++)
            fgets(linha_auxiliar, sizeof(linha_auxiliar), arquivo_entrada);
		
        fprintf(arquivo_saida, "%s\n", linha_auxiliar);
        fclose(arquivo_saida);

        //Chamada recursiva da função para leitura e impressão 
        pre_fix_esquerda(ptr_arvore->direita, nome_arquivo);
    }
}

//Procedimento para Manipulação e Leitura do arquivo de Dados
void ler_arquivo(char *nome_arquivo, TNo **ptr_arvore)
{    
    FILE *arquivo_entrada;
    char linha_auxiliar[100];
    int linha_lida;
	
	TNo* ptr_no_temporario;

    arquivo_entrada = fopen(nome_arquivo, "r");
    if (arquivo_entrada == NULL) {
        printf("Nao foi possivel realizar a leitura dos dados no arquivo.\n");
        exit(0);
	}
	
	
    fgets(linha_auxiliar, sizeof(linha_auxiliar), arquivo_entrada);
	linha_lida = 1;


	while((fgets(linha_auxiliar, sizeof(linha_auxiliar), arquivo_entrada) !=0)){
        
		linha_lida++;
        ptr_no_temporario = (TNo*)malloc(sizeof(TNo));
		strncpy(ptr_no_temporario->codigo_video, linha_auxiliar, 7);
        ptr_no_temporario->linha_arquivo = linha_lida;
    	inserir_arvore(ptr_arvore, ptr_no_temporario);
	}

	fclose(arquivo_entrada);
}

//Procedimento extra para gerar Saída em um arquivo
void gravar_saida(char *nome_arquivo, TNo *ptr_arvore)
{
    if(ptr_arvore != NULL) {

        FILE *arquivo_saida;
        arquivo_saida = fopen("Videos_Codigo.txt","w");
        fclose(arquivo_saida);

        pre_fix_esquerda(ptr_arvore, nome_arquivo);
        printf("\nArquivo com videos organizados pelo codigo gerado com sucesso.\n");
    } else {
        printf("\nNao foi possivel gerar o arquivo.\n");
    }
}

//Função para realizar procura de um código informado pelo usuário
TNo *procurar_codigo(TNo *ptr_arvore, char codigo[7])
{
    if(ptr_arvore != NULL)
    {
        if(strcmp(codigo, ptr_arvore->codigo_video) == 0)
            return ptr_arvore;
        else if(strcmp(codigo, ptr_arvore->codigo_video) < 0)
            return procurar_codigo(ptr_arvore->esquerda,codigo);
        else
            return procurar_codigo(ptr_arvore->direita,codigo);
    }
    else
        return NULL;
}

//Procedimento para impressão das informações do vídeo encontrado
void imprimir_informacoes(TNo *ptr_arvore, char codigo[7])
{
    TNo *ptr_no_video;
    ptr_no_video = procurar_codigo(ptr_arvore,codigo);

    if(ptr_no_video == NULL) {
        printf("Filme nao Catalogado. Verifique o codigo e tente novamente.\n");
    } else {       
        printf("Informacoes do video encontrado: \n");
        printf("Codigo: [%s].\n",ptr_no_video->codigo_video);
        printf("Linha de ocorrencia do video no arquivo de entrada: [%d].\n",ptr_no_video->linha_arquivo);
    }
}

//Procedimento para exibição do cabeçalho
void imprimir_cabecalho()
{
    printf("Universidade de Brasilia\n");
    printf("Disciplina: Estrutura de Dados e Algoritmos\n");
    printf("Aluno: Matheus Herlan dos Santos Ferraz\n\n");
}

//Procedimento para exibição do menu de operações
void imprimir_menu()
{
    printf("-------------------------------------------------------------\n");
    printf("|                 1 - Carregar Dados na Arvore              |\n");
    printf("|                 2 - Buscar Filme pelo Codigo              |\n");
    printf("|             3 - Gerar Arquivo com Videos Ordenados        |\n");
    printf("|                    Outro Numero para Sair                 |\n");
    printf("-------------------------------------------------------------\n\n");
}
