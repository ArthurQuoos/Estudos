#include <stdio.h>

void selectionSort(int *v, int n) {
 int i, j, min, aux, contador;
 for(i = 0; i < n-1; i++) {
 min = i;
 for(j = i+1; j < n; j++) {
 if(v[j] < v[min]) {

 aux = v[min];
 v[min] = v[j];
 v[j] = aux;
 contador++;
      }
    }
  }
  printf("Numero de trocas: %d\n",contador);
}

//Algoritmo otimizado primeiro encontra o "verdadeiro" menor valor para depois 
//trocar, reduzindo drasticamente o número de atribuições

void selectionSortOtimizado(int *v, int n){
    int i, j, min, aux, contador;
    contador = 0;
    for(i = 0; i < n-1; i++) {
        min = i;
        for(j = i+1; j < n; j++){
            if(v[j] < v[min]){
                min = j; //marca apenas o indice do menor
            }
        }
        if(min != i){
            aux = v[i];
            v[i] = v[min];
            v[min] = aux;
            contador++;
        }
    }
    printf("\nNumero de trocas: %d\n",contador);
}

int main()
{
    int vetor[] = {6, 5, 4, 3, 2};
    int vetor2[] = { 4, 2, 5, 6, 3};
    selectionSort(vetor, 5);
    for(int x=0; x < 5;x++){
        printf("%d, ",vetor[x]);
    }
    printf("\nAlgoritmo otimizado: ");
        selectionSortOtimizado(vetor2, 5);
    for(int x=0; x < 5;x++){
        printf("%d, ",vetor[x]);
    }
    return 0;
}