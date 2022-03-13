/*
@file: Exercicios9ArqBinario.c
@date: 23/11/2021
@author: Arthur Albert Schmaiske Quoos
@brief:
*/
/*
================================================================================
Faça um programa que gere 100 números aleatórios. Esse programa deverá,
em seguida,armazenar esses números em um arquivo binário.
================================================================================
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(){
//variaveis necessarias
FILE *arq;
int x[100];
//para garantir que a funcao rand() sempre gere um valor diferente
srand(time(NULL));
//abrindo o arquivo
arq = fopen("TexBin.txt","wb");

for (size_t i = 0; i < 100; i++) {
  //Gerando valores e armazenando
  x[i] = rand() % 100;
//printf("%d ",x[i]);
}
//Escrevendo no arq todos os valores armazenados
  fwrite(x,sizeof(int),100,arq);

fclose(arq);

  return 0;
}
*/
/*
================================================================================
Elabore um programa que leia um arquivo binário contendo 100 números.
Mostre na tela a soma desses números
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
//declarando as variaveis e abrindo o arquivo
FILE *arq = fopen("TexBin.txt","rb");
int x[100];
int aux = 0;
//Lendo o arquivo e adquirindo os valores lidos
fread(x,sizeof(int),100,arq);
//Exibindo em "tabela" as informacoes
for (size_t i = 0; i < 100; i++) {
  printf("%d ",x[i]);
  aux++;
  if (aux == 10) {//pra ficar bunitinho
    printf("\n");
    aux = 0;
  }
}

fclose(arq);

  return 0;
}

/*
================================================================================
Crie uma estrutura representando um atleta. Essa estrutura deve conter o nome do
atleta, seu esporte, idade e altura. Agora, escreva um programa que leia os
dados de cinco atletas e os armazene em um arquivo binário
================================================================================
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Criando toda a estrutura como requisitado
typedef struct{
char nome[21];
char esporte[21];
int idade;
float altura;
}Atleta;

int main(){
  //variaveis necessarias
FILE *arq;
Atleta Atletas[5]; //chamando a struct

//preenchendo a struct
for (int i = 0; i < 5; i++) {
  printf("Insira o nome do %d atleta:\n",i+1);
  setbuf(stdin,NULL);
  fgets(Atletas[i].nome,21,stdin);
  Atletas[i].nome[strcspn(Atletas[i].nome,"\n")]='\0';
  printf("Qual a modalidade deste atleta:");
  setbuf(stdin,NULL);
  fgets(Atletas[i].esporte,21,stdin);
  Atletas[i].esporte[strcspn(Atletas[i].esporte,"\n")]='\0';
  printf("Qual a idade deste atleta?\n");
  setbuf(stdin,NULL);
  scanf("%d",&Atletas[i].idade);
  printf("Qual a altura deste atleta?\n");
  setbuf(stdin,NULL);
  scanf("%f",&Atletas[i].altura);
}

arq = fopen("TexBin.txt","wb");

//passando as informacoes para o arquivo
  for (size_t i = 0; i < 5; i++) {
    fwrite(Atletas[i].nome,sizeof(char),21,arq);
    fwrite(Atletas[i].esporte,sizeof(char),21,arq);
    fwrite(&Atletas[i].idade,sizeof(int),1,arq);
    fwrite(&Atletas[i].altura,sizeof(float),1,arq);
  }
//fechando o arquivo
fclose(arq);

  return 0;
}
*/
/*
================================================================================
Considerando a estrutura atleta do exercício anterior, escreva um programa que
leia um arquivo binário contendo os dados de cinco atletas. Calcule e exiba o
nome do atleta mais alto e do mais velho.
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{ //ctrl + v da anterior
char nome[21];
char esporte[21];
int idade;
float altura;
}Atleta;

int main(){
//variaveis necessarias
Atleta Atletas[5];
FILE *arq = fopen("TexBin.txt","rb");
int aux;
float maiorF;
int maiorI;

//lendo as informacoes e salvando na struct
  for (size_t i = 0; i < 5; i++) {
      fread(Atletas[i].nome,sizeof(char),21,arq);
      fread(Atletas[i].esporte,sizeof(char),21,arq);
      fread(&Atletas[i].idade,sizeof(int),1,arq);
      printf("%d\n",Atletas[i].idade);
      fread(&Atletas[i].altura,sizeof(float),1,arq);
      printf("%f\n",Atletas[i].altura);
  }
//o arquivo ja nao e mais necessario
fclose(arq);
//separando o mais alto
maiorF = Atletas[0].altura;
  for (size_t i = 0; i < 5; i++) {
      if(Atletas[i].altura > maiorF){
        maiorF = Atletas[i].altura;
        aux = i;
      }
  }
//exibindo
  printf("O nome do Atleta mais alto e: %s\n",Atletas[aux].nome);
//separando o mais velho
  maiorI = Atletas[0].idade;
  for (size_t i = 0; i < 5; i++) {
      if(Atletas[i].idade > maiorI){
        maiorI = Atletas[i].idade;
        aux = i;
      }
  }
//exibindo
  printf("O nome do Atleta mais velho e: %s\n",Atletas[aux].nome);

  return 0;
}

/*
================================================================================
Crie uma estrutura representando um ranking. Essa estrutura deve conter o nome
do jogador e sua pontuação. Em seguida, escreva um programa que leia os dados
de 5 jogadores e os armazene em um arquivo utilizando a tecnica de Dados
formatados.
================================================================================
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//struct requisitada
typedef struct{
  char nome[21];
  int rank;
}Top5;

int main(){
FILE *arq; //ptr do arq
Top5 Atletas[5]; //chamando a struct

//preenchendo a struct
  for (size_t i = 0; i < 5; i++) {
    printf("Insira o nome do %d jogador:\n",i+1);
    setbuf(stdin,NULL);
    fgets(Atletas[i].nome,21,stdin);
    Atletas[i].nome[strcspn(Atletas[i].nome,"\n")]='\0';
    printf("Insira a pontuacao deste Atleta:\n");
    scanf("%d",&Atletas[i].rank);
  }
//abrindo o arq
  arq = fopen("Texto2.txt","w");
//escrevendo no arq
  for (size_t i = 0; i < 5; i++) {
    fprintf(arq,"Nome do %d atleta: %s\n",i+1,Atletas[i].nome);
    fprintf(arq,"A pontuacao do %d atleta: %d\n",i+1,Atletas[i].rank);
  }

fclose(arq);
  return 0;
}
*/
/*
================================================================================
Considerando a estrutura ranking do exercício anterior, escreva um programa que
leia o arquivo gerado contendo os dados dos 5 jogadores
================================================================================
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//ctrl+c na estrutura anterior
typedef struct{
  char nome[21];
  int rank;
}Top5;

int main(){
//variaveis necessarias e fopen no arquivo
FILE *arq = fopen("Texto2.txt","r");
Top5 Atletas[5];
int aux; // apenas para prevenir erros no fscanf
//verificar o arquivo
if(arq == NULL){
  printf("ERRO\n");
  exit(1);
}
//Extraindo as informacoes do arquivo
for (size_t i = 0; i < 5; i++) {
fscanf(arq,"Nome do %d atleta: %s\n",&aux,Atletas[i].nome);
fscanf(arq,"A pontuacao do %d atleta: %d\n",&aux,&Atletas[i].rank);
}
//printf apenas para verificar se esta tudo certo
for (size_t i = 0; i < 5; i++) {
  printf("Nome do %d atleta: %s\n",i+1,Atletas[i].nome);
  printf("A pontuacao do %d atleta: %d\n",i+1,Atletas[i].rank);
  printf("\n");
}

return 0;
}
*/
