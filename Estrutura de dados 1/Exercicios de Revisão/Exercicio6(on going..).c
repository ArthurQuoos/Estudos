/*
@file: Exercicio6.c
@date: 13/03/2022
@author: Arthur Albert Schmaiske Quoos
@brief: Baralho com Structs (on going...)
*/
/*
um baralho normal frequentemente usado em v´arios jogos para entretenimento
pode ser codificado definindo dois tipos abstrato de dados:
• Carta: que representa uma carta f´ısica do baralho. Possui trˆes atributos:
s´ımbolo/valor, o naipe, e uma vari´avel booleana indicando se a carta j´a foi jogada ou n˜ao;
• Baralho: uma estrutura que representa um conjunto de Cartas

void criaBaralho(baralho *baralho); inicia um novo baralho criando todas as cartas nele contido.
int cartasNaoJogadas(Baralho *baralho); Consulta o n´umero de cartas dispon´ıveis para jogo.
Carta topo(Baralho *baralho); Consulta a carta do topo de um baralho.
Carta fundo(Baralho *baralho); Consulta a carta do fundo de um baralho.
Carta* carteado(Baralho *baralho); Retorna um array com 3 cartas aleat´orias para um jogador;

Assim sendo, escreva fun¸c˜oes em C para simular os comportamentos listados na Tabela 1. Adicione comandos
na fun¸c˜ao principal que testem e validem todas as fun¸c˜oes implementadas
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> //esse ta pegado...

typedef struct {
  char naipe;
  char simbolo;
  bool foiJogada;
} Carta;

typedef struct {
  Carta baralho[4][13];
  int totalNaipes;
  int totalSimbolos;
  int qtdeCartas;
} Baralho;

//---------------------------------
//---------------------------------

void imprimeCarta(Carta *cd) {
  printf("[S:%c,N:%c,J:%d]", cd->simbolo, cd->naipe, cd->foiJogada);
}

void imprimeBaralho(Baralho *bar) {
  int i, j;
  // simbolos
  for(j = 0; j < 13; j++) {
    for(i = 0; i < 4; i++) {
      Carta temp = bar->baralho[i][j];
      imprimeCarta(&temp);
    }
    printf("\n");
  }
}

//---------------------------------
//---------------------------------

void iniciaBaralho(Baralho *bar) {

  char simbolos[13] = {'A','2','3','4',
    '5','6','7','8','9','D','J','Q','K'};
  char naipes[4]  = {'P','C','E','O'};

  int i, j;
  // naipes
  for(i = 0; i < 4; i++) {
      // simbolos
    for(j = 0; j < 13; j++) {
      bar->baralho[i][j].naipe = naipes[i] ;
      bar->baralho[i][j].simbolo = simbolos[j];
      bar->baralho[i][j].foiJogada = false; //0
    }
  }
}
//---------------------------------
//---------------------------------

int qtdeCartasNaoJogadas(Baralho *bar) {
  int cont = 0;
  for(int i=0; i<4;i++) {
    for(int j=0; j<13; j++) {
      Carta cd = bar->baralho[i][j];
      if(!cd.foiJogada) {
        cont++;
      }
    }
  }
  return (cont);
}

//---------------------------------
//---------------------------------

int main(int argc, char* argv[]) {

  Carta c;
  c.simbolo = 'Q';
  c.naipe   = 'E';

//  imprimeCarta(&c);

  Baralho deck;
  iniciaBaralho(&deck);
  imprimeBaralho(&deck);

  int pacoca = qtdeCartasNaoJogadas(&deck);
  printf("-------------------\n");
  printf("*** Cartas não jogadas = %d\n", pacoca);
  printf("-------------------\n");

  return 0;
}
