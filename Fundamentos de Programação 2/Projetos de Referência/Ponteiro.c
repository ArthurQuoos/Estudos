#include <stdio.h>
#include <stdlib.h>


void Ponteiro(){
  int variavel = 15;
  int *ptr;

//ponteiro ptr recebe o endereço de memoria da variavel
  ptr = &variavel;

  printf("Valor da variavel: %d\n", variavel); //aparece 15
  printf("Endereco de memoria da variavel: %p\n", &variavel); //aparece endereco
  printf("Valor do ponteiro: %p\n", ptr); //aparece endereco tambem
  printf("Deferenciando o ponteiro: %d\n", *ptr); //valor apontado no caso 15

  return ;
}//Ponteiro

void Operacoes(){
  int numero = 42;
  int *ptr = &numero;

  printf("Endereco armazenado: %p - %jd\n",ptr,(long int) ptr);
  ptr++;
  printf("Endereco armazenado: %p - %jd\n",ptr,(long int) ptr);
  ptr = ptr + 15;
  printf("Endereco armazenado: %p - %jd\n",ptr,(long int) ptr);
  ptr = ptr - 2;
  printf("Endereco armazenado: %p - %jd\n",ptr,(long int) ptr);

  return ;
}

void Comparacao(){
  int valor1 = 10, valor2 = 10;
  int *ptr1, *ptr2;
ptr1 = &valor1;
ptr2 = &valor2;

  if(*ptr1 == *ptr2){ //deferenciacao
    printf("Ponteiros iguais!\n");
  }else{
    printf("Ponteiros diferentes!\n");
  }//else

  return ;
}//comparacao

//void *ptrGenerico
//printf("blabla",*(int*)ptrGenerico)

void VetoresPonteiros(){
int vetor[5] = {10,20,30,40,50};
int *ptrVet = vetor;

  for(int i = 0; i < 5; i++) {
    printf("%d - %p\n",*(ptrVet+i),(ptrVet+i));//ptrVet[i]
  }//for

  return;
}

void PonteiroPonteiro(){
int x = 10;
int *ptr = &x;
int **ptrPtr = &ptr;

  printf("%d\n", x);
  printf("%d\n", *ptr);
  printf("%d\n", **ptrPtr);

return;
}

int main(){
Ponteiro();
printf("\n=======================================================\n");
Operacoes();
printf("\n=======================================================\n");
Comparacao();
printf("\n=======================================================\n");
VetoresPonteiros();
printf("\n=======================================================\n");
PonteiroPonteiro();
printf("\n=======================================================\n");
  return 0;
}
