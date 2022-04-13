
#include <stdio.h>
#include <stdlib.h> // malloc, sizeof, free
#include <stdbool.h> // true, false



//=============================Cabecalho===============================//

void iniciaListaOrdenada(ListaOrdenada *l);
bool estaVaziaListaOrdenada(ListaOrdenada *l);
int tamanhoListaOrdenada(ListaOrdenada *l);
void inserirListaOrdenada(ListaOrdenada *l, int x);
void imprimirListaOrdenada(ListaOrdenada *l);
bool pesquisaListaOrdenadaDeselegante(ListaOrdenada *lista, int valor, int *contador);
bool pesquisaListaOrdenadaElegante(ListaOrdenada *lista, int valor, int *contador);
bool removerListaOrdenada(ListaOrdenada* lista, int valor);
int primeiroElementoListaOrdenada(ListaOrdenada *lista);
void destruirListaOrdenada(ListaOrdenada *lista);

//struct NoLista* -> PtrNoLista
typedef struct NoLista* PtrNoLista;

// NoLista
typedef struct NoLista{
  int elemento;       // int
  PtrNoLista proximo; // proximo (PtrNoLista)
} NoLista;

// Lista
typedef struct {
  PtrNoLista inicio; // inicio / primeiro (PtrNoLista)
  int qtde;          // qtde elemento
} ListaOrdenada;

//================================Main=================================//

int main(){









return 0;
}

//==============================Funcoes===============================//
// iniciar lista
void iniciaListaOrdenada(ListaOrdenada *l) {
  l->inicio = NULL;
  l->qtde   = 0;
}

// imprimir lista
// esta Vazia
bool estaVaziaListaOrdenada(ListaOrdenada *l) {
//  return(l->qtde == 0);
  return(l->inicio == NULL);
}
// tamanho
int tamanhoListaOrdenada(ListaOrdenada *l) {
  return(l->qtde);
}

// inserir elemento
void inserirListaOrdenada(ListaOrdenada *l, int x) {

  // criar ponteiro para um novo no (NOVO)
  PtrNoLista novo;
  // alocar memoria do novo no (NOVO)
  novo = malloc(sizeof(NoLista));
  // copiar o valor (x) para o novo no (NOVO->x)
  novo->elemento = x;

  // situacao A: 1a inserção
  // situacao B: elemento < primeiro elemento da lista
  // situacao C: elemento no meio ou fim da lista

  // se for A ou B:
  if(estaVaziaListaOrdenada(l) ||
     novo->elemento < l->inicio->elemento) {
    //     proximo do novo no aponta para o inicio da lista
    novo->proximo = l->inicio;
    //     inicio aponta para o novo no
    l->inicio = novo;
  } else {
  // senao: (C)
  //     percorrer a lista e encontrar posicao de insercao (aux)
    PtrNoLista aux = l->inicio;
    // Parar qndo:  proximo do aux = NULL OU  proximo do aux (valor > elemento)
    while(aux->proximo != NULL && aux->proximo->elemento <= x) {
      aux = aux->proximo;
    }
    //AUX: uma posicao antes do novo elemento
    //     1. proximo do novo no aponta para o proximo do aux
    novo->proximo = aux->proximo;
  //     2. proximo do aux aponta para o novo no
    aux->proximo = novo;
  }
  // qtde++
  l->qtde++;
}

void imprimirListaOrdenada(ListaOrdenada *l) {
  printf("Lista = [");
//  inicio, print, proximo inicio, NULL
  PtrNoLista temp;
//  for(inicial, parada, incremento)
  for(temp = l->inicio; temp != NULL; temp = temp->proximo) {
    printf("%d ", temp->elemento);
  }
  printf("]\n");
}

// pesquisar um elemento

bool pesquisaListaOrdenadaDeselegante(ListaOrdenada *lista, int valor, int *contador) {
  //prt aux
  PtrNoLista aux;
  // percorrer a lista
  for(aux = lista->inicio; aux!=NULL; aux = aux->proximo) {
  // se a posicao do aux contem valor ->retorna vdd
    (*contador)++;
    if(aux->elemento == valor) {
      return true;
    }
  }// retorna falso (caso contrario)
  return false;
}

bool pesquisaListaOrdenadaElegante(ListaOrdenada *lista, int valor, int *contador) {
  //prt aux
  PtrNoLista aux;
  // percorrer a lista
  for(aux = lista->inicio; aux!=NULL; aux = aux->proximo) {
    (*contador)++;
  // se a posicao do aux contem valor ->retorna vdd
    if(aux->elemento == valor) {
      return true;
    } else if(aux->elemento > valor) {
      return false;
    }
  }// retorna falso (caso contrario)
  return false;
}

// remover elemento
bool removerListaOrdenada(ListaOrdenada* lista, int valor) {
  // Situacao 1: lista ta vazia ou  Situação 2: valor < primeiro elemento da lista
  if(estaVaziaListaOrdenada(lista) || valor < lista->inicio->elemento) {
    //    Retorna falso (nao existe o valor na lista)
    return false;
  }

  // Situação 3: valor == primeiro elemento
  if(valor == lista->inicio->elemento) {
  //    ponteiro auxiliar que salva o no apontado pelo inicio
    PtrNoLista aux = lista->inicio;
  //    inicio aponta para proximo do inicio (aux)
    lista->inicio = lista->inicio->proximo;
    // free no aux
    free(aux);
  //    qtde é decrementada
    lista->qtde--;
  //    retorna vdd
    return (true);
  }

  // Situação 4: percorrer a lista (true/false)
  PtrNoLista tmp = lista->inicio;
  while(tmp->proximo!=NULL && tmp->proximo->elemento < valor) {
    tmp = tmp->proximo;
  }
  // tmp->proximo == NULL ou tmp->proximo->elemento > valor (deu merda)
  if(tmp->proximo == NULL || tmp->proximo->elemento > valor) {
    // percorri a lista e o elemento nao existe no arranjo de itens
    return false;
  }
  // se ele existir (tmp->proximo->elemento == valor)
  // atualizar as referencias
  // parar uma posicao antes do elemento a ser removido (tmp)
  // criar outro ponteiro para remover o no (rm)
  PtrNoLista rm = tmp->proximo;
  // proximo do temp recebe o proximo do proximo do temp
  tmp->proximo = tmp->proximo->proximo;
  lista->qtde--;
  free(rm);
  return true;
}

int primeiroElementoListaOrdenada(ListaOrdenada *lista) {
  if(!estaVaziaListaOrdenada(lista)) {
    return (lista->inicio->elemento);
  } else {
    return(-9999);
  }
}

// destruir lista
void destruirListaOrdenada(ListaOrdenada *lista) {
  // percorre removendo a galera
  printf("Destruindo a lista ... \n");
  int cons;
  while(!estaVaziaListaOrdenada(lista)) {
    cons = primeiroElementoListaOrdenada(lista);
    printf("Removendo: %d ...\n", cons);
    removerListaOrdenada(lista, cons);
  }
}