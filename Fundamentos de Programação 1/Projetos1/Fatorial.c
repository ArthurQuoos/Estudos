/*
Fa�a um programa que receba um n�mero real,
 calcule e exiba o quadrado dele.
 O programa dever� calcular o quadrado de v�rios n�meros
 e finalizar quando for digitado um n�mero negativo ou zero.
*/
/*
@file: whileexercicios.c
@date: 13/07/2021
@author: Arthur Albert Schmaiske Quoos
@brief:Fatorial de um n�mero
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
  if(contador == valorini){ //impedir que ele conte +1 al�m do que deveria.
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
