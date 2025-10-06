#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Função de comparação para qsort (usada para ordenar strings)
int compareStrings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

// Função de busca binária
// Retorna verdadeiro se encontrou, e escreve o índice na variável de saída
bool buscaBinaria(char* arrayList[], int tamanho, const char* query, int* indice) {
    // Ordenar o array de strings
    qsort(arrayList, tamanho, sizeof(char*), compareStrings);

    printf("\nLista ordenada:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%s\n", arrayList[i]);
    }
    printf("\n");

    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int cmp = strcmp(arrayList[meio], query);

        if (cmp == 0) {
            *indice = meio;
            return true;
        } else if (cmp > 0) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

    *indice = -1;
    return false;
}


int main() {
  
    char* lista[] = {"AlanTuring", "arvore", "VonNeumann", "GeorgeBoole"};
    int tamanho = sizeof(lista) / sizeof(lista[0]);

    printf("Lista original:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%s\n", lista[i]);
    }

    printf("\n");

    int indice;
    char teste[30] = "GeorgeBoole"; //Define oque sera buscado

    // 
    if (buscaBinaria(lista, tamanho, teste, &indice)) {
        printf("Encontrado: %s no indice %d\n",teste, indice);
    } else {
        printf("%s nao encontrado.\n",teste);
    }

    return 0;
}
