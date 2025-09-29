#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>


int main(){

int key = ftok(".",'A');
int shmid = shmget(key, 50*sizeof(char), 0644);
char *ponteiro = shmat(shmid, 0, 0);

printf("%s\n",ponteiro);
return 0;
}


