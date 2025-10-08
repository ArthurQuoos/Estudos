#include <pthread.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define NUM_THREADS 5

int saldo = 1000;
pthread_mutex_t mutex;
pthread_t x[5];

void *AtualizaSaldo(void *n) {
    int num = (intptr_t)n; 
    
    int meu_saldo = saldo;
    int novo_saldo = meu_saldo + (num * 100); 

    printf("Sou a Thread %d. Novo saldo: %d\n", num, novo_saldo);
    
    int *saldoptr = malloc(sizeof(int));
    *saldoptr = novo_saldo;
    
    pthread_exit(saldoptr);    
    
}

int main() {
    void *status;
    int resultado = 0;    
    
   
    pthread_t threads[NUM_THREADS];
    //Criar as threads 

    for (int i = 0; i < 5; i++)
    {
        pthread_create(&x[i], NULL, AtualizaSaldo, i+1);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_join(x[i],&status);
        resultado = resultado + *(int*)status;
    }
    

    
    //Coletar os resultados para somar o saldo final 
    printf("Saldo Final: %d\n", resultado);
    return 0;
}