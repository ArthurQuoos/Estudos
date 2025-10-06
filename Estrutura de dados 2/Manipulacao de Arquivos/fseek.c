#include <stdio.h>
#include <stdlib.h>

struct pessoa{
    char nome[30];
    int idade;
    float peso;
};

int main(){
    FILE *arquivo;
    
    arquivo = fopen("RegistroDeDados.txt","wb");
    if(arquivo == NULL){
        printf("ERRO na abertura\n");
        exit(1);
    }
    for(int i = 0;i < 4;i++){ //Criando e registrando no arquivo
        struct pessoa p1; //temporario
        
        printf("Digite o nome:\n");
        scanf("%s",&p1.nome);
        printf("Digite a idade:\n");
        scanf("%d",&p1.idade);
        printf("Digite o peso:\n");
        scanf("%f",&p1.peso);

        fwrite(&p1,sizeof(struct pessoa),1,arquivo);
    }
    fclose(arquivo);

    arquivo = fopen("RegistroDeDados.txt","rb");
        if(arquivo == NULL){
        printf("ERRO na abertura\n");
        exit(1);
    }
    
    struct pessoa p1;

 /*   while(!feof(arquivo)){ //exibe oque esta no arquivo
        if(fread(&p1,sizeof(struct pessoa),1,arquivo)==1){
            printf("Nome: %s\nIdade: %d\nPeso: %f\n",p1.nome,p1.idade,p1.peso);
            printf("----------------------------------------------------\n");
        };
    }*/

    fseek(arquivo, sizeof(struct pessoa), SEEK_SET);
    fread(&p1,sizeof(struct pessoa), 1, arquivo);
    printf("Nome: %s\nIdade: %d\nPeso: %f\n",p1.nome,p1.idade,p1.peso);

    fclose(arquivo);

    return 0;
}