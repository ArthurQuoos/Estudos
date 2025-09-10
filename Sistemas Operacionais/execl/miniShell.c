#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
int x = 1;
    while(x=1){
        int pid = fork();

        if(pid == 0){
            char resposta[30];
            printf("Qual o comando devo passar no execl?\n");
            fgets(resposta, sizeof(resposta), stdin);
            resposta[strcspn(resposta, "\n")] = 0;
            execl(resposta," ", NULL);
        }else if(pid > 0){
            wait(NULL);
            printf("Processo filho terminou\n");
            printf("Deseja continuar? (1-Sim/0-Nao)\n");
            scanf("%d", &x);
        }else{
            printf("Erro\n");
        }

    }


    return 0;
}