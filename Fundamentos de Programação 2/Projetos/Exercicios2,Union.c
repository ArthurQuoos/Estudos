/*
@file: Exercicios2,Union.c
@date: 02/10/2021
@author: Arthur Albert Schmaiske Quoos
@brief: Exercicio 2: Cadastro de 5 pessoas.
*/
/*
Crie uma enumeração representando os meses do ano.
 Agora, escreva um programa que leia um valor inteiro do teclado
 e exiba o nome do mês correspondente e a quantidade de dias que ele possui.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
//passo1: Enumerando os meses.
typedef enum {JANEIRO=1,FEVEREIRO,MARCO,ABRIL,MAIO,JUNHO,JULHO,AGOSTO,SETEMBRO,
OUTUBRO,NOVEMBRO,DEZEMBRO}Meses;

int main(){
//passo2: adquirir o valor do teclado.
  int opcao;
  printf("Insira um numero:");
  scanf("%d",&opcao);

  switch(opcao){
//passo3: Meses de 31 dias.
case JANEIRO:
  printf("Mes de Janeiro: 31 dias.\n");
  break;
case MARCO:
  printf("Mes de Marco: 31 dias.\n");
break;
case MAIO:
  printf("Mes de Maio: 31 dias.\n");
break;
case JULHO:
  printf("Mes de Julho: 31 dias.\n");
break;
case AGOSTO:
  printf("Mes de Agosto: 31 dias.\n");
break;
case OUTUBRO:
  printf("Mes de Outubro: 31 dias.\n");
break;
case DEZEMBRO:
  printf("Mes de Dezembro: 31 dias.\n");
break;
//passo4: Meses com 29 dias.
case NOVEMBRO:
  printf("Mes de Novembro: 29 dias.\n");
break;
case SETEMBRO:
  printf("Mes de Setembro: 29 dias.\n");
break;
case JUNHO:
  printf("Mes de Junho: 29 dias.\n");
break;
case ABRIL:
  printf("Mes de Abril: 29 dias.\n");
break;
//passo5: Fevereiro com 28 dias.
case FEVEREIRO:
  printf("Mes de Fevereiro: 28 dias (em anos bissextos possui 29 dias).\n");
break;
//passo6: para o caso de inserir um numero errado.
default:
  printf("Numero invalido.\n");
}
*/

/*
Crie um programa de cadastro que receba, armazene, e em seguida, exiba os dados de 5 pessoas.
Cada pessoa possui: nome, idade, peso, data de nascimento, brasileiro ou estrangeiro.
Caso seja Brasileiro, armazene o CPF, caso estrangeiro, armazene o passaporte.

Regra: Utilize structs, typedef, union e enum.
*/

//passo1:Criar a estrutura como requisitado pelo enunciado
typedef enum {BRASILEIRO=1, ESTRANGEIRO}Nacionalidade;

typedef struct{
  char nome[51];
  Nacionalidade tipo; //chamando enum
  int idade;
  float peso;
  struct{
    int dia;
    int mes;
    int ano;
  }Nascimento;
  union{
    int cpf;
    char passaporte[15];
  }Id;

}Cadastro;

int main(){
  Cadastro Pessoas[5];
printf("Sistema de Cadastro.\n");

//passo2: Adquirir todas as informacoes do teclado
for (size_t i = 0; i < 5; i++) {
  printf("Insira os seus dados:\nSeu Nome:");  //nome
  fflush(stdin);  //dica do Letrouche de por o fflush/setbuf antes de ler a string
  fgets(Pessoas[i].nome,51,stdin);
  Pessoas[i].nome[strcspn(Pessoas[i].nome,"\n")]='\0';

  printf("Quantos anos voce tem?");  //idade
  scanf("%d",&Pessoas[i].idade);

  printf("Quanto voce pesa?");  //peso
  scanf("%f",&Pessoas[i].peso);

  printf("Qual a data que voce nasceu?(dia, mes e ano)"); //nascimento
  scanf("%d",&Pessoas[i].Nascimento.dia);
  scanf("%d",&Pessoas[i].Nascimento.mes);
  scanf("%d",&Pessoas[i].Nascimento.ano);

do{ //"do_while" para o caso de uma "opcao invalida"
  printf("Qual sua nacinalidade, (1 para Brasileiro e 2 para Estrangeiro)\n");
  scanf("%d",&Pessoas[i].tipo);

switch(Pessoas[i].tipo){   //para adquirir ou CPF ou passaporte
    case BRASILEIRO:
    printf("Qual seu CPF:");
    scanf("%d",&Pessoas[i].Id.cpf);
    setbuf(stdin,NULL);
break;
    case ESTRANGEIRO:
    printf("Qual seu passaporte:");
    setbuf(stdin,NULL);
    fgets(Pessoas[i].Id.passaporte,15,stdin);
    Pessoas[i].Id.passaporte[strcspn(Pessoas[i].Id.passaporte,"\n")]='\0';
break;
  default:
    printf("Opcao invalida\n");
break;

  }//switch
  }while(Pessoas[i].tipo != 1 && Pessoas[i].tipo !=2);//do
  }//for

//passo3: Exibir todas as informacoes
for (size_t i = 0; i < 5; i++) {
  printf("\n====================================================================\n");//enfeite
    if(Pessoas[i].tipo==1){
      printf("Nome: %s \nIdade: %d \nPeso: %.2f \nData de nascimento: %.2d/%.2d/%.4d \nOrigem: Brasileiro CPF: %d\n",
      Pessoas[i].nome,Pessoas[i].idade,Pessoas[i].peso,Pessoas[i].Nascimento.dia,Pessoas[i].Nascimento.mes,Pessoas[i].Nascimento.ano,Pessoas[i].Id.cpf);
    }else{
      printf("Nome: %s \nIdade: %d \nPeso: %.2f \nData de nascimento: %.2d/%.2d/%.4d \nOrigem: Estrangeiro Passaporte: %s",
      Pessoas[i].nome,Pessoas[i].idade,Pessoas[i].peso,Pessoas[i].Nascimento.dia,Pessoas[i].Nascimento.mes,Pessoas[i].Nascimento.ano,Pessoas[i].Id.passaporte);
    }//else
  }//for

  return 0;
}//main
