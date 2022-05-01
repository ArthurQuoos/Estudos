#include <stdio.h>
#include <stdlib.h> // malloc, sizeof, free
#include <stdbool.h> // true, false

//------------------
// Single-linkage
//------------------

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
} Lista;

void iniciaListaOrdenada(Lista *l);
bool estaVaziaListaOrdenada(Lista *l);
int tamanhoListaOrdenada(Lista *l);
void inserirListaOrdenada(Lista *l, int x);
void imprimirListaOrdenada(Lista *l);
bool pesquisaListaOrdenada(Lista *lista, int valor, int *contador);
bool removerListaOrdenada(Lista *lista, int valor);
void destruirListaOrdenada(Lista *lista);
int primeiroElementoListaOrdenada(Lista *lista);
void destruirListaOrdenada2(Lista *lista);


Lista* constroi(int n, int* v){
  Lista *ListaTemp; //Chamando uma lista temporaria
    iniciaListaOrdenada(ListaTemp);

    if(n == 0){ //para o caso do tamano do vetor = 0
      return ListaTemp;
    }
//inserindo os valores do vetor na lista temporaria
    for (size_t i = 0; i < n; i++) {
      inserirListaOrdenada(ListaTemp,v[i]);
    }

  return ListaTemp;
}

int main(int argc, char* argv[]){
  Lista *lista;
    int tam = 10;
    int *vetor = malloc(tam * sizeof(int));
      for(int i = 0; i < tam; i++){
          vetor[i] = rand() % 100; // sorteia números entre 0 e 100
          printf("vetor[%d]: %d\n",i+1,vetor[i]);
  }

    lista = constroi(tam,vetor);
    imprimirListaOrdenada(lista);

free(vetor);
destruirListaOrdenada(lista);

  return 0;

}


// iniciar lista
void iniciaListaOrdenada(Lista *l) {
  l->inicio = NULL;
  l->qtde   = 0;
}

// imprimir lista
// esta Vazia
bool estaVaziaListaOrdenada(Lista *l) {
//  return(l->qtde == 0);
  return(l->inicio == NULL);
}
// tamanho
int tamanhoListaOrdenada(Lista *l) {
  return(l->qtde);
}

// inserir elemento
void inserirListaOrdenada(Lista *l, int x) {

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

void imprimirListaOrdenada(Lista *l) {
  printf("Lista = [");
//  inicio, print, proximo inicio, NULL
  PtrNoLista temp;
//  for(inicial, parada, incremento)
  for(temp = l->inicio; temp != NULL; temp = temp->proximo) {
    printf("%d ", temp->elemento);
  }
  printf("]\n");
}

//------------------
//------------------

// pesquisa
bool pesquisaListaOrdenada(Lista *lista, int valor, int *contador) {
  // percorrer a lista e encontrar/não elemento
  PtrNoLista aux;
  for(aux = lista->inicio; aux!=NULL; aux=aux->proximo) {
    (*contador)++;
    if(aux->elemento == valor) {
      return true;
    }
    if(aux->elemento > valor) {
      return false;
    }
  }
  return false;
}


// remoção
bool removerListaOrdenada(Lista *lista, int valor) {

  PtrNoLista aux;

//  situacao 1: lista vazia (falso)
//  situacao 2: valor < primeiro elemento da lista (falso)
//  situacao 1 ou 2: retornar falso
  if(estaVaziaListaOrdenada(lista) ||
     valor < lista->inicio->elemento) {
    return false;
  }
//  situacao 3: valor == primeiro elemento da lista
  if(valor == lista->inicio->elemento) {
  // criar um auxiliar e aux recebe o inicio
    aux = lista->inicio;
   // inicio recebe o proximo do inicio
    lista->inicio = lista->inicio->proximo;
  // libera memoria do aux
    free(aux);
  // qtde é decrementada
    lista->qtde--;
  // return vdd
    return (true);
  }

  //  situacao 4: percorrer a lista
  aux = lista->inicio;
  while(aux->proximo!=NULL && aux->proximo->elemento < valor) {
    aux = aux->proximo;
  }

  // proximo aux (contem na teoria) a posicao onde valor deveria existir
  //  aux->proximo == NULL (FALSO)
  //  aux->proximo->elemento != valor (FALSO)
  //  4a: nao achei depois de percorrer
  if(aux->proximo == NULL || aux->proximo->elemento!=valor) {
    return false;
  }
  //  4b: achei depois de percorrer
  // criar outra variavel de ptr
  PtrNoLista remove;
  // ptr apontar para o proximo do auxiliar
  remove = aux->proximo;
  // proximo do auxiliar recebe o proximo do proximo do auxiliar
  aux->proximo = aux->proximo->proximo;
  // desolaca memoria do ptr
  free(remove);
  // qtde --
  lista->qtde--;
//  retorna verdadeiro
  return(true);
}


// destrutor
void destruirListaOrdenada(Lista *lista) {
  // enqto qtde de elementos for diferente de zero
  printf("Destrutor\n");
  PtrNoLista aux;
  while(tamanhoListaOrdenada(lista) != 0) {
    // aux salva o atual (inicio)
    aux = lista->inicio;
    printf("Removendo: %d \n", aux->elemento);
    //  inicio vai p proximo
    lista->inicio = lista->inicio->proximo;
    // libera aux
    free(aux);
    // qtde--
    lista->qtde--;
  }
}

int primeiroElementoListaOrdenada(Lista *lista) {
  if(!estaVaziaListaOrdenada(lista)) {
    return(lista->inicio->elemento);
  } else {
    return(-9999);
  }
}

void destruirListaOrdenada2(Lista *lista) {
  // enqto qtde de elementos for diferente de zero
  printf("Destrutor 2\n");
  int remover;
  while(!estaVaziaListaOrdenada(lista)) {
    // consulta o primeiro elemento
    remover = primeiroElementoListaOrdenada(lista);
    printf("Removendo: %d \n", remover);
    // peço remover ele
    removerListaOrdenada(lista, remover);
  }
}
