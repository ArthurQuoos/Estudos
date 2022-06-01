#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
//----------------------------
//----------------------------

typedef struct NoArvore* PtrNoArvore;

typedef struct NoArvore {
  char chave;
  PtrNoArvore direita;
  PtrNoArvore esquerda;
} NoArvore;

//----------------------------
//----------------------------

void iniciaArvoreBinaria(PtrNoArvore *no);
bool estaVaziaArvoreBinaria(PtrNoArvore *no);
bool insereArvoreBinaria(PtrNoArvore *no, char *valor);
void preOrdemArvoreBinaria(PtrNoArvore *no);
void emOrdemArvoreBinaria(PtrNoArvore *no);
void posOrdemArvoreBinaria(PtrNoArvore *no);
bool pesquisaArvoreBinaria(PtrNoArvore *no, char *valor);
PtrNoArvore procuraMaiorElemento(PtrNoArvore *no);
bool removeArvoreBinaria(PtrNoArvore *no, int valor);
void destroiArvore(PtrNoArvore *node);
void destroiArvore(PtrNoArvore *node);

int main(int argc, const char * argv[]){
  PtrNoArvore raiz;
  FILE *entrada;
  FILE *saida;
char letra;
char *token;
char *palavra;
char pagina;
  entrada = fopen("entrada1.txt","r");//argv[0]
  saida = fopen("saida.txt","w");//argv[1]
  if (entrada == NULL || saida == NULL){
     printf("Erro na abertura do arquivo\n");
     exit(1); //finaliza o programa
   }

while((letra = fgetc(entrada)) != EOF){
  if(letra == '<'){
    token = strtok(entrada,':'); //NULL para continuar do mesmo lugar
    if((strcmp(letra,"termos")) == 0){
      while((letra = fgetc(NULL)) =! '>'){
        tolower(letra);
        strcat(&palavra,letra);
        if(letra == ','){
        insereArvoreBinaria(&raiz, palavra);
        }
      }//while >
    }//termos
  //  else{//page
  //    fscanf(entrada,"page:%d",&pagina);
  //  }

  }//if <

}//whileGrandao

   return 0;
}

/*
== 'a' || palavra == 'b' || palavra == 'c' || palavra == 'd' ||
palavra == 'e' || palavra == 'f' || palavra == 'f' || palavra == 'g' ||
palavra == 'h' || palavra == 'i' || palavra == 'j' || palavra == 'k' ||
palavra == 'l' || palavra == 'm' || palavra == 'n' || palavra == 'o' ||
palavra == 'p' || palavra == 'q' || palavra == 'r' ||palavra == 's' ||
palavra == 't' || palavra == 'u' || palavra == 'v' || palavra == 'w' ||
palavra == 'x' || palavra == 'y' || palavra == 'z'
*/
void iniciaArvoreBinaria(PtrNoArvore *no) {
  // *no = NULL
  (*no) = NULL;
}

bool estaVaziaArvoreBinaria(PtrNoArvore *no) {
  return ((*no) == NULL);
}

bool insereArvoreBinaria(PtrNoArvore *no, char *valor) {
  // condicoes de parada recursao (true, false)
  // 1 - achei o ponto de insercao
  if((*no) == NULL) {
    (*no) = malloc(sizeof(NoArvore));
    (*no)->direita  = NULL;
    (*no)->esquerda = NULL;
    strcpy((*no)->chave,valor);
    return (true);
  }
  // 2 - nao quero inserir numeros repetidos
  if(strcmp((*no)->chave,valor) == 0) return false;

  // condicoes de recursao (percorrer a arvore)
  // valor > no.chave -> ir p subarvore direita
  if(strcmp((*no)->chave,valor) == 1) {
    return(insereArvoreBinaria(&(*no)->direita, valor));
  } // valor < no.chave -> ir p subarvore esquerda
  else {
    return(insereArvoreBinaria(&(*no)->esquerda, valor));
  }
}

