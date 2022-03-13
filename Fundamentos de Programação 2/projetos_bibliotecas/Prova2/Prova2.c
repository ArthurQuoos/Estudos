/*
@file: Prova2.c
@date: 08/12/2021
@author: Arthur Albert Schmaiske Quoos
@brief:
*/
/*
================================================================================
Para isso, a central da Amazon está recebendo as notificações de falhas ao
redor do mundo. Você devera implementar um sistema para salvar e processar essas
notificações. Para isso:

a) (5 pontos) Aloque dinamicamente um vetor de Notificações de tamanho 5.
Cada Notificação contém:

Pais (string tam: 20):
Cidade(string tam: 20):
Quantidade de Servidores UP - ativos (inteiro)
Quantidade de Servidores Down - com problemas (inteiro)

Os países possíveis são: Brasil, EUA, Franca, Londres, China e Japao (sem acentos)
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

  int main(){
    //A
    //Alocando espaco para os vetores requisitados
char **pais = (char**) malloc(5 * sizeof(char));
  for (size_t i = 0; i < 5; i++) {
    pais[i] = (char*) malloc(20 * sizeof(char));
  }
  char **cidade = (char**) malloc(5 * sizeof(char));
    for (size_t i = 0; i < 5; i++) {
      cidade[i] = (char*) malloc(20 * sizeof(char));
    }
int *servUP = (int*) malloc(5 * sizeof(int));
int *servDOWN = (int*) malloc(5 * sizeof(int));

/*
================================================================================
b) (10 pontos) Receba os dados de diversos relatórios de falhas e vá armazenando
neste vetor. A cada vez que o tamanho do vetor se tornar insuficiente, realoque
seu tamanho aumentando o vetor em 5 unidades. Ao receber o valor "fim"
como entrada de um pais, o sistema de entradas deverá parar e o vetor tamanho do
vetor ajustado ao tamanho exato da quantidade de relatórios.
================================================================================
*/
  //B
int x = 0;
int y = 5;
//Preencher os dados
do{
 for (x ; x < y; x++) {
     printf("De qual pais este relatorio esta vindo?(fim para quebrar o loop)\n");
     setbuf(stdin,NULL);
     fgets(pais[x],20,stdin);
     pais[x][strcspn(pais[x],"\n")]='\0';
     if (strcasecmp(pais[x],"fim")==0){ //verificar para quebrar o laco for
     printf("Quebrando o loop\n");
     break;
     }
     printf("De qual Cidade?\n");
     setbuf(stdin,NULL);
     fgets(cidade[x],20,stdin);
     cidade[x][strcspn(cidade[x],"\n")]='\0';
     printf("Quantos servidores estao UP?\n");
     setbuf(stdin,NULL);
     scanf("%d",&servUP[x]);
     printf("Quantos servidores estao DOWN?\n");
     setbuf(stdin,NULL);
     scanf("%d",&servDOWN[x]);
   }
   if (strcasecmp(pais[x],"fim")!=0){ //realocar para aumentar o limite
      y += 5;
      pais = (char**) realloc(pais, y * sizeof(char));
        for (size_t i = 0; i < y; i++) {
            pais[i] = (char*) realloc(pais[i], 20 * sizeof(char));
          }
            cidade = (char**) realloc(cidade, y * sizeof(char));
        for (size_t i = 5; i < y; i++) {
            cidade[i] = (char*) realloc(cidade[i], 20 * sizeof(char));
          }
          servUP = (int*) realloc(servUP, y * sizeof(int));
          servDOWN = (int*) realloc(servDOWN, y * sizeof(int));
      }
}while(strcasecmp(pais[x],"fim")!=0);
x = x - 1; //prevenir do fim

//realocar para a quantidade exata
  pais = (char**) realloc(pais, x * sizeof(char));
  for (size_t i = 0; i < x; i++) {
    pais[i] = (char*) realloc(pais[i], 20 * sizeof(char));
  }
  cidade = (char**) realloc(cidade, x * sizeof(char));
  for (size_t i = 0; i < x; i++) {
    cidade[i] = (char*) realloc(cidade[i], 20 * sizeof(char));
  }
  servUP = (int*) realloc(servUP, x * sizeof(int));
  servDOWN = (int*) realloc(servDOWN, x * sizeof(int));

