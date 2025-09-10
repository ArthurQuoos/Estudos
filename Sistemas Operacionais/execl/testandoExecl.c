#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
    int pid = fork();

    if(pid == 0){ //Filho
        printf("Filho: Vou modificar meu comportamento para rodar hello world!\n");
        execl("hello", " ", NULL);
    }else if(pid > 0){ //Pai
        wait(NULL);
        printf("Filho executou um hello world!\n");
    }else{
        printf("ERRO\n");
    }


    return 0;
}