void preOrdemArvoreBinaria(PtrNoArvore *no) {
  if((*no) == NULL) return;
  printf("%s ", (*no)->chave);
  preOrdemArvoreBinaria(&(*no)->esquerda);
  preOrdemArvoreBinaria(&(*no)->direita);
}

void emOrdemArvoreBinaria(PtrNoArvore *no) {
  if((*no) == NULL) return;
  emOrdemArvoreBinaria(&(*no)->esquerda);
  printf("%s ", (*no)->chave);
  emOrdemArvoreBinaria(&(*no)->direita);
}

void posOrdemArvoreBinaria(PtrNoArvore *no) {
  if((*no) == NULL) return;
  posOrdemArvoreBinaria(&(*no)->esquerda);
  posOrdemArvoreBinaria(&(*no)->direita);
  printf("%s ", (*no)->chave);
}

bool pesquisaArvoreBinaria(PtrNoArvore *no, char *valor){
  //situacao 2: nao tem
  if((*no) == NULL) return false;
  //situacao 1: achei
  if(strcmp((*no)->chave,valor) == 0) return true;
  // recursao
  //valor > no.x -> subarvore direita
  if(strcmp((*no)->chave,valor) == 1) {
    return(pesquisaArvoreBinaria(&(*no)->direita, valor));
  } else {
  // valor < no.x -> subarvore esquerda
    return(pesquisaArvoreBinaria(&(*no)->esquerda, valor));
  }
}

//----------------------------
//----------------------------

// Funcao auxiliar (procura maximo na subarvore esquerda)
// No -> No-Esq
// procurar, até encontrar um elemento cujo filho da direita é NULL
// Qndo: no = no->esq
//       tmp = no
// return (tmp)

PtrNoArvore procuraMaiorElemento(PtrNoArvore *no) {
  while((*no)->direita != NULL) {
    (*no) = (*no)->direita;
  }
  // dentro do (*no) (maior)
  PtrNoArvore ret = (*no);
  (*no) = (*no)->esquerda;
  return(ret);
}


//----------------------------
//Remocao
//----------------------------

bool removeArvoreBinaria(PtrNoArvore *no, char *valor) {

// pode não encontrar o valor (NULL) -> return false
// não remove
  if((*no) == NULL) return false;

// se encontrei o valor a ser removido:
  if(strcmp((*no)->chave,valor) == 0) {
    PtrNoArvore tmp = (*no);
    // caso 1 (folha): no = NULL
    if((*no)->direita == NULL && (*no)->esquerda == NULL) {
      (*no) = NULL;
    }
    // caso 2 (subarvore-esquerda existe): no = no-esq
    else if((*no)->esquerda != NULL && (*no)->direita == NULL) {
      (*no) = (*no)->esquerda;
    }
// caso 3 (subarvore-direita existe): no = no-direita
    else if((*no)->esquerda == NULL && (*no)->direita!= NULL) {
      (*no) = (*no)->direita;
    } else {
      // caso 4 (temos as duas subarvores)
      //     A: maior elemento da subarvore esqueda (funcao auxiliar)
      tmp = procuraMaiorElemento(&(*no)->esquerda);
      //     B: menor elemento da subarvore direita (funcao auxiliar)
      strcpy((*no)->chave, tmp->chave);
    }
    free(tmp); // desaloca memoria do no
    return true;
  }

  // clausulas recurivas
  if(valor > (*no)->chave){ //vai p direita na arvore
      return(removeArvoreBinaria(&(*no)->direita, valor));
  } else {// valor < no->chave -> vai p esquerda na arvore
    return(removeArvoreBinaria(&(*no)->esquerda, valor));
  }
}


// destruir arvore (motosserra) ???
void destroiArvore(PtrNoArvore *node) {
  // percurso
  //percorrer a arvore e desalocar memoria de traz p frente
  if((*no) != NULL) {
    destroiArvore(&(*no)->esquerda);
    destroiArvore(&(*no)->direita);
    free(*no);
    (*no) = NULL;
  }
}
