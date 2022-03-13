/*
Você foi convocado para trabalhar como programador nas Olimpíadas de Tokyo.
Seu trabalho é gerar um relatório sobre as medalhas distribuídas.
Para isso, faça um programa que receba a quantidade de medalhas de ouro,
 prata e bronze de diversos países.
Após digitar os dados de cada país,
o programa deve perguntar se o usuário deseja digitar os dados de um novo país.
O programa deve continuar recebendo dados se o usuário entrar a letra s (de sim) ou finalizar ao receber qualquer outro valor.
Ao finalizar o programa deve exibir:
a) A quantidade de países que foram informados
b) A soma de todas as medalhas de ouro, prata e bronze (separadamente);
c) A quantidade de países que não receberam nenhuma medalha.
*/
/*
@file: ProvaExercicio2.c
@date: 20/07/2021
@author: Arthur Albert Schmaiske Quoos
@brief: Relatorio das olimpiadas
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
  int ouro,prata,bronze;
  int ouro2 = 0;
  int prata2 = 0;
  int bronze2 = 0;//as variaveis "2" sao para acumular os valores
  int paises = 0; //paises que nao adquiriram medalhas
int auxiliar = 0;
int contador = 0;//para contar os paises informados
char opcao;
printf("Relatorio das Olimpiadas de Tokio \n");
do{
  contador++;
printf("\nOlimpiadas de tokio Pais \"%d\"\n",contador);
  printf("Medalhas de ouro deste pais: ");
  scanf("%d",&ouro);
  printf("Medalhas de prata deste pais: ");
  scanf("%d",&prata);
  printf("Medalhas de bronze deste pais: ");
  scanf("%d",&bronze);
  if(ouro == 0 && prata == 0 && bronze == 0){
  ++paises;
}//if (so pra garantir que nao vai dar problema eu vou usar as {} )
ouro2 = ouro + ouro2;

prata2 = prata + prata2;   //acumulando os valores

bronze2 = bronze +bronze2;

setbuf(stdin,NULL);
  printf("Deseja entrar outro pais(S/N): "); 
  scanf("%c",&opcao);

} while(opcao == 'S');

  printf("\nConclusao: \n\n");
  printf("Paises informados: %d\n",contador);
  printf("Total de medalhas de ouro: %d\n",ouro2);
  printf("Total de medalhas de prata: %d\n",prata2);
  printf("Total de medalhas de bronze: %d\n",bronze2);
  printf("Paises que nao adquiriram nenhuma medalha: %d\n",paises);

  return 0;
}//main
