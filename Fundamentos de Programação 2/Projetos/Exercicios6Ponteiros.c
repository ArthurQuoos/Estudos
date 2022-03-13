/*
@file: Exercicios6Ponteiros.c
@date: 10/11/2021
@author: Arthur Albert Schmaiske Quoos
@brief:
*/
/*
================================================================================
Escreva um programa que contenha duas variáveis inteiras. Compare os endereços
e exiba o endereço e o conteúdo do maior endereço.
================================================================================
*/
/*
#include <stdio.h>
#include <stdio.h>

int main(){
//passo1: Criar as variaveis como pode o enunciado
int x = 10, y = 5;
int *ptr, *ptr1;
//passo2: atribuir os enderecos das variaveis aos ponteiros
  ptr = &x;
  ptr1 = &y;
//passo3: uma simples comparacao entre eles
  if(*ptr > *ptr1){
    printf("A variavel x com valor %d e endereco %p e maior\n", *ptr,ptr);
  }else{
    printf("A variavel y com valor %d e endereco %p e maior\n", *ptr1,ptr1);
  }//else
  return 0;
}//main
*/
/*
================================================================================
Crie um programa que contenha um vetor float (tamanho 10).
Imprima o endereço de cada posição desse vetor.
================================================================================
*/
/*
#include <stdio.h>
#include <stdlib.h>

//passo1: Criar um programa com um vetor float
int main(){
float vet[10];
float *ptrVet = vet;

//passo2: Exibir o endereco de cada posicao
for (int i = 0; i < 10; i++) {
  printf("Vetor%d - %p\n",i,(ptrVet+i));
}

  return 0;
}
*/
/*
================================================================================
Crie um programa que contenha uma matriz (3x3) de float.
Imprima o endereço de cada posição dessa matriz.
================================================================================
*/
/*
#include <stdio.h>
#include <stdlib.h>

int main(){
//passo1: Declarando a matriz
float matriz[3][3];
//float **ptrMat = matriz; //nao tava dando certo com essa linha
//passo2: usar um for aninhado para exibir em formato de tabela
for (int y = 0; y < 3; y++) {
  for (int x = 0; x < 3; x++) {
    printf("%p ",&matriz[x][y]);
  }
  printf("\n");
}

  return 0;
}
*/
/*
================================================================================
Crie um programa que contenha um vetor de inteiros de tamanho 5.
Utilizando aritmética de ponteiros, leia os dados do teclado e exiba seus
valores multiplicado por 2.
Em seguida, exiba o endereço de memória das posições que contém valores pares.
================================================================================
*/
/*
#include <stdio.h>
#include <stdlib.h>
//passo1: Criando um vetor de tamanho 5 como exigido
  int main(){
int vet[5];
int *ptrVet = vet;
//passo2: Lendo os dados do teclado
printf("Insira 5 valores inteiros:\n");
  for (size_t i = 0; i < 5; i++) {
    scanf("%d",&vet[i]);
  }//for

ptrVet = vet;//atribuindo o vetor ao ponteiro
//passo3: Exibindo o valor multiplicado
printf("Valores multiplicados por 2\n");
  for (int i = 0; i < 5; i++) {
    printf("Vetor%d: %d \n",i,*(ptrVet+i)+*(ptrVet+i));//ou *(ptrVet)*2
  }//for
//passo4: Exibindo o endereco dos valores pares
  printf("Endereco de memorias com valores pares:\n");
  for (int i = 0; i < 5; i++) {
    if((*(ptrVet+i) % 2)==0){
      printf("Vetor%d: %p\n",i,(ptrVet+1));
    }
  }
}//main
*/
/*
================================================================================
Elabora uma função que receba duas strings como parâmetros e verifique
se a segunda string está dentro da primeira. Para isso,
utilize apenas aritmética de ponteiros.
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Criar a funcao declarando os ponteiros
void StrStrManual(char* ptr1,char* ptr2){
  int Ta, Tb;
  int aux = 0; //auxiliar
//adqurindo o tamanho das strings
Ta = strlen(ptr1);
Tb = strlen(ptr2);

    for (size_t i = 0; i < Ta; i++) {
      if(ptr1[i] == ptr2[aux]){ //verificando letra por letra
        aux++; //se V, ira comparar a proxima letra [i] com a proxima de [aux]
      }else{
        if(aux < Tb){
          aux = 0; //se F, resetar aux
        }
      }
    }//for
//Exibir o resultado, se encontrar todas as letras aux ira ficar com valor = Tb
  if(Tb == aux){
    printf("Substring encontrada\n");
  }else{
    printf("Substring nao encontrada\n"); //caso contrario
  }
}

int main(){
  char fraseA[21] = "Amendoboboyeah";
  char fraseB[21] = "bobo";

  StrStrManual(fraseA,fraseB); //enviando as frases para os ponteiros

  return 0;
}//main

/*
================================================================================
Considere a seguinte declaração:
   int a, *b, **c, ***d;
   Escreva um programa que receba o valor de a, calcule e exiba:

O dobro do valor a, utilizando o ponteiro b
O triplo do valor a, utilizando o ponteiro c
O quadruplo do valor a, utilizando o ponteiro d
================================================================================
*/
/*
#include <stdio.h>
#include <stdlib.h>

int main(){
//passo1:
int a = 5;
int *b = &a, **c = &b, ***d = &c;

printf("%d - %p\n",a, &a);

printf("%d - %p\n",(*b)*2, b);

printf("%d - %p\n",(**c)*3, c);

printf("%d - %p\n",(***d)*4, d);

  return 0;
}
*/
