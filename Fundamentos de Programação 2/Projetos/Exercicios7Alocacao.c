/*
@file: Exercicios7Alocacao.c
@date: 16/11/2021
@author: Arthur Albert Schmaiske Quoos
@brief:
*/
/*
================================================================================
Elabore um programa que leia do usuário o tamanho de um vetor a ser lido.
Em seguida, faça a alocação dinâmica desse vetor. Por fim, leia o vetor do
usuário e o imprima.
================================================================================
*/
/*
#include <stdio.h>
#include <stdlib.h>

int main(){

int *vetor;
int x;
//adquirindo o tamanho do vetor
printf("Qual o tamanho do vetor?\n");
scanf("%d",&x);

//alocando o espaco
  vetor = (int*) malloc(x * sizeof(int));

//preencher o vetor
printf("Agora preencha o vetor\n");
for (size_t z = 0; z < x; z++) {
  scanf("%d",&vetor[z]);
}
//Exibir
for (size_t i = 0; i < x; i++) {
  printf("vetor[%d]: %d\n",i,vetor[i]);
}
//Liberar o espaco
  free(vetor);

return 0;
}
*/
/*
================================================================================
Escreva uma função que receba um valor inteiro positivo N por parâmetro e retorne
o ponteiro para um vetor de tamanho N alocado dinamicamente.
Se N for negativo ou igual a zero, um ponteiro nulo deverá ser retornado
================================================================================
*/
/*
#include <stdio.h>
#include <stdlib.h>

//passo1: criar a funcao recebendo n, atencao ao tipo de retorno
int* AlocaVetor(int n){
  int *ptr;
ptr = (int*) malloc(n * sizeof(int));
//para o caso de n negativo
if(n <= 0){
    ptr = NULL;
    printf("alocado NULL\n");
}//Exibir para testar
if(ptr != NULL){
  printf("Alocado com sucesso\n");
}else{
  printf("Nao foi alocado\n");
}
  return ptr;
}

int main(){
int *vetor;
//retornando para o vetor
vetor = AlocaVetor(10);
//Liberando o espaco
free(vetor);

  return 0;
}
*/

/*
================================================================================
Escreva uma função que receba como parâmetro dois vetores via referência( A e B)
e o tamanho N. A função deve retornar o ponteiro para um vetor C de tamanho N
alocado dinamicamente, em que:
C[i] = A[i] * B[i]
================================================================================
*/
/*
#include <stdio.h>
#include <stdlib.h>

//Funcao recebendo dois vetores e o tamanho n
int* Vetores(int* vetorA,int* vetorB, int n){

  int* vetorC = (int*) malloc(n * sizeof(int));

  //vetorC = (int*) malloc(n * sizeof(int));


  for (int i = 0; i < n; i++) {
    vetorC[i] = (vetorA[i]) * (vetorB[i]);
}
//retornando os valores para um vetor com ponteiro
  return vetorC;
}

int main(){
  int n = 3;
int *vetorA = (int*) malloc(n * sizeof(int));
int *vetorB = (int*) malloc(n * sizeof(int));
int *vetorC;

//preencher os vetores para testar o codigo
printf(" - Preencher os vetores - \n");
for (int x = 0; x < n; x++) {
  printf("VetorA[%d]:",x);
  scanf("%d",&vetorA[x]);
}
for (int y = 0; y < n; y++) {
  printf("VetorB[%d]:",y);
  scanf("%d",&vetorB[y]);
}

  vetorC = Vetores(vetorA,vetorB,n);
//Exibindo
for (int i = 0; i < n; i++) {
  printf("VetorC[%d] = %d\n",i,vetorC[i]);
}
//liberando o espaco
  free(vetorA);
  free(vetorB);
  free(vetorC);

return 0;
}
*/

/*
================================================================================
Escreva uma função que receba como parâmetro um valor L e um valor C e retorne o
ponteiro para uma matriz alocada dinamicamente contendo L linhas e C colunas.
Essa matriz deve ser inicializada com o valor 0 em todas as suas posições.
================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
//Funcao com parametro L e C
int** AlocaMatriz(int l,int c){
   //alocando espaco para a matriz_auxiliar
  int** matriz_aux = (int**) malloc(l * sizeof(int*));
for (int i = 0; i < c; i++) {
  //alocando vetor para cada linha
  matriz_aux[i] = (int*) malloc(c * sizeof(int*));
}
  //igualando a zero para retira qualquer lixo
  for (int x = 0; x < l; x++) {
    for (int y = 0; y < c; y++) {
      matriz_aux[x][y] = 0;
    }
  }
//retornando a matriz_auxiliar para a matriz_main
  return matriz_aux;
}

int main(){
int** matriz;
int l = 4;
int c = 4;

  matriz = AlocaMatriz(l,c);
  //Exibindo
for (int x = 0; x < l; x++) {
  for (int y = 0; y < c; y++) {
printf("%d ",matriz[x][y]);
  }
  printf("\n");
}

//Limpando
  for (size_t y = 0; y < l; y++) {
    free(matriz[y]);
  }
  free(matriz);
   //acho que estou limpando a matriz errado mas ta ai

  return 0;
}
