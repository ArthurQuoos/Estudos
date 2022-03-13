/*
@file: ifelseBhaskara.c
@date: 06/07/2021
@author: Arthur Albert Schmaiske Quoos
@brief: Aula 06 exercÌcio 03
*/
/*
Fa√ßa um programa que receba os coeficientes a, b e c
de uma equa√ß√£o do segundo grau e retorne as ra√≠zes da
equa√ß√£o (se existirem).
Óë´ Para isso, lembre-se da f√≥rmula de B√°skara:
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main(){
setlocale(LC_ALL,"");
int a;
int b;
int c;
int delta;
float x1;
float x2;
  printf("insira o n˙mero A: \n");
  scanf("%d", &a);
  printf("insira o n˙mero B: \n");
  scanf("%d", &b);
  printf("insira o n˙mero C: \n");
  scanf("%d", &c);

  delta = b * b - 4 * a * c;

if(delta >= 0){
  printf("delta = %d\t",delta);
  printf("Raiz existe\n");
  x1 = (-b + sqrt(delta) / 2 * a);
  x2 = (-b - sqrt(delta) / 2 * a);
  printf("x1 = %.2f\n",x1);
  printf("x2 = %.2f\n",x2);
}else{
  printf("Raiz n„o existe.\n");
}
return 0;
}
