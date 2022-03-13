/*
@file: sqrt.c
@date: 29/06/2021
@author: Arthur Albert Schmaiske Quoos
@brief: Aula 05 Exercício 05
*/
/*
Sabendo que a função sqrt(valor),
que está na biblioteca math.h retorna a raiz quadrada do valor,
calcule a raiz quadrada de um número que o usuário digitar.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
float x;
float y;
printf("digite um numero: \n");
scanf("%f", &x);
y = x;
y = sqrt(x);
printf("valor da raiz quadrada de %.2f: %.2f\n", x, y);
return 0;
}
