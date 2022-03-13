/*
1
Crie e exiba uma matriz identidade com dimensões 5 x 5;
==============================================================
2
Faça um algoritmo que leia uma matriz 3 por 3 (3x3)
e retorne a soma dos elementos da sua diagonal principal
e da sua diagonal secundária;
==============================================================
3
Construa um programa que leia uma matriz de tamanho 5 x 5
e escreva a localização
(linha, coluna) do maior valor encontrado na matriz
==============================================================
4
Faça um programa que multiplique por 5 a matriz A
(preenchida a partir do teclado) para gerar a matriz C.
==============================================================
5
Faça um programa que some as matrizes A e B, gerando a matriz C
==============================================================
6
Faça um programa que multiplique as matrizes A e D abaixo gerando matriz AD
==============================================================
*/
/*
@file: ExerciciosMatrizes.c
@date: 29/07/2021
@author: Arthur Albert Schmaiske Quoos
@brief: multiplicacao de matriz
*/
#include <stdio.h>
#include <stdlib.h>

int main(){

/*
// 1
//passo1:criar a matriz identidade
  int matriz[5][5] = {{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1}};
//passo2:usar for para exibir a matriz
  for(int l = 0;l<5;l++){
    for(int c = 0;c<5;c++){
      printf(" %d ",matriz[l][c]);
    }
    printf("\n");
  }
printf("\n");
*/

/*
// 2
//passo1:Criar a estrutura de codigo para "ler" a matriz
int matriz[3][3];
int soma1, soma2; //<--passo2
  printf("Insira os valores da matris 3x3: ");
  for(int l=0;l<3;l++){
    for(int c=0;c<3;c++){
      scanf("%d",&matriz[l][c]);
    }
  }
//passo2:somar as diagonais
soma1 = matriz[0][0] + matriz[1][1] + matriz [2][2];
soma2 = matriz[0][2] + matriz[1][1] + matriz [2][0];
//passo3:exibir o resultado
printf("A soma da diagonal principal e secundaria respectivamente: %d, %d\n",soma1,soma2);
*/

/*
// 3
int matriz[5][5];
int localL, localC;//para salvar o local do maior valor
int maior = 0;  //pedi ajuda do alexandre para resolver

//passo1:Criar a estrutura de codigo para "ler" a matriz
printf("Insira os valores da matriz 5x5: ");
for(int l=0;l<5;l++){
  for(int c=0;c<5;c++){
    scanf("%d",&matriz[l][c]);
  }
}
//passo2:Fazer um codigo para que todos os valores da matriz sejam revisados pelo "if"
for(int l=0;l<5;l++){
  for(int c=0;c<5;c++){
    if(matriz[l][c] > maior){
      maior = matriz[l][c];
      localL = l;
      localC = c;
    }//if
  }//forinterno
}//forexterno
//passo3:Exibir a localizacao do maior valor
printf("O maior valor da matriz esta localizado na linha \"%d\" e coluna \"%d\"",localL,localC);
printf("\n");
*/

/*
// 4
int l,c;

    //passo1:Gerar a matriz A
printf("Quantas linhas tera a matriz: ");
scanf("%d",&l);

printf("Quantas colunas tera a matriz: ");
scanf("%d",&c);
int matrizA[l][c];
int matrizB[l][c];

printf("Insira os valores da matriz: ");
for(int l2=0;l2<l;l2++){
  for(int c2=0;c2<c;c2++){
    scanf("%d",&matrizA[l2][c2]);
  }//forinterno
}//forexterno
    //passo2:Exibir a matrizA
printf("\nMatriz A\n");
for(int l2 = 0;l2 <l;l2++){
  for(int c2 = 0;c2<c;c2++){
    printf(" %d ",matrizA[l2][c2]);
  }//forinterno
  printf("\n");
}//forexterno
    //passo3:calcular e exibir a matrizB
printf("\nMatriz A * 5\n");
  for(int l2=0;l2<l;l2++){
    for(int c2=0;c2<c;c2++){
  matrizB[l2][c2] = matrizA[l2][c2] * 5;
  printf(" %d ",matrizB[l2][c2]);
  }//forinterno
printf("\n");
}//forexterno
*/


/*
// 5
int l,c;

    //passo1:Quantas linhas e colunas terao as matrizes
printf("Quantas linhas tera a matriz: ");
scanf("%d",&l);

printf("Quantas colunas tera a matriz: ");
scanf("%d",&c);
int matrizA[l][c];
int matrizB[l][c];
int matrizC[l][c];
    //passo2:Quais os valores da matriz A
printf("Insira os valores da matriz A: ");
for(int l2=0;l2<l;l2++){
  for(int c2=0;c2<c;c2++){
    scanf("%d",&matrizA[l2][c2]);
  }//forinterno
}//forexterno
    //passo3:Quais os valores da matriz B
printf("Insira os valores da matriz B: ");
for(int l2=0;l2<l;l2++){
  for(int c2=0;c2<c;c2++){
    scanf("%d",&matrizB[l2][c2]);
  }//forinterno
}//forexterno
    //passo4:Exibir a matriz A
printf("\nMatriz A\n");
for(int l2 = 0;l2 <l;l2++){
  for(int c2 = 0;c2<c;c2++){
    printf(" %d ",matrizA[l2][c2]);
  }//forinterno
  printf("\n");
}//forexterno
    //passo5:exibir a matriz B
printf("\nMatriz B\n");
for(int l2 = 0;l2 <l;l2++){
  for(int c2 = 0;c2<c;c2++){
    printf(" %d ",matrizB[l2][c2]);
  }//forinterno
  printf("\n");
}//forexterno
    //passo6:calcular e exibir a matriz C
printf("\nMatriz C = A+B\n");
  for(int l2=0;l2<l;l2++){
    for(int c2=0;c2<c;c2++){
  matrizC[l2][c2] = matrizA[l2][c2] + matrizB[l2][c2];
  printf(" %d ",matrizC[l2][c2]);
  }//forinterno
printf("\n");
}//forexterno
*/

// 6
int l,c;

    //passo1:Quantas linhas e colunas terao as matrizes
printf("Quantas linhas tera a matriz: ");
scanf("%d",&l);

printf("Quantas colunas tera a matriz: ");
scanf("%d",&c);

int matrizA[l][c];
int matrizB[l][c];
int matrizAB[l][c];

    //passo2:Quais os valores da matriz A
printf("Insira os valores da matriz A: ");
  for(int l2=0;l2<l;l2++){
    for(int c2=0;c2<c;c2++){
      scanf("%d",&matrizA[l2][c2]);
    }//forinterno
  }//forexterno

    //passo3:Quais os valores da matriz B
printf("Insira os valores da matriz B: ");
  for(int l2=0;l2<l;l2++){
    for(int c2=0;c2<c;c2++){
      scanf("%d",&matrizB[l2][c2]);
    }//forinterno
  }//forexterno

    //passo4:Exibir a matriz A
printf("\nMatriz A\n");
  for(int l2 = 0;l2 <l;l2++){
    for(int c2 = 0;c2<c;c2++){
      printf(" %d ",matrizA[l2][c2]);
      }//forinterno
    printf("\n");
  }//forexterno

    //passo5:exibir a matriz B
printf("\nMatriz B\n");
  for(int l2 = 0;l2 <l;l2++){
    for(int c2 = 0;c2<c;c2++){
      printf(" %d ",matrizB[l2][c2]);
      }//forinterno
    printf("\n");
  }//forexterno

    //passo6: Calcular a matrizAB e exibir
  printf("\nMatriz AB\n");
  for(int l2=0;l2 <l;l2++){
    for(int c2=0,l3=0;c2<c,l3<l;c2++,l3++){
      matrizAB[l2][c2]= matrizA[l2][c2] * matrizB[l3][l2];
      printf(" %d ",matrizAB[l2][c2]);
    }
    printf("\n");
  }
  return 0;
}
