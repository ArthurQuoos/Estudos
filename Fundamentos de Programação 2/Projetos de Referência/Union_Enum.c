#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
typedef union {
  int unidade;
  float peso;
}Quantidade;

int main(){
  Quantidade minha_quantidade;

  minha_quantidade.unidade = 15;
  printf("Quantidade: %d\n",minha_quantidade.unidade);

  minha_quantidade.peso = 23.9;
  printf("Quantidade: %.2f\n",minha_quantidade.peso);
  //printf("Quantidade: %d\n",minha_quantidade.unidade);
*/

 typedef enum {VERDE=1, AMARELO, PRETO, BRANCO} Cores;

int main(){
    int opcao;
    printf("Menu de programa:\n");
    printf("1 - Verde\n");
    printf("2 - Amarelo\n");
    printf("3 - Preto\n");
    printf("4 - Branco\n");
    printf("Digite sua opcao de cor:");
  scanf("%d",&opcao);

  switch(opcao){
    case VERDE:
    printf("Voce escolheu verde \n");
    break;
    case AMARELO:
    printf("Voce escolheu amarelo \n");
    break;
    case PRETO:
    printf("Voce escolheu preto \n");
    break;
    case BRANCO:
    printf("Voce escolheu branco \n");
    break;
  }



  return 0;
}
