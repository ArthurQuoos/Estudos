
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// 1. ptr p um no de fila
// struct nofila* -> ptrnofila (typedef)
    typedef struct NoFila* PtrNoFila;

// 2. no fila
    typedef struct NoFila{
        int x;
        PtrNoFila proximo;
    }NoFila;
// 3. fila dinamica
typedef struct {
    PtrNoFila inicio;
    PtrNoFila fim;
    int qtde;
}FilaDin

//====================================
void iniciaFilaDin(FilaDin *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
//
}

bool estaVaziaFilaDin(FilaDin *fila){
    return(fila->qtde = 0);
}

int tamanhoFilaDin(FilaDin *fila){
    return(fila->qtde);
}

void imprimirFilaDin(FilaDin *fila){
    printf("Fila = [");
    //laco de repeticao (inicio), proximo valor de um auxiliar == NULL
    //   -printf aux->x
    PtrNoFila aux;
    for(aux = fila->inicio; aux != NULL; aux = aux->proximo){
        printf("%d ", aux->x);
    }
    printf("]\n");
}

void enfileirarFilaDin(FilaDin *fila, int valor){
    //criar um novo no, alocar memoria
    PtrNofila novo = malloc(sizeof(NoFila));

    //primeira insercao
    if(estaVaziaFilaDin(fila)){
        //inicio aponta p novo no
        fila->inicio = novo;
        //fim aponta p novo no
        fila->fim = novo;
    }else{
        //2 ou + insersoes
    }
}

void desenfileirarFilaDin(FilaDin *fila){
    // se ! estiver vazia:
        
        if(!estaVaziaFilaDin(fila)){
        // criar aux
        //aux = inicio
        PtrNoFila aux = fila->inicio;
        if(tamanhoFilaDin(fila)== 1){
        //inicio = fim = NULL
        fila->inicio = NULL;
        fila->fim = NULL;
        //free aux
        //qtde--
    //tem mais elementos
        }else{
            fila->inicio = fila->inicio->proximo;
        }
        free(aux);
        fila->qtde--;
        }else{
        printf("Warning: esta vazia\n");
        }
        //criar aux
        //aux = inicio
        //inicio = proximo do inicio
        //free aux
        //qtde--
        }
}

int main(){
    int tam;
    FilaDin f;
    iniciaFilaDin(&f);

    if(estaVaziaFilaDin(&f)){
        printf("A fila esta vazia\n");
    }


    return 0;
}