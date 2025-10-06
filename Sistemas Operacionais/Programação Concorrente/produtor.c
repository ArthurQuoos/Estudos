#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <signal.h>
#include <pthread.h>
 
 
 
#define SHM_SIZE 1024
 
//Processo 1
 
const int REP = 5;
char dado;
key_t key;
int shmid, counterid, flagsid;
char *data;
int  *counter;
int in;
int *flag;
 
 
 
void exit(int signum){
 
    shmdt(data);                              //segmento 3  
    shmctl(shmid, IPC_RMID, NULL);            //
    
    exit(0);
}
 
 
 
void producer()
{
    printf("Producer was born!\n");
 
    while(1) {    
 
flag[1] = 1;   
 
while(flag[0] && flag[2] == 0);
 
        while (*counter == 5);       
        
        data[in] = (char) in + 0x61;  
        printf("Stored... %c  Element %d  Counter %d\n", data[in],in,*counter);
       
        flag[2] = 0;
flag[1] = 0;        
       
        (*counter)++;
      
        in = ++in % REP;
    }
       
}
 
 
 
void main()
{
    printf("The Producer x Consumer Problem\n");
    int status;
    in = 0;
     
    key = ftok("/home", 'A');                      //  Segmento   
    shmid = shmget(key, 1024, 0644 | IPC_CREAT);   //
    data = (malloc(REP*sizeof(char)));               //     1        
    data = shmat(shmid, (void *)0, 0);             //
    
    
    key = ftok("/home/downloads", 'B');            //  Segmento   
    counterid = shmget(key, sizeof(int), 0644 | IPC_CREAT); //    2
    counter = shmat(counterid, (void *)0, 0);          //  
    
    
    key = ftok("/home", 'C');                      //  Segmento   
    flagsid = shmget(key, 3*sizeof(int), 0644 | IPC_CREAT);   //
    flag = (malloc(3*sizeof(int)));               //     3        
    
    flag[0] = 0;
    flag[1] = 1;
    flag[2] = 1;
            
    *counter = 0;
         
    signal(SIGINT, exit);  
          
    producer();       
       
    
}