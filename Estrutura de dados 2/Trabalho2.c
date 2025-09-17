#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <string.h>

void swap(int *a, int *b) {
int tmp = *a;
*a = *b;
*b = tmp;
}

void bubbleSort(int *v, int n,int x) {
 clock_t start = clock();  //variavel start para marcar o inicio do tempo
 bool changed = true;
 int trocas = 0;
 int comp = 0;

 if(x == 0){
 while(changed) {
    changed = false;
    for(int i = 0; i < n-1; i++) {
        comp++;
        if(v[i] > v[i+1]) {
        swap(&v[i], &v[i+1]);
        changed = true;
        trocas++;
             }
         }
    }
    printf("Vetor ordenado em ordem ascendente (bubbleSort):\n");
    for(int i = 0; i < n; i++){
        printf("%d ",v[i]);
    }
    
    }else if(x == 1){
         while(changed) {
    changed = false;
    for(int i = 0; i < n-1; i++) {
        comp++;
        if(v[i] < v[i+1]) {
        swap(&v[i], &v[i+1]);
        changed = true;
        trocas++;
             }
         }
    }
        printf("Vetor ordenado em ordem decrescente (bubbleSort):\n");
    for(int i = 0; i < n; i++){
        printf("%d ",v[i]);
    }
    
    }
    printf("\nNumero de Comparacoes: %d\n",comp);
    printf("Numero de trocas: %d\n",trocas);
    clock_t end = clock(); //variavel end para marcar o inicio do tempo
    printf("Tempo de ordenacao: %lf segundos\n\n", ((double)(end - start)) / CLOCKS_PER_SEC);
 }

