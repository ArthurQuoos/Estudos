/*
Faça um programa que receba um número real,
 calcule e exiba o quadrado dele.
 O programa deverá calcular o quadrado de vários números
 e finalizar quando for digitado um número negativo ou zero.
*/
/*
@file: whileexercicios.c
@date: 13/07/2021
@author: Arthur Albert Schmaiske Quoos
@brief:Fatorial de um número
*/
#include <stdio.h>
#include <stdlib.h>
int main(){
  int valor;
  int contador = 0;
  int auxiliar;
  int valorini;//valor incial
  printf("digite um numero para obter o fatorial do mesmo:\n");
  scanf("%d",&valorini);
  valor = valorini;
  while(contador < valorini){
  contador++;
  if(contador == valorini){ //impedir que ele conte +1 além do que deveria.
    printf("Resultado final: %d\n",valor);
    return 0;
  }else{
    auxiliar = valor * contador;
    valor = auxiliar;
  }



printf("resultado: %d\n",valor);
}//while

return 0;
}
