/*
1) Crie um algoritmo que imprima uma tabela de conversão de polegadas para
centímetros. Deseja-se que na tabela conste valores de 1 polegada até 20 polegadas
inteiras. (Para isso considere: 1 polegada = 2,54 cm)
Exemplo de saída:
1” equivale a 2,54 cm
2” equivalem a 5,08 cm
3” equivalem a 7,62 cm
================================================================================
2
Crie um programa que receba um número positivo Z e imprima todos os números de Z
até 1 e no final exiba quais são os números múltiplos de 4, quantos números são
múltiplos de 3 e a média dos números múltiplos de 5.
================================================================================
3
Faça um programa que solicite o tamanho de um quadrado e mostre a borda de um
quadrado utilizando o caracter #.
================================================================================
4
Faça um programa que leia e armazene um vetor (VetorA) de inteiros e tamanho 10.
Crie um VetorB, de mesmo tamanho, gerado a partir do Vetor A invertido (de trás para frente).
Em seguida, calcule o VetorC que deverá ser o resultado do VetorA multiplicado
pelo escalar 3 e em seguida subtraído do Vetor B.
================================================================================
5
 Faça um programa que receba 10 números inteiros. Em seguida o programa deverá
 permitir o usuário buscar números dentro do vetor,
 informando se o mesmo está ou não no vetor.
 O usuário poderá realizar quantas buscas quiser e finalizar ao solicitar a
  busca de um valor negativo.
================================================================================
6
Faça um programa que leia e armazene as notas (valores reais) de 10 alunos.
O programa somente deverá aceitar notas entre 0 e 10 (inclusive),
solicitando uma nova digitação quando uma nota inválida for digitada.
Após a leitura o programa deve:
a) Contar e exibir quantos alunos foram reprovados (nota < 6.0);
b) Exibir as notas dos alunos que foram aprovados (nota >= 6.0);
c) Calcular e exibir a média geral de todas as notas;
d) Calcular e exibir a porcentagem de alunos aprovados;
e) Exibir a nota mais alta e a mais baixa.
*/
/*
@file: ****.c
@date: ***
@author: Arthur Albert Schmaiske Quoos
@brief: ***
*/

#include <stdio.h>
#include <stdlib.h>

/*  //exercicio 1
//passo1:nao sera necessario nenhuma funcao
int main(){
//passo2:varaiveis necessarias
int pol;
float cm;
printf("Tabela de conversao de polegadas para centimetros!. \n");

// * passo3:sera feito um laco de repeticao que ira calcular os cm enquanto exibe
// * a tabela

for(pol=1;pol<=20;pol++){
  cm =(float)pol * 2.54;
  printf("- %2d polegada(s) equivale(m) a %5.2f cm -\n",pol,cm);
}
*/

/*   //execicio 2
int main(){
  int z;
  int y=0; //contador de 3
  float media=0;
  int contmedia=0;
printf("Insira um numero: ");
scanf("%d",&z);

  for(int x=z;x>0;x--){
    printf("%d ",x);
  }
printf("\n");
printf("\nMultiplos de 4:\n");
for(int x=z;x>0;x--){
    if(x % 4 ==0){
      printf("%d\n",x);
    }
}
printf("\n");
printf("Quantos multiplos de 3 existem: ");
for(int x=z;x>0;x--){
    if(x % 3 ==0){
      y++;
    }
}
printf("%d\n",y);

printf("\n");
printf("Media dos numeros multiplos de 5: ");
for(int x=z;x>0;x--){
  if(x % 5 ==0){
    media +=x;
    contmedia++;
  }
}
media = media / contmedia;
printf("%.2f\n",media);
*/

  // exercicio 3 quadrado com espaco vazio
