/*
@file: DoWhileGoTo.c
@date: 14/07/2021
@author: Arthur Albert Schmaiske Quoos
@brief: Exemplo de dowhile e goto.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

  int i=0;
  inicio://label de nome incio

  if(i == 10)
  goto final;
  printf("%d \n",i);
  i++;                //o amaldiçoado
  goto inicio;
  final://label de nome final
  printf("Saiu do laco\n");

/*
  int idade;
do {                              // do while
  printf("Digite sua idade:");
  scanf("%d",&idade);
} while(idade < 0);
printf("Valor aceito: %d\n",idade);
*/
/*
  int contador = 0;
  while(contador <10){
    if(contador==5){
      break;                //break
    }//if
    printf("%d ",contador);
    ++contador; //dúvida ????? em cima ou embaixo e porq? ?????
  }//while
printf("\nSaiu do laco\n");
*/
/*
int i = 0;
  while(i<10){
    if(i==5){
      i++;
      continue;         //continue
    }//if
printf("%d ",i);
i++;
  }//while
printf("\nSaiu do laco\n");
*/


return 0;
}//main
