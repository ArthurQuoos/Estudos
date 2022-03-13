#include <stdio.h>
#include <stdlib.h>

/*
void exibeNumeros (int valor){
  if(valor == 1){ //caso base
    printf("%d ",valor);
  }else{  //caso recursivo
     printf("%d ",valor);
     exibeNumeros(valor-1);//chamada recursiva
     printf("%d ",valor);
  }//else
  return;
}//exibeNumeros

int main(){
    exibeNumeros(5);
  return 0;
}//main
*/

int somaNumeros(int valor){
  if(valor == 1){//caso base
    return 1;
  }else{ //caso recursivo
    return valor + somaNumeros(valor -1);
  }//else
}//somaNumeros

int main(){
  int soma = somaNumeros(6);
  printf("A soma e %d \n",soma);
  return 0;
}
