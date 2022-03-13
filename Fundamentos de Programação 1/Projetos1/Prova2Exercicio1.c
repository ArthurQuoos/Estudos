/*
@file: Prova2Exercicio1.c
@date: 24/08/2021
@author: Arthur Albert Schmaiske Quoos
@brief: Execicio 1 da prova 2 manipular as string de acordo com o que foi pedido
*/
/*
Faça um programa que receba duas frases com o tamanho máximo de 30 caracteres cada.

Se Frase1 e Frase2 tiverem o mesmo tamanho, o programa deverá criar
uma NOVA string Frase3, contendo a primeira e segunda frases intercaladas.
Exemplo:
Frase1: BRASIL
Frase2: parana
Frase3: BpRaArSaInLa


 Se Frase1 e Frase2 tiverem tamanhos diferentes, deve-se gerar uma
 NOVA string Frase3, que é o resultado da concatenação de Frase1 com Frase2 com
 um caractere de espaço entre elas.

Exemplo:
Frase1: BRASIL
Frase2: UTFPR
Frase3: BRASIL UTFPR

Obs.: Em nenhum dos casos as strings com as Frases iniciais devem ser modificadas.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//passo1:Declaração das variaveis necessarias.
char frase1[30];
char frase2[30];
char frase3[100];
  int tamanho1;
  int tamanho2;

//passo1:funcao para o caso dos tamanhos iguais
/*
void tamanhoigual(){
for(int x=0;x<tamanho1;x++){
strcat(frase3,frase1);
strcat(frase3,frase2);
}
printf("teste frase 3: %s",frase3);
return;
}
*/

//passo3:funcao para o caso dos tamanhos diferentes
void tamanhodif(){

strcat(frase3,frase1);
strcat(frase3," ");
strcat(frase3,frase2);

return;
}

//passo4:int main() para adquirir os valores das strings e conectar as funcoes
int main(){


printf("Insira duas frases: \n");

fgets(frase1,30,stdin);
frase1[strcspn(frase1,"\n")]='\0';
setbuf(stdin,NULL);

fgets(frase2,30,stdin);
frase2[strcspn(frase2,"\n")]='\0';
setbuf(stdin,NULL);

tamanho1 = strlen(frase1);
tamanho2 = strlen(frase2);

if(tamanho1 == tamanho2){
  //tamanhoigual();

}else{
  tamanhodif();
}

//passo5:Exibir os resultados finais.
printf("\nFrase1: \"%s\"\n",frase1);
printf("Frase2: \"%s\"\n",frase2);
printf("Frase3: \"%s\"\n",frase3);



  return 0;
}
