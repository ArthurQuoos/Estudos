#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

/*
Excrever um programa C que cria uma árvore de 3 processos, onde o processo A faz um fork() 
criando um processo B, o processo B, por sua vez, faz um fork() criando um processo C. 
Cada processo deve exibir uma mensagem "Eu sou o processo XXX, filho de YYY", onde XXX e 
YYY são PIDs de processos. Utilizar wait() para garantir que o processo C imprima sua resposta 
antes do B, e que o processo B imprima sua resposta antes do A. Utilizar sleep() (man 3 sleep) 
para haver um intervalo de 1 segundo entre cada mensagem impressa.
*/

void main(){
    int pidB = fork();
    int pidC;
    int status;




      if(pidB > 0){
                wait(&status);
                sleep(3);
                printf("1Eu sou o processo %d filho de %d\n",getpid(),getppid());//processo A   
                
        }else if(pidB == 0){
                pidC = fork();
                if(pidC > 0){
                       wait(&status);
                        sleep(3);
                        printf("2Eu sou o processo %d filho de %d\n",getpid(),getppid()); //Precesso B
                        
                }else if(pidC == 0){
                    printf("3Eu sou o processo %d filho de %d\n",getpid(),getppid());//Processo C
                    
                }
                }else{
        printf("ERRO!");
        exit(-10);
    }




}