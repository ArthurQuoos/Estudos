#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
  setlocale(LC_ALL,"");
  char opcao;
  printf("Escolha uma cor:\n");
  printf("v - Verde\n");
  printf("a - Amarelo\n");
  printf("p - Preto\n");
  printf("b - Branco\n");
  scanf("%c", &opcao);
switch(opcao){
  case 'v':
  case 'V':
    printf("Voc