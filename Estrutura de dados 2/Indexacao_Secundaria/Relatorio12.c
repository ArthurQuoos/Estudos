//---------------- Estrutura básica Índice Secundário - abaixo ----------------------
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SIZE_PK 40              // tamanho maximo de chave primaria

typedef struct{
  int size;
  int top;
  int qtde;
  int status;
} HeaderInfo;

#define BUFFER 150
 
typedef struct {
  char primeiroNome[BUFFER];
  char sobrenome[BUFFER];
  char nomeHeroi[BUFFER];
  char poder[BUFFER];
  char fraqueza[BUFFER];
  char cidade[BUFFER];
  char profissao[BUFFER];
} Heroi;

typedef struct {
  char chavePrimaria[MAX_SIZE_PK];  // chavePrimaria (titulo + artista)
  int RRN;       // RRN
} ItemArrayPrimario;

typedef struct {
  char chavePrimaria[MAX_SIZE_PK];
  char chaveSecundaria[15];
} ItemArraySecundario;

typedef struct {
  FILE *arqDados;         // arquivo com os dados (brutos/reais)
  FILE *arqIdxPrimario;   // arquivo de dump do indice primario
  FILE *arqIdxSecundario; // arquivo de dump do indice secundario (generos)
  ItemArrayPrimario *arrayPrimario;     //arrayPrimario
  ItemArraySecundario *arraySecundario; //arraySecundario
} IndiceSecundario;

// -----------------------------------------
// -----------------------------------------

char* criarChavePrimaria(char* primeiroNome, char* sobrenome) {
  // concatena, maiusculo
  char* chave = malloc(MAX_SIZE_PK * sizeof(char));
  strcpy(chave, primeiroNome);
  strcat(chave, sobrenome);
  // printf("Merge = %s\n", chave);
  for(int i = 0; i < strlen(chave); i++) {
    chave[i] = toupper(chave[i]);
  }

  return(chave);
}

// -----------------------------------------
// -----------------------------------------

char* criarChaveSecundaria(char* cidade) {
  for (int i = 0; i < strlen(cidade); i++) {
    cidade[i] = toupper(cidade[i]);
  }
  return(cidade);
}

// -----------------------------------------
// -----------------------------------------

// leitura da quantidade de registros (cabecalho)
HeaderInfo numeroRegistrosCabecalho(IndiceSecundario *idx) {
  // garante: cabeçote está no começo do arquivo
  fseek(idx->arqDados, 0, SEEK_SET);
  HeaderInfo ret;
  fscanf(idx->arqDados, "SIZE=%d TOP=%d QTDE=%d STATUS=%d\n", &ret.size,
    &ret.top, &ret.qtde, &ret.status);
  return(ret);
}

// -----------------------------------------
// -----------------------------------------

Heroi quebraStringEmHeroi(char *string) {
    Heroi ret;
    char* aux = strtok(string, "|\n");
    strcpy(ret.primeiroNome, aux);
    aux = strtok(NULL, "|\n");
    strcpy(ret.sobrenome, aux);
    aux = strtok(NULL, "|\n");
    strcpy(ret.nomeHeroi, aux);
    aux = strtok(NULL, "|\n");
    strcpy(ret.poder, aux);
    aux = strtok(NULL, "|\n");
    strcpy(ret.fraqueza, aux);
    aux = strtok(NULL, "|\n");
    strcpy(ret.cidade, aux);
    aux = strtok(NULL, "|\n");
    strcpy(ret.profissao, aux);
    return (ret);
}

// -----------------------------------------
// -----------------------------------------


// ordernar indice primario
// ordernar indice secundario
// atualizar o status do arqDados
// leitura de registro -> Musica (artista, titulo, genero)
// gravar indice primario no arquivo primario
// gravar indice secundario no arquivo secundario

// -----------------------------------------
// -----------------------------------------


