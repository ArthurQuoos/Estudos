/*
@file: ExerciciosFuncoesFD2.c
@date: 06/10/2021
@author: Arthur Albert Schmaiske Quoos
@brief:
*/
/*
Faça um algoritmo que implemente uma função que receba 3 números inteiros
e retorne o maior valor. Se algum número for negativo retorne -1;
*/

#include <stdio.h>
#include <stdlib.h>

/*
//passo1: declarando as variaveis globais que serao necessarias para todas as funcoes
int numeros[2];
int maior=0;

//passo2:declarando a funcao com a condicao para que o maior numero perdure
int funcao(){
  for(int x=0;x <3;x++){
      if(numeros[x] > maior){
      maior = numeros[x];
      }//if
    }//for
  return maior;
}
//passo3:funcao main com explicacoes para o usuario e ligando a funcao ao programa
int main(){

  printf("Insira 3 numeros inteiros: \n");
    for(int x=0;x <3;x++){
    scanf("%d",&numeros[x]);
  }//for

//passo4:Criar a condicao para caso o exista um numero negativo seja exibido -1
  for(int x=0;x <3;x++){
      if(numeros[x] < 0){

      return -1;
      }//if
  }//for para -1
  funcao();

  printf("Exibindo o maior numero: %d\n",maior);

  return 0;
}
*/

/*
================================================================================
Elabore uma função que receba por parâmetro o sexo (char) e a altura de uma pessoa (real),
calcule e retorne seu peso ideal. Para isso, utilize as fórmulas a seguir:

Para homens: (72.7*altura) - 58
Para mulheres: (62.1*altura) – 44.7
================================================================================
*/
/* //2
//passo1: Cabecalho com as funcoes e variaveis necessarias
float funcaopesoideal(char sexo);
float altura;
float pesoideal;

int main(){

printf("Para calcular seu peso ideal informe:\n");

//passo2: adquirir a altura da pessoa
printf("Sua altura: ");
  scanf("%f",&altura);
//chamando a funcao e definindo o parametro como exigido no enunciado
funcaopesoideal('f');
//exibindo o resultado (retorno da funcaopesoideal)
printf("Seu peso ideal: %.2f\n",pesoideal);

return 0;
}

//passo3: funcao para calcuar o peso ideal com switch para o caso de masc ou femin
float funcaopesoideal(char sexo){

  switch(sexo){
    case 'm':
    pesoideal = 72.7 * altura - 58;
    break;
    case 'f':
    pesoideal = altura * 62.1 - 44.7;
    break;
    default:
    printf("ERROR BIBOP ERROR\n");
  }
  return pesoideal;
}
*/

/*
================================================================================
Escreva um procedimento que recebe por parâmetro as 3 notas de um aluno e uma letra.
Se a letra for A, o procedimento calcula a média aritmética das notas do aluno,
se for P, a sua média ponderada (pesos: 5, 3 e 2) e se for S, a soma das notas.
O valor calculado também deve ser retornado e exibido na função main.
================================================================================
*/
/*
//passo1:Variaveis globais necessarias
char letra;
float x; //auxiliar

//passo2:funcao para calcular as notas com switch para cada tipo de media exigida
float calcular(float nota1, float nota2, float nota3){
  switch(letra){
    case 'A':
    x = nota1 + nota2 + nota3;
    x = x / 3;
    break;
    case 'P':
    x = (nota1 * 5)+(nota2 * 3)+(nota3*2);
    x = x / 6;
    break;
    case 'S':
    x = nota1 + nota2 + nota3;
    break;
    default:
    printf("ERROR BIBOP ERROR\n");
  }//switch
  return x;
}//calcular

//passo3:Main com explicacoes para o usuario e scanf para adquirir os valores
int main(){

printf("Que tipo de calculo de media devera ser executado: \n");
printf(" - A - Para calcular a media simples.\n");
printf(" - P - Para calcular a media ponderada.\n");
printf(" - S - Para soma as notas.\n");
scanf("%c",&letra);
letra = toupper(letra);//ate hoje nao entendo porque esse comando da um alerta

//passo4:Executar a funcao para os calculos
calcular(5.8,7.2,8.4);

//passo5: Exibir os resultados
switch(letra){
  case 'A':
  printf("A media simples do aluno e de: %.2f\n\n",x);
  break;
  case 'P':
  printf("A media ponderada do aluno e de: %.2f\n\n",x);
  break;
  case 'S':
  printf("A soma das notas do aluno e de: %.2f\n\n",x);
  break;
}//switch

return 0;
}//main
*/
/*
================================================================================
Faça uma função que receba a média final de um aluno por parâmetro
e retorne o seu conceito, conforme a tabela abaixo:

Nota Conceito
[ 9 - 10]  A
[ 7 – 9 [  B
[ 5 - 7 [  C
[ 0 – 5 [  D
================================================================================
*/
/*
char notaconceito; //para que o valor da nota retorne a main
//passo1:funcao que classificara a nota do aluno
char conceito(float nota){
  if(nota < 0 && nota <=4){
  notaconceito = 'D';
  }else{
    if(nota >=5 && nota <=6){
    notaconceito = 'C';

    }else{
      if(nota >=7 && nota <= 8){
      notaconceito = 'B';

      }else{
        if(nota >=9 ){  //estou deixando o if com uma condicao ampla para evitar valores invalidos.
        notaconceito = 'A';
        }//if
      }//else
    }//else
  }//else
  return notaconceito;
}//conceito
//passo2:Main. Para conectar a funcao ao programa e exibir o resultado.
int main(){

conceito(9.0);
printf("Nota Conceito: %c\n",notaconceito);

return 0;
}
*/

/*
================================================================================
Crie uma função que que receba o valor de um inteiro positivo N,
calcule e retorne o fatorial desse número.
================================================================================
*/

//passo1:Variaveis globais
int x;

//passo2:Criar a funcao para calcular o fatorial de x
int fatorial(){
  int y = x; //y = contador
  y -= 1;
  if(x == 0){ //fatorial de 0! = 1, e eu nao sei como fazer essa conta em C.
    x = 1;
    return x;
  }
  for(y;y>0;y--){
  x = x * y;

  }//for
  return x;
}//fatorial

//passo3:Main. para Receber os valores, conectar a "fatorial" ao codigo e exibir o resultado
int main(){
  int f;
  printf("Insira um numero para receber o fatorial: \n");
  scanf("%d",&f);
  x = f;
  fatorial();
  printf(" %d! = %d \n",f,x);

return 0;
}
