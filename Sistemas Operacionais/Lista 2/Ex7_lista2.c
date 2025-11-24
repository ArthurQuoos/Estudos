/*
7) programa abaixo manipula uma matriz de tamanho MxN (veja os defines para o tamanho da matriz). A função SumValues soma todos os valores em uma linha da matriz. A linha a ser somada é
identificada pela variável i. Modifique o programa principal (main) nos locais indicados para:


           1. Criar N threads, uma para somar os valores de cada linha.

           2. Receber o resultado do somatório de cada linha e gerar o somatório total da matriz.

           3. Analise o programa: há problemas de sincronização que precisam ser resolvidos? Se sim, resolva-os.

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

/* number of matrix columns and rows */
#define M 5
#define N 10
 
int matrix[N][M];
pthread_t threads[N];
int sum_total;


/* thread function; it sums the values of the matrix in the row */
void* SumValues(void* i)
{
    int n = (long) i;     /* row number */
    int j, total = 0;

    /* sum values of row n */
    for (j = 0; j < M; j++)
        total += matrix[n][j];

    printf("The total in row %d is %d\n", n, total);

    /* allocate space to return the result */
    int* retval = malloc(sizeof(int));
    *retval = total;

    pthread_exit(retval);
}


int main(int argc, char *argv[])
{
    sum_total = 0;
    int i, j;

    /* initialize the matrix */
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            matrix[i][j] = i * M + j;

    /* ----------------------------------------- */
    /* 1. CREATE THREADS                         */
    /* ----------------------------------------- */
    for (i = 0; i < N; i++)
        pthread_create(&threads[i], NULL, SumValues, (void*)(long)i);

      
    /* ----------------------------------------- */
    /* 2. WAIT THREADS AND SUM RESULTS           */
    /* ----------------------------------------- */
    for (i = 0; i < N; i++) {
        int *retval;
        pthread_join(threads[i], (void**)&retval);

        sum_total += *retval;   // add row sum to total

        free(retval);           // free memory returned by the thread
    }
 
    printf("The total values in the matrix is %d\n", sum_total);

    return 0;
}

//Corrigido

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* número de colunas e linhas da matriz */
#define COLUNAS 5
#define LINHAS 10
 
int matriz[LINHAS][COLUNAS];
pthread_t threads[LINHAS];
int soma_total;


/* função executada por cada thread: soma os valores de uma linha */
void* somarLinha(void* arg)
{
    int linha = (long) arg;
    int j, soma_linha = 0;

    /* soma os valores da linha */
    for (j = 0; j < COLUNAS; j++)
        soma_linha += matriz[linha][j];

    printf("A soma da linha %d é %d\n", linha, soma_linha);

    /* aloca espaço para retornar a soma */
    int* retorno = malloc(sizeof(int));
    *retorno = soma_linha;

    pthread_exit(retorno);
}


int main()
{
    soma_total = 0;
    int i, j;

    /* inicializa a matriz com valores */
    for (i = 0; i < LINHAS; i++)
        for (j = 0; j < COLUNAS; j++)
            matriz[i][j] = i * COLUNAS + j;

    /* ----------------------------------------- */
    /* 1. CRIAÇÃO DAS THREADS                    */
    /* ----------------------------------------- */
    for (i = 0; i < LINHAS; i++)
        pthread_create(&threads[i], NULL, somarLinha, (void*)(long)i);

      
    /* ----------------------------------------- */
    /* 2. ESPERA DAS THREADS E SOMA DOS RESULTADOS */
    /* ----------------------------------------- */
    for (i = 0; i < LINHAS; i++) {
        int *resultado_linha;
        pthread_join(threads[i], (void**)&resultado_linha);

        soma_total += *resultado_linha;  // adiciona a soma da linha ao total

        free(resultado_linha);           // libera memória alocada pela thread
    }
 
    printf("A soma total da matriz é %d\n", soma_total);

    return 0;
}

