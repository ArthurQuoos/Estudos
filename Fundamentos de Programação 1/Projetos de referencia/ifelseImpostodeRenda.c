/*
@file: ifelseImpostoDeRenda.c
@date: 06/07/2021
@author: Arthur Albert Schmaiske Quoos
@brief: Aula 06 exerc�cio 04
*/

/*
Faça um programa que calcule o imposto de renda a ser
pago tendo como entrada o salário de um empregado. O
imposto deve ser calculado da seguinte maneira:
imposto = salário x alíquota – parcela da dedução
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
int main(){
setlocale(LC_ALL,"");
  float salario, aliquota, parcela;
  float imposto;
  float x, y;
  printf("Sal�rio: ");
  scanf("%f", &salario);

    if(salario <= 1903.98){
  printf("n�o precisa pagar imposto\n");
    }else{
      if(salario >= 1903.99 && salario <= 2826.65){
      x = salario / 100;//dividindo em o salario em 100 para adquirir a Al�quota
      y = x * 7.5;
      aliquota = y;
      printf("Al�quota de 7,5%%: %.2f\n",y);
      parcela = 142.80;
      printf("Parcela de dedu��o: %.2f\n", parcela);
      imposto = aliquota - parcela;
      printf("Imposto a ser pago: %.2f\n",imposto);
    }else{
      if(salario >= 2826.66 && salario <= 3751.05){
      x = salario / 100;//dividindo em o salario em 100 para adquirir a Al�quota
      y = x * 15;
      aliquota = y;
      printf("Al�quota de 15%%: %.2f\n",y);
      parcela = 354.80;
      printf("Parcela de dedu��o: %.2f\n", parcela);
      imposto = aliquota - parcela;
      printf("Imposto a ser pago: %.2f\n",imposto);

    }else{
      if(salario >= 3751.06 && salario <= 4664.68){
      x = salario / 100;//dividindo em o salario em 100 para adquirir a Al�quota
      y = x * 22.5;
      aliquota = y;
      printf("Al�quota de 22,5%%: %.2f\n",y);
      parcela = 636.13;
      printf("Parcela de dedu��o de: %.2f\n", parcela);
      imposto = aliquota - parcela;
      printf("Imposto a ser pago: %.2f\n",imposto);

    }else{
      if(salario >=4664.68){
      x = salario / 100;//dividindo em o salario em 100 para adquirir a Al�quota
      y = x * 27.5;
      aliquota = y;
      printf("Al�quota de 27,5%%: %.2f\n",y);
      parcela = 868.36;
      printf("Parcela de dedu��o de: %.2f\n", parcela);
      imposto = aliquota - parcela;
      printf("Imposto a ser pago: %.2f\n",imposto);
    }//if final
      }//else +4664
    }//else 3751
  }//else 2826
}//else 1903
return 0;
}
