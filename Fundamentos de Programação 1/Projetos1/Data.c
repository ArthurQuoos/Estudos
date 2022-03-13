#include <stdio.h>
#include <stdlib.h>



int main(){
 int dia;
 int mes;
 int ano;
 // 24/06/2021
 printf("digite o dia(dd/mm/aaaa)");
 scanf("%d/%d/%d", &dia, &mes, &ano);
 printf("Data: %02d/%02d/%04d\n",dia, mes, ano);

 return 0; //finaliza o programa
}// main
