/*
Faça um programa que receba valores enquanto eles estiverem no intervalo
 de 500 a 1000. Ao receber um valor fora da faixa,
  o programa deverá parar de solicitar valores,
  exibir quantos valores válidos foram digitados e finalizar.
*/

/*
@file: DoWhileExercicio.c
@date: 15/07/2021
@author: Arthur Albert Schmaiske Quoos
@brief: exercicio para determinar valores validos
*/


#include <stdio.h>
#include <stdlib.h>

int main(){
int contador = 0;
int x;
do{
  printf("Digite um valor de 500 a 1000\n");
  scanf("%d",&x);

if(x >=500 && x <=1000){
 contador++;
    }//if
}//do
while(x >=500 && x <=1000);
  printf("Valores validos digitados: %d\n",contador);

  return 0;
}//main
