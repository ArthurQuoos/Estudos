/*
@file: idade_scanf.c
@date: 29/06/2021
@author: Arthur Albert Schmaiske Quoos
@brief: aula 05 exercÃ­cio 02
*/
/*
Faça um programa que calcule e mostre a idade de uma pessoa
a partir do ano em que a pessoa nasceu e do ano atual.
Os valores serão digitados pelo usuário.
Considere que ela já fez aniversário nesse ano
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 int main(){
const int ano_atual = 2021;
int nascimento;
int idade;

printf("Em que ano voce nasceu? ");
scanf("%d", &nascimento);
idade = ano_atual - nascimento;
printf("Voce tem %d anos de idade\nEstou certo? s/n\n", idade);
getchar();

   return 0;
 }
