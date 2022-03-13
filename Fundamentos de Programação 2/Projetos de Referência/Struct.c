#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
struct Aluno{
  char nome[50];
  int idade;
  float peso;
  float altura;
};//struct
*/

/*
struct alunos{
  char nome[50];
  int idade;
  float peso;
  float altura;
};//struct
*/
typedef struct{
  char nome[50];
  int idade;
  float peso;
  float altura;
}alunos;//struct

int main(){

/*
  struct Aluno aluno1 = {"Fulano",15,75.2,1.71};
  //strcpy(aluno1.nome,"Fulano");

printf("Nome: %s\n",aluno1.nome);
printf("Idade: %d\n",aluno1.idade);
printf("Peso: %.2f\n",aluno1.peso);
printf("Altura: %.2f\n",aluno1.altura);
*/


  alunos alunos[3];

for (size_t i = 0; i < 3; i++) {
printf("Digite o nome;");
fgets(alunos[i].nome,21,stdin);
alunos[i].nome[strcspn(alunos[i].nome,"\n")]='\0';
setbuf(stdin,NULL);

printf("Digite a idade:");
scanf("%d",&alunos[i].idade);

printf("Digite o peso:");
scanf("%f",&alunos[i].peso);

printf("Digite a altura:");
scanf("%f",&alunos[i].altura);
setbuf(stdin,NULL);

}//for

for (size_t i = 0; i < 3; i++) {
  printf("Nome: %s\n",alunos[i].nome);
  printf("Idade: %d\n",alunos[i].idade);
  printf("Peso: %.2f\n",alunos[i].peso);
  printf("Altura:%.2f\n",alunos[i].altura);
}//for


  return 0;
}
