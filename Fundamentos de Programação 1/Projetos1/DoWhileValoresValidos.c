/*
Faça um programa que calcule a média para 5 alunos,
sendo que cada aluno tem 2 notas (reais).
O programa somente deverá aceitar notas no intervalo fechado de 0 a 10,
 solicitando nova digitação quando necessário
*/
/*
@file: mediaDoWhile.c
@date: 14/07/2021
@author: Arthur Albert Schmaiske Quoos
@brief: Programa de media dos alunos com do while
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
float nota1, nota2,auxiliar, auxiliar2;
int contador = 0;

do{
  printf("digite as 2 notas do aluno neste formato \"x x\" \n");
  scanf("%f %f",&nota1,&nota2);
  while(nota1 > 10 || nota1 < 0 || nota2 < 0 || nota2 > 10){
    printf("valor invalido\n");
    printf("Digite novamente:");
    scanf("%f %f",&nota1,&nota2);
  }
  auxiliar = nota1 + nota2;
  auxiliar2 = auxiliar / 2;

  ++contador;

  printf("a media do aluno %d  %.2f\n",contador,auxiliar2);
}
  while(contador < 5 );

//while
  return 0;
}
