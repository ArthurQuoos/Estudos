/*
Faça um programa que exiba um menu com duas opções:

a - IMC
b - Natação

Na opção a, o programa deve receber o peso (em kg) e a altura de uma pessoa (em metros),
 calcular e exibir o IMC - Índice de Massa Corporal da pessoa com uma casa decimal.
 Para isso, utilize a fórmula IMC = peso / (altura²) .
 Se o IMC for menor que 18,5 o programa deve exibir a mensagem "Abaixo do peso".
 Se o IMC for maior ou igual a 18,5 e menor que 25, o programa deve exibir "Peso Normal".
 Se o IMC for igual ou maior que 25, o programa deve exibir "Acima do Peso".
 Para isso, seu programa deve utilizar estruturas de seleção (IF)

Na segunda opção, elabore um programa que, dada a idade de um nadador,
classifique-o em uma das seguintes categorias:

    infantil A = 5 - 7 anos
    infantil B = 8 - 10 anos
    juvenil A = 11 - 13 anos
    juvenil B = 14 - 17 anos
    adulto = maiores de 17 anos
    o programa deverá informar "Idade sem categoria disponível"
    caso uma idade inferior a cinco anos seja digitada.
    Observações:

    Seu programa deve fazer a seleção da opção de entrada aceitando letras maiúsculas e minusculas
    e usando a estrutura de seleção adequada.
    Seu menu deve tratar o caso do usuário digitar uma opção inválida,
    retornando mensagem de erro.
    O menu deve ser exibido e executado apenas uma vez.
*/
/*
@file: ProvaExercicio1.c
@date: 20/07/2021
@author: Arthur Albert Schmaiske Quoos
@brief: menu de IMC e Natacao.
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
int opcao;
float peso, altura, auxiliar, imc;//variaveis de IMC
int idade;                       //variaveis de natacao
printf("MENU:\n");
printf("\t1 - Para calcular o IMC. \n");
printf("\t2 - Para verificar sua classificacao da natacao\n");
scanf("%d",&opcao);

  switch(opcao){
case 1:
  printf("Voce escolheu a opcao \"1\"\n");
  printf("Digite a sua altura (em metros): ");
  scanf("%f",&altura);
  printf("Agora seu peso(em kg): ");
  scanf("%f",&peso);
  auxiliar = altura * altura;
  imc = peso / auxiliar;
  printf("Seu IMC e: %.1f\n",imc);
if(imc < 18.5){
  printf("abaixo do peso\n");
}else{
  if(imc >= 18.5 && imc < 25){
    printf("Peso normal\n");
  }else{
    if(imc >= 25){
      printf("Acima do peso\n");
    }//if
  }//else2
}//else1
break;
case 2:
  printf("Voce escolheu a opcao \"2\"");
  printf("Quantos anos voce tem? ");
  scanf("%d",&idade);
  if(idade >= 5 && idade <= 7){
    printf("Voce faz parte da classificacao: Infantil A\n");
  }else{
    if(idade >=8 && idade <=10){
      printf("Voce faz parte da classificacao: Infantil B\n");
    }else{
      if(idade >=11 && idade <=13){
        printf("Voce faz parte da classificacao: Juvenil A\n");
      }else{
        if(idade >=14 && idade <=17){
          printf("Voce faz parte da classificacao: Juvenil B\n");
        }else{
          if(idade > 17)
          printf("Voce faz parte da classificacao: Adulto\n");
        }//else2.4
      }//else2.3
    }//else2.2
  }//else2.1
break;
default:
printf("ERROR BIBOP BIP ERROR\n");//para opcao invalida
break;
}//switch

  return 0;
}//main
