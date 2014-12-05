//Biblioteca para manipulação de Listas Simplesmente Encadeadas

//Definição da Estrutura do Tipo No
struct No
{
	int numero;
	No *proximo;
};

//Procedimento para realizar inicialização de uma Lista
void iniciar_lista(No *ptr_lista)
{
	ptr_lista->proximo = NULL;
}

//Procedimento para inserir um Nó na Cabeça da Lista
void inserir_cabeca(No *ptr_lista, int valor_inserir)
{
	No *novo_no, *cabeca_atual_lista;
	novo_no = (No*)malloc(sizeof(No));
	novo_no->numero = valor_inserir;
	cabeca_atual_lista = ptr_lista->proximo;
	ptr_lista->proximo = novo_no;
	novo_no->proximo = cabeca_atual_lista;
}

//Função para excluir o Nó que representa a cabeça da Lista
No *excluir_cabeca(No *ptr_lista)
{
	No *ptr_auxiliar;
	ptr_auxiliar = ptr_lista;
	ptr_lista = ptr_lista->proximo;
	free(ptr_auxiliar);
	return ptr_lista;
}

//Função para inserir um Nó na calda da Lista
No *inserir_calda(No *ptr_lista, int valor_inserir)
{
	No *novo_no, *ptr_auxiliar;
	novo_no = (No*)malloc(sizeof(No));
	novo_no->numero = valor_inserir;
	novo_no->proximo = NULL;
	ptr_auxiliar = ptr_lista;
	while(ptr_auxiliar->proximo != NULL)
		ptr_auxiliar = ptr_auxiliar->proximo;
	ptr_auxiliar->proximo = novo_no;
	return ptr_lista;
}

//Função para excluir um Nó na calda da Lista
No *excluir_calda(No *ptr_lista)
{
	No *ptr_auxiliar;
	ptr_auxiliar = ptr_lista;
	while(ptr_auxiliar->proximo->proximo != NULL)
		ptr_auxiliar = ptr_auxiliar->proximo;
	free(ptr_auxiliar->proximo);
	ptr_auxiliar->proximo = NULL;
	return ptr_lista;
}

//Função para inserir um elemento antes de uma chave
No *incluir_elemento(No *ptr_lista, int valor_chave, int valor_inserir)
{
	No *novo_no, *ptr_auxiliar;
	novo_no = (No*)malloc(sizeof(No));
	novo_no->numero = valor_inserir;
	ptr_auxiliar = ptr_lista;
	while(ptr_auxiliar->proximo->numero != valor_chave)
		ptr_auxiliar = ptr_auxiliar->proximo;
	novo_no->proximo = ptr_auxiliar->proximo;
	ptr_auxiliar->proximo = novo_no;
	return ptr_lista;
}

//Função para excluir um nó qualquer da Lista
No *excluir_elemento(No *ptr_lista, int valor_chave)
{
	No *ptr_anterior, *ptr_posterior;
	ptr_anterior = ptr_lista;
	while(ptr_anterior->proximo->numero != valor_chave)
		ptr_anterior = ptr_anterior->proximo;
	ptr_posterior = ptr_anterior->proximo->proximo;
	free(ptr_anterior->proximo);
	ptr_anterior->proximo = ptr_posterior;
	return ptr_lista;
}

//Função para realizar uma busca de um elemento na Lista
int buscar_elemento(No *ptr_lista, int valor_buscar)
{
	No *ptr_auxiliar;
	for(ptr_auxiliar = ptr_lista; ptr_auxiliar != NULL; ptr_auxiliar = ptr_auxiliar->proximo)
	{
		if(ptr_auxiliar->numero == valor_buscar)
			return 1;
	}
	return 0;
}

//Procedimento para exibir os Nós da Lista
void imprimir_lista(No *ptr_lista)
{
	No *ptr_auxiliar;
	ptr_auxiliar = ptr_lista->proximo;
	while(ptr_auxiliar != NULL)
	{
		printf("%d.\n",ptr_auxiliar->numero);
		ptr_auxiliar = ptr_auxiliar->proximo;
	}
}
