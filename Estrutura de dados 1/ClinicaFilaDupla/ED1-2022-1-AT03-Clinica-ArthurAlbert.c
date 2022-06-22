#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


typedef struct NoLista *PtrNoLista;

typedef struct NoLista {
    int elemento; //codigo
    char nome[80];
    char sexo;
    char idade[3];
    char peso[5];
    char altura[5];
    char telefone[35];
    PtrNoLista proximo;
    PtrNoLista anterior;
} NoLista;

typedef struct {
    PtrNoLista inicio;
    int tamanho;
} ListaDupla;

void iniciaListaDupla(ListaDupla *lista);
bool estaVaziaListaDupla(ListaDupla *lista);
int tamanhoListaDupla(ListaDupla *lista);
bool insereListaDupla(ListaDupla *lista, char info[7][100]);
void imprimeListaDupla(ListaDupla *lista,FILE *saida);
void imprimeListaDuplaReverso(ListaDupla *lista,FILE *saida);
void destroiListaDupla(ListaDupla *lista);
bool procuraListaDupla(ListaDupla *lista, int x,FILE *saida);
bool removePrimeiroListaDupla(ListaDupla *lista, int *item);
bool removeListaDupla(ListaDupla *lista, int x, int *item);
bool removeUltimoListaDupla(ListaDupla *lista, int *item);
int primeiroListaDupla(ListaDupla *lista);
int ultimoListaDupla(ListaDupla *lista);


