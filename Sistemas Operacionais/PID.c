#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void main(){
    int pid = fork();
    int status;

    if(pid > 0){
        printf("codigo do Pai. PID %d\n",getpid());
            wait(&status);
        printf("Meu Filho terminou com status: %d\n",WEXITSTATUS(status));

        if(WIFSIGNALED(status)){
            printf("Meu filho foi morto por um kill\n");
        }else if(WIFEXITED(status)){
            printf("Meu Filho encerrou normalmente\n");
        }
    }else if(pid == 0){
        printf("Código do Filho. PID %d\n",getpid());
        sleep(5);
        exit(10);

    }else{
        printf("ERRO!");
        exit(-10);
    }
}