/*
@file: ForExemplo.c
@date: 21/07/2021
@author: Arthur Albert Schmaiske Quoos
@brief: exemplo de for 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // para usar a funcao usleep
int main(){

int contador;
int i;
int j;
/*
  for(contador = 0; contador <10){
    printf("Contador: %d\n",contador);
}//for
*/
/*
  for(contador = 0; contador <=10; contador += 3){  // ++ por 3
    printf("contador: %d\n",contador);
  }
*/
/*
  for (int contadorfor = 0; contadorfor >= 0; contadorfor += 3){
    printf("Contadorfor: %d\n"contadorfor);  //declarando variavel dentro do for
  }//for
*/
/*
  for (i = 0, j =99; i <5; i++, j--){    //declarando variaveis
    printf("i: %d j: %d\n",i,j);
  }//for
*/

  for (i = 0; i < 10; i++){
    printf("i: %d\n",i);
      for (j = 0; j < 10; j++){     //for aninhado x * xinterno
        printf("j: %d\n",j);
        usleep(100000);
      }//internofor
  }//for


return 0;
}
