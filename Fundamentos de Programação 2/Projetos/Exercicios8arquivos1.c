/*
@file: Exercicios8arquivos1.c
@date: 18/11/2021
@author: Arthur Albert Schmaiske Quoos
@brief:
*/
/*
================================================================================
Escreva um programa que leia do usuário o nome de um arquivo texto. Em seguida,
mostre na tela quantas linhas esse arquivo possui.
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
//Criando as variaveis necessarias
FILE *arq;
int ContaLinhas = 0;
int resultado;
char NomeArquivo[21];
int existe_linha;
//Adquirindo as informacoes do teclado
printf("Insira o nome de um arquivo:");
setbuf(stdin,NULL);
fgets(NomeArquivo,21,stdin);
NomeArquivo[strcspn(NomeArquivo,"\n")]='\0'; //facin
//Abrindo o arquivo e verificando
  arq = fopen(NomeArquivo,"r");
  if(arq == NULL){
    printf("Erro na abertura do arquivo\n");
    exit(1);
  }
//Adquirindo o valor (char) do arquivo e comparando com '\n'
while((resultado = fgetc(arq)) != EOF){
  existe_linha = 1; //para contar a ultima linha
  if(resultado == '\n') {
    ContaLinhas++;
  }
}
  if(existe_linha){ //caso especial para a ultima linha
    ContaLinhas++;
  }
//Exibindo o resultado
printf("O arquivo possui %d linhas de texto.\n",ContaLinhas);

fclose(arq);

  return 0;
}


/*
================================================================================
Escreva um programa que leia do usuário os nomes de dois arquivos texto.
Crie um terceiro arquivo texto com o conteúdo dos dois primeiros juntos
(o conteúdo do primeiro seguido do conteúdo do segundo)
================================================================================
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

FILE *arq;
FILE *arq2;
FILE *arq3;
char NomeArquivo1[21];
char NomeArquivo2[21];
char c;
int resultado;

//adquirindo pelo usuario o nome dos arq1 e arq2 para gerar o arq3
  printf("Insira o nome do primeiro arquivo:");
  setbuf(stdin,NULL);
  fgets(NomeArquivo1,21,stdin);
  NomeArquivo1[strcspn(NomeArquivo1,"\n")]='\0';
  printf("Insira o nome do segundo arquivo:");
  setbuf(stdin,NULL);
  fgets(NomeArquivo2,21,stdin);
  NomeArquivo2[strcspn(NomeArquivo2,"\n")]='\0';

  arq = fopen(NomeArquivo1,"r"); //abrindo e testando separadamente
  if(arq == NULL){
    printf("Erro na abertura do Arquivo 1\n");
  }
  arq2 = fopen(NomeArquivo2,"r");
  if(arq == NULL){
    printf("Erro na abertura do arquivo 2\n");
  }
  //para saber em qual arq daria erro antes de fechar caso fosse nos dois
    if(arq == NULL || arq2 == NULL){
      exit(1);
    }

    arq3 = fopen("Juncao.txt","w"); //abrindo e nomeando o arq3 usando 'write'
    if(arq3 == NULL){
      printf("Erro na abertura do arquivo 3\n");
    }
//copiando o conteudo de arq1 para arq3
    while((c = fgetc(arq)) != EOF){
    resultado = fputc(c,arq3);
    if(resultado == EOF){
      printf("Erro na gravacao\n");
      exit(1);
    }
  }
  fputc('\n',arq3); //pula linha pra ficar bunitin
//copiando o conteudo de arq2 para arq3
    while((c = fgetc(arq2)) != EOF){
    resultado = fputc(c,arq3);
    if(resultado == EOF){
      printf("Erro na gravacao\n");
      exit(1);
    }//if
  }//while

fclose(arq);
fclose(arq2);
fclose(arq3);
printf("Nenhum erro aparente, verificar no arquivo \"Juncao\"\n");//teste
  return 0;
}
*/
/*
================================================================================
Escreva um programa para converter o conteúdo de um arquivo texto em caracteres
maiúsculos. O programa deverá ler do usuário o nome do arquivo a ser convertido
e o nome do arquivo a ser salvo.
================================================================================
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){

FILE *arq;
FILE *arq2;
char NomeArquivo1[21];
char NomeArquivo2[21];
char c;
int resultado;
//adquirindo os nomes dos arquivos
printf("Insira o nome de um arquivo para ser convertido:");
setbuf(stdin,NULL);
fgets(NomeArquivo1,21,stdin);
NomeArquivo1[strcspn(NomeArquivo1,"\n")]='\0';
printf("Insira o nome do arquivo que devera ser salvo:");
setbuf(stdin,NULL);
fgets(NomeArquivo2,21,stdin);
NomeArquivo2[strcspn(NomeArquivo2,"\n")]='\0';
//abrindo e verificando os arquivos
arq = fopen(NomeArquivo1,"r"); //neste caso apenas para ler
if(arq == NULL){
  printf("Erro na abertura do Arquivo 1\n");
  exit(1);
}
arq2 = fopen(NomeArquivo2,"w"); //aqui sim sera "write"
if(arq2 == NULL){
  printf("Erro na abertura do Arquivo 2\n");
  exit(1);
}
//pegando a letra e escrevendo em maiusculo
while((c = fgetc(arq)) != EOF){
//demorei pra entender o lugar certo do upper
  resultado = fputc(toupper(c),arq2);
  if(resultado == EOF){
    printf("Erro na gravacao\n");
    exit(1);
  }//if
}

fclose(arq);
fclose(arq2);
printf("Nenhum erro aparente, verificar no arquivo\n");//teste

  return 0;
}
*/
/*
================================================================================
Crie um programa para calcular e exibir o número de palavras contido em um
arquivo texto. O usuário deverá informar o nome do arquivo
================================================================================
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
//Incluir varaiveis necessarias
FILE *arq;
int ContaPalavras = 0;
int resultado;
char NomeArquivo[21];
int ultima;
char c;
//Ler o nome e a palavra do teclado
printf("Insira o nome de um arquivo:");
setbuf(stdin,NULL);
fgets(NomeArquivo,21,stdin);
NomeArquivo[strcspn(NomeArquivo,"\n")]='\0';
//abrir o arquivo e verificar
  arq = fopen(NomeArquivo,"r");
  if(arq == NULL){
    printf("Erro na abertura do arquivo\n");
    exit(1);
  }
//adquirindo a letra e verificando se deve continuar
  while ((c = fgetc(arq)) != EOF){
  ultima = 1; //para a ultima palavra
    if (c == ' ' || c == '\n'){ //verificando se 'c' e igual a ' ' ou '\n'
       ContaPalavras++;
       }
  }
  if (ultima){ //condicao especial para a ultima palavra
     ContaPalavras++;
   }

printf("O arquivo possui %d palavra(as).\n",ContaPalavras);

fclose(arq);

  return 0;
}
*/

