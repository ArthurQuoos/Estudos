/*
@file: switchParIdade.c
@date: 06/07/2021
@author: Arthur Albert Schmaiske Quoos
@brief: Aula 07 Exerc√É¬≠cio 01
*/
/*
Crie um programa que forne√ßa um menu com
duas op√ß√µes. Caso o usu√°rio digite 1, o programa
solicitar√° um n√∫mero e verificar√° se o valor √© par ou
impar. Caso o usu√°rio digite 2, o programa solicitar√°
uma idade e verificar√° se pessoa √© maior ou menor
de idade.
Veja o exemplo de menu abaixo:
Menu de programa:
1 ‚Äì Verifica par/impar
2 ‚Äì Verifica maior/menor de idade
Digite sua op√ß√£o:
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main(){
int opcao;
int x; //n˙mero que o usuario digitar.
int y; //auxiliar para definir par ou impar.
int idade;
setlocale(LC_ALL,"");
  printf("Qual serviÁo vocÍ deseja?\n");
  printf("1 - para descobrir se um n˙mero È par ou impar.\n");
  printf("2 - para verificar se vocÍ È maior ou menor de idade.\n");
  scanf("%i", &opcao);
switch(opcao){
  case 1:
  printf("VocÍ selecionou a opÁ„o 1.\n");
  printf("Insira um n˙mero:");
  scanf("%d",&x);
  y = x % 2;
  if(y == 0){
    printf("O n˙mero %d È par\n",x);
  }else{
    printf("O n˙mero %d È impar\n",x);
  }//else
break;
  case 2:
  printf("VocÍ selecionou a opÁ„o 2.\n");
  printf("Quantos anos vocÍ tem?  ");
  scanf("%d", &idade);
  if(idade >=18){
  printf("VocÍ È maior de idade.\n");
}else{
  printf("VocÍ È menor de idade.\n");
  }//else
break;
  default:
  printf("opÁ„o inv·lida\n");
}//switch
return 0;
}