void iniciaIndiceSecundario(IndiceSecundario *ds, char* nomeArquivo) {

  // abrir os arquivos
  ds->arqDados         = fopen(nomeArquivo, "r+");
  ds->arqIdxPrimario   = fopen("indicePrimario.txt", "w+");
  ds->arqIdxSecundario = fopen("IndiceSecundario.txt", "w+");

  // descobrir qtde de registros no arquivo de arqDados
  HeaderInfo info = numeroRegistrosCabecalho(ds);
  printf("Numero de Registros: %d\n", info.qtde);

  // alocar memoria do arrayPrimario
  ds->arrayPrimario   = malloc(info.qtde * sizeof(ItemArrayPrimario));
  // alocar memoria do arraySecundario
  ds->arraySecundario = malloc(info.qtde * sizeof(ItemArraySecundario));

  // Percorre o arquivo (laço):
  char linha[info.size+1];
  char keyP[MAX_SIZE_PK], keyS[MAX_SIZE_PK];
  Heroi registro;
  int RRN = 0;
  ItemArrayPrimario iap;
  ItemArraySecundario ias;

  while(fgets(linha, info.size, ds->arqDados) != NULL) {
    // iteração = registro (ano|duracao|titulo|artista|...)
    registro = quebraStringEmHeroi(linha);
    // criar chave canonica primaria
    strcpy(keyP, criarChavePrimaria(registro.primeiroNome, registro.sobrenome));

    strcpy(keyS, criarChaveSecundaria(registro.cidade));
    printf("==========================\n");
    // insere no array primario: (chave primaria | RNN)
    strcpy(iap.chavePrimaria, keyP);
    iap.RRN = RRN;
    ds->arrayPrimario[RRN] = iap;
    //     insere no array secundario (chave secundaria | chave primaria)
    strcpy(ias.chavePrimaria, keyP);
    strcpy(ias.chaveSecundaria, keyS);
    printf("keyP = %s\n", ias.chavePrimaria);
    printf("keyS = %s\n", ias.chaveSecundaria);
    ds->arraySecundario[RRN] = ias;
    RRN++;
  }

  // Ordena:
  //     ordena arraySecundario (se tiver chaves iguais, considerar a primaria)
  //     ordena arrayPrimario
  // Abrir/Criar os arquivos de dump
  //      grava o indice primario (arqIdxPrimario)
  //      grava o indice secundario (arqIdxSecundario)
  // Atualiza o STATUS do header (arq Dados) -> TRUE
}
// -----------------------------------------
// -----------------------------------------

void imprimeIndiceSecundario(IndiceSecundario *ds) {
  // int N = sizeof(ds->arraySecundario)/sizeof(ds->arraySecundario[0]);
  int N = numeroRegistrosCabecalho(ds).qtde;
  // percorrer e imprimir as posicoes dos vetores
  ItemArrayPrimario iap;
  ItemArraySecundario ias;
  printf("====================================\n");
  printf(" IDX PRIM | IDX SEC\n");
  printf("====================================\n");
  printf("N = %d\n", N);
  for(int i = 0; i < N; i++) {
    iap = ds->arrayPrimario[i];
    ias = ds->arraySecundario[i];
    printf("%d: [%s | %d] [%s | %s]\n", i, iap.chavePrimaria, iap.RRN,
      ias.chaveSecundaria, ias.chavePrimaria);
  }
  printf("====================================\n");

}

// -----------------------------------------
// -----------------------------------------

void destroiIndiceSecundario(IndiceSecundario *ds) {
    // verifica se não está atualizado no arquivo
    //      gravar os indices nos arquivos de dump
    // desalocar os vetores (arrayPrimario, arraySecundario)
    // fechar os arquivos (dumps, dados)
}

// -----------------------------------------
// -----------------------------------------

int main(int argc, char *argv[]) {
  IndiceSecundario secondIdx;
  // Inicia Indice Secundario baseado no arquivo já existente
  iniciaIndiceSecundario(&secondIdx, "heroi.txt");
  imprimeIndiceSecundario(&secondIdx);
  // destroiIndiceSecundario(&secondIdx);
  return 0;
}
