#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define BUFFER 150
 
typedef struct {
  char primeiroNome[BUFFER];
  char sobrenome[BUFFER];
  char nomeHeroi[BUFFER];
  char poder[BUFFER];
  char fraqueza[BUFFER];
  char cidade[BUFFER];
  char profissao[BUFFER];
} Heroi;
 
typedef struct {
  char chave[BUFFER];   //é a chave canonica de um registro
  int RRN;              //Referencia para leitura e gravacao do registro
} ArrayItem;
 
 
//Indice
typedef struct {
  FILE *arqDados;      //arquivo de dados (r+)
  FILE *arqIdx;        //arquivo de indice (r+)
  ArrayItem *vetor;    //vetor de pares ordenados (chave, RRN)
  int numeroRegistros; //guarda o numero de registros na memoria
  bool status;         //status de escrita do arquivo
} Indice;

//--------------------------------------------------------------
//--------------------------------------------------------------
int numeroRegistros(Indice *idx);
Heroi quebraStringEmHeroi(char *string);
char* geraChaveRegistro(char* str1, char* str2);
void imprimeVetorIndices(Indice *idx);
void iniciaIndiceArquivo(Indice *idx, char* filename);
int comparaChave(const void *a, const void *b);
void gravaArquivoIndice(Indice *idx);