#include "mylib.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

char *amsg;  //para ser usado no handler ex2

void myprintf(int x, int y, char* msg){
	

	int size = strlen(msg);
	char msg2[11];
	strcpy(msg2,"\033[ B\033[ C");	
	
	
	
	msg2[6]= y + '0';

		
        write(1, msg2, 10);
	write(1, msg, size);
	write(1, "\n", 1);
}

void handler(int signum){
	
	write(1, amsg,  strlen(amsg));	
	
}

void printsinc(char* msg, int segundos){

	amsg = malloc(strlen(msg)*(sizeof(char)));	

	strcpy(amsg,msg);

	signal(SIGALRM, handler);		
	
	while(1){	
		alarm(segundos);
		pause();
	}

}







