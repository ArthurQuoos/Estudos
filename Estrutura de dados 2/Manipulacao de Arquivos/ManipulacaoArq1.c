/*
1) Implemente um algoritmo em C, que faça a Leitura do arquivo 
chamado arqmos.txt , caractere por caractere.  
Após a leitura do arquivo, o  programa deve solicitar 
ao usuário para digitar uma palavra e após isso deve ser 
inserido no arquivo (caractere por caractere) essa palavra, 
usando a função fputc. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){  

  FILE *arq;
  char palavra[30];
  char c;

  //abre o arquivo
  arq = fopen("arqmos.txt","r+"); // rw = leitura e escrita
  if(arq == NULL){
    printf("Erro na abertura do arquivo\n");
    exit(1); //finaliza o programa
  }//if


  //Le enquanto nao chegar no fim do arquivo
  while((c = fgetc(arq)) != EOF){ //define o cursor para o final
    printf("%c",c);
  }//for
int opcao;

do{
  printf("\nDigite uma palavra para ser registrada no arquivo:\n");
  scanf("%s",palavra);
  while ((c = getchar()) != '\n' && c != EOF);//limpar buffer

  for(int i = 0;i<strlen(palavra);i++){ //Registrar letra por letra
    if(fputc(palavra[i],arq) != EOF){
      printf("Registrando letra: \"%c\"\n",palavra[i]);
    }else{
      printf("Erro ao registrar o caractere \"%c\"\n",palavra[i]);
      exit(1);
    }
  }
  fputc('\n',arq);
  printf("Quer registrar outra palavra? (1-sim/2-nao)\n"); //pergunta se quer continuar
  scanf("%d",&opcao);
  while ((c = getchar()) != '\n' && c != EOF);//limpar buffer
}while(opcao == 1);

rewind(arq); //voltando cursor para o comeco
printf("\nVerificando se gravou corretamente\n");
  while((c = fgetc(arq)) != EOF){ 
    printf("%c",c);
  }//for

printf("\nFechando...\n");
fclose(arq);//fecha o programa
  return 0;
}//main


