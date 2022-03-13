#include <stdio.h>
#include <stdlib.h>

int main(){
  int meta;
  int producao;
  printf("Digite a producao:");
  scanf("%d",&producao);
  meta = producao < 200 ? 0 : 1; // <--------Ternário
  printf("Status da meta: %d\n",meta);


  return 0;
}
