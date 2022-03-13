
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main(){
/*
int contador = 0;
  while(contador < 100){
    printf("%d\n",contador);   //exemplo1
    contador++;
  }//while
*/
/*
char tecla;
tecla = '1';
  printf("Mostra teclas ate que digite z..\n");
    while(tecla != 'z'){
      scanf("%c",&tecla);       //exemplo 2
      setbuf(stdin,NULL);
      printf("Tecla: %c \n",tecla);

    }//while
*/
/*
int contador = 0;
int contapar = 0;
  while(contador <=20){
    if(contador % 2 == 0){
      contapar ++;        //Variavel contadora
    }//if
    contador++;
  }//while
    printf("Numeros pares = %d\n",contapar);
*/

int contador = 0;
int soma = 0;
  while(contador <= 1000){
    soma = soma + contador;    //variavel Acumuladora
    contador ++;
  }//while
  printf("A soma: %i\n",soma);
  
  return 0;
}
/*
@file: while.c
@date: 12/07/2021
@author: Arthur Albert Schmaiske Quoos
@brief: resumo
*/
