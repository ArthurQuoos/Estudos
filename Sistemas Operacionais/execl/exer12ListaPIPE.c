#include <unistd.h>
#include <signal.h>


void main(){
    int pipeDC[2];
    int pipeCB[2];
    int pipeBA[2];

    pipe(pipeDC);
    pipe(pipeCB);
    pipe(pipeBA);

    int pidB = fork();


    if(pidB ==0){
            int pidC = fork();
            if(pidC == 0){
                int pidD = fork();

                        if(pidD == 0){
                                char *msg = "vamo muçar\n\n";
                                write(pipeDC[1], msg, 14);
                        }else{
                            char buff[14];
                            read(pipeDC[0],buff, 14 );
                            write(pipeCB[1], buff, 14);
                        }
                }else{
                        char buff2[14];
                        read(pipeCB[0],buff2, 14 );
                        write(pipeBA[1], buff2, 14);
                    }
            }else{
                    char buff3[14];
                    read(pipeBA[0],buff3, 14 );
                    write(1,"Recebi esta msg: ",18);
                    write(1,buff3,14);
            }    
}