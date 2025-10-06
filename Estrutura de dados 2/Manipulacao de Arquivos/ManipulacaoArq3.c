#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arq;
    char linha[101];  // Para leitura dos dados em blocos
    char frase[101];  // Para a frase que o usuário vai digitar
    size_t tamanho_lido;  // Variável para armazenar o número de bytes lidos
    char c;
    int opcao; 

    // Abre o arquivo para leitura e escrita (sem apagar conteúdo)
    arq = fopen("arqmos.txt", "r+b");  // "r+b" para leitura e escrita binária
    if (arq == NULL) {
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }

    printf("Conteudo atual do arquivo:\n");

    // Leitura do arquivo usando fread()
    // Vamos ler em blocos de 100 caracteres
    while ((tamanho_lido = fread(linha, sizeof(char), sizeof(linha) - 1, arq)) > 0) {
        linha[tamanho_lido] = '\0';  // Garantir que a string lida é bem formada
        printf("%s", linha);  // Exibe o conteúdo do arquivo
    }

    do{
    // Solicita uma frase ao usuário
    printf("\nDigite uma frase (ate 100 caracteres):\n");
    fgets(frase, sizeof(frase), stdin);  // Lê a frase com fgets()

    // Remove o \n da frase, se houver
    frase[strcspn(frase, "\n")] = '\0';

    // Grava a frase no arquivo usando fwrite()
    if (fwrite(frase, sizeof(char), strlen(frase), arq) != strlen(frase)) {
        printf("Erro ao gravar a frase no arquivo.\n");
        fclose(arq);
        exit(1);
    }
     printf("Frase gravada com sucesso!\n");

    // Adiciona uma nova linha ao final da frase
    fputc('\n', arq);
    printf("Deseja gravar mais uma frase? (1-sim/2-nao)\n");
    scanf("%d",&opcao);
    while ((c = getchar()) != '\n' && c != EOF);//limpar buffer
    }while(opcao == 1);


    rewind(arq);
        printf("Resultado Final:\n");
        while ((tamanho_lido = fread(linha, sizeof(char), sizeof(linha) - 1, arq)) > 0) {
        linha[tamanho_lido] = '\0';  // Garantir que a string lida é bem formada
        printf("%s", linha);  // Exibe o conteúdo do arquivo
    }

    fclose(arq);  // Fecha o arquivo
    return 0;
}
