/*
@file: switchParIdade.c
@date: 06/07/2021
@author: Arthur Albert Schmaiske Quoos
@brief: Aula 07 ExercÃ­cio 01
*/
/*
Crie um programa que forneça um menu com
duas opções. Caso o usuário digite 1, o programa
solicitará um número e verificará se o valor é par ou
impar. Caso o usuário digite 2, o programa solicitará
uma idade e verificará se pessoa é maior ou menor
de idade.
Veja o exemplo de menu abaixo:
Menu de programa:
1 – Verifica par/impar
2 – Verifica maior/menor de idade
Digite sua opção:
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main(){
int opcao;
int x; //n�mero que o usuario digitar.
int y; //auxiliar para definir par ou impar.
int idade;
setlocale(LC_ALL,"");
  printf("Qual servi�o voc� deseja?\n");
  printf("1 - para descobrir se um n�mero � par ou impar.\n");
  printf("2 - para verificar se voc� � maior ou menor de idade.\n");
  scanf("%i", &opcao);
switch(opcao){
  case 1:
  printf("Voc� selecionou a op��o 1.\n");
  printf("Insira um n�mero:");
  scanf("%d",&x);
  y = x % 2;
  if(y == 0){
    printf("O n�mero %d � par\n",x);
  }else{
    printf("O n�mero %d � impar\n",x);
  }//else
break;
  case 2:
  printf("Voc� selecionou a op��o 2.\n");
  printf("Quantos anos voc� tem?  ");
  scanf("%d", &idade);
  if(idade >=18){
  printf("Voc� � maior de idade.\n");
}else{
  printf("Voc� � menor de idade.\n");
  }//else
break;
  default:
  printf("op��o inv�lida\n");
}//switch
return 0;
}
