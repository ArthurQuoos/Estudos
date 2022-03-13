#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){  //nao funfo

  FILE *arq;
  char c;
  //abre o arquivo
  arq = fopen("arquivo.txt","r"); // r = read
  if(arq == NULL){
    printf("Erro na abertura do arquivo\n");
    exit(1); //finaliza o programa
  }//if
  //Le enquanto nao chegar no fim do arquivo
  while((c = fgetc(arq)) != EOF){
    printf("%c",c);
  }//for
//fecha o programa
fclose(arq);

  return 0;
}//main


/*
int main(){

  FILE *arq;
  char texto[100] = "Texto do arquvio via fputs";
  int resultado;
  //abre o arquivo
  arq = fopen("arquivo.txt","w");
  if(arq == NULL){
    printf("Erro na abertura do arquivo\n");
    exit(1);
  }
  //Escreve o texto no arquivo
  resultado = fputs(texto,arq);
  if(resultado == EOF){ //Le enquanto nao chegar no fim do arquivo
    printf("Erro na gravacao!\n");
  }
  //fecha o arquivo
  fclose(arq);

}
*/
