/*
@file: Exercicio3.c
@date: 12/03/2022
@author: Arthur Albert Schmaiske Quoos
@brief: Exercicio de revisao sobre funcoes recursivas
*/
/*
================================================================================
Escreva uma fun¸c˜ao recursiva para calcular o valor de um n´umero inteiro de base
x elevada a um expoente inteiro y.
================================================================================
*/
#include <stdio.h>


//o expoente funciona como um contador enquanto a aux multiplica o x.
int powRecursivo(int x, int expoente,int aux){
if(expoente == 1){
  return x;
}else{
  x = x * aux;
  powRecursivo(x,expoente-1,aux);
}

}

int main(){
    int x = 2;
    int expoente = 5;
    int aux = x;
    int resultado;
    printf("%d elevado a %d e igual a:",x,expoente);
resultado = powRecursivo(x,expoente,aux);
    printf(" %d\n",resultado);

return 0;
}
