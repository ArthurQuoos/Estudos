

#include <stdio.h>
#define TAMANHO 10
#include <stdbool.h>

//pilha estatica 
//int vetor
//topo

typedef struct{
int vetor[TAMANHO];
int topo;
}PilhaEstatica;

//Inicialiazacao da pilha (inica/cria)
void iniciaPilhaEstatica(PilhaEstatica *pilha){
    //atribuir -1 para topo
    pilha->topo = -1;

}

bool estaVaziaPilhaEstatica(PilhaEstatica *pilha){
    return(pilha->topo == -1);
}

bool estaCheiaPilhaEstatica(PilhaEstatica *pilha){
    return (pilha->topo == (TAMANHO -1));
}

void imprimiPilhaEstatica(PilhaEstatica *pilha){
    printf("Pilha = [ ");
    int i;
    //for(<inicial>; <parada>; <inc/dec>)
    for(i = 0; i <= pilha->topo; i++){
        printf("%d ",pilha->vetor[i];)
    }

    printf("]\n");
}

int tamanhoPilhaEstatica(PilhaEstatica *pilha){


return x;
}

//insercao -> empilhar -> push
void empilharPilhaEstatica(PilhaEstatica *pilha){
    
    if(estaCheiaPilhaEstatica(pilha)){
        printf("Warning: elemento nao pode ser inserid. Pilha cheia\n");
    }else{
        //false = pode inserir
        pilha->topo++;
        //true = nao pode inserir

    }
}

//desempilhar (pop)
//se vazia nao faz nada
//senao: salvar o valor contido na posicao veotr [topo] em alguma variavel
//decrementa o topo
//retorno o valor para a main
int desempilharPilhaEstatica(PilhaEstatica *pilha){
    int aux = -999; //precisa de um valor para funcionar
    if(estaVaziaPilhaEstatica(pilha)){
        printf("Waring:Esta vazia, nao pode retirar de uma pilha vazia\n");
    }else{

    }
return aux;
}

int consultaPilhaEstatica(){


    
}

int main(int argc, const char * argv){
    PilhaEstatica p;
    iniciaPilhaEstatica(&p); 

    if(estaVaziaPilhaEstatica(&p)){
        printf("Pilha esta vazia\n");
    }else{
        printf("Tem alguma coisa\n");
    }

    if(estaCheiaPilhaEstatica(&p)){
        printf("Pilha Esta Cheia\n");
    }else{
        printf("Podemos inserir elemetos\n");
    }

    int tam = tamanhoPilhaEstatica(&p);
    printf("Tamanho da pilha = %d\n",tam);

    //unica insercao
    empilharPilhaEstatica(&p, 42);
    imprimePilhaEstatica(&p);
    tam = tamanhoPilhaEstatica(&p);
    printf("Tamanho pilha = %d\n",tam);

    int aux;
    aux = desempilharPilhaEstatica(&p);
    printf("Elemento removido = %d\n",aux);
    imprimePilhaEstatica(&p);

return 0;
}