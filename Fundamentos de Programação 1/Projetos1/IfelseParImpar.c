/*
@file: ifelseParouImpar.c
@date: 06/07/2021
@author: Arthur Albert Schmaiske Quoos
@brief: Aula 06 exerc�cio 02
*/

/*
Faça um programa que receba um número e determine
se ele é um número par ou ímpar.
 Obs.: Utilize o operador % que retorna o resto da divisão)
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main(){
  setlocale(LC_ALL,"");
  int x;
  int resultado;
  printf("Escreva um n�mero: ");
  scanf("%d",&x);
  resultado = x % 2;

  if(resultado == 0){
    printf("O n�mero %d � par\n",x);
  }else{
    printf("O n�mero %d � impar\n",x);
  }

return 0;
}
