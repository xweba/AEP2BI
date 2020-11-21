#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct tipoElemento
{
	int info;
	struct tipoElemento *proximo;
}TElemento;

typedef struct tipoLista
{
	TElemento *inicio;
	TElemento *fim;
}TLista;

TLista tabelaHashing[10];

int hash (int info)
{
	return info % 10;
}

void inicializar ()
{
	for (int i = 0; i < 10; i++)
	{
		tabelaHashing[i].inicio = NULL;
		tabelaHashing[i].fim = NULL;
	}
}

void inserir()
{
	int indice;
	TElemento *novo;
	novo = new TElemento;

	printf("\n Informe um valor: ");
	scanf("%d", &novo->info);
	novo->proximo = NULL;

	indice = hash (novo->info);

	if (tabelaHashing[indice].inicio == NULL)
	{
		tabelaHashing[indice].inicio = novo;
		tabelaHashing[indice].fim = novo;
	}
	else
	{
		tabelaHashing[indice].fim->proximo = novo;
		tabelaHashing[indice].fim = novo;
	}
}

void apresentar ()
{
	int i;

	for (i = 0; i < 10; i++)
	{
		TElemento *aux;
		aux = tabelaHashing[i].inicio;
		if (aux != NULL)
		{
			printf("\n Indice: %d - ", i);
			while (aux != NULL)
			{
				printf("%d | ", aux->info);
				aux = aux->proximo;
			}
		}
		else
		{
			printf("\n Indice: %d - / ", i);
		}
	}
}

void consultar()
{
	int infoConsultar;

	printf("\n Informe um valor para consulta: ");
	scanf("%d", &infoConsultar);

	int indice;
	indice = hash(infoConsultar);

	TElemento *aux;
	aux = tabelaHashing[indice].inicio;

	while (aux != NULL)
	{
		if (aux->info == infoConsultar)
		{
			printf("\n O valor foi encontrado");
			break;
		}
		else
		{
			aux = aux->proximo;
		}
	}
	if (aux == NULL)
	{
		printf("\n O valor nao foi encontrado");
	}
}

void excluir()
{
	int infoExcluir;

	printf("\n Informe o valor para ser excluido: ");
	scanf("%d", &infoExcluir);

	int indice;
	indice = hash(infoExcluir);

	TElemento *atual, *anterior;
	atual = tabelaHashing[indice].inicio;
	anterior = tabelaHashing[indice].inicio;

	while (atual != NULL)
	{
		if (atual->info == infoExcluir)
		{
			if (atual == tabelaHashing[indice].inicio)
			{
				tabelaHashing[indice].inicio = atual->proximo;
			}
			else
			{
				anterior->proximo = atual->proximo;
				if (atual == tabelaHashing[indice].fim)
				{
					tabelaHashing[indice].fim = anterior;
				}
			}
			break;
		}
		else
		{
			anterior = atual;
			atual = atual->proximo;
		}
	}
	if (atual != NULL)
	{
		printf("\n Elemento excluido com sucesso!");
		free(atual);
	}
	else
	{
		printf("\n Elemento nao existe na tabela hashing");
	}
}

int main()
{
	int opcao;
	inicializar();
	do
	{
		printf("\n\n 1 - Inserir valor");
		printf("\n 2 - Consultar valor");
		printf("\n 3 - Remover valor");
		printf("\n 4 - Apresentar tabela (todos os elementos)");
		printf("\n 0 - Sair");
		printf("\n Escolha uma opcao: ");
		scanf("%d", &opcao);
		switch(opcao)
		{
			case 1: inserir(); break;
			case 2: consultar(); break;
			case 3: excluir(); break;
			case 4: apresentar(); break;
		}
	}while (opcao != 0);
}