void insertionSort(int *v, int n, int x) {
    clock_t start = clock();  // marca o início do tempo
    int i, j, chosen;
    int trocas = 0;
    int comp = 0;

    for (i = 1; i < n; i++) {
        chosen = v[i];
        j = i - 1;

        while (j >= 0) {
            comp++; // conta a comparação v[j] com chosen

            if ((x == 0 && chosen < v[j]) || (x != 0 && chosen > v[j])) {
                v[j + 1] = v[j];
                j--;
                trocas++;
            } else {
                break; // sai quando não precisa mais mover
            }
        }
        v[j + 1] = chosen;
    }

    // imprimir vetor ordenado
    printf("Vetor ordenado (insertionSort): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    // imprimir estatísticas
    printf("\nComparacoes: %d\n", comp);
    printf("Trocas: %d\n", trocas);

    clock_t end = clock(); // marca o fim
    printf("Tempo de ordenacao: %lf segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);
}

// Merge com contador
void merge(int *v, int inicio, int meio, int fim, int x, long long *trocas,long long *comp) {
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;

    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;

    temp = (int *) malloc(tamanho * sizeof(int));
    if (temp != NULL) {
        for (i = 0; i < tamanho; i++) {
            if (!fim1 && !fim2) {
                (*comp)++;
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
            (*trocas)++;
        }

        for (j = 0, k = inicio; j < tamanho; j++, k++) {
            v[k] = temp[j];
            (*trocas)++;
        }
    }

    free(temp);
}

// MergeSort recursivo com contador
void mergeSort(int *v, int inicio, int fim, int x, long long *trocas, long long *comp) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(v, inicio, meio, x, comp, trocas);
        mergeSort(v, meio + 1, fim, x, comp, trocas);
        merge(v, inicio, meio, fim, x, comp, trocas);
    }
}

// criaHeap ajustado para contar comparações e trocas separadas
void criaHeap(int *v, int inicio, int fim, int x, long long *comp, long long *trocas) {
    int aux = v[inicio];
    int filho = 2 * inicio + 1;

    if (x == 1) { // decrescente (min-heap)
        while (filho <= fim) {
            if (filho < fim) {
                (*comp)++; // comparação entre filhos
                if (v[filho] > v[filho + 1]) {
                    filho = filho + 1;
                }
            }
            (*comp)++; // comparação pai-filho
            if (aux > v[filho]) {
                v[inicio] = v[filho];
                inicio = filho;
                filho = 2 * inicio + 1;
                (*trocas)++;
            } else {
                break;
            }
        }
        v[inicio] = aux;
    } else { // crescente (max-heap)
        while (filho <= fim) {
            if (filho < fim) {
                (*comp)++; // comparação entre filhos
                if (v[filho] < v[filho + 1]) {
                    filho = filho + 1;
                }
            }
            (*comp)++; // comparação pai-filho
            if (aux < v[filho]) {
                v[inicio] = v[filho];
                inicio = filho;
                filho = 2 * inicio + 1;
                (*trocas)++;
            } else {
                break;
            }
        }
        v[inicio] = aux;
    }
}

void heapSort(int *v, int n, int x) {
    clock_t start = clock();
    int i, aux;
    long long comp = 0, trocas = 0;

    // construir o heap
    for (i = (n - 1) / 2; i >= 0; i--) {
        criaHeap(v, i, n - 1, x, &comp, &trocas);
    }

    // ordenar
    for (i = n - 1; i >= 1; i--) {
        aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        trocas++; // troca da raiz com o último
        criaHeap(v, 0, i - 1, x, &comp, &trocas);
    }

    clock_t end = clock();

    // resultados
    printf("Vetor ordenado (heapSort): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\nComparacoes: %lld\n", comp);
    printf("Trocas: %lld\n", trocas);
    printf("Tempo de ordenacao: %lf segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);
}

// Função para trocar dois elementos de lugar
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para particionar o vetor e retornar o índice da partição
int particionar(int *x, int inicio, int fim, int *comp, int *trocas) {
    int pivo = x[fim]; // Escolhe o último elemento como pivô
    int i = inicio - 1;
    for (int j = inicio; j < fim; j++) {
        (*comp)++; // Conta a comparação
        if (x[j] <= pivo) {
            i++;
            trocar(&x[i], &x[j]); // Troca os elementos
            (*trocas)++;
        }
    }
    trocar(&x[i + 1], &x[fim]);
    (*trocas)++;
    return i + 1;
}

// Função recursiva do Quick Sort
void quickSort(int *x, int inicio, int fim, int *comp, int *trocas) {
    if (inicio < fim) {
        int pi = particionar(x, inicio, fim, comp, trocas);
        quickSort(x, inicio, pi - 1, comp, trocas);
        quickSort(x, pi + 1, fim, comp, trocas);
    }
}

void selectionSort(int *v, int n, int x) {
    clock_t inicio = clock();

    int i, j, min, aux;
    int trocas = 0;
    int comp = 0;

    if (x == 0) { // Ordem crescente
        for (i = 0; i < n - 1; i++) {
            min = i;
            for (j = i + 1; j < n; j++) {
                comp++; // Contar comparação
                if (v[j] < v[min]) {
                    min = j;
                }
            }
            if (min != i) {
                aux = v[i];
                v[i] = v[min];
                v[min] = aux;
                trocas++;
            }
        }
    } else if (x == 1) { // Ordem decrescente
        for (i = 0; i < n - 1; i++) {
            min = i;
            for (j = i + 1; j < n; j++) {
                comp++; // Contar comparação
                if (v[j] > v[min]) {
                    min = j;
                }
            }
            if (min != i) {
                aux = v[i];
                v[i] = v[min];
                v[min] = aux;
                trocas++;
            }
        }
    }

    clock_t fim = clock();

    // Exibe os resultados
    printf("Vetor ordenado (selectionSort): ");
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    printf("Número de comparações: %d\n", comp);
    printf("Número de trocas: %d\n", trocas);
    printf("Tempo de ordenação: %lf segundos\n\n", ((double)(fim - inicio)) / CLOCKS_PER_SEC);
}


int main(){
    int crescente[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 
    17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 
    36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 
    55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 
    74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 
    92, 93, 94, 95, 96, 97, 98, 99, 100};
    
    int decrescente[] = {100, 99, 98, 97, 96, 95, 94, 93, 92, 91,
    90, 89, 88, 87, 86, 85, 84, 83, 82, 81,
    80, 79, 78, 77, 76, 75, 74, 73, 72, 71,
    70, 69, 68, 67, 66, 65, 64, 63, 62, 61,
    60, 59, 58, 57, 56, 55, 54, 53, 52, 51,
    50, 49, 48, 47, 46, 45, 44, 43, 42, 41,
    40, 39, 38, 37, 36, 35, 34, 33, 32, 31,
    30, 29, 28, 27, 26, 25, 24, 23, 22, 21,
    20, 19, 18, 17, 16, 15, 14, 13, 12, 11,
    10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    int copy[100];
    srand(time(NULL)); 
    int x[100];
    for(int i = 0; i < 100; i++){
        x[i] = rand() % 1000;
    }
    int n = sizeof(x) / sizeof(x[0]);
    bubbleSort(x,n,0); //ordem aleatoria
    memcpy(copy, crescente, sizeof(crescente));
    bubbleSort(copy,n,0);//vetor crescente
    memcpy(copy,decrescente,sizeof(decrescente));
    bubbleSort(copy,n,0);//ordem decrescente
    printf("\n");
    
        for(int i = 0; i < 100; i++){
        x[i] = rand() % 1000;
    }
    insertionSort(x,n,0); //ordem aleatoria 
    memcpy(copy, crescente, sizeof(crescente));
    insertionSort(copy,n,0); //ordem crescente
    memcpy(copy,decrescente,sizeof(decrescente));
    insertionSort(copy,n,0); //ordem decrescente
    printf("\n");
    
    
    
    for(int i = 0; i < 100; i++){
        x[i] = rand() % 1000;
    }
    long long trocas = 0;
    long long comp = 0;
    clock_t start = clock();  
    mergeSort(x,1,n-1,1,&trocas,&comp); //ordem aleatoria
    clock_t end = clock(); 
    printf("Vetor ordenado (mergeSort): ");
    for(int i = 0; i < n; i++){
        printf("%d ",x[i]);
    }
    printf("\nNumero de comparacoes: %lld\n",comp);
    printf("Numero de alteracoes: %lld\n", trocas);
    printf("Tempo de ordenacao: %lf segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);
     trocas = 0;
     comp = 0;
    memcpy(copy, crescente, sizeof(crescente));
    start = clock();  //variavel start para marcar o inicio do tempo
    mergeSort(copy,0,n-1,1,&trocas,&comp);
    end = clock(); //variavel end para marcar o inicio do tempo
    printf("Vetor ordenado (mergeSort): ");
    for(int i = 0; i < n; i++){
        printf("%d ",copy[i]);
    }
    printf("\nNumero de comparacoes: %lld\n",comp);
    printf("Numero de alteracoes: %lld\n", trocas);
    printf("Tempo de ordenacao: %lf segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);
     trocas = 0;
     comp = 0;
    start = clock();  //variavel start para marcar o inicio do tempo
    memcpy(copy, decrescente, sizeof(decrescente));
    mergeSort(copy,0,n-1,1,&trocas,&comp);
    end = clock(); //variavel end para marcar o inicio do tempo
    printf("Vetor ordenado (mergeSort): ");
    for(int i = 0; i < n; i++){
        printf("%d ",copy[i]);
    }
    printf("\nNumero de comparacoes: %lld\n",comp);
    printf("Numero de alteracoes: %lld\n", trocas);
    printf("Tempo de ordenacao: %lf segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    printf("\n");
    
    

    for(int i = 0; i < 100; i++){
        x[i] = rand() % 1000;
    }
    heapSort(x,n,0); //Aleatoria
    memcpy(copy, crescente, sizeof(crescente));
    heapSort(copy,n,0);//ascendente
    memcpy(copy, decrescente, sizeof(decrescente));
    heapSort(copy,n,0);//decrescente
    

    printf("\n");
        for(int i = 0; i < 100; i++){
        x[i] = rand() % 1000;
    }
    selectionSort(x,n,0); //aleatoria
    memcpy(copy, crescente, sizeof(crescente));
    selectionSort(copy,n,0); //ascendente
    memcpy(copy, decrescente, sizeof(decrescente));
    selectionSort(copy,n,0); //Decrescente
    printf("\n");

    int compa = 0;
    int trocaz = 0;
    for(int i = 0; i < 100; i++){
        x[i] = rand() % 1000;
    }
    start = clock();
    quickSort(x,0,n-1,&compa, &trocaz); //aleatoria
    end = clock();
        printf("Vetor ordenado (QuickSort):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }
    printf("\nComparacoes: %d\n", compa);
    printf("Trocas: %d\n", trocaz);
    printf("Tempo de ordenacao: %lf segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    printf("\n");
    memcpy(copy, crescente, sizeof(crescente));
    start = clock();
    quickSort(copy,0,n-1,&compa,&trocaz);
    end = clock();
    printf("Vetor ordenado (QuickSort):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", copy[i]);
    }
    printf("\nComparacoes: %d\n", compa);
    printf("Trocas: %d\n", trocaz);
    printf("Tempo de ordenacao: %lf segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    printf("\n");
    memcpy(copy, decrescente, sizeof(decrescente));
    start = clock();
    quickSort(copy,0,n-1,&compa,&trocaz);
    end = clock();
    printf("Vetor ordenado (QuickSort):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", copy[i]);
    }
    printf("\nComparacoes: %d\n", compa);
    printf("Trocas: %d\n", trocaz);
    printf("Tempo de ordenacao: %lf segundos\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    printf("\n");
    return 0;
}
