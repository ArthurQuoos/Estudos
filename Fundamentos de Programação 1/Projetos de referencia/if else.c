/*
@file: if else.c
@date:
@author: Arthur Albert Schmaiske Quoos
@brief: ***
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
int idade;
setlocale(LC_ALL,"Portuguese");
printf("Quantos anos voc� tem?\n");
scanf("%d",&idade);
 if(idade >=18){
  printf("Voc� � adulto\n");
}else{
  if(idade >=12){
    printf("Voc� � adolescente\n");
  }else{
      if(idade >=3){
        printf("Voc� � crian�a\n");
      }else{
        printf("O tal do bafo de leite\n");
        }// else crian�a e bebe
      }// else adolescente
    }// else adulto




return 0;
}
