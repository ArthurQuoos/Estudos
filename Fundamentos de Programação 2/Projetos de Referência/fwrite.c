#include <stdio.h>
#include <stdlib.h>


int main(){  //criando o arquivo binario

  char str[20]="Ola arquivo";
  float numero = 5.23;
  int vetor[5] = {10, 20 ,30 ,40 ,50};

  FILE *arq = fopen("arquivo.bin","wb");

  fwrite(str,sizeof(char),20,arq);
  fwrite(&numero,sizeof(float),1,arq);
  fwrite(vetor,sizeof(int),5,arq);

  fclose(arq);

  return 0;
}
*/


int main(){

  char str[20];
  float numero;
  int vetor[5];

  FILE *arq = fopen("arquivo.bin","rb"); //Abre o arquivo leitura binaria
  fread(str,sizeof(char),20,arq); // Le 20 caracteres
  fread(&numero,sizeof(float),1,arq); // Le um numero real
  fread(vetor,sizeof(int),5,arq); // Le um vetor de inteiros de tamanho 5
  //Exibe os dados lidos
  printf("Texto: %s\n",str);
  printf("Float: %.2f\n",numero);
  for (size_t i = 0; i < 5; i++) {
    printf("%d ",vetor[i]);
  }//for
printf("\n");

fclose(arq); //fecha o programa

  return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>

int main(){

  FILE *arq;
  arq = fopen("arquivo.txt","w");

  char texto[20] = "Apucarana";
  float real = 5.26;
  int inteiro = 256;

  fprintf(arq,"Texto: %s\n",texto);
  fprintf(arq,"Real: %f\n",real);
  fprintf(arq,"Inteiro: %i\n",inteiro);

  fclose(arq);


  return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

  FILE *arq;
  arq = fopen("arquivo.txt","r"); //Abre o arquivo

  char texto[20], str[20];
  float real;
  int inteiro;
  //Leitura usando fscanf
  fscanf(arq,"%s %s\n",texto, str);
  fscanf(arq,"%s %f\n",texto, &real);
  fscanf(arq,"%s %i\n",texto, &inteiro);
  //Exibindo dados lidos
  printf("Texto: %s\n",str);
  printf("Float: %f\n",real);
  printf("Inteiro: %i\n",inteiro);
}
