#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <semaphore.h>

typedef struct {
    sem_t sem_parent; /* vez do pai (ímpares) */
    sem_t sem_child;  /* vez do filho (pares) */
} Shared;

int main(void)
{
    key_t key = ftok("/tmp", 'S');
    if (key == -1) { perror("ftok"); exit(1); }

    int shmid = shmget(key, sizeof(Shared), 0600 | IPC_CREAT);
    if (shmid == -1) { perror("shmget"); exit(1); }

    Shared *s = (Shared *) shmat(shmid, NULL, 0);
    if (s == (void *) -1) { perror("shmat"); shmctl(shmid, IPC_RMID, NULL); exit(1); }

    /* semáforos em memória compartilhada */
    sem_init(&s->sem_child, 1, 1);  /* filho (pares) começa liberado */
    sem_init(&s->sem_parent, 1, 0); /* pai (ímpares) começa bloqueado */

    pid_t pid = fork();
    if (pid < 0) { perror("fork"); exit(1); }

    if (pid == 0) {
        /* Filho: imprime pares */
        for (int i = 0; i < 10; i += 2) {
            sem_wait(&s->sem_child);
            printf("Processo filho %d\n", i);
            fflush(stdout);
            sem_post(&s->sem_parent);
        }
        shmdt(s);
        _exit(0);
    } else {
        /* Pai: imprime ímpares */
        for (int i = 1; i < 10; i += 2) {
            sem_wait(&s->sem_parent);
            printf("Processo pai %d\n", i);
            fflush(stdout);
            sem_post(&s->sem_child);
        }

        waitpid(pid, NULL, 0);

        sem_destroy(&s->sem_parent);
        sem_destroy(&s->sem_child);
        shmdt(s);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}