int main(){

  int tam;
printf("Qual o tamanho do quadrado? \n");
scanf("%d",&tam);

  for(int x=tam;x>0;x--){
    printf("#");
  }
printf("\n");

  for(int x=tam-2;x>0;x--){
    printf("#");
    for(int y=tam-2;y>0;y--){
      printf(" ");
    }
    printf("#\n");
  }
  for(int x=tam;x>0;x--){
    printf("#");
  }
printf("\n");
printf("bogos binted\n");


/*  //4
//passo1:Varaiveis globais
int vetorA[10];
int vetorB[10];
int vetorC[10];
int x; //para criar o vetorB
//passo2: programa que leia e armazene um vetor (VetorA) de inteiros e tamanho 10
  void criarvetorA(){
    printf("Insira os 10 valores do vetorA:\n");
    for(x=0;x<10;x++){
      scanf("%d",&vetorA[x]);
    }
  return;
}
//passo3: criar o vetorB a partir do vetorA invertido
  void criarvetorB(){
    for(int y=0;y<10;y++){
      x--;
      vetorB[y] = vetorA[x];
    }
  return;
}
//passo4: criar o vetor C a partir do vetorA * 3 - vetorB
  void criarvetorC(){
    for(int z=0;z<10;z++){
      vetorC[z] = vetorA[z] * 3 - vetorB[z];
    }
  return;
}
//passo:conectar as funcoes.
  int main(){
    criarvetorA();
    criarvetorB();
    criarvetorC();

//passo: Exbir os vetores, hora da verdade.
    printf("\n");
    for(int x=0;x<10;x++){
      printf("VetorA[%d] = %2d \n",x,vetorA[x]);
    }
    printf("\n\n");

    for(int x=0;x<10;x++){
      printf("VetorB[%d] = %2d \n",x,vetorB[x]);
    }
    printf("\n\n");
    for(int x=0;x<10;x++){
      printf("VetorC[%d] = %2d \n",x,vetorC[x]);
    }
    printf("\n");
*/

/*   //5
//passo1:Declarar variaveis (locais)
int main(){
  int lista[10]={1,2,3,4,5,6,7,8,9,10};
  int x;

//passo2: Criar o programa para receber o valor do usario.
  printf("Insira um numero: \n");
  scanf("%d",&x);

//passo3: criar o programa para que todas passem pelo if lista == x
//porem apenas aparecer printf quando o valor estiver na lista
for(int y=0;y<10;y++){
  if(x == lista[y]){
    printf("O Valor esta dentro da lista.\n");
      return 0;
  }//if
}//for
printf("O Valor NAO esta dentro da lista.\n");
*/


/*
   // 6
//passo1:variaveis necessarias (globais)
float notas[10];
float media=0;
int Aprovados=0;
//passo2: funcao para ler e armazenar
void receber(){
printf("Insira as notas dos alunos: \n");
  for(int x=0;x<10;x++){
    printf("aluno %d: ",x+1);
    scanf("%f",&notas[x]);
    setbuf(stdin,NULL);
    while(notas[x]  < 0 ||notas[x] > 10){
      printf("Valor invalido, insira novamente: \n");
      scanf("%f",&notas[x]);
      setbuf(stdin,NULL);

  }//while
}//for
  return;
}//receber

//passo3:Contar alunos reprovados
void reprovados(){
  int contrpro=0;
  printf("\n\nNumero de alunos reprovados: \n");
  for(int x=0;x<10;x++){
  if(notas[x] < 6){
    contrpro++;
    //printf("reprovados teste = %d",contrpro);
  }//if
}//for
printf("\n""%d"" aluno(s).\n",contrpro);
  return;
}

//passo4: Exibir as notas dos alunos aprovados
//aproveitar este codigo para contar quanto alunos foram aprovados ira ajudar
//nos passos seguintes
int aprovados(){

  printf("\n");
  printf("Alunos Aprovados: \n\n");
  for(int x=0;x<10;x++){
  if(notas[x] >= 6){
    Aprovados++;
    printf("Aluno: %d nota:%.1f \n",x+1,notas[x]);
    }
  }
return Aprovados;
}

//passo5: Calcular e exibir a media geral de todas as notas
void mediageral(){
  for(int x=0;x<10;x++){
  media += notas[x];
  }//for
media = media / 10;
printf("\nMedia Geral das notas: %.2f \n",media);

return;
}//media

//passo6:Calcular e exibir a porcentagem de alunos aprovados
void porcentagem(){
float porcaprov;
porcaprov = Aprovados * 10;
printf("\nA porcentagem de alunos aprovados: %.2f%%.\n",porcaprov);
  return;
}

//passo7:Exibir a nota mais alta e a mais baixa.
void extremos(){
float alto=0;
float baixo=10;
  for(int x=0;x<10;x++){
    if(notas[x] > alto){
      alto = notas[x];
    }
    if(notas[x] < baixo){
      baixo = notas[x];
    }
  }
  printf("\nA nota mais alta: %.1f\n",alto);
  printf("A nota mais baixa: %.1f\n\n",baixo);
  return;
}

//passo8:Criar a main() para conectar todas as funcoes ao programa
int main(){
  receber();
  reprovados();
  aprovados();
  mediageral();
  porcentagem();
  extremos();
*/

/*

*/

  return 0;
}
