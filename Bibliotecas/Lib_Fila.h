//Biblioteca para manipulação de filas

//Definica do Tipo Elemento
struct TElemento {
	char senha_cliente[5];
	char tipo_atendimento;
	TElemento *proximo;
};

//Definicao do Tipo Fila
struct TFila {
	int tamanho;
	TElemento *inicio, *final;
};

//Procedimento para esvaziar/inicializar uma fila
void esvaziar(TFila *ptr_fila)
{
	ptr_fila->inicio = NULL;
 	ptr_fila->final = NULL;
  	ptr_fila->tamanho = 0;
}  

//Procedimento para verificar se a fila está ou não vazia
bool vazio(TFila *ptr_fila) {
	if (ptr_fila->inicio == NULL)
		return true;
	else 
		return false;
}

//Função para retornar o tamanho da fila
int tamanho(TFila *ptr_fila) {
	int tamanho_corrente_fila;
	tamanho_corrente_fila = ptr_fila->tamanho;
  	return tamanho_corrente_fila;
}

//Função para enfileiramento de um elemento na fila
bool enfileirar(TFila *ptr_fila, TElemento *ptr_elemento){
	
	ptr_elemento->proximo = NULL;
	int resultado_verificacao;
	
	resultado_verificacao = ptr_fila->tamanho;

	if (vazio(ptr_fila)) {
    	ptr_fila->inicio = ptr_elemento;
    	ptr_fila->final = ptr_elemento;
  	} else {
  		ptr_fila->final->proximo = ptr_elemento;
  		ptr_fila->final = ptr_elemento;
  	}
  	
  	printf("Novo Elemento Enfileirado na Fila.\n\n");
  	
  	ptr_fila->tamanho++;

	if((resultado_verificacao + 1) == ptr_fila->tamanho)
		return true;
	else
		return false;
}

//Função para desenfileirar um elemento da fila
TElemento *desenfileirar(TFila *ptr_fila){
	
	TElemento *ptr_elemento;
	
	if(vazio(ptr_fila)) { 
    	printf("A Fila esta Vazia.\n\n");
    	return ptr_elemento;
  	}
	
	ptr_elemento = ptr_fila->inicio;
  	ptr_fila->inicio = ptr_fila->inicio->proximo;

  	ptr_fila->tamanho--;
  	
  	printf("Elemento Desenfileirado da Fila.\n\n");
  	
  	return ptr_elemento;
}

//Função para imprimir a fila
void imprime(TFila *ptr_fila) {
  
	TElemento *ptr_elemento;
  
  	ptr_elemento = ptr_fila->inicio->proximo;
  	printf("%s\n", ptr_fila->inicio->senha_cliente);
  	while (ptr_elemento != NULL) { 
    	printf("%s\n", ptr_elemento->senha_cliente);
    	ptr_elemento = ptr_elemento->proximo;
    }
}

//Função para impressão do menu de operações
void imprimir_menu() {
	printf("\n+++++++++++++++++ Menu +++++++++++++++++++");
	printf("\n Escolha uma das opcoes de operacao");
	printf("\n 1 - Enfileirar");
	printf("\n 2 - Desenfileirar");
	printf("\n 3 - Esvaziar");
	printf("\n 4 - SAIR");
	printf("\n++++++++++++++++++++++++++++++++++++++++++\n");
}

//Procedimento para impressão do cabeçalho
void imprimir_cabecalho()
{
	printf("Universidade de Brasilia\n");
	printf("Disciplina: EDA\n");
	printf("Aluno: Matheus Herlan dos Santos Ferraz\n\n");
}
