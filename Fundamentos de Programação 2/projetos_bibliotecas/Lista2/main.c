/*
@file: ****.c
@date: ***
@author: Arthur Albert Schmaiske Quoos
@brief: ***
*/
/*
================================================================================
1) Crie uma função que receba uma string e retorne o ponteiro para essa string
invertida.
================================================================================
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "inverteString.h"

char* inverteString(char msg[101]){
int tamanho;
int aux = 0;
    tamanho = strlen(msg);
int copiaTamanho = tamanho;

  char *invertida = (char*) malloc(tamanho * sizeof(char));

  for (tamanho;tamanho >= 0;tamanho--) {
      invertida[aux] = msg[tamanho-1];
      aux++;
      }

      invertida[copiaTamanho] = '\0';

  return invertida;
}

int main(){
char msg[21] = "Amendobobo";
char *inv;
printf("%s\n",msg);
inv = inverteString(msg);
printf("%s\n",inv);


  return 0;
}
*/

/*
================================================================================
2) Escreva uma função que receba como parâmetro uma matriz A contendo N linhas e
N colunas. A função deve retornar o ponteiro para um vetor B de tamanho N alocado
dinamicamente, em que cada posição de B é a soma dos números daquela coluna da
matriz.
================================================================================
*/
/*
#include <stdio.h>
#include <stdlib.h>

int* somaColunasM(int n,int matriz[n][n]){
int *vetorB;

  vetorB = (int*) malloc(n * sizeof(int));

for (size_t i = 0; i < n; i++) { //igualando a zero
  vetorB[i] = 0;
}

for (size_t i = 0; i < n; i++) {
  for (size_t z = 0; z < n; z++) {
    vetorB[i] += matriz[z][i];
  }
}

  return vetorB;
}

int main(){
int n = 3;
int *vetorC = (int*) malloc(n * sizeof(int));
int matriz[n][n];

printf("Preencha a matriz:\n");
for (size_t x = 0; x < n; x++) {
  for (size_t y = 0; y < n; y++) {
    printf("Linha: %d Coluna: %d \n",x,y);
    scanf("%d",&matriz[x][y]);
  }
}

vetorC = somaColunasM(n, matriz);

printf("Soma das colunas da matriz:\n");
for (size_t x = 0; x < n; x++) {
  printf("%d ",vetorC[x]);
}

  return 0;
}
*/
/*
================================================================================
3) Escreva uma função que receba como parâmetro duas matrizes, A e B, e seus tamanhos.
A função deve retornar o ponteiro para uma matriz C, em que C é o produto da
multiplicação da matriz A pela matriz B. Se a multiplicação das matrizes não for
possível, retorne um ponteiro nulo.
================================================================================
*/
/*
#include <stdio.h>
#include <stdlib.h>

int** multiplicaMatriz(int linha_A,int coluna_A, int linha_B,int coluna_B,
                       int matrizA[linha_A][coluna_A],int matrizB[linha_B][coluna_B]){
//Verificando se e possivel multiplicar
  if (coluna_A != linha_B){
     printf("Impossivel multiplicar\n");
     return NULL;
     }

//alocando espaco para a matrizProduto
     int** matrizP = (int**) malloc(linha_A * sizeof(int*));
     for (int i = 0; i < linha_A ; i++) {
     matrizP[i] = (int*) malloc(coluna_B * sizeof(int));
     }//for

//multiplicando
  for (size_t linha = 0; linha < linha_A; linha++) {
    for (size_t coluna = 0; coluna < coluna_B; coluna++) {
      matrizP[linha][coluna] = 0;
      for (size_t i = 0; i < linha_A; i++) {
        matrizP[linha][coluna] += matrizA[linha][i] * matrizB[i][coluna];
      }//for
    }//for
  }//for


  return matrizP;
}


int main(){
  int **matrizFinal; //matriz que recebe
  int matrizA[5][3] = {{2,4,2},{3,6,1},{3,5,2},{1,2,1},{2,3,5}};
  int matrizB[3][5] = {{1,2,3,5,6},{4,6,1,2,3},{3,6,1,1,2}};
  //os tamanhos sao necessarios para enviar a matriz
  int linha_A = 5;
  int coluna_A = 3;
  int linha_B = 3;
  int coluna_B = 5;

matrizFinal = multiplicaMatriz( linha_A, coluna_A, linha_B, coluna_B,
                                matrizA, matrizB);

//Exibindo
  for (size_t linha = 0; linha < linha_A; linha++) {
    for (size_t coluna = 0; coluna < coluna_B; coluna++) {
  printf("%d ",matrizFinal[linha][coluna]);
  }
  printf("\n");
  }

  //liberar o espaco
  free(matrizFinal);
  for (size_t i = 0; i < linha_A; i++) {
      free(matrizFinal);
  }

  return 0;
}

*/
/*
================================================================================
4) Faça uma função que calcule receba um vetor de inteiros e retorne a soma de
seus elementos
================================================================================
*/
/*
#include <stdio.h>
#include <stdlib.h>

int somaVetor(int tm, int vetorA[tm]){
int soma = 0;

for (size_t i = 0; i < tm; i++) {
  soma += vetorA[i];
}

  return soma;
}

int main(){
int vetorA[5] = {1,2,3,4,5};
int tm = sizeof(vetorA) / sizeof(int);
int resultado = somaVetor(tm,vetorA);

printf("Resultado: %d\n",resultado);

  return 0;
}
*/

