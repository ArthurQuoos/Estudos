#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
 
#define SHM_SIZE 1024

const int REP = 5;
char dado;
key_t key;
int shmid;
char *data;

int producer(int n)
{
    printf("Producer was born!\n");
    for(int i = 0; i < REP; i++) {
        data[i] = (char) (i + 0x61);
        printf("Stored... %c \n", data[i]);
        usleep(100000);
    }
    return n;
}
 
int consumer(int n)
{
    printf("Consumer was born!\n");
    for(int i = 0; i < REP; i++) {
        dado = data[i];
        printf("Consumed... %c \n", dado);
        usleep(100000);
    }
    return n;
}
 
int main()
{
    printf("The Producer x Consumer Problem\n");
     
    key = ftok("/home", 'A');                      // Segmento de dados
    shmid = shmget(key, REP * sizeof(char), 0644 | IPC_CREAT);
    if (shmid == -1) { perror("shmget"); exit(1); }
    data = (char *) shmat(shmid, NULL, 0);
    if (data == (void *) -1) { perror("shmat"); shmctl(shmid, IPC_RMID, NULL); exit(1); }

    int pid = fork();
    if(pid == 0){
        producer(REP);       
        shmdt(data);
        _exit(0);
    } else if (pid > 0) {
        /* sincronização com 1 comando */
        waitpid(pid, NULL, 0);   /* espera o produtor terminar */

        consumer(REP);

        shmdt(data);
        shmctl(shmid, IPC_RMID, NULL);
    } else {
        perror("fork");
        exit(1);
    }   
    
    return 0;
}

//Corrigido

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024
#define REP 5

char dado;
key_t key;
int shmid;
char *data;

int producer()
{
    printf("Producer was born!\n");

    for (int i = 0; i < REP; i++) {

        data[i] = (char)(i + 0x61);   // a, b, c, d, e
        printf("Stored... %c\n", data[i]);

        /* ÚNICO comando de sincronização */
        usleep(120000);    
    }
    return 0;
}

int consumer()
{
    printf("Consumer was born!\n");

    for (int i = 0; i < REP; i++) {

        dado = data[i];
        printf("Consumed... %c\n", dado);

        /* (não pode usar outro comando, apenas 1 no programa inteiro) */
    }

    return 0;
}

int main()
{
    printf("The Producer x Consumer Problem\n");

    key = ftok("/home", 'A');
    shmid = shmget(key, REP * sizeof(char), 0644 | IPC_CREAT);
    if (shmid == -1) { perror("shmget"); exit(1); }

    data = (char *) shmat(shmid, NULL, 0);
    if (data == (void *) -1) {
        perror("shmat");
        shmctl(shmid, IPC_RMID, NULL);
        exit(1);
    }

    pid_t pid = fork();

    if (pid == 0) {
        /* Process F = Producer */
        producer();
        shmdt(data);
        _exit(0);
    }
    else if (pid > 0) {
        /* Process P = Consumer */
        consumer();

        waitpid(pid, NULL, 0);

        shmdt(data);
        shmctl(shmid, IPC_RMID, NULL);
    }
    else {
        perror("fork");
        exit(1);
    }

    return 0;
}
