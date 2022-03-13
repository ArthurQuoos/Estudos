/*
Faça um programa que mostre n elementos da sequência de Fibonacci.
O valor de n é passado para o programa.
O primeiro termo é 0, e o segundo termo é 1,
os demais devem seguir a fórmula tn = tn-1 + tn-2
Obs.: Assista ao video do moodle para entender a sequência

*/
/*
@file: exerciciosfor.c
@date: 22/07/2021
@author: Arthur Albert Schmaiske Quoos
@brief: Sequencia de Fibonacci
*/
#include <stdio.h>
#include <stdlib.h>
int main(){
int tn1 = 0;
int tn2 = 1;
int tn;
int contador;

printf("Digite quantas numeros da sequencia de Fibonacci devem aparecer: ");
scanf("%d",&contador);
contador = contador - 2;
printf("%d %d ",tn1,tn2);
    for (contador;contador > 0;contador--){
    tn = tn1 + tn2;
    tn1 = tn2;
    tn2 = tn;

printf("-%d-",tn);

}//for
  return 0;
}//main
