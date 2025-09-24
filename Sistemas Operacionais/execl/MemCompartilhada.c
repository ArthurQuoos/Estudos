#include <stdio.h>
#include <unistd.h>

//gcc -o ex exemplo.c
// ./ex "Valor"

void main(int argc,char *argv[]){

    char *buff;
    int key = ftok(".",'A');// Criando chave: H:\Sistemas Operacionais\execl
    int shmid = shmget(key, 50*sizeof(char), IPC_CREAT | 0644);
    buff = shamt(shmid,0,0);

if((argv[1] != NULL) && (strcmp(argv[1], "apagar"))){
    strcpy(buff,argv[1]);
}else if((argc > 1 )&& (!strcmp(argv[1], "apagar"))){
    //strcpy(buff, " ");
    shmdt(buff); //desanexando regiao de memoria
    shmctl(shmid, IPC_RMID, NULL);  //destruindo regiao de memoria
}else{
    printf("->> %s \n", buff);
}



}