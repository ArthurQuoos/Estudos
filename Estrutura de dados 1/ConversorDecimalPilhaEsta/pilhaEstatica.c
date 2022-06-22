#include "pilhaEstatica.h"

void iniciaPe(PilhaEstatica *p) {
 p->topo = 0;
}

bool estaVaziaPe(PilhaEstatica *p) {
 return(p->topo == 0);
}

bool estaCheiaPe(PilhaEstatica *p) {
 return(p->topo == N);
}

void empilharPe(PilhaEstatica *p, int valor) {
 if(!estaCheiaPe(p)){
   p->vetor[p->topo] = valor;
   p->topo++; /* p->topo = p->topo + 1 */
 } else {
   printf("Warning: nao inserido porque está cheia\n");
 }
}

int desempilharPe(PilhaEstatica *p) {
 int x = -1;
 if(!estaVaziaPe(p)){
   x = p->vetor[p->topo-1];
   p->topo--;
 } else{
   printf("Warning: nao removido porque esta vazia\n");
 }
 return(x);
}

int tamanhoPe(PilhaEstatica *p) {
 return(p->topo);
}

//Objeto topo(pilhaEstatica *pilha) {
  // adicione seu codigo aqui
//}

void imprimePe(PilhaEstatica *p) {
 int i = 0;
 printf("Pilha = {");
 for(i = 0; i < p->topo; i++) {
   printf("|%d| ", p->vetor[i]);
 }
 printf("}\n");
}
