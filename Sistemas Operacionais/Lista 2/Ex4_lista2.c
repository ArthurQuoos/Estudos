//4) A partir do código produtor/consumidor, 
//modifique o exercício para que o mesmo corresponda ao algoritmo 
//produtor/consumidor do slide 3 da aula de programação concorrente.


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define N 5
#define REP 10

typedef struct {
    volatile int counter;
    char buf[N];
} Shared;

int main()
{
    key_t key = ftok("/tmp", 'C');
    if (key == -1) { perror("ftok"); exit(1); }

    int shmid = shmget(key, sizeof(Shared), 0666 | IPC_CREAT);
    if (shmid == -1) { perror("shmget"); exit(1); }

    Shared *s = (Shared *) shmat(shmid, NULL, 0);
    if (s == (void *) -1) { perror("shmat"); shmctl(shmid, IPC_RMID, NULL); exit(1); }

    /* Inicializa área compartilhada */
    s->counter = 0;
    memset(s->buf, 0, N);

    pid_t pid = fork();
    if (pid < 0) { perror("fork"); shmdt(s); shmctl(shmid, IPC_RMID, NULL); exit(1); }

    if (pid == 0) {
        /* Produtor (filho) */
        int in = 0;
        for (int i = 0; i < REP; i++) {
            /* espera enquanto buffer cheio */
            while (s->counter == N) usleep(1000);

            /* produz um caractere */
            char item = 'A' + (i % 26);
            s->buf[in] = item;

            /* atualiza índices e contador */
            in = (in + 1) % N;
            s->counter++;

            printf("Producer stored: %c  (counter=%d)\n", item, s->counter);
            fflush(stdout);
            usleep(50000);
        }
        shmdt(s);
        _exit(0);
    } else {
        /* Consumidor (pai) */
        int out = 0;
        for (int i = 0; i < REP; i++) {
            /* espera enquanto buffer vazio */
            while (s->counter == 0) usleep(1000);

            char item = s->buf[out];
            s->buf[out] = 0; /* opcional: limpa slot */

            out = (out + 1) % N;
            s->counter--;

            printf("Consumer got:   %c  (counter=%d)\n", item, s->counter);
            fflush(stdout);
            usleep(80000);
        }

        waitpid(pid, NULL, 0);

        /* limpeza */
        shmdt(s);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}
//Corrigido

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define N 5        // tamanho do buffer circular
#define REP 10     // número de produções/consumos

typedef struct {
    volatile int counter;  // número de itens no buffer
    char buf[N];           // buffer circular
} Shared;

int main() {

    /* Cria chave para memória compartilhada */
    key_t key = ftok("/tmp", 'C');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    /* Cria segmento de memória compartilhada */
    int shmid = shmget(key, sizeof(Shared), 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    /* Conecta ao segmento */
    Shared *s = (Shared *) shmat(shmid, NULL, 0);
    if (s == (void *) -1) {
        perror("shmat");
        shmctl(shmid, IPC_RMID, NULL);
        exit(1);
    }

    /* Inicializa área compartilhada */
    s->counter = 0;
    memset(s->buf, 0, N);

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        shmdt(s);
        shmctl(shmid, IPC_RMID, NULL);
        exit(1);
    }

    /* ============================================================
       PROCESSO FILHO - PRODUTOR
       ============================================================ */
    if (pid == 0) {

        int in = 0;

        for (int i = 0; i < REP; i++) {

            while (s->counter == N)
                usleep(1000);  // espera buffer cheio

            char item = 'A' + (i % 26);

            s->buf[in] = item;
            in = (in + 1) % N;

            s->counter++;

            printf("Producer stored: %c   (counter = %d)\n", item, s->counter);
            fflush(stdout);

            usleep(50000);
        }

        shmdt(s);
        _exit(0);
    }

    /* ============================================================
       PROCESSO PAI - CONSUMIDOR
       ============================================================ */
    else {

        int out = 0;

        for (int i = 0; i < REP; i++) {

            while (s->counter == 0)
                usleep(1000);  // espera buffer vazio

            char item = s->buf[out];

            s->buf[out] = 0;  // opcional: limpa posição
            out = (out + 1) % N;

            s->counter--;

            printf("Consumer got:   %c   (counter = %d)\n", item, s->counter);
            fflush(stdout);

            usleep(80000);
        }

        /* Espera processo filho terminar */
        waitpid(pid, NULL, 0);

        /* Limpa sistema de memória compartilhada */
        shmdt(s);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}
