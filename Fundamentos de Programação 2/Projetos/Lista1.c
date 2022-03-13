/*
@file: Lista1.c
@date: 14/10/2021
@author: Arthur Albert Schmaiske Quoos
@brief: Lista de atletas
*/
/*
================================================================================
Crie uma estrutura representando um atleta. Essa estrutura deve conter o nome do atleta,
seu esporte, idade e altura. Agora, escreva um programa que leia os dados de cinco atletas.
Calcule e exiba os nomes do atleta mais alto e do mais velho.
================================================================================
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//passo1:Definir a struct como o enunciado pede.
typedef struct{
  char nome[21];
  char esporte[21];
  int idade;
  float altura;
}Atletas;
//passo2:Criar a main e preencher a struct
  int main(){
Atletas Atleta[5];

  printf("Top5 Atletas.\n");
  printf("Insira os dados dos Atletas:\n");
  for (int i = 0; i < 5; i++) {
    printf("================================================================\n");
    printf("Atleta #%d\n",i+1);

    printf("Insira o nome:\n");
    setbuf(stdin,NULL);
    fgets(Atleta[i].nome,21,stdin);
    Atleta[i].nome[strcspn(Atleta[i].nome,"\n")]='\0';

    printf("Qual esporte ele pratica?\n");
    setbuf(stdin,NULL);
    fgets(Atleta[i].esporte,21,stdin);
    Atleta[i].esporte[strcspn(Atleta[i].esporte,"\n")]='\0';

    printf("Qual a idade de %s?\n",Atleta[i].nome);
    scanf("%d",&Atleta[i].idade);

    printf("E qual a altura desse atleta?\n");
    scanf("%f",&Atleta[i].altura);
  }//for
  //passo3:Criar o programa para ler as informacoes e descobrir qual e o mais alto/velho
int maisvelho = 0;
int maisalto = 0;
int idade = 0;
int altura = 0;
  for (int x = 0; x < 5; x++) {
    if(Atleta[x].idade > idade){
      idade = Atleta[x].idade; //filtrando para encontrar o mais velho
      maisvelho = x; //armazenado qual posicao da lista o mais velho esta
    }//if
  }//for
  for (int t = 0; t < 5; t++) {
    if(Atleta[t].altura > altura){
      altura = Atleta[t].altura;
      maisalto = t;
    }//if
  }//for

//passo4: Exibir o mais velho e o mais alto
  printf("\nExibindo o Atleta mais velho: %s\n",Atleta[maisvelho].nome);
  printf("\nExibindo o Atleta mais alto: %s\n",Atleta[maisalto].nome);

  return 0;
}
*/
/*
================================================================================
Usando a estrutura “atleta” do exercício anterior, escreva um programa que leia
os dados de cinco atletas e os exiba por ordem de idade, do mais velho para o mais novo.
Dica: Procure pelo algoritmo BubbleSort no Google
================================================================================
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char nome[21];
  char esporte[21];
  int idade;
  float altura;
}Atletas;

void Preencher(Atletas Atleta[5]){

printf("Insira os dados dos Atletas:\n");
for (int i = 0; i < 5; i++) {
  printf("================================================================\n");
  printf("Atleta #%d\n",i+1);

  printf("Insira o nome:\n");
  setbuf(stdin,NULL);
  fgets(Atleta[i].nome,21,stdin);
  Atleta[i].nome[strcspn(Atleta[i].nome,"\n")]='\0';

  printf("Qual esporte ele pratica?\n");
  setbuf(stdin,NULL);
  fgets(Atleta[i].esporte,21,stdin);
  Atleta[i].esporte[strcspn(Atleta[i].esporte,"\n")]='\0';

  printf("Qual a idade de %s?\n",Atleta[i].nome);
  scanf("%d",&Atleta[i].idade);

  printf("E qual a altura desse atleta?\n");
  scanf("%f",&Atleta[i].altura);
  }//for
}//Preencher

void BubbleSort(Atletas Atleta[5]){
  int n = 5;
  int k, j;
  Atletas Auxiliar;

     for (k = 1; k < n; k++) {
        // printf("\n[%d] ", k);

         for (j = 0; j < n - 1; j++) {
          //   printf("%d, ", j);

             if (Atleta[j].idade > Atleta[j + 1].idade) {
                 Auxiliar      = Atleta[j];
                 Atleta[j]     = Atleta[j + 1];
                 Atleta[j + 1] = Auxiliar;
             }
         }
     }

  return;
}//BubbleSort

void Exibir(Atletas Atleta){

  printf("Nome: %s ",Atleta.nome);
  printf("Idade: %d \n",Atleta.idade);
}

  int main(){
Atletas Atleta[5];

Preencher(Atleta);
printf("\n======================================================================\n");

BubbleSort(Atleta);

for (int i = 0; i < 5; i++) {
Exibir(Atleta[i]);
}
printf("\n======================================================================\n");

return 0;
}//main
*/

/*
================================================================================
Elabore uma função que receba como parâmetro um valor inteiro n e gere
como saída um triângulo lateral formado por asteriscos conforme o exemplo a seguir,
em que usamos n = 4:
*
**
***
****
***
**
*
================================================================================
*/
/*
#include <stdio.h>
#include <stdlib.h>

void triangulo(int n){
  int i;
  int x;
  for ( i=1 ; i < n; i++) {
    for (x=0 ; x < i; x++) {
      printf("*");
    }
    printf("\n");
  }
  for ( i ; i > 0; i--) {
    for (x = 0; x < i; x++) {
      printf("*");
    }
    printf("\n");
  }
return ;
}

int main(){

  triangulo(10);

  return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>

float serieS(int n){
  if(n > 0){
    return (1+n*n)/(float)n + serieS(n-1);
  }else{
    return 0;
  }
}

int main(){
  printf("S = %f\n",serieS(5));

  system("pause");
  return 0;
}
