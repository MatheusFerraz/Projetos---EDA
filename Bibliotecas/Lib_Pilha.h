//Biblioteca para manipula��o de pilhas

//Defini��o do Tipo Elemento (N� da lista que seguir� regras da Pilha)
struct TElemento {
	int endereco_memoria;
	int quantidade_bytes;
	struct TElemento *proximo;
};

//Defini��o do Tipo Pilha
struct TPilha {
	int tamanho;
	TElemento *topo_pilha;
};

//Procedimento para esvaziar e inicializar uma pilha
void esvaziar_inicializar_pilha(TPilha *ptr_pilha){
	ptr_pilha->topo_pilha = NULL;
	ptr_pilha->tamanho = 0;
}

//Fun��o para verifica��o de conte�do da pilha
bool verificar_se_esta_vazia(TPilha *ptr_pilha)
{
	if (ptr_pilha->topo_pilha == NULL) {
		return true;
	} else {
		return false;
	}		
}

//Fun��o para verificar tamanho da pilha
int verificar_tamanho_pilha(TPilha *ptr_pilha)
{
	int tamanho_corrente;
	tamanho_corrente = ptr_pilha->tamanho;
	return tamanho_corrente;
}

//Fun��o para empilhamento de um novo elemento na pilha
bool empilhar_elemento(TPilha *ptr_pilha, int quantidade_bytes, int endereco_memoria){
	
	TElemento *ptr_elemento;
	int resultado_verificacao;
	
	resultado_verificacao = ptr_pilha->tamanho;

	ptr_elemento = (TElemento*)malloc(sizeof(TElemento));
	ptr_elemento->quantidade_bytes = quantidade_bytes;
	ptr_elemento->endereco_memoria = endereco_memoria;

	ptr_elemento->proximo = ptr_pilha->topo_pilha;
	ptr_pilha->topo_pilha = ptr_elemento;

	ptr_pilha->tamanho++;
	printf("Novo Elemento Empilhado na Pilha.\n");
	
	if((resultado_verificacao + 1) == ptr_pilha->tamanho)
		return true;
	else 
		return false;
	
}

//Fun��o para desempilhamento de um elemento na pilha
TElemento *desempilhar_elemento(TPilha *ptr_pilha)
{	
	TElemento *topo_atual_pilha;
	
	if(verificar_se_esta_vazia(ptr_pilha)) {
		printf("A pilha ja se encontra vazia.\n\n");
		return topo_atual_pilha;
	} else {
		topo_atual_pilha = ptr_pilha->topo_pilha;
		ptr_pilha->topo_pilha = topo_atual_pilha->proximo;
		ptr_pilha->tamanho--;
		printf("Elemento desempilhado da pilha.\n\n");
		return topo_atual_pilha;
	}
}

//Fun��o para consultar o �ltimo elemento armazenado na pilha
TElemento *consultar_topo(TPilha *ptr_pilha)
{
	if (verificar_se_esta_vazia(ptr_pilha)) {
		printf("A pilha est� vazia.\n\n");
		return ptr_pilha->topo_pilha;
	} else {
		return ptr_pilha->topo_pilha;
	}
}

//Procedimento para impress�o do menu de opera��es
void imprimir_menu()
{
	printf("--------------------------------------------\n");
	printf("|           Escolha uma das opcoes         |\n");
	printf("|               1 - Empilhar               |\n");
	printf("|              2 - Desempilhar             |\n");
	printf("|               3 - Consultar              |\n");
	printf("|            Outro numero - Sair           |\n");
	printf("--------------------------------------------\n\n");
}

//Procedimento para impress�o do cabe�alho
void imprimir_cabecalho()
{
	printf("Universidade de Brasilia\n");
	printf("Disciplina: EDA\n");
	printf("Aluno: Matheus Herlan dos Santos Ferraz\n\n");
}
