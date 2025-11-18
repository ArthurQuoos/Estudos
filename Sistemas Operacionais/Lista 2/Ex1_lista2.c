/*
Um mecanismo disponibilizado por sistemas UNIX para troca de mensagens entre processos é o
PIPE. Pipes são mecanismos de comunicação indireta onde mensagens são trocadas através de
mailboxes. Cada mailbox possui um identificador único, permitindo que processos identifiquem o
canal de comunicação entre eles.

O fluxo de mensagens em um Pipe é:
             unidirecional: sobre um mesmo pipe, apenas um processo envia mensagens e um processo recebe mensagens;           

             FIFO: as mensagens são entregues na ordem de envio;

             Não-estruturado: não há estrutura pré-definida para o formato da mensagem. No UNIX, pipes são inicializados através da SystemCall pipe, que possui a seguinte sintaxe:

             int pipe(int pipefd[2]): pipe inicializa um novo pipe no sistema e retorna, no array pipefd, os descritores identificando cada uma das pontas do pipe. A
primeira posição do array, i.e. pipefd[0], recebe o descritor que pode ser aberto apenas para leitura, enquanto a segunda posição do array, i.e.
pipefd[1], recebe o descritor que pode ser aberto apenas para escrita. A função retorna zero no caso de sucesso, ou -1 se ocorrer erro.
As primitivas send/receive para uso de um pipe no UNIX são implementadas por SystemCalls read/write, conforme segue:
            ssize_t read(int fd, void *buf, size_t count): “puxa” dados do pipe identificado pelo descritor fd. Os dados recebidos são os apontados pelo ponteiro buf,
sendo count a quantidade máxima de bytes a serem recebidos. A função retorna o número de bytes recebidos. ssize_t write(int fd, const void *buf, size_t count): “empurra” dados no pipe identificado pelo descritor fd. Os dados transmitidos são os apontados pelo ponteiro buf, sendo count a quantidade de bytes a serem transmitidos. A função retorna o número de bytes transmitidos. Abaixo há um exemplo de programa criando um pipe e compartilhando os descritores entre dois processos (criados via fork()).



         Exercício 1: Faça um programa utilizando o posix do linux que faça dois processos 
         filhos enviarem mensagem para um mesmo pai por meio de PIPES.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main() {
    int pipe1[2], pipe2[2];
    pid_t pid1, pid2;
    char buffer[100];

    // Cria dois pipes
    pipe(pipe1);
    pipe(pipe2);

    // ============================
    //       FILHO 1
    // ============================
    pid1 = fork();
    if (pid1 == 0) {
        close(pipe1[0]);  // fecha leitura
        char msg[] = "Mensagem do filho 1";
        write(pipe1[1], msg, strlen(msg) + 1);
        close(pipe1[1]);
        exit(0);
    }

    // ============================
    //       FILHO 2
    // ============================
    pid2 = fork();
    if (pid2 == 0) {
        close(pipe2[0]);  // fecha leitura
        char msg[] = "Mensagem do filho 2";
        write(pipe2[1], msg, strlen(msg) + 1);
        close(pipe2[1]);
        exit(0);
    }

    // ============================
    //       PROCESSO PAI
    // ============================
    close(pipe1[1]);  // pai fecha escrita
    close(pipe2[1]);  // pai fecha escrita

    read(pipe1[0], buffer, sizeof(buffer));
    printf("Pai recebeu: %s\n", buffer);

    read(pipe2[0], buffer, sizeof(buffer));
    printf("Pai recebeu: %s\n", buffer);

    close(pipe1[0]);
    close(pipe2[0]);

    return 0;
}



/*
         Exercício 2: Shared Memory, Complete o código a seguir para que os processos pai e filho possam 
        compartilhar um segmento de memória. O filho escreve no segmento e o pai imprime na tela o conteúdo da mensagem.



*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main(int argc, char *argv[])
{
      key_t key;
      int shmid;
      char *segmento;
      pid_t filho;

      //  Criar a chave: 
      key = ftok("/tmp", 'R');  use um caminho existente 
      if (key == -1)
      {
           perror("ftok");
           exit(1);
       }

      //Criar o segmento (ou obter se já existir) 
      shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
      if (shmid == -1) {
          perror("shmget");
          exit(1);
      }

      //Vincula o segmento de memória à variável segmento
      segmento = shmat(shmid, (void *)0, 0);
      if (segmento == (char *)(-1)) {
         perror("shmat");
         exit(1);
      }

    //Código do filho
    filho = fork();
    if(filho == -1) {
        perror("fork");
        // Desvincular e remover antes de sair em erro 
        shmdt(segmento);
        shmctl(shmid, IPC_RMID, NULL);
        exit(1);
    }

    if(filho == 0){
        printf("Filho escrevendo no segmento de memória compartilhada...\n");
        snprintf(segmento, SHM_SIZE, "Mensagem do processo filho.");
        _exit(0);
    } else {
        waitpid(filho, NULL, 0); // Espera o filho terminar
        printf("Pai lendo do segmento de memória compartilhada...\n");
        printf("Conteúdo: %s\n", segmento);
    }

    // Desvincular do segmento 
    if (shmdt(segmento) == -1) {
          perror("shmdt");
          // continuar para tentar remover o segmento 
    }

    // Remover o segmento do sistema 
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl(IPC_RMID)");
    }

    return 0;


}
 */