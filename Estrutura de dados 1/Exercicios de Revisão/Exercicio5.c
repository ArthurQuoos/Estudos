/*
@file: Exercicio5.c
@date: 13/03/2022
@author: Arthur Albert Schmaiske Quoos
@brief: Exercicio de revisao sobre Structs
*/
/*
================================================================================
Defina um tipo abstrato de dados que ir´a representar bandas de m´usica.
Essa estrutura deve ter o nome da banda, que tipo de m´usica ela toca, o n´umero
de integrantes, e em que posi¸c˜ao do ranking essa banda est´a dentre as suas 5
bandas favoritas.
a) Crie uma fun¸c˜ao para preencher as 5 estruturas de bandas criadas no exemplo passado;
b) Ap´os criar e preencher, exiba todas as informa¸c˜oes das bandas/estruturas;
c) Crie uma fun¸c˜ao que pe¸ca ao usu´ario um n´umero de 1 at´e 5. Em seguida, seu programa deve exibir
informa¸c˜oes da banda cuja posi¸c˜ao no seu ranking ´e a que foi solicitada pelo usu´ario.
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char nome[21];
  char estilo[21];
  int membros;
  int ranking;
}Bandas;
//Preenchendo a struct
void Preenche(Bandas Top[5]){
printf("Insira as informacoes das bandas!!!\n");
for (int i = 0; i < 5; i++) {
  printf("\n==================================================================\n");
  printf("O nome da banda %d: ",i+1);
  setbuf(stdin,NULL);
  fgets(Top[i].nome,21,stdin);
  Top[i].nome[strcspn(Top[i].nome,"\n")]='\0';
  printf("Qual o estilo da banda %d: ",i);
  setbuf(stdin,NULL);
  fgets(Top[i].estilo,21,stdin);
  Top[i].estilo[strcspn(Top[i].estilo,"\n")]='\0';
  printf("Quantos membros essa banda tem? ");
  scanf("%d",&Top[i].membros);
  //Condicao para que esteja dentro do intervalo de 1 a 5
  do{
  printf("Qual a posicao dessa banda no meu top5(de 1 a 5)? ");
  scanf("%d",&Top[i].ranking);
  }while(Top[i].ranking > 5 || Top[i].ranking < 1);
}
  return;
}

int Pesquisar(Bandas Top[5],int x){
  int aux;
  for (int i = 0; i < 5; i++) {
    if(Top[i].ranking == x){
      aux = i;
      return aux; //retornando apenas a posicao dentro da struct
    }
  }
}

int main(){
  Bandas Top[5];
  int x;
  Preenche(Top);
  printf("\n==================================================================\n");
  for (int i = 0; i < 5; i++) { //imprimindo para verificar se a funcao funcionou
      printf("Nome da banda %d: %s\n",i+1,Top[i].nome);
      printf("Estilo da banda: %s\n",Top[i].estilo);
      printf("Numero de membros: %d\n",Top[i].membros);
      printf("Posicao do Top5: %d\n",Top[i].ranking);
  }
  printf("\n==================================================================\n");
  printf("Qual banda voce quer pesquisar?(de 1 a 5) ");
  scanf("%d",&x);
  x = Pesquisar(Top,x); // x <- recebendo a posicao da struct
  printf("Nome da banda: %s\n",Top[x].nome);
  printf("Estilo da banda: %s\n",Top[x].estilo);
  printf("Numero de membros: %d\n",Top[x].membros);
  printf("Posicao do Top5: %d\n",Top[x].ranking);

return 0;
}
