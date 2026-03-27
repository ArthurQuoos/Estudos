#include <stdio.h>
#include <unistd.h>
#include <signal.h>


void repetidor(int sig){
write(1,"Dentro de um loop\n",18);
alarm(3);
}

void interrompe(int sig){
    write(1,"PARANDO...\n",11);
    exit(0);
}

int main()
{
    signal(SIGALRM, repetidor);
    signal(SIGINT, interrompe);
    alarm(3);
    
    while(1){
        pause();
        
    }

    return 0;
}
