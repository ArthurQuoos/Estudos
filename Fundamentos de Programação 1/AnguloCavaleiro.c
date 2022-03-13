/*
@file: CalcularCavaleiro.c
@date: 17/07/2021
@author: Arthur Albert Schmaiske Quoos
@brief: Calcular o angulo cavaleiro para Desenho Tecnico
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
float x, auxiliar;
int opcao;
int fecharourepetir;
printf("qual angulo?\n");
printf("1 - 30 graus\n");
printf("2 - 45 graus\n");
printf("3 - 60 graus\n");
scanf("%d",&opcao);

  switch(opcao){
case 1:
  do{
  printf("30 graus = 2/3\nqual a medida para calcular: ");
  scanf("%f",&x);
  auxiliar = x;
  x = auxiliar / 3;
  auxiliar = x;
  x = auxiliar * 2;
  printf("Resultado: - %.2f - \n Para calcular outro valor tecle 1",x);
scanf("%d",&fecharourepetir);
}
while(fecharourepetir == 1);
break;
case 2:
  do{
  printf("45 graus = 1/2\nqual a medida para calcular: ");
  scanf("%f",&x);
  auxiliar = x;
  x = auxiliar / 2;

  printf("Resultado: - %.2f - \n Para calcular outro valor tecle 1",x);
  scanf("%d",&fecharourepetir);
  }
  while(fecharourepetir == 1);
  break;
case 3:
do{
  printf("60 graus = 1/3\nqual a medida para calcular: ");
  scanf("%f",&x);
  auxiliar = x;
  x = auxiliar / 3;

  printf("Resultado: - %.2f - \n Para calcular outro valor tecle 1: ",x);
  scanf("%d",&fecharourepetir);
  }
  while(fecharourepetir == 1);
  break;



  }//switch


return 0;
}//main
