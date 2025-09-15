#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

void swap(int *a, int *b) {
int tmp = *a;
*a = *b;
*b = tmp;
}

void bubbleSort(int *v, int n,int x) {
 clock_t start = clock();  //variavel start para marcar o inicio do tempo
 bool changed = true;
 int contadorAlteracoes = 0;
 if(x == 0){
 while(changed) {
    changed = false;
    for(int i = 0; i < n-1; i++) {
        if(v[i] > v[i+1]) {
        swap(&v[i], &v[i+1]);
        changed = true;
        contadorAlteracoes++;
             }
         }
    }
    printf("Vetor ordenado em ordem ascendente (bubbleSort):\n");
    for(int i = 0; i < n; i++){
        printf("%d ",v[i]);
    }
    printf("\nNumero de trocas: %d\n",contadorAlteracoes);
    }else if(x == 1){
         while(changed) {
    changed = false;
    for(int i = 0; i < n-1; i++) {
        if(v[i] < v[i+1]) {
        swap(&v[i], &v[i+1]);
        changed = true;
        contadorAlteracoes++;
             }
         }
    }
        printf("Vetor ordenado em ordem decrescente (bubbleSort):\n");
    for(int i = 0; i < n; i++){
        printf("%d ",v[i]);
    }
    printf("\nNumero de trocas: %d\n",contadorAlteracoes);
    }
    clock_t end = clock(); //variavel end para marcar o inicio do tempo
    printf("\nTempo de ordenacao: %lf segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);
 }

void insertionSort(int *v, int n,int x) {
 clock_t start = clock();  //variavel start para marcar o inicio do tempo
 int i, j, chosen;
 int contador = 0;
 for(i = 1; i < n; i++) {
 chosen = v[i];
 j = i-1;
 //procurar os valores que podem trocar uma posição para a frente
  while (j >= 0 && ((x == 0 && chosen < v[j]) || (x != 0 && chosen > v[j]))) {
 v[j+1] = v[j];
 j = j-1;
 contador++;
 }
 // move o elemento para novo lugar
 v[j+1] = chosen;
 
 } 
    printf("Vetor ordenado (insertionSort): ");
    for(int i = 0; i < n; i++){
        printf("%d ",v[i]);
    }
 printf("\nNumero de trocas: %d.\n",contador);
     clock_t end = clock(); //variavel end para marcar o inicio do tempo
    printf("\nTempo de ordenacao: %lf segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);
}

// Merge com contador
void merge(int *v, int inicio, int meio, int fim, int x, long long *contador) {
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;

    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;

    temp = (int *) malloc(tamanho * sizeof(int));
    if (temp != NULL) {
        for (i = 0; i < tamanho; i++) {
            if (!fim1 && !fim2) {
                if ((x == 0 && v[p1] < v[p2]) || (x != 0 && v[p1] > v[p2])) {
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
            (*contador)++;
        }

        for (j = 0, k = inicio; j < tamanho; j++, k++) {
            v[k] = temp[j];
            (*contador)++;
        }
    }

    free(temp);
}

// MergeSort recursivo com contador
void mergeSort(int *v, int inicio, int fim, int x, long long *contador) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(v, inicio, meio, x, contador);
        mergeSort(v, meio + 1, fim, x, contador);
        merge(v, inicio, meio, fim, x, contador);
    }
}

void criaHeap(int *v, int inicio, int fim, int x,int *contador){
    int aux = v[inicio];
    int filho = 2*inicio + 1;

    if(x==1){ // 1 para decrescente (min-heap)
        while(filho <= fim){
            if(filho < fim){
                if(v[filho] > v[filho + 1]){ // menor filho
                    filho = filho + 1;
                }
            }
            if(aux > v[filho]){ // min-heap: pai maior que filho
                v[inicio] = v[filho];
                inicio = filho;
                filho = 2*inicio + 1;
                (*contador)++;
            }else{
                break;
            }
        }
        v[inicio] = aux;
        (*contador)++;
    }else if(x==0){ // 0 para crescente (max-heap)
        while(filho <= fim){
            if(filho < fim){
                if(v[filho] < v[filho + 1]){ // maior filho
                    filho = filho + 1;
                }
            }
            if(aux < v[filho]){ // max-heap: pai menor que filho
                v[inicio] = v[filho];
                inicio = filho;
                filho = 2*inicio + 1;
                (*contador)++;
            }else{
                break;
            }
        }
        v[inicio] = aux;
        (*contador)++;
    }
}

void heapSort(int *v, int n,int x){
    int contador=0;
    clock_t start = clock();  //variavel start para marcar o inicio do tempo
    int i, aux;
    for(i = (n-1)/2; i >= 0; i--){
        criaHeap( v, i, n-1,x,&contador);
    }
    for (i = n-1;i >= 1; i--){
        aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        criaHeap(v, 0, i-1,x,&contador);
    }
    clock_t end = clock(); //variavel end para marcar o inicio do tempo
        printf("Vetor ordenado (heapSort): ");
    for(int i = 0; i < n; i++){
        printf("%d ",v[i]);
    }
 printf("\nNumero de trocas: %d.\n",contador);
    printf("Tempo de ordenacao: %lf segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);
}

void selectionSort(int *v, int n,int x){
    clock_t start = clock();
    int i, j, min, aux, contador;
    contador = 0;
    if(x==0){
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
    }else if(x==1){
        for(i = 0; i < n-1; i++) {
        min = i;
        for(j = i+1; j < n; j++){
            if(v[j] > v[min]){
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
    }
    clock_t end = clock();
     printf("Vetor ordenado (selectionSort): ");
    for(int i = 0; i < n; i++){
        printf("%d ",v[i]);
    }
    printf("\nNumero de alteracoes: %d\n", contador);
    printf("Tempo de ordenacao: %lf segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    printf("\n");

}

int main(){

    srand(time(NULL)); 
    int x[100];
    for(int i = 0; i < 100; i++){
        x[i] = rand() % 1000;
    }
    int n = sizeof(x) / sizeof(x[0]);
    bubbleSort(x,n,1);
        for(int i = 0; i < 100; i++){
        x[i] = rand() % 1000;
    }
    bubbleSort(x,n,0);
    
    for(int i = 0; i < 100; i++){
        x[i] = rand() % 1000;
    }
    insertionSort(x,n,1); //Decrescente
    printf("\n");
        for(int i = 0; i < 100; i++){
        x[i] = rand() % 1000;
    }
    insertionSort(x,n,0); //ascendente
    printf("\n");
    
    for(int i = 0; i < 100; i++){
        x[i] = rand() % 1000;
    }
    
    
    long long contadorAlteracoes = 0;
    clock_t start = clock();  //variavel start para marcar o inicio do tempo
    mergeSort(x,0,n-1,1,&contadorAlteracoes);
    clock_t end = clock(); //variavel end para marcar o inicio do tempo
        printf("Vetor ordenado (mergeSort): ");
    for(int i = 0; i < n; i++){
        printf("%d ",x[i]);
    }
    printf("\nNumero de alteracoes: %lld\n", contadorAlteracoes);
    printf("Tempo de ordenacao: %lf segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    printf("\n");
    
        for(int i = 0; i < 100; i++){
        x[i] = rand() % 1000;
    }
    contadorAlteracoes = 0;
    start = clock();  //variavel start para marcar o inicio do tempo
    mergeSort(x,0,n-1,0,&contadorAlteracoes);
    end = clock(); //variavel end para marcar o inicio do tempo
            printf("Vetor ordenado (mergeSort): ");
    for(int i = 0; i < n; i++){
        printf("%d ",x[i]);
    }
    printf("\nNumero de alteracoes: %lld\n", contadorAlteracoes);
    printf("Tempo de ordenacao: %lf segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);


    for(int i = 0; i < 100; i++){
        x[i] = rand() % 1000;
    }
    heapSort(x,n,1); //Decrescente
    printf("\n");
        for(int i = 0; i < 100; i++){
        x[i] = rand() % 1000;
    }
    heapSort(x,n,0); //ascendente
    printf("\n");

    for(int i = 0; i < 100; i++){
        x[i] = rand() % 1000;
    }
    selectionSort(x,n,1); //Decrescente
    printf("\n");
        for(int i = 0; i < 100; i++){
        x[i] = rand() % 1000;
    }
    selectionSort(x,n,0); //ascendente
    printf("\n");


    return 0;
}
