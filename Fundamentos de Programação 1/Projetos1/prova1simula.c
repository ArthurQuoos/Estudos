/*
@file: prova1simula.c
@date: 08/07/2021
@author: Arthur Albert Schmaiske Quoos
@brief: Simulação da prova 1 (Fracasso Total)
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*
Faça um programa que receba o dia,
mês e ano de uma data
e informe se é uma data válida ou não (considere também os anos bissextos)
*/
int main(){
int dia, mes, ano;

setlocale(LC_ALL,"");
printf("Insira a data neste formato dd/mm/aaaa.\n");
scanf("%d/%d/%d",&dia,&mes,&ano);

  if(mes ==2,mes <= 28,ano % 4 ==0 || (ano % 100 == 0 && % 400 ==0),dia <=29){
  printf("ano bisexto.");

  }else{
  if(dia >=1 <=31,mes ==1 ==3  ==5  ==7  ==8  ==9  ==10  ==12){
    printf ("é uma uma data válida\n");

}else{
  if(mes == 4 ==6 ==11,dia >=30){
  printf("mes com 30 dias");


  }else{
    printf("não é valido\n");

    }//else3
  }//else2
}//else1
return 0;
}
//final