int main(int argc, const char * argv[]){
  ListaDupla lista;
FILE *entrada;
FILE *saida;

char infoTemp[7][100];//armazena as infomacoes coletadas
int control = 0;//controle de informacoes lidas
int aux; //auxiliar na conversao de char->int para a funcao de proucuraListaDupla
char frase[200];
char *token;

  entrada = fopen(argv[1],"r");//argv[1]
  saida = fopen(argv[2],"w");//argv[2]
  if (entrada == NULL || saida == NULL){
     printf("Erro na abertura do arquivo\n");
     exit(1); //finaliza o programa
   }
   if(argc != 3){
     printf("Erro na passagem de parametros\n");
     return 0;
   }

   iniciaListaDupla(&lista);

   fgets(frase,200,entrada);
while(!feof(entrada)){
     printf("%s",frase);
     token = strtok(frase,"{},");
     //printf("%s\n",token);
  if(frase[0] == '{'){ //ifElseGrande para verificar se deve inserir ou "exibir"
     while((strcmp(token,"\n")) != 0){
       strcpy(infoTemp[control],token);
       control++;
       token = strtok(NULL,"{},");
       //printf("%s\n",token);
  }
  if(control != 7){ //numero errado de informacoes coletadas
    printf("Arquivo Invalido!\n");
    fprintf(saida,"Arquivo Invalido!\n");
    fclose(entrada);
    fclose(saida);
    destroiListaDupla(&lista);
    return 0;
  }
  control = 0;
  insereListaDupla(&lista,infoTemp);
}else{ //instrucao
  if((strcmp(token,"1\n")) == 0){ //ordem crescente
    imprimeListaDupla(&lista,saida);

  }else{
    if((strcmp(token,"2\n")) == 0){ //ordem decrescente
      imprimeListaDuplaReverso(&lista,saida);

    }else{
      if((strcmp(token,"3\n")) == 0){ //consulta
        fgets(frase,200,entrada);
        aux = strtol(frase,NULL,10);
        if(procuraListaDupla(&lista,aux,saida)){
          printf("achou\n");
          fclose(entrada);
          fclose(saida);
          destroiListaDupla(&lista);
          return 0;
          }
      }else{
        printf("Arquivo Invalido!\n");
        fprintf(saida,"Arquivo Invalido!\n");
        fclose(entrada);
        fclose(saida);
        destroiListaDupla(&lista);
        return 0;
      }//elseErro
    }//else
  }//else
}//bigElse


  fgets(frase,200,entrada);
}//whileGrande

fclose(entrada);
fclose(saida);
destroiListaDupla(&lista);

  return 0;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void iniciaListaDupla(ListaDupla *lista){
  lista->inicio = NULL;
  lista->tamanho = 0;

// PtrNoLista sentinela = (PtrNoLista) malloc(sizeof(NoLista));
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool estaVaziaListaDupla(ListaDupla *lista){
  return(lista->tamanho == 0);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int tamanhoListaDupla(ListaDupla *lista){
  return(lista->tamanho);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool insereListaDupla(ListaDupla *lista, char info[7][100]){
  int x = strtol(info[0],NULL,10);
  PtrNoLista novo = (PtrNoLista) malloc(sizeof(NoLista));

  if(!novo) {
    printf("@ O novo nó não foi alocado\n");
    return (false);
  }
  novo->elemento = x;
  strcpy(novo->nome,info[1]);
  novo->sexo = info[2][0];
  strcpy(novo->idade,info[3]);
  strcpy(novo->peso,info[4]);
  strcpy(novo->altura,info[5]);
  strcpy(novo->telefone,info[6]);
  //printf("{%d,%s,%c,%s,%s,%s,%s inseriu?}\n", novo->elemento,novo->nome,novo->sexo,novo->idade,novo->peso,novo->altura,novo->telefone);

  /* primeira inserção */
  if(estaVaziaListaDupla(lista)) {
    novo->proximo  = NULL;
    novo->anterior = NULL;
    lista->inicio  = novo;
    //lista->fim = novo;//sentinela
  }
  /* inserindo um elemento menor do que o primeiro */
  else if (x < lista->inicio->elemento) {
    novo->anterior = NULL;
    lista->inicio->anterior = novo;
    novo->proximo = lista->inicio;
    lista->inicio = novo;

  }
  /* encontrando a posição de inserção */
  else {
    PtrNoLista aux;
    aux = lista->inicio;
    while(aux->proximo != NULL && x > aux->proximo->elemento) {
      aux = aux->proximo;
    }

    novo->proximo = aux->proximo;
    if(aux->proximo != NULL) {
      aux->proximo->anterior = novo;
    }
    novo->anterior = aux;
    aux->proximo   = novo;
  }
  lista->tamanho++;
  return(true);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void imprimeListaDupla(ListaDupla *lista,FILE *saida) {
  PtrNoLista ptr;
  for(ptr = lista->inicio; ptr != NULL; ptr = ptr->proximo) {
    printf("{%d,%s,%c,%s,%s,%s,%s}\n", ptr->elemento,ptr->nome,ptr->sexo,ptr->idade,ptr->peso,ptr->altura,ptr->telefone);
    fprintf(saida,"{%d,%s,%c,%s,%s,%s,%s}\n", ptr->elemento,ptr->nome,ptr->sexo,ptr->idade,ptr->peso,ptr->altura,ptr->telefone);
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void imprimeListaDuplaReverso(ListaDupla *lista,FILE *saida) {

  if(estaVaziaListaDupla(lista)) {
    printf(" [*] Lista:{ }\n");
  } else {

    PtrNoLista ptr;
    for(ptr = lista->inicio; ptr->proximo != NULL; ptr = ptr->proximo);

    PtrNoLista aux = ptr;
    do {
      printf("{%d,%s,%c,%s,%s,%s,%s}", ptr->elemento,ptr->nome,ptr->sexo,ptr->idade,ptr->peso,ptr->altura,ptr->telefone);
      fprintf(saida,"{%d,%s,%c,%s,%s,%s,%s}\n", ptr->elemento,ptr->nome,ptr->sexo,ptr->idade,ptr->peso,ptr->altura,ptr->telefone);
      aux = aux->anterior;
    } while(aux != NULL);
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void destroiListaDupla(ListaDupla *lista) {
  printf("@ Destruindo lista dupla!\n");
  PtrNoLista remove;
  while((lista->inicio)!= NULL) {
    remove = lista->inicio;
    lista->inicio = lista->inicio->proximo;
    lista->tamanho--;
    free(remove);
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool procuraListaDupla(ListaDupla *lista, int x,FILE *saida){

  if(estaVaziaListaDupla(lista)) return (false);

  PtrNoLista ptr;
  for(ptr = lista->inicio; ptr->proximo != NULL && x > ptr->elemento; ptr = ptr->proximo);
  if(ptr == NULL || ptr->elemento > x) {
    return (false);
  }
  fprintf(saida,"{%d,%s,%c,%s,%s,%s,%s}\n", ptr->elemento,ptr->nome,ptr->sexo,ptr->idade,ptr->peso,ptr->altura,ptr->telefone);
  printf("{%d,%s,%c,%s,%s,%s,%s}\n", ptr->elemento,ptr->nome,ptr->sexo,ptr->idade,ptr->peso,ptr->altura,ptr->telefone);

  return (true);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool removePrimeiroListaDupla(ListaDupla *lista, int *item) {

  if(estaVaziaListaDupla(lista)){
    return(false);
  }

  PtrNoLista aux = lista->inicio;
  *item = aux->elemento;

  lista->inicio = lista->inicio->proximo;
  lista->inicio->anterior = NULL;
  lista->tamanho--;
  free(aux);

  printf("@Elemento: %d foi removido\n", (*item));
  return (true);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool removeListaDupla(ListaDupla *lista, int x, int *item) {

  if(estaVaziaListaDupla(lista) || x < lista->inicio->elemento) {
    return(false);
  }

  if(x == lista->inicio->elemento) {
    return (removePrimeiroListaDupla(lista, item));
  }

  PtrNoLista aux = lista->inicio;
  while((aux->proximo != NULL) && (x > aux->proximo->elemento)) {
    aux = aux->proximo;
  }

  if(aux->proximo == NULL || aux->proximo->elemento > x) {
    return (false);
  }

  PtrNoLista remove = aux->proximo;
  *item = remove->elemento;

  if(aux->proximo->proximo != NULL) {
    aux->proximo->proximo->anterior = aux;
  }
  aux->proximo = aux->proximo->proximo;
  lista->tamanho--;
  free(remove);
  printf("@Elemento: %d foi removido\n", (*item));

  return(true);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool removeUltimoListaDupla(ListaDupla *lista, int *item) {

  if(estaVaziaListaDupla(lista)) return(false);

  if(tamanhoListaDupla(lista) == 1) {
    return(removePrimeiroListaDupla(lista, item));
  }

  PtrNoLista aux;
  for(aux = lista->inicio; aux->proximo->proximo != NULL; aux = aux->proximo);

  PtrNoLista remove = aux->proximo;
  *item = remove->elemento;
  aux->proximo = NULL;
  free(remove);

  printf("@Elemento: %d foi removido\n", (*item));
  lista->tamanho--;
  return(true);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int primeiroListaDupla(ListaDupla *lista){
  return(lista->inicio->elemento);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int ultimoListaDupla(ListaDupla *lista){
  PtrNoLista ptr;
  for(ptr = lista->inicio; ptr->proximo != NULL; ptr = ptr->proximo);
  return(ptr->elemento);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
