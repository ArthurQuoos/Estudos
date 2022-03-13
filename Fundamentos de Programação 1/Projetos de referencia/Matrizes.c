/*
@file: Matrizes.c
@date: 27/07/2021
@author: Arthur Albert Schmaiske Quoos
@brief: Aula 12
*/
#include <stdio.h>
#include <stdlib.h>
int main(){
  int l,c;
  int matriz[3][3];

  for(l=0;l<3;l++){    //for para linhas
    for(c=0;c<3;c++){  //for para colunas
      printf("Digite matriz [%d][%d]:",l,c);
      scanf("%d",&matriz[l][c]);
    }//for externo
  }//for interno
  for(l=0;l<3;l++){    //for para linhas
    for(c=0;c<3;c++){  //for para colunas
      printf(" %d ",matriz[l][c]);
    }//for externo
    printf("\n");
  }//for interno
}//main
