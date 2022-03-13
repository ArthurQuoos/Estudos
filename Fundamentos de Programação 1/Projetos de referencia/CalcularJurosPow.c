/*
@file: Calcular juros.c
@date: 29/06/2021
@author: Arthur Albert Schmaiske Quoos
@brief: Aula 04 exercicio 02
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*Uma conta de caderneta de poupança foi aberta com um
depósito de R$ 500,00. Imagine que esta conta é remunerada
em 1% de juros ao mês. Qual será o valor da conta após três
meses?
Para calcular potência, deve-se colocar a biblioteca #include <math.h>
no começo do arquivo, e usar a função pow. Exemplo:
variavel = pow(base,expoente) */

int main(){
float resultado, deposito;
deposito = 500;
resultado = deposito * pow (1.01, 3);

printf("resultado: %.2f\n", resultado);


  return 0;
}
