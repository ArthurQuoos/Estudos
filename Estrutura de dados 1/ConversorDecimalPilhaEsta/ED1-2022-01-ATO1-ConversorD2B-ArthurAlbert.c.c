/*
@file: Conversor.c
@date: 28/03/2022
@author: Arthur Albert Schmaiske Quoos
@brief: Conversor de Decimal para binario usando Pilhas
*/
//----------------------------- Cabecalho --------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 50

typedef struct {
   int vetor[N];  //vetor com 10 elementos inteiros
   int topo;       //controla o topo da pilha
} PilhaEstatica2;
typedef struct {
   int vetor[N];
   int topo;
   int valorTopo;
} PilhaEstatica;

void iniciaPe(PilhaEstatica *p);
int tamanhoPe(PilhaEstatica *p);
void imprimePe(PilhaEstatica *p);
bool estaVaziaPe(PilhaEstatica *p);
bool estaCheiaPe(PilhaEstatica *p);
void empilharPe(PilhaEstatica *p, int valor);
int desempilharPe(PilhaEstatica *p);
//funcoes para a segunda pilha
void iniciaPe2(PilhaEstatica2 *p);
int tamanhoPe2(PilhaEstatica2 *p);
void imprimePe2(PilhaEstatica2 *p);
bool estaVaziaPe2(PilhaEstatica2 *p);
bool estaCheiaPe2(PilhaEstatica2 *p);
void empilharPe2(PilhaEstatica2 *p, int valor);
int desempilharPe2(PilhaEstatica2 *p);

//-------------------------------- main ----------------------------------------

int main(int argc, char *argv[]) {
 int aux = 0;
 PilhaEstatica p;
 PilhaEstatica2 p2;
 FILE *arq;
 FILE *arq2;
 //Iniciar as Pilhas
 iniciaPe(&p);
 iniciaPe2(&p2);
//Abrir e verificar os arquivos
 arq = fopen(argv[1],"r");
 arq2 = fopen(argv[2],"w");
 if (arq == NULL || arq2 == NULL){
    printf("Erro na abertura do arquivo\n");
    exit(1); //finaliza o programa
  }
//Ler o arquivo de entrada e obtendo os valores para a pilha 1
 while (fscanf(arq,"%d",&aux)!= EOF){
        empilharPe(&p,aux);
        imprimePe(&p);
      }
//verificando...
 aux = tamanhoPe(&p);
 printf("Tamanho: %d\n",aux);

 int x; //variavel auxiliar
 while (!estaVaziaPe(&p)){
        //desempilhando da pilha1
        aux = desempilharPe(&p);
        while (aux > 0){
          //Convertendo...
 		          //obtém o resto da divisão de num por 2
 		          x = aux % 2;
              empilharPe2(&p2,x); //empilhando o resultado
 		           aux = aux / 2;
 	           }
       while (!estaVaziaPe2(&p2)){
          //Desempilhando a 2 e escrevendo o valor convertido de um dos valores da pilha1
             aux = desempilharPe2(&p2);
             fprintf(arq2,"%d",aux);
           }
       fprintf(arq2,"\n"); //pulando linha pra ficar organizado

     }
     //verificando se esta vazia
  if (estaVaziaPe(&p)) {
      printf("Aviso: esta vazia\n");
    }
  if (estaVaziaPe2(&p2)) {
      printf("Aviso: esta vazia\n");
    }
fclose(arq); //fechando os arq
fclose(arq2);
 return 0;
}


//============================== funcoes pilha1 ================================

void iniciaPe(PilhaEstatica *p) {
 p->topo = 0;
}

bool estaVaziaPe(PilhaEstatica *p) {
 return(p->topo == 0);
}

bool estaCheiaPe(PilhaEstatica *p) {
 return(p->topo == N);
}

void empilharPe(PilhaEstatica *p, int valor) {
 if(!estaCheiaPe(p)){
   p->vetor[p->topo] = valor;
   p->topo++; /* p->topo = p->topo + 1 */
 } else {
   printf("Warning: nao inserido porque está cheia\n");
 }
}

int desempilharPe(PilhaEstatica *p) {
 int x = -1;
 if(!estaVaziaPe(p)){
   x = p->vetor[p->topo-1];
   p->topo--;
 } else{
   printf("Warning: nao removido porque esta vazia\n");
 }
 return(x);
}

int tamanhoPe(PilhaEstatica *p) {
 return(p->topo);
}

void imprimePe(PilhaEstatica *p) {
 int i = 0;
 printf("Pilha = {");
 for(i = 0; i < p->topo; i++) {
   printf("|%d| ", p->vetor[i]);
 }
 printf("}\n");
}
//============================== Funcoes pilha2 ===============================
void iniciaPe2(PilhaEstatica2 *p) {
 p->topo = 0;
}

bool estaVaziaPe2(PilhaEstatica2 *p) {
 return(p->topo == 0);
}

bool estaCheiaPe2(PilhaEstatica2 *p) {
 return(p->topo == N);
}

void empilharPe2(PilhaEstatica2 *p, int valor) {
 if(!estaCheiaPe2(p)){
   p->vetor[p->topo] = valor;
   p->topo++; /* p->topo = p->topo + 1 */
 } else {
   printf("Warning: nao inserido porque está cheia\n");
 }
}

int desempilharPe2(PilhaEstatica2 *p) {
 int x = -1;
 if(!estaVaziaPe2(p)){
   x = p->vetor[p->topo-1];
   p->topo--;
 } else{
   printf("Warning: nao removido porque esta vazia\n");
 }
 return(x);
}

int tamanhoPe2(PilhaEstatica2 *p) {
 return(p->topo);
}

void imprimePe2(PilhaEstatica2 *p) {
 int i = 0;
 printf("Pilha = {");
 for(i = 0; i < p->topo; i++) {
   printf("|%d| ", p->vetor[i]);
 }
 printf("}\n");
}
