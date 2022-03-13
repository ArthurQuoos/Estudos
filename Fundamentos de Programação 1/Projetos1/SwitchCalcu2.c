/*
@file: SwitchCalcu2.c
@date: 12/07/2021
@author: Arthur Albert Schmaiske Quoos
@brief: Aula 07 Exercício 03
*/
/*
Altere o exercício anterior para receber os 3 valores no mesmo scanf.
Exemplo:
Digite a conta a ser realizada: 5+8
O resultado é: 13
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
float x, y, z;
int opcao;
setlocale(LC_ALL,"");
  printf("Tecle \"1\" para operações de soma\n");
  printf("tecle \"2\" para operações de subtração\n");
  printf("Tecle \"3\" para operações de multiplicação\n");
  printf("Tecle \"4\" para operações de divisão\n");
  printf("Em seguida insira os números desejados.\n");
  scanf("%d %f %f", &opcao, &x, &y);
switch(opcao){
    case 1:
  printf("Você escolheu operações de soma.\n");
    z = x + y;
  printf("Resultado: %.2f\n", z);
  break;
    case 2:
  printf("Você escolheu operações de subtração.n");
  z = x - y;
  printf("Resultado: %.2f\n", z);
break;
    case 3:
  printf("Você escolheu operações de multiplicação.\n");
  z = x * y;
  printf("Resultado: %.2f\n",z);
break;
    case 4:
  printf("Você escolheu operações de divisão.\n");
  z = x / y;
  printf("Resultado: %.2f\n",z);
break;
  default:
  printf("ERRO BIPBOP ERRO\n");
}//switch

return 0;
}
