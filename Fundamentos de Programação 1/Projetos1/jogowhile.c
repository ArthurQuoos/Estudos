/*
Faça um programa que simule um jogo,
onde o usuário deverá descobrir um número aleatório
escolhido pelo computador (de 1 a 100).
O usuário poderá realizar até 6 tentativas,
 o programa deverá retornar as mensagens “muito alto”,
“muito baixo” até o usuário acertar o número
ou esgotar o número máximo de tentativas

Dica: Pesquise sobre como gerar um numero aleatório
utilizando a função rand da biblioteca math.h
*/
/*
@file: jogowhile.c
@date: 14/07/2021
@author: Arthur Albert Schmaiske Quoos
@brief: jogo de adivinhacao com while
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <windows.h>//iiiiiii o professor usa o linux, ai azedou pra por musica
int main(){
int chute;
int contador = 6;
int x;
srand(time(NULL));
printf("Jogo de adivinhacao\n");
printf("Pressione qualquer botao para comecar (exceto barra de espaco) ");
getchar();
Beep (330,100);Sleep(100);//comecinho da musica do super mario
Beep (330,100);Sleep(300);
Beep (330,100);Sleep(300);
Beep (262,100);Sleep(100);
Beep (330,100);Sleep(300);
Beep (392,100);Sleep(700);


printf("Adivinhe um numero entre 0 a 100\n");
x = rand() % 100;
//printf("%d ", x );//teste
while(contador >0){
printf(" voce tem %d tem tentativas\n",contador);
scanf("%d",&chute);
contador--;
if(chute == x){
  printf("Voce acertou\nParabeins\nQue cara bom =o\n");
  return 0;
}else{
  if(contador == 0){
    printf("Voce perdeu, o numero era %d Treine mais\n",x);
    return 0;
}else{
  if(chute < x){
    printf("mais alto\n");

  }else{
    if(chute > x){
      printf("mais baixo\n");

        }//if final
      }//else3
    }//else2
  }//else1
}//while

return 0;
}//main