/*
================================================================================
c) (5 pontos) Salve os dados em um aquivo BINÁRIO chamado "notifications.dat".
Feche o arquivo e libere a memória utilizada pelo vetor;
================================================================================
*/
//abrir e criar o arquivo
FILE *arq = fopen("notifications.dat","wb");
//escrevendo as informacoes no arquivo
for (size_t i = 0; i < x; i++) { //escrevendo no arquivo binario
    fwrite(pais[i],sizeof(char),20,arq);
    fwrite(cidade[i],sizeof(char),20,arq);
    fwrite(&servUP[i],sizeof(int),1,arq);
    fwrite(&servDOWN[i],sizeof(int),1,arq);
  }
  //Liberando o espaco
for (size_t i = 0; i < x; i++) {
    free(pais[i]);
  }
    free(pais);
for (size_t i = 0; i < x; i++) {
    free(cidade[i]);
  }
    free(cidade);

free(servUP);
free(servDOWN);
fclose(arq);
/*
================================================================================
d) (5 pontos) Abra o arquivo gerado anteriormente, carregue os dados em um novo
vetor de Relatórios alocado dinamicamente. E exiba os dados em uma tabela na tela.
================================================================================
*/
//abrir para ler o arquivo binario
fopen("notifications.dat","rb");
//alocando o espaco para as novas variaveis
char **Rpaises = (char**) malloc(x * sizeof(char));
      for (size_t i = 0; i < x; i++) {
          Rpaises[i] = (char*) malloc(20 * sizeof(char));
        }
char **Rcidades = (char**) malloc(x * sizeof(char));
      for (size_t i = 0; i < x; i++) {
          Rcidades[i] = (char*) malloc(20 * sizeof(char));
        }
int *RservUP = (int*) malloc(x * sizeof(int));
int *RservDOWN = (int*) malloc(x * sizeof(int));
//adquirindo as informacoes para as variaveis
for (size_t i = 0; i < x; i++) {
  fread(Rpaises[i],sizeof(char),20,arq);
  fread(Rcidades[i],sizeof(char),20,arq);
  fread(&RservUP[i],sizeof(int),1,arq);
  fread(&RservDOWN[i],sizeof(int),1,arq);
}

fclose(arq);
//printar a tabela na tela
printf("Tabela inicial\n");
printf("Paises \t Cidades \t UP \t DOWN\n");
for (size_t i = 0; i < x; i++) {
    printf("%.-20s |%.-20s |%.2d |%.2d |\n",Rpaises[i],Rcidades[i],RservUP[i],RservDOWN[i]);
}

/*
================================================================================
e) (5 pontos) Calcule o total de servidores ativos, com problemas e o percentual
de servidores com problemas em cada país. Exiba os dados na tela e gere um
arquivo MODO TEXTO chamado "report.txt" no seguinte formato:

PAIS       |UP   |DOWN | RATE|
Brasil     |   80|   30|  25%|
EUA        |  200|   50|  20%|
França     |   80|    5|   6%|
Inglaterra |  100|    0|   0%|
China      |  117|    3|   3%|
Japão      |   45|    0|   0%|
================================================================================
*/
//criar a nova variavel para a tabela
float *rate = (float*) malloc(x * sizeof(float));
//calculando a taxa
for (size_t i = 0; i < x; i++) {
  RservUP[i] = (float)RservUP[i] / 100;
  rate[i] = RservUP[i] * RservDOWN[i];
}
arq = fopen("report.txt","w");
//escrevendo no arquivo e exibindo na tela
printf("\nTabela Final\n");
fprintf(arq,"\nTabela Final\n");
printf("PAIS \t| UP | DOWN | RATE |\n");
fprintf(arq,"PAIS \t| UP | DOWN | RATE |\n");
for (size_t i = 0; i < x; i++) {
  printf("%-20s | %.2d | %.2d | %.2f |\n",Rpaises[i],RservUP[i],RservDOWN[i],rate[i]);
  fprintf(arq,"%-20s | %.2d | %.2d | %.2f |\n",Rpaises[i],RservUP[i],RservDOWN[i],rate[i]);
}

fclose(arq);
//Liberando o espaco
for (size_t i = 0; i < x; i++) {
    free(Rpaises[i]);
  }
    free(Rpaises);
for (size_t i = 0; i < x; i++) {
    free(Rcidades[i]);
  }
    free(Rcidades);
free(RservUP);
free(RservDOWN);
free(rate);

return 0;
}//main
