/*
1
Crie um programa para armazenar 10 nomes  em um vetor e imprimir uma lista numerada
================================================================================
2
Faça um programa que armazene o nome e salário de 5 empregados.
Em seguida calcule um aumento de 8% nos salários e exiba a nova folha de pagamentos.
================================================================================
3
Desenvolva um programa que armazene o nome e o telefone de 5 pessoas.
 Ao digitar a posição desejada, o programa deve exibir o nome e telefone
 daquela posição. O programa finaliza ao receber a entrada -1.
================================================================================
4
Faça um programa que receba um nome,
ele deve perguntar novamente caso o nome tenha tamanho inferior a 5 caracteres.
 Ao receber um nome com 5 caracteres ou mais o programa exibe o nome e finaliza.
================================================================================
5
Faça um programa que receba uma frase e depois exiba quantas vezes cada vogal aparece.
 Ele deve contar considerando o tamanho da String.
6
Faça um programa que receba um nome e um sobrenome.
Ele deve construir uma nova string no formato americano (Sobrenome, Nome)
Exemplo: Silva, José
================================================================================
7
Escreva um programa que receba uma sigla de um estado da região Sul ou Sudeste
e exiba o nome completo do estado correspondente.
*/
/*
@file: exerciocioString.c
@date: 03/08/2021
@author: Arthur Albert Schmaiske Quoos
@brief:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){

/*
  //  1
//passo1: Declarando a string de acordo com o enunciado
char nomes[10][21];

//passo2: ler e armazenar os nomes
printf("Digite os nomes: ");

  for(int l=0;l<10;l++){
fgets(nomes[l],21,stdin);
nomes[l][strcspn(nomes[l],"\n")]='\0';
fflush(stdin);
  }//for

//passo3: Exibir os nomes
  for(int l=0;l<10;l++){
printf("%.2d - %-20s |\n",l +1,nomes[l]);
  }//for
*/

/*
  //  2
//passo1:Declarar as variaveis necessarias
float salario[5];
char empregados[5][11];
int x; //auxiliar
//passo2: ler os dados necessarios
for(int l=0;l<5;l++){
  printf("Insira o nome do empregado: ");
  fgets(empregados[l],11,stdin);
  empregados[l][strcspn(empregados[l],"\n")]='\0';
  setbuf(stdin,NULL);
  printf("Insira o salario do mesmo: ");
  scanf("%f",&salario[l]);
  setbuf(stdin,NULL);
//passo3:Calcular os novos salarios
x = salario[l];
x = x / 100; //1%
x = x * 8; //1% --> 8%
salario[l] += x;
}//for
//passo4:Exibir os novos valores
for(int l=0;l<5;l++){
  printf("O novo salario de: %s agora e: %.2f\n",empregados[l],salario[l]);
}
*/
/*
  // 3
//passo1: declarando e inicializando as variaves necessarias
int telefone[5] = {1234567,7654321,3217654,12324576,7654123};
char nome[5][21] = {"Eu","Eumesmo","Eudnv","Eumaisumavez","Simsoueu"};
int x;
//passo2: enfeitando o "layout" e explicando ao usuario como utilizar o programa
  printf("Bem vindo!\n Qual telefone voce deseja?\n");
  printf("1-%s\n 2-%s\n 3-%s\n 4-%s\n 5-%s\n",nome[0],nome[1],nome[2],nome[3],nome[4]);
  printf("Digite:\"-1\" para fechar\n");

//passo3: poderia ter feito com switch mas optei por DoWhile por ser algo simples
//usando "do" para iniciar o laço e inserir as condicoes com if

do{
  printf("R: ");
  scanf("%d",&x);
  if(x < -1 || x > 5){
    printf("\nOpcao invalida, Digite novamente: ");
    scanf("%d",&x);
  }
if(x == -1){
  printf("\nAte a proxima...\n");
  return 0;
}
x = x - 1;
  printf("Nome: %s \nTelefone: %d\n",nome[x],telefone[x]);
}while(1); //while infinito
*/

/*
  //  4
//passo1: declarando as variaves necessarias
char nome[11];
int tamanho,x;
//passo2: inserir o nome, e caso seja invalido repetir o processo
do{
  printf("Insira um nome com 5 ou mais caracteres: ");
  fgets(nome,11,stdin);
setbuf(stdin,NULL);
nome[strcspn(nome,"\n")]='\0';
tamanho = strlen(nome);
//printf("%d\n",tamanho); //teste
  if(tamanho < 5){
  printf("O nome nao possui 5 ou mais caracteres.\n");
}//if
  }while(tamanho < 5);

//passo3: exibir o nome, caso valido
printf("O nome %s possui 5 ou mais caracteres.\n",nome);
*/


    //  5
