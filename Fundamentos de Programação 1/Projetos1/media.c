/*
@file: média.c
@date: 29/06/2021
@author: Arthur Albert Schmaiske Quoos
@brief: Aula 05 Exercício 04
*/
/*
Calcule a média aritmética de 4 números reais
 que o usuário digitar.
 Imprima a média na tela apenas com 2 casas decimais.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
float divisor = 4;
float a, b, c, d;
float media;
float resultado;
printf("escreva 4 numeros reais ou inteiros: \n");
scanf("%f %f %f %f", &a, &b, &c, &d);
media = a + b + c + d;
resultado = media / divisor;
printf("Media dos numeros apresentados: %.2f \n", resultado);


  return 0;
}
