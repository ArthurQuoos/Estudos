#include <stdio.h>
#include <stdlib.h>
/*
A importância de R$ 780.000,00 será dividida entre três ganhadores de um concurso, sendo que:

   i. O primeiro ganhador receberá 46% do total.
   ii. O segundo receberá 32% do total.
   iii. O terceiro receberá o restante.

Calcule e imprima a quantia recebida por cada um dos ganhadores.
780000 % 100
% x 46
% x 32
32 + 46
780000 - 32 46
*/
int main(){
int premio = 780000;
int ganhador1;
int ganhador2;
int ganhador3;
int resto;
resto = premio / 100;
ganhador1 = resto * 46;
ganhador2 = resto * 32;
ganhador3 = premio - (ganhador1 + ganhador2);
printf("O preimeiro ganhador recebeu: %d\n",ganhador1);
printf("O segundo ganhador recebeu: %d\n",ganhador2);
printf("o terceiro ganhador recebeu: %d\n",ganhador3);
return 0;
}
