/*
@file: Prova2Exercicio2.c
@date: 24/08/2021
@author: Arthur Albert Schmaiske Quoos
@brief: Execicio 2 da prova 2
*/
/*
A comissão organizadora das Olimpíadas de Tokyo 2020 gostou do seu trabalho na
prova anterior e lhe passou mais uma tarefa.

Agora para ajudar no Salto em Distância. Para isso, faça um programa que armazene
os dados de 5 atletas, cada atleta possui nome (20 caracteres),
e a distancia de três saltos (real) e o maior salto
(que deverá ser determinado a partir dos três saltos).
Para isso, faça cada item abaixo em uma função diferente:

a) Faça um programa que receba os dados dos 5 atletas: nome(strings)
e 3 saltos ( matriz 5x4 - valores entre 2 e 10 metros inclusive).
Solicite novos valores caso o usuário digite fora da faixa permitida.

b) Calcule o maior salto de cada atleta, utilizando um laço for,
e salve na última coluna da matriz dos saltos;

c) Exiba em formato de tabela (alinhada) os nomes,
e o maior salto de todos os atletas que saltaram 5 metros ou mais
( com duas casas decimais).

d) Utilizando laços de repetição,
calcule e exiba a média dos maiores saltos dos 5 atletas.

e) Exiba o nome do atleta e a distancia do melhor salto do atleta que
saltou a maior distância (duas casas decimais)(campeao).

f) Receba um nome de atleta e busque ele na lista, exibindo os 3 saltos desse
atleta e o valor do seu maior salto (apenas 1 vez). Exiba uma mensagem
informando também caso não encontre o nome buscado.

Obs.:

Os itens devem ser executados sequencialmente
Para obtenção da nota máxima, faça a leitura inicial e cada item, de A a F, em uma função separada.
Bônus do professor maluco: Escolha, obrigatoriamente, um dos itens de "C" a "F"
para ser eliminado da questão, indique o item descartado com um comentário em seu código
*/
#include <stdio.h>
#include <stdlib.h>

//passo1:Variaveis necessarias
char nome[5][10];
float saltos[5][4];
float media=0;
char nomeF[10];

//passo2:LetraA Adquirir os dados
void letraA(){
    printf("Insira os dados dos atletas(nome)(3saltos):\n");
  for(int x=0;x<5;x++){
    fgets(nome[x],10,stdin);
    nome[strcspn(nome,"\n")]='\0';
    setbuf(stdin,NULL);
    for(int y=0;y<5;y++){
      for(int z=0;z<3;z++){
        scanf("%f",&salto[y][z]);
      }//forz
    }//fory
  }//forx
  return;
}//letraA

//passo3:LetraB adquirir o maior salto e coloca-lo na 4 posicao da matriz "saltos"
void letraB(){
  float maior=0;
  for(int x=0;x<5;x++){
    for(int y=0;y<3;y++){
    if(saltos[x][y] > maior){
      maior = saltos[x][y];
      saltos[x][4] = maior;
      media += maior // preparando para a letraD
      }
    }
  }
    return;
}//letraB

//passo4:Exibir em formato de tabela apenas os atletas com o mairo salto sendo>5
void letraC(){

  printf("Nomes: \tMaiores saltos:\n");
for(int x=0;x<5;x++){
  //for(int y=0;y<4;y++){
    if(salto[x][4] > 5){
      printf("%-10s%.2f\n",nome[x],saltos[x][4]);
    }//if
  }//forx
return;
}//letraC

//passo5:Calcular a media dos maior saltos
void letraD(){

media = media / 5;
printf("\nA media dos maiores saltos e de: %.2f\n",media);

  return;
}

//Bonus do professor: vou usar esse bonus na letra E

//passo6:Encontrar um nome na lista e exibir (nao consegui inserir de uma forma
//que aparecesse 1 vez a msg para o caso de nao encontrar o nome)
void letraF(){

fgets(nomeF,10,stdin);
nome[strcspn(nome,"\n")]='\0';
setbuf(stdin,NULL);


  for(int x=0;x<5;x++){
    if(strcasecmp(nome[x],nomeF)==0){
      printf("\nAtleta: %s %.2f %.2f %.2f e maior salto %.2f\n",nome[x],saltos[x][0],saltos[x][1],saltos[x][2],saltos[x][3]);
    }

  }
  return;
}

//passo7: main() para conectar todas as funcoes.
int main(){

letraA();
letraB();
letraC();
letraD();
letraF();


  return 0;
}
