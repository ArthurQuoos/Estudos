/*
void iniciaPe(PilhaEstatica *p);
int tamanhoPe(PilhaEstatica *p);
void imprimePe(PilhaEstatica *p);
bool estaVaziaPe(PilhaEstatica *p);
bool estaCheiaPe(PilhaEstatica *p);
void empilharPe(PilhaEstatica *p, int valor);
int desempilharPe(PilhaEstatica *p);
*/
//  pilhaEstatica.h
//  Stacks


#ifndef pilhaEstatica_h
#define pilhaEstatica_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXTAM 100

/* tipo abstrato para item, que será inserido na pilha */
/*
typedef struct {
  int chave;
  /* podemos adicionar mais coisas aqui */
//} Objeto;


/* tipo abstrato de pilha */
//typedef struct {
//  Objeto array[MAXTAM];
//  int topo;
//} pilhaEstatica;
typedef struct {
   int vetor[MAXTAM];  //vetor com 10 elementos inteiros
   int topo;       //controla o topo da pilha
} pilhaEstatica;

/* funções de manipulação */
void iniciaPe(pilhaEstatica *pilha);
bool estaVaziaPe(pilhaEstatica *pilha);
bool estaCheiaPe(pilhaEstatica *pilha) ;
void empilharPe(pilhaEstatica *p, int valor);
void desempilharPe(pilhaEstatica *p);
int tamanhoPe(pilhaEstatica *pilha);
//Objeto topo(pilhaEstatica *pilha);
void imprimePe(pilhaEstatica *pilha);

#endif /* pilhaEstatica_h */
