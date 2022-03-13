/*
@file: ifelseParouImpar.c
@date: 06/07/2021
@author: Arthur Albert Schmaiske Quoos
@brief: Aula 06 exercício 02
*/

/*
FaÃ§a um programa que receba um nÃºmero e determine
se ele Ã© um nÃºmero par ou Ã­mpar.
î‘« Obs.: Utilize o operador % que retorna o resto da divisÃ£o)
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main(){
  setlocale(LC_ALL,"");
  int x;
  int resultado;
  printf("Escreva um número: ");
  scanf("%d",&x);
  resultado = x % 2;

  if(resultado == 0){
    printf("O número %d é par\n",x);
  }else{
    printf("O número %d é impar\n",x);
  }

return 0;
}
