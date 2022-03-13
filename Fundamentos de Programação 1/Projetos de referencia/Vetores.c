#include <stdio.h>
#include <stdlib.h>

int main(){

  int idades[5];
  for(int i=0;i<5;i++){
printf("Digite o valor da idade %i: ",i);
scanf("%d",&idades[i]);
}//for

  for(int i=0;i<5;i++){
    printf("Idade[%d]: %d\n",i,idades[i]);
}//for






  return 0;
}//main
