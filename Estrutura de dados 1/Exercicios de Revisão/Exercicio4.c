/*
@file: Exercicio4.c
@date: 12/03/2022
@author: Arthur Albert Schmaiske Quoos
@brief: Exercicio de revisao sobre Alocacao dinamica
*/
/*
================================================================================
Fa¸ca um programa que leia um valor N e crie dinamicamente um
vetor com essa quantidade de elementos. Em seguida, passe esse vetor para uma fun¸c˜ao que vai ler os
elementos desse vetor. Depois, no programa principal, imprima os valores do vetor preenchido. Al´em disso,
antes de finalizar o programa, lembre-se de liberar a ´area de mem´oria alocada para armazenar os valores do
vetor.
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>

//Alocando o vetor e retornando o valor para o vetor da main
int* AlocaVetor(int x){
     int *ptr = (int*) malloc(x * sizeof(int));
     if(ptr != NULL){
       printf("Alocado com sucesso\n");
     }else{
       printf("Nao foi alocado\n");
     }
return ptr;
}
//preenchendo o vetor da main
void preencheVetor(int* vetor,int x){
      for (int i = 0; i < x; i++) {
      printf("Insira um valor: ");
      scanf("%d",&vetor[i]);
      }
return;
}
//imprimindo o vetor
void PrintfVetor(int* vetor,int x){
     for (int i = 0; i < x; i++) {
       printf("Vetor[%d]: %d \n",i+1,vetor[i]);
     }
return;
}

int main(){
    int x = 3;
    int *vetor = AlocaVetor(x); //vetor recebendo o valor do ptr
    preencheVetor(vetor,x);
    PrintfVetor(vetor,x);
    free(vetor);
return 0;
}
