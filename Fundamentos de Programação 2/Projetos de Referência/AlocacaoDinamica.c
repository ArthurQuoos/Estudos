#include <stdio.h>
#include <stdlib.h>


int main(){

  int *ptr;
  //Aloca o vetor de 50 int - 3 maneiras
  ptr = (int*) malloc(200);
  ptr = (int*) malloc(50 * sizeof(int));
  ptr = (int*) calloc(50 , sizeof(int));

  //redimensiona o valor alocado para 80 int
  ptr = (int*) realloc(ptr,80 * sizeof(int));

  //Libera a memoria alocada
  free(ptr);

}



int main(){  //alocar matriz

  int** matriz;

  //Aloca o vetor de ponteiro para as linhas
  matriz = (int**) malloc(4 * sizeof(int*));
  //Aloca cada uma das linhas da matriz
  for (size_t i = 0; i < 4; i++) {
    matriz[i] = (int*) malloc(4 * sizeof(int));
  }//for

//Recebe os dados da matriz do teclado
for (size_t j = 0; j < 4; j++) {
  for (size_t c = 0; c < 4; c++) {
    printf("Matriz[%d][%d] ",j , c);
    scanf("%d",&matriz[j][c]);
  }//for colunas
  printf("\n");
}//for linhas

for (size_t j = 0; j < 4; j++) {
  for (size_t c = 0; c < 4; c++) {
    printf("%4d ",matriz[j][c]);
  }//for colunas
  printf("\n");
}//for linhas

  //Libera a memoria de cada uma das linhas da matriz
  for (size_t i = 0; i < 4; i++) {
    free(matriz[i]);
  }//for
  //Libera a memoria do vetor de ponteiros para as linhas
  free(matriz);

  return 0;
}


/*
  //alocar struct
  typedef struct{
    char nome[50];
    int idade;
  }Pessoa;

  int main(){
    Pessoa* cadastro = (Pessoa*) malloc (sizeof(Pessoa));

    strcpy(castro->nome,"Rosinosvalda");
    cadastro->idade =22;

    free(cadastro);
    return 0;
  }
  //vetor de struct
  Pessoa* vetCadastro = (Pessoa*) malloc (3 * sizeof(Pessoa));

  strcpy (vetCadastro[0].nome,"Rosinosvalda");
  vetCadastro[0].idade = 22;
  strcpy(vetCadastro[1].nome,"Rosinosberto");
  vetCadastro[1].idade =28;
  strcpy(vetCadastro[2].nome,"Rosinoscleia");
  vetCadastro[2].idade = 35;

  free(vetCadastro);
*/
