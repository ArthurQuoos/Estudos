/*
@file: IfelseNota.c
@date: 06/07/2021
@author: Arthur Albert Schmaiske Quoos
@brief: Aula 06 exercício 01
*/
/*
Faça um programa que receba como entrada a nota de
um aluno. O programa deve exibir “aprovado” caso a nota
seja igual ou superior a 6, ou exibir “reprovado” caso
contrário.
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
  float nota;
setlocale(LC_ALL,"Portuguese");
  printf("Nota do aluno Pedrinho: ",nota);
  scanf("%f", &nota);

  if(nota >=5,8){//O professor é bomzinho, ele arrendonda a nota
    printf("Pedrinho: Aprovado\n");
  }else{
    if(nota <=5,7){
      printf("Pedrinho: Reprovado\n");

    }
  }
return 0;
}
