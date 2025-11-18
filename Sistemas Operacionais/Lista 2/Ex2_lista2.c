
/*2) Construa um “pipeline”. Crie um programa que conecte 4 
processos através de 3 pipes. Utilize fork() para criar 
vários processos. Mande uma mensagem do quarto processo e 
faça a mensagem viajar pelos pipes  até chegar no primeiro 
processo, e exiba a mensagem.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){

    int pipe1[2], pipe2[2], pipe3[2];

    char buffer[100];

    pipe(pipe1);
    pipe(pipe2);
    pipe(pipe3);

    int pid1 = fork();
    if(pid1 == 0){
        // Processo 1   
        int pid2 = fork();
        if(pid2 == 0){
            //processo 2
            int pid3 = fork();
            if(pid3 == 0){
                //processo 3
                int pid4 = fork();
                if(pid4 == 0){
                    //processo 4
                    printf("Processo 4 enviando mensagem...\n");
                    char* msg = "Mensagem do processo 4";
                    write(pipe3[1], msg, 24);
                }else{
                    //processo 3
                    printf("Processo 3 recebendo mensagem...\n");
                    read(pipe3[0], buffer, 24);
                    write(pipe2[1], buffer, 24);
                }
            }else{
            //processo 2
            printf("Processo 2 recebendo mensagem...\n");
            read(pipe2[0], buffer, 24);
            write(pipe1[1], buffer, 24);
            }
        }else{
        //processo 1
        read(pipe1[0], buffer, 24);
        printf("Processo 1 recebeu: %s\n", buffer);
     }
    }else{
        perror("fork");
        exit(1);
    }
    
    return 0;
}