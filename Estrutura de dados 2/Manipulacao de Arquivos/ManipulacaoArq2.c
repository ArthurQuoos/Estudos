/*
2) Implemente um algoritmo em C, que faça a Leitura do arquivo 
chamado arqmos.txt , cadeia por cadeia (string) - função fgets

Após a leitura do arquivo, o  programa deve solicitar ao 
usuário para digitar uma frase de 100 caracteres  e após 
isso deve ser inserido no arquivo, usando a função fputs.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arq;
    char linha[101];   // Para leitura das linhas do arquivo
    char frase[101];   // Para a frase que o usuário vai digitar
    char c; //variavel para limpar buffer
    int opcao;

    // Abre o arquivo para leitura e escrita (sem apagar conteúdo)
    arq = fopen("arqmos.txt", "r+");  // 
    if (arq == NULL) {
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }

    printf("Conteudo atual do arquivo:\n");
    // Leitura do arquivo linha por linha
    while (fgets(linha, sizeof(linha), arq) != NULL) {
        printf("%s", linha);
    }

    do{
    // Solicita uma frase ao usuário
    printf("\nDigite uma frase (até 100 caracteres):\n");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';

    // Grava a frase no arquivo com fputs
    if (fputs(frase, arq) == EOF) {
        printf("Erro ao gravar a frase no arquivo.\n");
        fclose(arq);
        exit(1);
    }

    // Adiciona uma nova linha ao final da frase
    fputc('\n', arq);

    printf("Frase gravada com sucesso!\n");
    printf("Deseja gravar mais uma frase? (1-sim/2-nao)\n");
    scanf("%d",&opcao);
    while ((c = getchar()) != '\n' && c != EOF);//limpar buffer
    }while(opcao == 1);

    rewind(arq);
    printf("Como ficou no final:\n");
    // Leitura do arquivo linha por linha
    while (fgets(linha, sizeof(linha), arq) != NULL) {
        printf("%s", linha);
    }

    printf("Fechando...\n");
    fclose(arq);
    return 0;
}