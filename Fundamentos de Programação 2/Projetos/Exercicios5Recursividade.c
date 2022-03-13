/*
@file: Exercicios5Recursividade.c
@date: 13/05/2021
@author: Arthur Albert Schmaiske Quoos
@brief: multplicacao usando somas e recursividade.
*/
/*
================================================================================
Crie uma função que retorne x*y através de operação de soma.
A função recebe x e y por parâmetro
================================================================================
*/

//passo0:entender a logica
// multplicacao 5 * 5 = 5 + multplicacao 5,4
// multplicacao 5 * 4 = 5 + multplicacao 5,3
// multplicacao 5 * 3 = 5 + multplicacao 5,2
// multplicacao 5 * 2 = 5 + multplicacao 5,1
// multplicacao 5 * 1 = 5 caso base
/*
#include <stdio.h>
#include <stdlib.h>
//passo1: Funcao recursiva para calcular x*y
int multplicacao(int x,int y){
  if(y == 1){
    return x;
  }else{
    return x + multplicacao(x,y-1); //somando usando o return
  }//else
}//multplicacao

//passo2: Main para receber e exibir o valor calculado
int main(){
int produto;
produto = multplicacao(5,5);
printf("Resultado: %d\n",produto);
  return 0;
}//main
*/

/*
================================================================================
Crie uma função que retorne x elevado a y através de operação de multiplicação.
A função recebe x e y por parâmetro
================================================================================
*/
/*
#include <stdio.h>
#include <stdlib.h>
//passo1: Criar a funcao para calcular o valor de x.
//nesse caso o valor ira voltar por z
int powfalso(int x, int y, int z){
  if(y == 1){
    return z;
  }else{
  z = z * x;
  powfalso(x,y-1,z);
  }//else
}//powfalso

//passo2: Criar a main para receber os valores por parametro e exibir os resultados
int main(){
int produto;
  produto = powfalso(2,4,2);  //z precisa ter o mesmo valor de x para funcionar
printf("Resultado: %d\n",produto);

  return 0;
}
*/

/*
================================================================================
Crie uma função que retorne o fatorial de um número passado por parâmetro.

fatorial(n):

  =1 se n=0

  = n x fatorial (n-1) se n>0
================================================================================
*/
/*
#include <stdio.h>
#include <stdlib.h>

//passo1: criando a funcao com as condicoes que o enunciado pede
int fatorial(int n){
if(n == 0){ //para o caso de n = 0
  return 1;
  }else{
    if(n > 0){  //para o caso de n > 0
      return n * fatorial(n-1);
    }//if
  }//else
}//fatorial
//passo2: Inserir por parametro o valor de n e exibir o resultado
int main(){
  int produto;
  produto = fatorial(5);
printf("Resultado: %d\n",produto);
  return 0;
}
*/
/*
================================================================================
Faça uma função recursiva que retorne o n-ésimo termo da sequência de Fibonacci,
sendo que n é recebido por parâmetro. Utilize essa função para desenvolver um
programa que mostre no main() os n termos dessa sequência na tela,
a partir do valor de n recebido pelo teclado.
Sabe-se que o 1º termo é 0 e o 2º termo é 1.
================================================================================
*/
/*
#include <stdio.h>
#include <stdlib.h>

//passo1: Variavel global necessaria
int tn;
int tn1 = 0;
int tn2 = 1;
//passo2: Funcao para calcular a sequencia de Fibonacci
int Fibonacci(int n){
  if(n == 2){
    return tn; //retornando o n-esimo numero da sequencia
  }else{
    tn = tn1 + tn2;
    tn1 = tn2;
    tn2 = tn;
    Fibonacci(n-1);
  }
}
//passo3: Main para adquirir o valor de n e para exibir o resultado da funcao
int main(){
  int n;
  int produto;
  printf("Qual numero da sequencia de Fibonacci voce deseja?\n");
  scanf("%d",&n);

produto = Fibonacci(n);
  printf("O termo correspondente: %d \n",produto);
  return 0;
}
*/
/*
================================================================================
Um problema típico em ciência da computação consiste em converter um número
da sua forma decimal para binária. Crie um algoritmo recursivo para resolver esse problema.

●Solução trivial: x=0 quando o número inteiro já foi convertido para binário

●Passo da recursão: saber como x/2 é convertido. Depois,
imprimir um dígito (0 ou 1) dado o sucesso da divisão.
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//passo1: criar a funcao para converter o um numero
int converter(int x){
  if(x % 2 == 0){
    printf("0");
  }else{
    printf("1");
  }//else
  if(x == 1||x == 0){ //verificar se ainda e possivel dividir
    printf("\n"); //so pra ficar bunito.
    return x; //retornando nada =/
  }else{
    x = x / 2;
    converter(x);
  }//else
}//converter
//passo2: Main para conectar a funcao ao programa e adquirir o numero a ser convertido
int main(){
  int x;
  printf("Qual numero decimal voce deseja converter para binario?");
  scanf("%d",&x);
  converter(x);

  return 0;
}


/*
================================================================================
Considere a função X abaixo:

int X(int a){
  if(a <=0) return0;
  else return a + X(a-1);
}//X

O que essa função faz? Escreva uma função não-recursiva que resolve o mesmo problema.
================================================================================
*/
/*
#include <stdio.h>
#include <stdlib.h>

//passo1: Criar a funcao X imitando a funcao do enunciado sem a recursiva
int X(int a){
  int copia = a; //copia para facilitar
  copia -= 1; //..."a + X(a-1);"
  for (copia ; copia >= 0; copia--) {
  a += copia;
}//for
  return a;//retornando o resultado
}
//passo2:Criar a main para conectar a funcao ao programa e Exibir o resultado
int main(){
  int Res;
  Res = X(5);
  printf("Resultado: %d\n",Res);

  return 0;
}//main
*/
