/*
@file: entrada de dados.c
@date: 29/06/2021
@author: Arthur Albert Schmaiske Quoos
@brief: aula 05 video
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

  int main (){
int dia, mes, ano;
char letra;

setlocale(LC_ALL,"Portuguese");// s� pra poder escrever M�s certo
printf("digite sua data de nascimento\nDia/M�s/Ano\n");
scanf("%.2d/%.2d/%.2d", &dia, &mes, &ano);
printf("digite uma letra: ");
setbuf(stdin,NULL);
scanf("%c", &letra);
    return 0;
  }
