#include <stdio.h>
#include <unistd.h>


void main(){
    int fd[2];
    pipe(fd);

    if (fork() > 0){
        char *msg = "Simba sou seu pai\n";
        write(fd[1], msg,20);
    }else{
        char buff[1024];
        read(fd[0],buff,20);
        printf("Misg do Mufasa: %s",buff); //Filho
    }
}