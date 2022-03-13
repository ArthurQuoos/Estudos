#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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



  return 0;
}
