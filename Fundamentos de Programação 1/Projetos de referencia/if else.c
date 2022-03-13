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
printf("Quantos anos você tem?\n");
scanf("%d",&idade);
 if(idade >=18){
  printf("Você é adulto\n");
}else{
  if(idade >=12){
    printf("Você é adolescente\n");
  }else{
      if(idade >=3){
        printf("Você é criança\n");
      }else{
        printf("O tal do bafo de leite\n");
        }// else criança e bebe
      }// else adolescente
    }// else adulto




return 0;
}
