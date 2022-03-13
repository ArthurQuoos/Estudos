#include <stdio.h>
#include <stdlib.h>


void incrementa(int* valor){
  printf("Valor recebido %d\n",*valor);
  (*valor)++;
  printf("Valor incrementado %d\n",*valor);
  return;
}//incrementa

int main(){
  int valor = 15;
  incrementa(&valor);
  printf("Valor apos a funcao: %d\n",valor);
  return 0;
}//main

void incrementaVetor(int tam, int vet[]){
  for(int i = 0; i < tam; i++){
    vet[i]++;
  }//for
  return;
}//incrementaVetor

int main(){
  int vetor[5]= {10,20,30,40,50};
  incrementaVetor(5,vetor);
  printf("Vetor apos a funcao:\n");
  for (size_t i = 0; i < 5; i++) {
    printf("%d ",vetor[i]);
  }//for
  printf("\n");
  return 0;
}//main


typedef struct{
  int x, y;
}Ponto;

void incrementaPonto(Ponto* p){
  p->x++;
  p->y++;
  return;
}//incrementa

int main(){
  Ponto p1 = {1,2};
  printf("Ponto antes da funcao (%d, %d)\n",p1.x, p1.y);
  incrementaPonto(&p1);
  printf("Ponto apos a funcao (%d, %d)\n",p1.x, p1.y);
  return 0;
}//main
