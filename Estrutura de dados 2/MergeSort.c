#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//1 
void mergeSort(int *v, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        mergeSort(v,inicio,meio);
        mergeSort(v,meio+1,fim);
        merge(v,inicio,meio,fim);
    }
}


void merge(int *v, int inicio, int meio, int fim) {
    int *temp, p1, p2, tamanho, i , j , k;
    int fim1 = 0, fim2 = 0;

    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;

    temp = (int *) malloc(tamanho * sizeof(int));
    if (temp != NULL) {
        for (i = 0; i < tamanho; i++) {
            if (!fim1 && !fim2) {
                if (v[p1] < v[p2]) {
                    temp[i] = v[p1++];
                } else {
                    temp[i] = v[p2++];
                }
                if (p1 > meio) fim1 = 1;
                if (p2 > fim) fim2 = 1;
            } else {
                if (!fim1) {
                    temp[i] = v[p1++];
                } else {
                    temp[i] = v[p2++];
                }
            }
        }

        // Copiando de volta para o vetor original
        for (j = 0, k = inicio; j < tamanho; j++, k++) {
            v[k] = temp[j];
        }
    }

    free(temp);
}

void mergeSortDecrescente(int *v, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        mergeSort(v,inicio,meio);
        mergeSort(v,meio+1,fim);
        merge(v,inicio,meio,fim);
    }
}

//2
void mergeDecrescente(int *v, int inicio, int meio, int fim) {
    int *temp, p1, p2, tamanho, i , j , k;
    int fim1 = 0, fim2 = 0;

    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;

    temp = (int *) malloc(tamanho * sizeof(int));
    if (temp != NULL) {
        for (i = 0; i < tamanho; i++) {
            if (!fim1 && !fim2) {
                if (v[p1] > v[p2]) { // aqui é feita a comparaçao
                    temp[i] = v[p1++];
                } else {
                    temp[i] = v[p2++];
                }
                if (p1 > meio) fim1 = 1;
                if (p2 > fim) fim2 = 1;
            } else {
                if (!fim1) {
                    temp[i] = v[p1++];
                } else {
                    temp[i] = v[p2++];
                }
            }
        }

        // Copiando de volta para o vetor original
        for (j = 0, k = inicio; j < tamanho; j++, k++) {
            v[k] = temp[j];
        }
    }
    free(temp);
}

/*
int main()
{
    int v[] = {23, 4, 67, -8, 90, 54, 21};
    //Para descobrir o tamanho do vetor declarado na mesma funcao
    int n = sizeof(v) / sizeof(v[0]); 
    mergeSort(v,0, n - 1);
    mergeSortDecrescente(v,0, n - 1);
    for(int i = 0; i < n; i++){
        printf("%d ",v[i]);
    }
    printf("\n");
    return 0;
}
*/
//3


int main()
{
    srand(time(NULL));
    int x[100];
    for(int i = 0; i < 100; i++){ //criando vetor com 100 numeros
        x[i] = rand() % 100;
        printf("%d ",x[i]);
    }

    clock_t start = clock();  //variavel start para marcar o inicio do tempo
    mergeSort(x,0, 99);
    clock_t end = clock(); //variavel end para marcar o inicio do tempo
    printf("\nTempo de ordenacao: %lf segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    for(int i = 0; i < 99; i++){ //imprimindo vetor com 100 numeros ja ordenados
        printf("%d ",x[i]);
    }
    printf("\n");
    return 0;
}