//passo1: variaveis necessarias
char frase[101];
int vogalA =0;
int vogalE =0;
int vogalI =0;
int vogalO =0;
int vogalU =0;
int len; //tamanho

//passo2: Inserir a frase
  printf("Insira uma frase famosa(sem acentuacao): ");
  fgets(frase,51,stdin);
  frase[strcspn(frase,"\n")]='\0';
  fflush(stdin);

//passo3: Criar a condicao para rodar toda a frase dentro do if
len = strlen(frase);
  for(int y=0;y < len;y++){

//passo4:condicao para cada uma das vogais
//Tornar a frase minuscula para para otimizar o codigo
      if(tolower(frase[y]) =='a'){
      vogalA++;
    }else{
      if(tolower(frase[y]) =='e'){
      vogalE++;
    }else{
      if(tolower(frase[y]) =='i'){
      vogalI++;
    }else{
      if(tolower(frase[y]) =='o'){
      vogalO++;
    }else{
      if(tolower(frase[y]) =='u'){
      vogalU++;
      }//elseA
      }//elseE
      }//elseI
      }//elseO
      }//elseU
    }//for
//passo5:Exibir os resultados.
printf("\nQuantas vezes \"A\" aparece:%d\n",vogalA);
printf("Quantas vezes \"E\" aparece:%d\n",vogalE);
printf("Quantas vezes \"I\" aparece:%d\n",vogalI);
printf("Quantas vezes \"O\" aparece:%d\n",vogalO);
printf("Quantas vezes \"U\" aparece:%d\n\n",vogalU);


/*
    //  6
//passo1:variaveis necessarias
char nome[11];
char sobrenome[11];
//passo2: "ler" e armazenar o nome
printf("Insira o seu nome: ");
fgets(nome,11,stdin);
nome[strcspn(nome,"\n")]='\0';
printf("Insira o seu sobrenome: ");
fgets(sobrenome,11,stdin);
sobrenome[strcspn(sobrenome,"\n")]='\0';
//passo3:usar o comando strcat para juntar as strings na ordem determinada
strcat(sobrenome,", ");
strcat(sobrenome,nome);
//passo4:exibir o nome completo
printf("Seu nome entao e:\n %s\n",sobrenome);
*/

/*
//passo1: Variaveis necessarias
char sigla[3];
char sul[3][21] = {"Parana","Santa Catarina","Rio Grande do Sul"};
char sudeste[4][21] ={"Rio de Janeiro","Sao Paulo","Minas Gerais","Espirito Santo"};
//passo2: Ler e armazenar as informacoes necessarias
printf("Insira a sigla de um dos estados brasileiros da regiao sul ou sudeste: ");
fgets(sigla,3,stdin);
sigla[strcspn(sigla,"\n")]='\0';
setbuf(stdin,NULL);
//passo3: condicoes para determinar que retorno o usuario tera.
if(strcasecmp(sigla,"pr")==0 || strcasecmp(sigla,"sc")==0 || strcasecmp(sigla,"rs")==0){
  printf("Regiao: Sul\n");
    if(strcasecmp(sigla,"pr")==0){
      printf("%s\n",sul[0]);
        }else{
          if(strcasecmp(sigla,"sc")==0){
            printf("%s\n",sul[1]);
              }else{
                printf("%s\n",sul[2]);//rio grande do sul
    }//else
  }//else
}else{
  if(strcasecmp(sigla,"rj")==0 || strcasecmp(sigla,"sp")==0 || strcasecmp(sigla,"mg")==0|| strcasecmp(sigla,"es")==0){
    printf("Regiao: Sudeste\n");
      if(strcasecmp(sigla,"rj")==0){
        printf("%s\n",sudeste[0]);
          }else{
            if(strcasecmp(sigla,"sp")==0){
              printf("%s\n",sudeste[1]);
                }else{
                  if(strcasecmp(sigla,"mg")==0){
                    printf("%s\n",sudeste[2]);
                      }else{
                        if(strcasecmp(sigla,"es")==0){
                          printf("%s\n",sudeste[3]);
        }//if
      }//else
    }//else
  }//ifregiaoSudeste
}else{
  printf("Sigla invalida\n");
  }//elseSiglainvalida
}//elseSudeste
*/

  return 0;
}//main
