
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//--------------------------
// Single-linkage
//--------------------------

// NoLista -> PtrNoLista
typedef struct NoLista* PtrNoLista;

//NoLista
typedef struct NoLista{
    int elemento;       //int
    PtrNoLista proximo; //proximo (PtrNoLista)
}NoLista;

// Lista
typedef struct{
    PtrNoLista inicio;  // inicio/ primeiro (PtrNoLista)
    int qtde;           // qtde elemento
}ListaOrd;

void iniciaListaOrd(ListaOrd *lista){
    lista->inicio = NULL;
    lista->qtde = 0;
}

bool estaVaziaListaOrd(ListaOrd *lista){

}

int tamanhoListaOrd(ListaOrd *lista){
    return (L->qtde);
}

void inserirListaOrd(ListaOrd *lista, int x){
    //criar ponteiro para um novo no (NOVO)
    PtrNoLista novo;
    //alocar memoria do novo no (NOVO)
    novo = malloc(sizeof(NoLista));
    //copiar o valor (x) para o novo no (novo-x)
    novo->elemento = x;
//Sitaucao A: 1a insercao
//Situacao B: elemento <  primeiro elemnto da lista
//Situacao C> elemento no meo ou fim da lista 
//Se for A ou B:
if(estaVaziaListaOrd(lista) || novo->elemento < lista->inicio){
//      proximo do novo no aponta para o incio da lista 
novo->proximo = lista->inicio;
//      inicio aponta para o novo no
lista->inicio = novo;
}else{
// senao: (c)
//      percorrer a lista e encontrar posicao de insercao (aux)
PtrNoLista aux = lista->inicio;
//parar qndo:
//proximo do aux = NULL
//proximo do aux (valor > elemento)
while(aux->proximo != NULL && aux->proximo->elemento <=x){
    aux = aux->proximo;
}
// (proximo do aux tiver um valor > elemento)
// AUX: uma posicao antes do novo elemento
// 1. proximo do novo no aponta para o proximo do aux
novo->proximo = aux->proximo;
// 2. proximo do aux aponta para o novo no
aux->proximo = novo;
}
//qtde++
lista->qtde++;
}

void imprimirListaOrd(ListaOrd *lista){
    printf("Lista = [");
//inicio, print, proximo inicio, NULL
PtrNoLista temp;
for(temp = lista->inicio; temp != NULL){
    printf("%d ",);
}
printf("]\n");
}
//-------------------------
//imprimir lista
//esta vazia
//tamanho
//opcionais (homework)
//maximo    (ultimo)
//minimo    (primeiro)
//proximo   (primeiro dele, se existir)
//anterior  (anterior dele, se existir)


// iniciar lista
//destruir a lista
//inserir lista
//remover elemento
//



int main(int argc,char* argv[]){
    ListaOrd l;
    iniciaListaOrd(&l);
    if(estaVaziaListaOrd(&l)){
        printf("Esta Vazia\n");
    }
    printf("Tamanho da lista: %d\n",tamanhoListaOrd(&l));

    imprimirListaOrd(&l);
    inserirListaOrd(&l,1);
    imprimirListaOrd(&l);
    inserirListaOrd(&l,2);
    imprimirListaOrd(&l);
    inserirListaOrd(&l,3);
    imprimirListaOrd(&l);
    inserirListaOrd(&l,4);
    imprimirListaOrd(&l);
    printf("Tamanho = %d\n",tamanhoListaOrd(&l));    
    
    return 0;
}