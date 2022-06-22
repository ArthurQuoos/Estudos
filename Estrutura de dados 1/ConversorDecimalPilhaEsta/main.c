#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilhaEstatica.h"

//#define N 10
/*
typedef struct {
   int vetor[N];  //vetor com 10 elementos inteiros
   int topo;       //controla o topo da pilha
} PilhaEstatica;
*/
/*
void iniciaPe(PilhaEstatica *p);
int tamanhoPe(PilhaEstatica *p);
void imprimePe(PilhaEstatica *p);
bool estaVaziaPe(PilhaEstatica *p);
bool estaCheiaPe(PilhaEstatica *p);
void empilharPe(PilhaEstatica *p, int valor);
int desempilharPe(PilhaEstatica *p);
*/

int main(int argc, const char * argv[]) {
 pilhaEstatica p;

 iniciaPe(&p);
 imprimePe(&p);

 if(estaVaziaPe(&p)) {
   printf("Aviso: está vazia\n");
 }



 return 0;
}
