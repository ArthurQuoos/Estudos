#include "inverteString.h"

char* inverteString(char msg[101]){
int tamanho;
int aux = 0;
    tamanho = strlen(msg);
int copiaTamanho = tamanho;

  char *invertida = (char*) malloc(tamanho * sizeof(char));

  for (tamanho;tamanho >= 0;tamanho--) {
      invertida[aux] = msg[tamanho-1];
      aux++;
      }

      invertida[copiaTamanho] = '\0';

  return invertida;
}
