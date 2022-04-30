#include <stdio.h>
#include <stdbool.h> // true/false
#include <stdlib.h>

/* definir os tipos */
typedef struct NoPilha* PtrNoPilha;

typedef struct NoPilha {
  char valor;
  PtrNoPilha proximo; // struct NoPilha*
} NoPilha;

typedef struct {
  PtrNoPilha topo;   // struct NoPilha*
  int tamanho;
} PilhaDinamica;

int desempilhaPd(PilhaDinamica *pd);
void empilhaPd(PilhaDinamica *pd, char valor);
void imprimePd(PilhaDinamica *p);
bool estaVaziaPd(PilhaDinamica *pd);
int tamanhoPd(PilhaDinamica *pd);
void iniciaPd(PilhaDinamica *pd);


int main(int argc, const char * argv[]){
PilhaDinamica pilha;
FILE *entrada;
FILE *saida;
char temp[9];
char aux; //variavel que recebe os caracteres
int x = 0; //controlador de variaveis temp
int tam; //tamanho da pilha
int y = 0; //variavel de controle para saber quando salvar o temp

entrada = fopen(argv[0],"r");
saida = fopen(argv[1],"w");
if (entrada == NULL || saida == NULL){
   printf("Erro na abertura do arquivo\n");
   exit(1); //finaliza o programa
 }

iniciaPd(&pilha);

// Lendo um caractere da notação.
while((aux = fgetc(entrada)) != EOF){
  if(y == 1){ //if necessario para salvar o valor temp na pilha quando precisar
    fprintf(saida,"STR temp%d(%c)\n",x,temp[x]);
    empilhaPd(&pilha,temp[x]);
    y = 0;
  }
  //Se for um operando, empilhe-o
  if(aux >= 'A' && aux <= 'Z'){
    empilhaPd(&pilha,aux);
  }else{
  // Mas se ele for um operador, retire o penultimo e o ultimo operando da pilha.
  if(aux == '*' || aux == '+' || aux == '/' || aux == '-'){
    //if para quando nao tiver 2 ou mais operandos na pilha
      if((tam = tamanhoPd(&pilha)) <= 1){
        printf("Expressao invalida\n");
        fprintf(saida,"Expressao Invalida\n");
        fclose(entrada);
        fclose(saida);
        return 0;
        }
      if(aux == '+'){
        temp[x] = desempilhaPd(&pilha);
        fprintf(saida,"LDR %c\n",temp[x]);
        x++;
        temp[x] = desempilhaPd(&pilha);
        fprintf(saida,"LDR %c\n",temp[x]);
        x--;
        fprintf(saida,"ADD %c ",temp[x]);
        x++;
        fprintf(saida,"%c\n",temp[x]);
        y = 1;//y=1 para que se houver um proximo loop, ele salve o valor

      }else{

      if(aux == '-'){
        temp[x] = desempilhaPd(&pilha);
        fprintf(saida,"LDR %c\n",temp[x]);
        x++;
        temp[x] = desempilhaPd(&pilha);
        fprintf(saida,"LDR %c\n",temp[x]);
        x--;
        fprintf(saida,"SUB %c ",temp[x]);
        x++;
        fprintf(saida,"%c\n",temp[x]);
        y = 1;

      }else{

      if(aux == '*'){
        temp[x] = desempilhaPd(&pilha);
        fprintf(saida,"LDR %c\n",temp[x]);
        x++;
        temp[x] = desempilhaPd(&pilha);
        fprintf(saida,"LDR %c\n",temp[x]);
        x--;
        fprintf(saida,"MUL %c ",temp[x]);
        x++;
        fprintf(saida,"%c\n",temp[x]);
        y = 1;

      }else{

      if(aux == '/'){
        temp[x] = desempilhaPd(&pilha);
        fprintf(saida,"LDR %c\n",temp[x]);
        x++;
        temp[x] = desempilhaPd(&pilha);
        fprintf(saida,"LDR %c\n",temp[x]);
        x--;
        fprintf(saida,"DIV %c ",temp[x]);
        x++;
        fprintf(saida,"%c\n",temp[x]);
        y = 1;
        }
      }//else
    }//else
  }//else
}//if operadores
else{
  printf("Caracter Desconhecido\n");
  fprintf(saida,"Entrada Invalida\n");
  fclose(entrada);
  fclose(saida);
  return 0;
    }//else
  }//else
}//while

if(estaVaziaPd(&pilha)){
  printf("Esta vazia mesmo\n");
}else{
  printf("Nao esta vazia no final\n");
}
fclose(entrada);
fclose(saida);

return 0;
}


//===================================funcoes====================================
void iniciaPd(PilhaDinamica *pd) {
  pd->topo = NULL;
  pd->tamanho = 0;
}

int tamanhoPd(PilhaDinamica *pd) {
  return(pd->tamanho);
}

bool estaVaziaPd(PilhaDinamica *pd) {
  return(pd->tamanho == 0);
}

void imprimePd(PilhaDinamica *p) {
  printf("Pilha = {");
  PtrNoPilha ptr;
  for(ptr = p->topo; ptr != NULL; ptr = ptr->proximo) {
    printf("%c ", ptr->valor);
  }
  printf("}\n");
}

void empilhaPd(PilhaDinamica *pd, char valor) {
  // passo 1
  PtrNoPilha Aux;
  // passo 2
  Aux = (PtrNoPilha)malloc(sizeof(PtrNoPilha)); // criando caixinha
  //passo 3
  Aux->valor = valor; //copia o valor p dentro do bloco
  //passo 4
  Aux->proximo = pd->topo; // Novo-proximo -> topo
  //passo 5
  pd->topo = Aux;     // topo -> novo
  //passo 6
  pd->tamanho++;
}

int desempilhaPd(PilhaDinamica *pd) {
  //passo 0 (valor para retorno)
  int v = -99;
  if(!estaVaziaPd(pd)) {
    //passo 1
    PtrNoPilha Aux;
    //passo 2
    Aux = pd->topo;
    //passo 3
    v = Aux->valor;
    //passo 4
    pd->topo = Aux->proximo; // pd->topo = pd->topo->prox;
    //passo 5 - desalocar a memoria
    free(Aux);
    // passo 6 - decerementar a qtde da pilha
    pd->tamanho--;
  } else {
    printf("Warning: esta vazia\n");
  }

  // passo 7 - retornar o valor da pilha
  return(v);
}
