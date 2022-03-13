#include <stdio.h>
#include <stdlib.h>
#include <string.h>  //biblioteca das funcoes de string.
//#include <stdio_ext.h>     //para a funcao fpurge
int main(){
/*
  char nome[21];  //lembrar de considerar o \0 ou \n por isso +1

  printf("Digite um nome: ");
  fgets(nome, 21, stdin);
  nome[strcspn(nome,"\n")]='\0';
  setbuf(stdin,NULL);

  printf("Nome: %s\n", nome);
  printf("A primeira letra: %c.\n",nome[0]); //diferenca para letra e nome inteiro...
*/
/*
  char nomes [4][10];           //"string matriz"

  for(int l=0;l<4;l++){
    printf("Digite um nome: ");
    fgets(nomes[l],10,stdin);
    nomes[l][strcspn(nomes[l],"\n")]='\0';
    //setbuf(stdin,NULL);
    fflush(stdin);
    //fpurge(stdin);    //para nomes muito grandes setbuff pode nao ser o bastante
}//for

  for(int l=0;l<4;l++){
    printf("Nome : %-10s | ",nomes[l]);
    printf("Primeira letra: %c.\n",nomes[l][0]);
  }//for
*/

/*
char nome[21];
int tamanho;
char saida[21];//copy
char sobrenome[21];

  printf("Digite um nome:");
  fgets(nome,21,stdin);
  nome[strcspn(nome,"\n")]='\0';
  setbuf(stdin,NULL);
  printf("Digite o sobrenome:");
  fgets(sobrenome,21,stdin);
  nome[strcspn(sobrenome,"\n")]='\0';
  setbuf(stdin,NULL);

            //comandos de string

//tamanho = strlen(nome);  //Quantos caracteres na string, atencao com acentos
//strcpy(saida, nome);     //copiar uma string para outra
strcat(nome," ");       //'espaco' para separar o nome do sobrenome.
strcat(nome,sobrenome);  // juntar duas strings
  printf("Nome Completo: %s\n", nome);
  //printf("Tamanho do nome: %d.\n",tamanho); //strlen
  //printf("Nome saida: %s\n",saida);  //strcpy
*/


char nome1[21] = "Joao";
char nome2[21] = "joao"; //<-- diferenca entre maiusculo e minusculo.'case' <- desconsidera

if(strcasecmp(nome1,nome2)==0){  // <---- compara as strings <-- 'case'
  printf("Os nomes sao iguais!\n");
}else{
  printf("Os nomes NAO sao iguais!\n");
}//else






  return 0;
}//main