/*
================================================================================
5) Faça um programa contendo uma função que receba o nome de um arquivo de texto
contendo uma sequencia de números, o primeiro valor representa o tamanho da
sequencia (quantidade de elementos) e salve os dados em um vetor alocado
dinamicamente e retorne esse vetor.
================================================================================
*/
/*
#include <stdio.h>
#include <stdlib.h>

int* lerVetor(char nomeArquivo[21]){
  FILE *arq;
  int tm;
  int *vetor;

  arq = fopen(nomeArquivo,"r");
  if (arq == NULL){
     printf("Erro na abertura do arquivo\n");
     exit(1);
   }

  fscanf(arq,"%d",&tm);

  vetor = (int*) malloc(tm * sizeof(int));

  for (size_t i = 0; i < tm; i++) {
      fscanf(arq,"%d",&vetor[i]);
    }
//exibir
  for (size_t i = 0; i < tm; i++) {
      printf("Vetor = %d\n",vetor[i]);
    }

fclose(arq);

  return vetor;
}

int main(){

int *vetorFinal = lerVetor("Textinho.txt");

int tm = sizeof(vetorFinal);
printf("%d\n",tm);
tm = sizeof(vetorFinal) / sizeof(int);
printf("%d\n",tm);
for (size_t i = 0; i < tm; i++) {
  printf("Vetor main: %d\n",vetorFinal[i]);
}

free(vetorFinal);

  return 0;
}
*/
/*
================================================================================
6) Usando as funções anteriores, crie um programa que leia um vetor de dados em
um arquivos, calcule a soma desse vetor utilizando outra função e escreva a
resposta no final arquivo original adicionando uma nova linha contendo
"A soma dos valores é <valor>"
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>

int* lerVetor(char nomeArquivo[21],int *tm){
  FILE *arq;
  int tmcopia;
  int *vetor;
  arq = fopen(nomeArquivo,"r");
  if (arq == NULL){
     printf("Erro na abertura do arquivo\n");
     exit(1);
   }
  fscanf(arq,"%d",&tmcopia);
  *tm = tmcopia;
  vetor = (int*) malloc(tmcopia * sizeof(int));
  for (size_t i = 0; i < tmcopia; i++) {
      fscanf(arq,"%d",&vetor[i]);
    }
//exibir
  for (size_t i = 0; i < tmcopia; i++) {
      printf("Vetor = %d\n",vetor[i]);
    }
fclose(arq);
  return vetor;
}

int somaVetor(int tm,int *vetorA){
int soma = 0;

for (size_t i = 0; i < tm; i++) {
  soma += vetorA[i];
}
  return soma;
}

int main(){
FILE* arq = fopen("Textinho.txt","a");
if (arq == NULL){
   printf("Erro na abertura do arquivo\n");
   exit(1);
 }
int tam;
int *vetorFinal = lerVetor("Textinho.txt",&tam);
int somaDoVetor = somaVetor(tam,vetorFinal);

fprintf(arq,"\nA soma do vetor e %d\n",somaDoVetor);

fclose(arq);
  return 0;
}
/*
================================================================================
7) Organize suas funções criando sua própria biblioteca em arquivos separados:
um com os cabeçalhos e include guards (.h) e outro com as implementações das
funções (.c). o arquivo main.c que contém a função main deve importar e utilizar
as funções da biblioteca. Para compilar seu programa, faça um arquivo makefile.
================================================================================
*/
