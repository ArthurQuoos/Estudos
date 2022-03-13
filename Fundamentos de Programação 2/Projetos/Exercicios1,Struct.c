/*
@file: Exercicios1_Struct.c
@date: 29/09/2021
@author: Arthur Albert Schmaiske Quoos
@brief: Exercicio 1;
*/
/*
Crie uma estrutura para representar as coordenadas de um ponto no plano
(posições X e Y).
Em seguida, declare e leia do teclado dois pontos e exiba a
distância entre eles.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
float Res;//Resultado final
//passo1: Criar a estrutura
typedef struct{
  int x;
  int y;
}Ponto;
//passo2: adquirir os pontos do teclado
int main(){
Ponto pontos[2];
  for(int i = 0;i<2;i++){
  printf(" X%d =",i+1);
  scanf("%d",&pontos[i].x);
  printf(" Y%d =",i+1);
  scanf("%d",&pontos[i].y);
}
//passo3: Calcular a distancia dos pontos
Res = sqrt(pow(pontos[0].x-pontos[1].x,2)+pow(pontos[0].y-pontos[1].y,2));
//passo4: Exibir o resultado
printf("Resultado final: %.2f\n",Res);

  return 0;
}
*/
/*2
Escreva um trecho de código para fazer a criação
dos novos tipos de dados conforme solicitado abaixo:
• Horário: composto de hora, minutos e segundos.
• Data: composto de dia, mês e ano.
• Compromisso: local, horário, Data e texto que descreve o compromisso.
*/
/*
//passo1:criar as estruturas necessarias
typedef struct{
  char texto[31];
  char local[51];
}Compromisso;

typedef struct{
  int horas;
  int minutos;
  int segundos;
}Horario;

typedef struct{
  int dia;
  int mes;
  int ano;
}Data;
//passo2: adquirir as informacoes
int main(){
  Compromisso Descricao;//"chamando a struct"
  Horario Hora;
  Data Dia;
  printf("Gerador de convite automatico 2000\n"); //zuera

  printf("Insira o dia depois o mes e por fim o ano do evento:"); //Data
  scanf("%d",&Dia.dia);
  scanf("%d",&Dia.mes);
  scanf("%d",&Dia.ano);

  printf("Insira o horario, primeiro pelas horas depois os minutos e por fim os segundos:");//Horario
  scanf("%d",&Hora.horas);
  scanf("%d",&Hora.minutos);
  scanf("%d",&Hora.segundos);
  setbuf(stdin,NULL);

  printf("Qual sera o local?\n");//Local
  fgets(Descricao.local,31,stdin);
  Descricao.local[strcspn(Descricao.local,"\n")]='\0';
  fflush(stdin);

  printf("Um pequeno texto para o convite:\n");//Texto
  fgets(Descricao.texto,51,stdin);
  Descricao.texto[strcspn(Descricao.texto,"\n")]='\0';
  fflush(stdin);
//passo3: Exibir as informacoes com um minimo de beleza
  printf("\nData: %.2d/%.2d/%.4d\n",Dia.dia,Dia.mes,Dia.ano);
  printf("Horario: %.2d:%.2d:%.2d\n",Hora.horas,Hora.minutos,Hora.segundos);
  printf("\nLocal: %s\n",Descricao.local);
  printf("\n(texto) %s\n",Descricao.texto);

  return 0;
}
*/

