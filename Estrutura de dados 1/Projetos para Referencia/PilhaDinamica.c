
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/*
===================================================================
Definir os tipos abstratos de dados
-NoPilha
-PilhaDinamica
===================================================================
Inicializacao da estrutura
Destruir a estrutura  //HOMEWORK
Insercao (push)/empilhar
Remover (pop)/desemplihar
Procura (top)/ consulta o elemento do topo //HOMEWORK
===================================================================
*/

void iniciaPilhaDin(PilhaDin *pilha){
    pilha->qtde = 0;
    pilha->topo = NULL;
}

void estaVaziaPilhaDin(PilhaDin *pilha){
    return(pilha->topo == NULL)
}

int tamanhoPilhaDin(PilhaDin *pilha){
    return(pilha->qtde);
}

void imprimirPilhaDin(PilhaDin *pilha){
    printf("Pilha = [");
    PtrNoPilha var = pilha->topo;
    while(var != NULL){
        printf("%d ",var->x);
        var = var->proximo;
    }
    printf("]\n");
}

void empilharPilhaDin(PilhaDin *pilha, int x){

    //criar o novo no (alocar memoria)
    PtrNoPilha novo = = malloc(sizeof(NoPilha));
    //copiar o valor no novo no 
    novo->x = x;
    //atualizar refs
    //     - novo->proximo = topo
    novo->proximo = pilha->topo;
    //     - topo = novo
    pilha->topo = novo;
    // qtde++
    pilha->qtde++;
}

int desempilharPilhaDin(PilhaDin *pilha){
    //se estiver vazia, nao remove
    if(estaVaziaPilhaDin(pilha)){
        printf("TA VAZIO\n");
    }else{
    //salvar o valor a ser retornado 
    ret = pilha->topo->x;
    //Ptr auxiliar
    pilha->topo = pilha->topo->proximo;
    //pilha->topo = aux->proximo;
    //desalocar a memoria
    }
     
    //atualizar o topo 
    //Desalocar memoria
    //qtde--
    //retornar

}

//Destruir
// - Esvaziar a pilha
// Desempilha qtde elementos

//Consulta do topo
// - Verificar se nao esta vazia
// - pega o valor do topo(topo->x) e copia para uma var


//========================================================================
typedef struct NoPilha* PtrNoPilha;
    typedef struct NoPilha{
    int x;
    PtrNoPilha proximo;
}NoPilha;

typedef struct{
    PtrNoPilha topo; //aponta p um no de pilha qualquer
    int qtde; //qtde de elementos na pilha
}PilhaDin;
//========================================================================


int main(int argc, char* argv[]){
int tam;
 PIlhaDin p;
 IniciaPilhaDin(&p);
if(estaVaziaPinlhaDin(&p));

        imprimirPilhaDin(&p);
    empilharPilhaDin(&p, 5);
        //5
        imprimirPilhaDin(&p);
    empilharPilhaDin(&p, 10);
        //10 5
        imprimirPilhaDin(&p);
    empilharPilhaDin(&p, 15);
        //15 10 5
        imprimirPilhaDin(&p);
    empilharPilhaDin(&p, 20);
        //20 15 10 5
        imprimirPilhaDin(&p);
    empilharPilhaDin(&p, 25);
        //25 20 15 10 5
        imprimirPilhaDin(&p);
    empilharPilhaDin(&p, 30);

    int tam= tamanhoPilhaDin(&p);
    printf("Tamanho = %d\n",tam);

    for(int i = 0; i < tam; i++){
        desempilharPilhaDin(&p);
        imprimirPilhaDin(&p);
    }
        desempilharPilhaDin(&p);
        imprimirPilhaDin(&p);

    return 0;

}