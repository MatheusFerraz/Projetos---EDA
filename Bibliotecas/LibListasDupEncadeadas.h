//Biblioteca para manipulação de Listas Duplamente Encadeadas

//Definição da estrutura do Tipo No
struct No
{
	No *anterior;
	int numero;
	No *proximo;
};

//Procedimento para realizar inicialização de uma Lista
void iniciar_lista(No *ptr_lista)
{
	ptr_lista = NULL;
}

//Função para inserção de um novo Nó na Cabeça da Lista
No *inserir_cabeca(No *ptr_lista, int valor_inserir)
{
	No *novo_no;
	novo_no = (No*)malloc(sizeof(No));
	novo_no->numero = valor_inserir;
	novo_no->anterior = NULL;
	novo_no->proximo = ptr_lista;
	if(ptr_lista != NULL)
		ptr_lista->anterior = novo_no;
	ptr_lista = novo_no;
	return ptr_lista;
}

//Função para inserção de um novo Nó na calda da Lista
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
	novo_no->anterior = ptr_auxiliar;
	return ptr_lista;
}

//Função para inserir um elemento depois de uma chave
No *inserir_elemento(No *ptr_lista, int valor_chave, int valor_inserir)
{
	No *novo_no, *ptr_auxiliar;
	novo_no = (No*)malloc(sizeof(No));
	novo_no->numero = valor_inserir;
	ptr_auxiliar = ptr_lista;
	while(ptr_auxiliar->proximo->numero != valor_chave)
		ptr_auxiliar = ptr_auxiliar->proximo;
	novo_no->proximo = ptr_auxiliar->proximo;
	ptr_auxiliar->proximo = novo_no;
	novo_no->proximo->anterior = novo_no;
	return ptr_lista;
}

//Função para excluir cabeça da Lista
No *excluir_cabeca(No *ptr_lista)
{
	ptr_lista = ptr_lista->proximo;
	free(ptr_lista->anterior);
	ptr_lista->anterior = NULL;
	return ptr_lista;
}

//Função para excluir calda
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

//Função para excluir uma chave
No *excluir_elemento(No *ptr_lista, int valor_chave)
{
	No *ptr_auxiliar;
	ptr_auxiliar = ptr_lista;
	while(ptr_auxiliar->numero != valor_chave)
		ptr_auxiliar = ptr_auxiliar->proximo;
	ptr_auxiliar->anterior->proximo = ptr_auxiliar->proximo;
	ptr_auxiliar->proximo->anterior = ptr_auxiliar->anterior;
	free(ptr_auxiliar);
	return ptr_lista;
}

//Procedimento para exibir os Nós da Lista
void imprimir_lista(No *ptr_lista)
{
	No *ptr_auxiliar;
	ptr_auxiliar = ptr_lista;
	while(ptr_auxiliar != NULL)
	{
		printf("%d.\n",ptr_auxiliar->numero);
		ptr_auxiliar = ptr_auxiliar->proximo;
	}
}