/*3
Construa uma estrutura aluno com nome, curso e 4 notas, média e situação.
Leia as informações nome, curso e notas do teclado,
calcule a média e armazene a situação do aluno:

media ≥ 7 → Aprovado;
3 ≤ media < 7 → Exame;
media < 3 → Reprovado;
*/
/*
//passo1: Criar a estrutura de acordo com o enunciado
typedef struct{
  char nome[21];
  char curso[21];
  float notas[4];
  float media;
  char situacao[10];
}Aluno;

int main(){
  Aluno aluno;
//passo2:Ler as informacoes do teclado
  printf("Insira o nome do aluno:\n");  //nome do aluno
  fgets(aluno.nome,21,stdin);
  aluno.nome[strcspn(aluno.nome,"\n")]='\0';
  fflush(stdin);
  printf("Qual Curso o aluno esta matriculado?\n"); //curso do aluno
  fgets(aluno.curso,21,stdin);
  aluno.curso[strcspn(aluno.curso,"\n")]='\0';
  fflush(stdin);

  printf("Insira as 4 notas do aluno:\n");  //notas do aluno
  aluno.media = 0;//aproveitando este for para o proximo passo
  for (size_t i = 0; i < 4; i++) {
  scanf("%f",&aluno.notas[i]);
  aluno.media += aluno.notas[i];//aproveitando este for para o proximo passo
}
//passo3: Calcular a media com os valores obtidos pelo teclado
  aluno.media = aluno.media / 4;
//passo4:Definir a situacao do aluno de acordo com o enuciado
  if(aluno.media >= 7){
    strcpy(aluno.situacao,"Aprovado");
  }else{
    if(aluno.media >= 3 && aluno.media <= 7){
      strcpy(aluno.situacao,"Exame");
    }else{
      if(aluno.media < 3){
        strcpy(aluno.situacao,"Reprovado");
      }//if
    }//else
  }//else
//passo5: Exibir as informacoes
printf("\nAluno: %s \nCurso: %s\n",aluno.nome,aluno.curso);
printf("Notas:\n");
for (size_t i = 0; i < 4; i++) {
printf("%.1f\n",aluno.notas[i]);
}
printf("Media do aluno: %.2f\n",aluno.media);
printf("%s\n",aluno.situacao);

  return 0;
}
*/
/*4
Faça um programa que controla o consumo de energia dos eletrodomésticos de uma casa e:

–Crie e leia 5 eletrodomésticos que contém nome (máximo 15 letras),
potência (real, em kW) e tempo ativo por dia (real, em horas).

–Leia um tempo t (em dias), calcule e mostre o consumo total na casa e o
consumo relativo de cada eletrodoméstico (consumo/consumo total)
nesse período de tempo. Apresente este último dado em porcentagem.
*/

//variaveis necessarias para os passos 3 e 4
float consumo=0;
float consumo_total=0;
float consumo_total2=0; //copia
int tempo_mes=0;

//passo1:definir a estrutura de acordo com o enunciado
typedef struct{
  char nome[16];
  float potencia;
  int tempo_H;
  float relativo;
}Eletrodomestico;

int main(){
  Eletrodomestico casa[5];
//passo2: adquirir as informacoes do teclado
for (size_t i = 0; i < 5; i++) {
  printf("Insira o nome do eletrodomestico:\n");
  fgets(casa[i].nome,16,stdin);
  casa[i].nome[strcspn(casa[i].nome,"\n")]='\0';
  fflush(stdin);
  printf("A potencia em kw:\n");
  scanf("%f",&casa[i].potencia);
  printf("E o tempo que fica ativo por dia (em horas):\n");
  scanf("%d",&casa[i].tempo_H);
  setbuf(stdin,NULL);
}

  printf("Por quantos dias do mes os eletrodomesticos sao utilizados:\n");
  scanf("%d",&tempo_mes);
//passo3: comecar a calcular o consumo total
//a parte do calculo nao e meu forte em...
for (size_t i = 0; i < 5; i++) {
  consumo = casa[i].potencia * casa[i].tempo_H;
  consumo_total += consumo;
}
//exibir o consumo total
  consumo_total = consumo_total * tempo_mes;
  printf("\nO consumo total na casa de KW e de: %.2f\n",consumo_total);
//passo4: calcular o consumo relativo de cada eltrodomestico e exibir
for (size_t i = 0; i < 5; i++) {
  consumo = casa[i].potencia * casa[i].tempo_H * tempo_mes;
  casa[i].relativo = (consumo / consumo_total) * 100;
  printf("O consumo relativo da %s e igual a %.2f%%\n",casa[i].nome,casa[i].relativo);
}

  return 0;
}