/*
================================================================================
Elabore um programa para calcular e exibir o número de vezes que cada letra
ocorre dentro de um arquivo texto. Ignore as letras com acento.
O usuário deverá informar o nome do arquivo.
================================================================================
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){

//Variaveis necessarias
  FILE *arq;
  char NomeArquivo[21];
  char c;
  int contadorABCD[26];
  char abcd[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p',
  'q','r','s','t','u','v','w','x','y','z'};
//zerando o vetor contadorABCD
  for (size_t i = 0; i < 26; i++) {
contadorABCD[i] = 0;
  }

//lendo o nome do arquivo do teclado
  printf("Insira o nome de um arquivo:");
  setbuf(stdin,NULL);
  fgets(NomeArquivo,21,stdin);
  NomeArquivo[strcspn(NomeArquivo,"\n")]='\0';
//abrindo e verificando
arq = fopen(NomeArquivo,"r");
  if (arq == NULL){
      printf("Erro ao abrir\n");
      exit(1);
   }
//comparando cada letra do arquivo com as letras do vetor abcd
  while ((c = fgetc(arq)) != EOF){
    for (size_t i = 0; i < 26; i++) {
     if (tolower(c) == abcd[i]){
        contadorABCD[i]++; //se Verd. o contador com a mesma posicao do abcd ++
        }
      }
      }
    for (size_t i = 0; i < 26; i++) {
     if (contadorABCD[i] != 0){ //Exibir apenas as letras que foram encontradas
        printf("A letra %c aparece %d vezes\n",abcd[i],contadorABCD[i]);
        }
      }

fclose(arq);

return 0;
}

/*
================================================================================
Elabore um programa no qual o usuário informe o nome de um arquivo texto e uma
palavra, e o programa informe o número de vezes que aquela palavra aparece
================================================================================
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
//Declarando as variaveis
FILE *arq;
char resultado;
char NomeArquivo[21];
char palavra[11];
int aux = 0;
int Tp; //Tamanho da palvra.
int aux2 = 0;
//lendo o nome e a palavra do teclado
  printf("Insira o nome de um arquivo:");
  setbuf(stdin,NULL);
  fgets(NomeArquivo,21,stdin);
  NomeArquivo[strcspn(NomeArquivo,"\n")]='\0';
  printf("Insira uma palavra:");
  setbuf(stdin,NULL);
  fgets(palavra,11,stdin);
  palavra[strcspn(palavra,"\n")]='\0';
//adquirirndo o tamanho da palavra
  Tp = strlen(palavra);
//abrindo o arquivo e verificando
  arq = fopen(NomeArquivo,"r");
  if(arq == NULL){
    printf("Erro na abertura do arquivo\n");
    exit(1);
  }
//Encontrar a palavra dentro do arquivo
  while ((resultado = fgetc(arq)) != EOF){
     if (aux == Tp){ //se encontrar todas as letras aux2++ e reseta para procurar dnv
        aux2++;
        aux = 0;
        }
        else{

     if (palavra[aux] == resultado){// se Verd. verificara a prox letra
        aux++;
        }
        else{

     if (palavra[aux] != resultado){// se Verd. volta para a primeira letra
        aux = 0;
        }
      }
    }
  }

  printf("A palavra foi encontrada %d vezes.\n",aux2);

fclose(arq);

return 0;
}
*/
