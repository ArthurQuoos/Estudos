/*
@file: SwitchCalcu2.c
@date: 12/07/2021
@author: Arthur Albert Schmaiske Quoos
@brief: Aula 07 Exerc�cio 03
*/
/*
Altere o exerc�cio anterior para receber os 3 valores no mesmo scanf.
Exemplo:
Digite a conta a ser realizada: 5+8
O resultado �: 13
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
float x, y, z;
int opcao;
setlocale(LC_ALL,"");
  printf("Tecle \"1\" para opera��es de soma\n");
  printf("tecle \"2\" para opera��es de subtra��o\n");
  printf("Tecle \"3\" para opera��es de multiplica��o\n");
  printf("Tecle \"4\" para opera��es de divis�o\n");
  printf("Em seguida insira os n�meros desejados.\n");
  scanf("%d %f %f", &opcao, &x, &y);
switch(opcao){
    case 1:
  printf("Voc� escolheu opera��es de soma.\n");
    z = x + y;
  printf("Resultado: %.2f\n", z);
  break;
    case 2:
  printf("Voc� escolheu opera��es de subtra��o.n");
  z = x - y;
  printf("Resultado: %.2f\n", z);
break;
    case 3:
  printf("Voc� escolheu opera��es de multiplica��o.\n");
  z = x * y;
  printf("Resultado: %.2f\n",z);
break;
    case 4:
  printf("Voc� escolheu opera��es de divis�o.\n");
  z = x / y;
  printf("Resultado: %.2f\n",z);
break;
  default:
  printf("ERRO BIPBOP ERRO\n");
}//switch

return 0;
}
