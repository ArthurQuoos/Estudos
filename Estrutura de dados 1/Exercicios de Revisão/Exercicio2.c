/*
@file: Exercicio2.c
@date: 12/03/2022
@author: Arthur Albert Schmaiske Quoos
@brief: Exercicio de revisao sobre arquivos
*/
/*
================================================================================
Fa¸ca um programa que receba do usu´ario um arquivo texto. Crie outro arquivo
texto de sa´ıda contendo o texto do arquivo de entrada original, por´em
substituindo todas as vogais pelo caractere ‘*’. Al´em disso, mostre na tela
quantas linhas esse arquivo possui. Dentro do programa fa¸ca o controle de erros,
isto ´e, insira comandos que mostre se os arquivos foram abertos com sucesso, e caso
contr´ario, imprima uma mensagem de erro encerrando o programa
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv[]){
  char letras;
  int contalinha = 1;
  FILE *arq1;
  FILE *arq2;


  arq1 = fopen("entrada.txt","r"); //abrindo os arquivos
  arq2 = fopen("saida.txt","w");
  if(arq1 == NULL || arq2 == NULL){  //verificando
    printf("ERRO BIB BIB BOP ERRO\n");
    exit(1); //caso der errado finaliza o programa
  }
  while((letras = fgetc(arq1)) != EOF){

    if(tolower(letras) == 'a' || tolower(letras) == 'e' || tolower(letras) == 'i'
        || tolower(letras) == 'o' || tolower(letras) == 'u' ){
      letras = '*';
    }
    if(letras == '\n'){
      contalinha++;
    }
    fprintf(arq2,"%c",letras);
  }

  fclose(arq1);
  fclose(arq2);
  printf("Quantidade de linhas: %d",contalinha);
  return 0;
}
