#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
//----------------------------
//----------------------------

typedef struct NoArvore* PtrNoArvore;

typedef struct NoArvore {
  char chave[45];
  int pages[20];
  int contapag; //para controlar o vetor -> pages[contapag]
  int controlepag; //para nao inserir paginas repetidas
  PtrNoArvore direita;
  PtrNoArvore esquerda;
} NoArvore;

//----------------------------
//----------------------------

void iniciaArvoreBinaria(PtrNoArvore *no);
bool estaVaziaArvoreBinaria(PtrNoArvore *no);
bool insereArvoreBinaria(PtrNoArvore *no, char *valor);
void preOrdemArvoreBinaria(PtrNoArvore *no);
void emOrdemArvoreBinaria(PtrNoArvore *no,FILE *saida);
void posOrdemArvoreBinaria(PtrNoArvore *no);
bool pesquisaArvoreBinaria(PtrNoArvore *no, char *valor,int pagina);
PtrNoArvore procuraMaiorElemento(PtrNoArvore *no);
bool removeArvoreBinaria(PtrNoArvore *no, char *valor);
void destroiArvore(PtrNoArvore *no);


int main(int argc, const char * argv[]){
  PtrNoArvore raiz;
  FILE *entrada;
  FILE *saida;
  entrada = fopen(argv[1],"r");//argv[0]
  saida = fopen(argv[2],"w");//argv[1]
  if (entrada == NULL || saida == NULL){
    printf("Erro na abertura do arquivo\n");
    exit(1); //finaliza o programa
  }
  if(argc != 3){
    printf("Erro na passagem de parametros\n");
    return 0;
  }

char letra;
char *token;
int pagina;
char frase[200];
int tm; //tamanho da string -> usado com tolower

  iniciaArvoreBinaria(&raiz);


   //adquirindo a primeira frase de termos
   fgets(frase,200,entrada);
   tm = strlen(frase); //convertendo a frase para minusculo
   for (size_t i = 0; i < tm; i++) {
     frase[i] = tolower(frase[i]);
   }
   token = strtok(frase,":,>"); //apenas retirando a palavra termos do caminho
   while((strcmp(token,"\n")) != 0){
     token = strtok(NULL,":,>");
     if((strcmp(token,"\n")) != 0){
       if(insereArvoreBinaria(&raiz,token)){ //inserindo os termos
         printf("Inseriu o termo \"%s\" corretamente\n",token);
       }
     }
   }

while(!feof(entrada)){
  token = strtok(frase,",.() <>:!?@#$%*");
  while(token != NULL){
  //printf("%s ",token);

    if((strcmp(token,"page")) == 0){
    //  fscanf(entrada,"<page:%d>",&pagina);
      token = strtok(NULL,",.() <>:!?@#$%*");
      pagina = strtol(token,NULL,10); //Transformando para número inteiro de base 10
    }else{
      if(pesquisaArvoreBinaria(&raiz,token,pagina)){
        //printf("\n----Encontrou palavra/inseriu %d na arvore----\n",pagina);
      }
    }
    token = strtok(NULL,",.() <>:!?");
  }//while token
  fgets(frase,200,entrada); //apos while(token) adquire a proxima frase
  tm = strlen(frase);
  for (size_t i = 0; i < tm; i++) {
    frase[i] = tolower(frase[i]);
  }
  }//whilegrandao

printf("\n\n\n==============\n");
  emOrdemArvoreBinaria(&raiz,saida);

fclose(entrada);
fclose(saida);
destroiArvore(&raiz);


   return 0;
}

//================================Funcoes=======================================

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
  //printf("%s\n",valor);
  if((*no) == NULL) {
    (*no) = malloc(sizeof(NoArvore));
    (*no)->contapag = 0;
    (*no)->controlepag = 0;
    (*no)->direita  = NULL;
    (*no)->esquerda = NULL;
    strcpy((*no)->chave,valor);
    return (true);
  }

  // 2 - nao quero inserir numeros repetidos
  if(strcmp((*no)->chave,valor) == 0) return false;

  // condicoes de recursao (percorrer a arvore)
  // valor > no.chave -> ir p subarvore direita
  if(strcmp((*no)->chave,valor) == -1) {
    return(insereArvoreBinaria(&(*no)->direita, valor));
  } // valor < no.chave -> ir p subarvore esquerda
  else {
    if(strcmp((*no)->chave,valor) == 1) {
    return(insereArvoreBinaria(&(*no)->esquerda, valor));
    }
  }
}

void preOrdemArvoreBinaria(PtrNoArvore *no) {
  if((*no) == NULL) return;
  printf("%s ", (*no)->chave);
  preOrdemArvoreBinaria(&(*no)->esquerda);
  preOrdemArvoreBinaria(&(*no)->direita);
}

void emOrdemArvoreBinaria(PtrNoArvore *no,FILE *saida) {
  if((*no) == NULL) return;
  emOrdemArvoreBinaria(&(*no)->esquerda,saida);
  printf("%s", (*no)->chave);
  fprintf(saida,"%s",(*no)->chave);
  for (size_t i = 0; i < (*no)->contapag; i++) {
    printf(",%d",(*no)->pages[i]);
    fprintf(saida,",%d",(*no)->pages[i]);
  }
  fprintf(saida,"\n");
  printf("\n");
  emOrdemArvoreBinaria(&(*no)->direita,saida);
}

void posOrdemArvoreBinaria(PtrNoArvore *no) {
  if((*no) == NULL) return;
  posOrdemArvoreBinaria(&(*no)->esquerda);
  posOrdemArvoreBinaria(&(*no)->direita);
  printf("%s ", (*no)->chave);
}

bool pesquisaArvoreBinaria(PtrNoArvore *no, char *valor,int pagina){
  //situacao 2: nao tem
  if((*no) == NULL) return false;

        //situacao 1: achei
        if(strcmp((*no)->chave,valor) == 0 && pagina != (*no)->controlepag){
          (*no)->pages[(*no)->contapag] = pagina;
          (*no)->contapag++;
          (*no)->controlepag = pagina;
          return true;
      }

  // recursao
  //valor > no.x -> subarvore direita
  if(strcmp((*no)->chave,valor) == -1) {
    return(pesquisaArvoreBinaria(&(*no)->direita, valor,pagina));
  } else {
  // valor < no.x -> subarvore esquerda
    return(pesquisaArvoreBinaria(&(*no)->esquerda, valor,pagina));
  }
}

//----------------------------
//----------------------------

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
void destroiArvore(PtrNoArvore *no) {
  // percurso
  //percorrer a arvore e desalocar memoria de traz p frente
  if((*no) != NULL) {
    destroiArvore(&(*no)->esquerda);
    destroiArvore(&(*no)->direita);
    free(*no);
    (*no) = NULL;
  }
}
