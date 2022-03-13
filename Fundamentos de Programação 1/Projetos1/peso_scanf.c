/*
@file: peso_scanf.c
@date: 29/06/2021
@author: Arthur Albert Schmaiske Quoos
@brief: aula 05 exercício 01
*/
/*
Faça um programa que receba a altura de uma pessoa
e calcule e exiba seu peso ideal utilizando a
seguinte fórmula:
peso ideal = 72.7 x altura – 58
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main(){
float altura;
float peso_ideal;
setlocale(LC_ALL,"Portuguese");
printf("digite a sua altura: ");
scanf("%f", &altura);
peso_ideal = 72.7 * altura - 58;
printf("Baseado na sua altura, o seu peso ideal: %.2f\n", peso_ideal);
/* eu tentei usar a biblioteca locale.h
(junto com o comando setlocale(LC_ALL"Portuguese")
mas por algum motivo isso atrapalhava na conta =[
*/
  return 0;
}
