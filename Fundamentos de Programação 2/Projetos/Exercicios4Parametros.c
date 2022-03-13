/*
@file: Exercicios4Parametros.c
@date: 07/10/2021
@author: Arthur Albert Schmaiske Quoos
@brief:
*/
/*
================================================================================
Escreva um programa que receba um número inteiro representando
a quantidade total de segundos e, usando passagem de parâmetros por referência,
converta a quantidade informada de segundos em Horas, Minutos e Segundos.
Imprima o resultado da conversão no formato HH:MM:SS.
Utilize o seguinte protótipo da função:
void converteHora(int total_segundos, int* hora, int* min, int* seg)
================================================================================
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//passo1: Criar a funcao converteHora como no enunciado
void converteHora(int total_segundos, int* hora, int* min, int* seg){
//o valor de total_segundos nao sera alterado portanto nao precisa de ponteiro
  *min = total_segundos % 3600;
  *hora = total_segundos / 3600;
  *seg = *min % 60;
  *min = *min / 60;
  return;
}//converteHora
//passo2: Main com as variaveis necessarias
int main(){
  int total_segundos;
  int hora;
  int min;
  int seg;
//passo3: adquirir o o valor de total_segundos
  printf("Conversao de segundos para horas, minutos e segundos.\n");
  printf("Quantos segundo voce deseja converter?\n");
  scanf("%d",&total_segundos);
//passo4: chamando a funcao converteHora prestando atencao aos ponteiros
  converteHora(total_segundos, &hora, &min, &seg);
  printf("\nConvertendo.");
  sleep(1); //zuera
  printf(".");
  sleep(1);
  printf(".\n");
  sleep(1);
//passo5: Exibir o resultado.
  printf("\nResultado: %.2d:%.2d:%.2d\n",hora,min,seg);

return 0;
}
*/
/*
================================================================================
Reescreva o exercício anterior utilizando a estrutura horário (contendo hora, minuto e segundo)
e passando a estrutura por referência. Utilize o seguinte protótipo da função:
void converteHorario(int total_segundos, Horario* hor)
================================================================================
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//passo1:Definindo a struct conforme o enunciado
typedef struct{
  int hora;
  int min;
  int seg;
}Horario;

//passo2: Reescrevendo a funcao de acordo com a struct
void converteHora(int total_segundos, Horario* Tempo){
  Tempo->min = total_segundos % 3600;
  Tempo->hora = total_segundos / 3600;
  Tempo->seg = Tempo->min % 60;
  Tempo->min = Tempo->min / 60;
return;
}//converteHora

int main(){
  int total_segundos;
  Horario Tempo;

//passo3: adquirir o o valor de total_segundos
  printf("Conversao de segundos para horas, minutos e segundos.\n");
  printf("Quantos segundo voce deseja converter?\n");
  scanf("%d",&total_segundos);

//passo4: chamando a funcao converteHora prestando atencao aos ponteiros
  converteHora(total_segundos, &Tempo);
  printf("\nConvertendo.");
  sleep(1); //zuera
  printf(".");
  sleep(1);
  printf(".\n");
  sleep(1);
//passo5: Exibir o resultado.
  printf("\nResultado: %.2d:%.2d:%.2d\n",Tempo.hora,Tempo.min,Tempo.seg);

return 0;
}
*/
/*
================================================================================
Crie um Sistema de Gerenciamento de Bandas seguindo os seguintes passos:
a) Defina uma estrutura que irá representar bandas de música.
Essa estrutura deve ter o nome da banda, que tipo de música ela toca,
o número de integrantes e em que posição do ranking essa banda está dentre as
suas 5 bandas favoritas;

b) Crie uma função para preencher as 5 estruturas de bandas criadas no exemplo passado.
Após criar e preencher, exiba todas as informações das bandas/estruturas.

c) Crie uma função que peça ao usuário um número de 1 até 5. Em seguida,
seu programa deve exibir informações da banda cuja posição no seu ranking é a que
foi solicitada pelo usuário;

d) Crie uma função que peça ao usuário um tipo de música e exiba as bandas
com esse tipo de música no seu ranking.

e) Crie uma função que peça o nome de uma banda ao usuário e diga se ela está
entre suas bandas favoritas ou não;

f) Agora junte tudo e crie um menu com as opções de preencher as estruturas
e todas as opções das questões passadas.
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//passo1: Definir a estrutura como exigido no enunciado
typedef struct{
  char nome[21];
  char tipo[21];
  int integrantes;
  int ranking;
}Bandas;

//passo2: Funcao para preencher a struct
void preencher(Bandas* Banda){
  for (int i = 0; i < 5; i++) {
    printf("\nBanda #%d\n",i+1);

    printf("Qual o nome dessa Banda?\n"); //nome
    setbuf(stdin,NULL);
    fgets(Banda[i].nome,21,stdin);
    Banda[i].nome[strcspn(Banda[i].nome,"\n")]='\0';

    printf("Qual o estilo musical?\n"); //Estilo musical
    setbuf(stdin,NULL);
    fgets(Banda[i].tipo,21,stdin);
    Banda[i].tipo[strcspn(Banda[i].tipo,"\n")]='\0';

    printf("Quantos integrantes?\n"); //<-- Quantos integrantes kkk
    scanf("%d",&Banda[i].integrantes);

    printf("E qual o ranking dela no seu Top5?\n"); //Ranking
    scanf("%d",&Banda[i].ranking);
}//for
                     //Exibir
printf("\n================================================================================\n");
for (int x = 0; x < 5; x++) {
  printf("\nBanda #%d\n",x);
  printf(" * Banda: %s\n",Banda[x].nome);
  printf(" * Tipo de musica: %s\n",Banda[x].tipo);
  printf(" * Integrantes: %d\n",Banda[x].integrantes);
  printf(" * Ranking: %d\n",Banda[x].ranking);
}//for
  return;
}//preencher

//passo3: Funcao para pesquisar por ranking
void qualRanking(Bandas* Banda){
  int opcao;
  printf("\n================================================================================\n");
  printf("Qual posicao do ranking voce deseja visualizar?");
  scanf("%d",&opcao);

  for (size_t i = 0; i < 5 ; i++) {   //exibindo
    if(Banda[i].ranking==opcao){
      printf("\nBanda #%d\n",i+1);
      printf(" * Banda: %s\n",Banda[i].nome);
      printf(" * Tipo de musica: %s\n",Banda[i].tipo);
      printf(" * Integrantes: %d\n",Banda[i].integrantes);
      printf(" * Ranking: %d\n",Banda[i].ranking);
    }//if
  }//for
  return;
}//Top5

//passo4:Funcao para pesquisar por tipo musical
void qualTipo(Bandas* Banda){
char pesquisarTipo[21];
int x=0;
char S_ou_N; //Sim ou Nao
  printf("\n================================================================================\n");
  do{
    printf("Por qual tipo de musica voce deseja pesquisar?");
    setbuf(stdin,NULL);
    fgets(pesquisarTipo,21,stdin);
    pesquisarTipo[strcspn(pesquisarTipo,"\n")]='\0';

      for (size_t i = 0; i < 5; i++) {
        if(strcasecmp(pesquisarTipo,Banda[i].tipo)==0){
          printf("%s",Banda[i].nome);
      }//if
    }//for
    printf(" - Deseja pesquisar novamente?(s/n)");
    scanf("%c",&S_ou_N);
  }while(S_ou_N !='n');
  return;
}//qualTipo

//passo5: Pesquisar por nome
void qualNome(Bandas* Banda){
char pesquisarNome[21];
char S_ou_N; //Sim ou Nao
  printf("\n================================================================================\n");
  do{
  printf("Por qual banda voce deseja pesquisar?");
  setbuf(stdin,NULL);
  fgets(pesquisarNome,21,stdin);
  pesquisarNome[strcspn(pesquisarNome,"\n")]='\0';

  for (size_t i = 0; i < 5; i++) {
    if(strcasecmp(pesquisarNome,Banda[i].nome)==0){
    printf("Banda encontrada! esta banda faz parte da lista\n");
    return;
  }//if
}//for
  printf("Banda nao encontrada. Esta banda nao faz parte da lista.\n");
  printf(" - Deseja tentar novamente?(s/n)\n");
  scanf("%c",&S_ou_N);
}while(S_ou_N !='n');
  return;
}//qualNome

int main(){
  Bandas Banda[5];
  int opcao;
  do{
printf("\n================================================================================\n");
  printf("\t-Menu-\n");
  printf("- 1 - Adicionar informacoes.\n");
  printf("- 2 - Pesquisar por Ranking.\n");
  printf("- 3 - Pesquisar por tipo de musica.\n");
  printf("- 4 - Verificar se uma banda esta na lista.\n");
  printf("- 5 - Fechar o programa.\n");
  printf("OBS: Primeiro adicione informacoes a lista para usar este programa corretamente!\n");
scanf("%d",&opcao);
switch(opcao){
  case 1:
    preencher(Banda);
  break;
  case 2:
    qualRanking(Banda);
  break;
  case 3:
    qualTipo(Banda);
  break;
  case 4:
    qualNome(Banda);
  break;
  case 5:
    printf("Finalizando.");
    sleep(1);
    printf(".");
    sleep(1);
    printf(".\n\n");
    return 0;
    break;
  default:
  printf("Opcao invalida.\n");
  break;
  }//switch
}while(1);// para finalizar com o "5";

  return 0;
}
