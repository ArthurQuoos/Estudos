#include "mylib.h"
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>


void myprintf(int x, int y, char* msg){
    
    int size = strlen(msg);
    char msg2[11];
    strcpy(msg2,"\033[ B\033[ C");   
    
    
    msg2[2]= x + '0';
    msg2[6]= y + '0';

       write(1,msg2,strlen(msg2));
       write(1,msg,strlen(msg));
}

static int contador_ctrlz = 0;

void stopper(int sig){
    contador_ctrlz++;
    if(contador_ctrlz >= 3){
        write(1, "\nParando...\n", 12);
        exit(0);
    } else {
        write(1, "\nCTRL+Z detectado...\n", 22);
    }
}

void printsinc(char* msg, int segundos){
    signal(SIGTSTP, stopper);
   
    while(1){
    sleep(segundos);
    write(1,msg,strlen(msg));
        
    }
    
}
