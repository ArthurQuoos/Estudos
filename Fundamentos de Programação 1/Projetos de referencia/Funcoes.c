#include <stdio.h>
#include <stdlib.h>

void mensagem();
float soma(float n1, float n2);
void mensageminterna();

int main(){
  float resultado;
  resultado = soma(2,4);
  printf("%.2f\n",resultado);
  mensagem();
  return 0;
}//main


void mensagem(){
  printf("...> Dentro da mensagem\n");
  mensageminterna();
return;
}//mensagem

float soma(float n1, float n2){
  return n1 + n2;
}//soma

void mensageminterna(){
  printf("...> Dentro da mensageminterna\n");
  return;
}//interna
