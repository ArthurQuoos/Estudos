/*
Faça um menu que mostre 3 opções

Menu do programa:
1 - Teste 1
2 - Teste 2
3 – Sair do programa
Digite sua opção:

A primeira opção imprime o texto “Teste1” e mostra o menu novamente.
A segunda opção imprime “Teste2” e mostra o menu novamente.
A terceira opção finaliza o programa.
Caso digite uma opção diferente, deve mostrar uma mensagem de erro
e mostrar o menu novamente.
*/
/*
@file: whileMenu.c
@date: 13/07/2021
@author: Arthur Albert Schmaiske Quoos
@brief: Menu teste com while
*/
#include <stdio.h>
#include <stdlib.h>


int main(){
int opcao;

while (1){ //<--dica do Darlan esse 1 cara inteligente
  printf("Menu do programa\n");
  printf("1 - Teste1\n");
  printf("2 - Teste2\n");
  printf("3 - Sair do programa\n");
  printf("Digite sua opcao: ");
  scanf("%d",&opcao);
switch(opcao){
case 1:
  printf("Teste 1\n");

break;
case 2:
  printf("Teste 2\n");

break;
case 3:
  printf("Fim do programa\n");
  return 0;
break;
default:
 printf("ERROR BIBOP ERROR\n");
 break;
}//switch
}//while



return 0;
}//main
