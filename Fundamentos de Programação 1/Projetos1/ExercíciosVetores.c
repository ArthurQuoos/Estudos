/*
Faça um programa que leia e armazene dois vetores de tamanho 5.
Ao final o programa deve calcular e exibir o vetor soma;
==================================================================
Crie um algoritmo que receba 10 números e os armazene em um vetor A.
Em seguida,
gere o vetor B onde cada elemento é o quadrado do valor da mesma
posição no vetor A
==================================================================
Leia um vetor A com 10 elementos inteiros
correspondentes as idades de um grupo de pessoas.
Escreva um programa que determine e escreva a quantidade de pessoas que possuem
idade superior a 35 anos
==================================================================
Crie e inicialize um vetor de inteiros de tamanho 8.
 Faça a soma dos seus elementos, e apresente o resultado.
==================================================================
 Dado dois vetores, A (4 elementos) e B (5 elementos),
 faça um programa que imprima todos os elementos comuns aos dois vetores.
 ==================================================================
 Faça um programa que receba e armazene 20 números em um vetor.

 Em seguida exiba:

 –Quantos números são iguais a 30;
 –Quantos números são maior que a média;
 –Quantos números são iguais à media;
 ==================================================================

*/
/*
@file: ExerciciosVetores.c
@date: 27/07/2021
@author: Arthur Albert Schmaiske Quoos
@brief: vetores com muitas condicoes....
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main (){
/*
int a[5];
int b[5];
int c[5];       //vetor resultado
int soma;       //fiquei na duvida de como deveria ser feito entao fiz dos dois jeitos

for(int i=0;i <5;i++){     //armazenar cada um dos vetores.
  printf("Digite um valor para os vetores \"a\": ");
  scanf("%d",&a[i]);
  printf("a[%d]: %d\n",i,a[i]);
}
printf("\n");
for(int i=0;i <5;i++){     //armazenar cada um dos vetores2.
  printf("Digite um valor para os vetores \"b\": ");
  scanf("%d",&b[i]);
  printf("b[%d]: %d\n",i,b[i]);
}
for(int i=0;i <5;i++){
  c[i] = a[i] + b[i];      //somar cada vetor em um novo
  printf("O resultado da soma dos vetores: %d\n",c[i]);
}
*/
/*
int a[10];
int b[10];

for(int i=0;i <10;i++){  //armazenando
  printf("Digite um valor para os vetores \"a\": ");
  scanf("%d",&a[i]);
  b[i] = a[i];        //copiando os vetores
}
printf("\n");
for(int i=0;i <10;i++){
b[i] = b[i]* b[i];
printf("quadrado dos vetores a: %d\n",b[i]);
}
*/
/*
//passo1:Determinar o vetor[10] e armazenar os valores
int idades[10];
int meiaIdade = 0;
for(int i=0;i <10;i++){
  printf("Insira as idades das pessoas de um \"certo grupo\": ");
  scanf("%d",&idades[i]);
}//for
//passo2:Exibir os valores do vetor
printf("A idade de cada uma das pessoas do grupo\"x\"\n");
for(int i=0;i <10;i++){

  printf("%d ",idades[i]);

//passo3:criar uma condicao para exibir quantas pessoas tem + de 35anos

if(idades[i] >= 35){
  meiaIdade++;
}//if
}//for
printf("\nExistem %d pessoas com 35 anos ou mais.",meiaIdade);
*/
/*
//passo1: Crie um vetor[8] e inicialize-o
int vetorA[8] = {5,4,6,7,2,4,5,3};
//passo2: some todos os resultados em uma variavel auxiliar
int soma; //auxiliar
soma = vetorA[0] + vetorA[1] + vetorA[2]+ vetorA[3]+ vetorA[4]+ vetorA[5]+ vetorA[6]+ vetorA[7];
printf("Resultado da soma: %d\n",soma);
*/
/*
//passo1:Criar 2 vetores (a[4] e b[5])
int a[4] = {5,4,3,2};
int b[5] = {6,5,4,3,2};

//passo2:Criar uma condicao para imprimir os valores iguais entre os vetores
for(int i=0;i <5;i++){

 for(int x=0;x <4;x++){
      if(a[x] == b[i]){
      printf("Valor igual entre a[%d] e b[%d] = %d e %d\n",x,i,a[x],b[i]);
}//if
    }//for externo
  }//for interno
*/
//passo1: Crie um vetor[20] e armazene seus valores
int vetor[20];
int media,media2,media3;
for(int i=0;i <20;i++){
printf("Insira os valores do Vetor: ");
scanf("%d",&vetor[i]);
}

//passo2:Crie uma condicao para exibir valores == 30
//passo3:Crie uma condicao para exibir valores > que a media
//passo4:Crie uma condicao para exibir valores == a media
media = vetor[0]+vetor[1]+vetor[2]+vetor[3]+vetor[4]+vetor[5]+vetor[6]+vetor[7];
media2 =vetor[8]+vetor[9]+vetor[10]+vetor[11]+vetor[12]+vetor[13]+vetor[14];
media3 = vetor[15]+vetor[16]+vetor[17]+vetor[18]+vetor[19];
media = media + media2 + media3; //para nao ficar uma linha gigante
media = media / 20;
printf("\nvalor da media = %d\n",media);
for(int i=0;i <20;i++){
  if(vetor[i] ==30){
  printf("Valor == a 30 no vetor[%d]\n",i);
}//if
}//for
for(int i=0;i <20;i++){

if(vetor[i] > media){
  printf("Valor > media no vetor[%d]\n",i);
}//if2
}//for2
for(int i=0;i <20;i++){
if(vetor[i]==media){
  printf("Valor == a media no vetor[%d]\n",i);
}//if
}//for

  return 0;
}//main
