/*
@file: Prova1.c
@date: 27/10/2021
@author: Arthur Albert Schmaiske Quoos
@brief:
*/
/*
================================================================================
Você foi contratado pela Riot Games para elaborar partes do sistema sistema de
Ranking do League of Legends. Para isso:

a) Defina um tipo e estrutura para salvar os dados de jogadores para um Ranking.
Cada jogador possui: nome, vitórias, derrotas, tier(nível) e pontos.

Os tiers são: Bronze, Prata, Ouro, Platina, Diamante e Desafiante.
Para organizar e armazenar os níveis utilize uma enumeração.

b) Receba do teclado e armazene os dados de 6 jogadores. Não devem ser permitidos
valores negativos, novos valores devem ser solicitados caso necessário;

c) Exiba uma tabela alinhada com o nome e a taxa de vitórias (winrate) de cada jogador
winrate=vitorias/vitorias+derrotas * 100 Cada cálculo deve ser feito por meio de
uma função adicional que recebe o número de vitórias e derrotas via cópia e retorna o winrate;

d) Exiba uma tabela com os líderes (maior número de pontos) de cada um dos níveis.
Para isso, faça uma função extra que receba um tier e retorne uma estrutura do
tipo Jogador com os dados do líder. Caso uma tier não possua jogadores, exiba "Sem jogador";

e) Faça a busca de um jogador pelo nome digitado. A busca deve ser feita por uma
função adicional que recebe o nome e retorna os dados de vitórias, derrotas, tier e pontos via referência;

f) Utilizando uma função recursiva, calcule a soma de todas as partidas
(vitórias e derrotas) de todos os jogadores.

Observações:

 - Cada um dos itens de B a E deve ser implementada em uma função diferente.
 - Não é permitido o uso de variáveis globais.
 - Nas funções extras, caso necessário, utilize parâmetros adicionais.

================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//passo1: Criando a estrutura de acordo com o enunciado; OK
typedef enum{BRONZE=1,PRATA,OURO,PLATINA,DIAMANTE,DESAFIANTE}Tier;

typedef struct{
  char nome[21];
  int win;
  int lose;
  Tier elo;
  int pdl; //pdl = pontos para subir de elo
}Jogadores;


//passo2: Preencher a struct
void Preencher(Jogadores *Player){
printf("Insira as informacoes requisitadas.\n");
  for (int i = 0; i < 6; i++) {
  printf("Jogador #%d\n",i);
  printf("Qual o nome de usuario deste jogador?");
  setbuf(stdin,NULL);
  fgets(Player[i].nome,21,stdin);
  Player[i].nome[strcspn(Player[i].nome,"\n")]='\0';
  //do while para valores negativos
do{
  printf("Quantas vitorias este jogador tem em sua conta?\n");
  scanf("%d",&Player[i].win);
}while(Player[i].win < 0);
do{
  printf("E quantas derrotas?\n");
  scanf("%d",&Player[i].lose);
}while(Player[i].lose < 0);
do{
  printf("Qual o Elo desse jogador(1,2,3,4,5 ou 6)\n");
  scanf("%d",&Player[i].elo);
}while(Player[i].elo < 0 || Player[i].elo > 6);
do{
  printf("E quantos pdls?\n");
  scanf("%d",&Player[i].pdl);
}while(Player[i].pdl < 0);
}//for
  return;
}//Preencher
//calcualar a winrate e retornar o valor da variavel

float Winrate(Jogadores Player,float winrate){
  winrate = Player.win/Player.win+Player.lose * 100;
  return winrate;
}
//Exbir a tabela
void Tabela(Jogadores *Player){
  float taxaW;
  printf("Tabela de Winrate dos jogadores\n");
  for (int i = 0; i < 6; i++) {
    taxaW = Winrate(Player[i],0);//recebendo o valor da variavel winrate
    printf("%-20s winrate: %d\n",Player[i].nome,taxaW);
  }//for
}//Tabela
//Buscar um jogador pelo nome
int Busca(Jogadores *Player){
  char aux[21];
  int x; //numero para encontrar salvar qual o jogador a pesquisa corresponde
  printf("Para procurar por um jogador insira seu nome de usuario:\n");
  setbuf(stdin,NULL);
  fgets(aux,21,stdin);
  aux[strcspn(aux,"\n")]='\0';
  for (int i = 0; i < 6; i++) {
    if(strcasecmp(aux,Player[i].nome)==0){
      printf("Jogador encontrado!\n");
      x = i;
    }//if
  }//for

  return Player[x]->win, Player[x]->lose, Player[x]->elo, Player[x]->pdl;
}//Busca

//exibir as informacoes prestando atencao aos casos de enum
void ExibirBusca(Jogadores Player){
  Busca(&Player);
  printf("Vitorias: %d\nDerrotas: %d\n",Player[x].win,Player[x].lose);
  switch (Player[x].elo){
    case BRONZE:
    printf("Tier: Bronze\nPontos: %d",Player[x].pdl);
break;
    case PRATA:
    printf("Tier: Bronze\nPontos: %d",Player[x].pdl);
break;
    case OURO:
    printf("Tier: Bronze\nPontos: %d",Player[x].pdl);
break;
    case PLATINA:
    printf("Tier: Bronze\nPontos: %d",Player[x].pdl);
break;
    case DIAMANTE:
    printf("Tier: Bronze\nPontos: %d",Player[x].pdl);
break;
    case DESAFIANTE:
    printf("Tier: Bronze\nPontos: %d",Player[x].pdl);
break;
}//switch
}//ExibirBusca


void Soma(Jogadores Player,int x,int soma){
  if(x<0){
  return;
}else{
soma += Player[x].win + Player[x].lose;
  Soma(Player,x-1,soma);
}//else
}//Soma

//int main para conectar as funcoes
int main(){
Jogadores Player;
Preencher(&Player);
Tabela(&Player);
ExibirBusca(Player);
Soma(Player,5,0);



  return 0;
}
