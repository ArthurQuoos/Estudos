#include "Indexacao.h"


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
 
int numeroRegistros(Indice *idx) {
    char *string;
    int size, top, qtde, status;
    fseek(idx->arqDados, 0, SEEK_SET); 
    fscanf(idx->arqDados, "SIZE=%d TOP=%d QTDE=%d STATUS=%d\n", &size, &top,
      &qtde, &status);
    fseek(idx->arqDados, 0, SEEK_SET); 
    return(qtde);
}
 
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
 
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
 
 
 
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
 
char* geraChaveRegistro(char* str1, char* str2) {
    int posicao = 0;
    strcat(str1, str2);
    for(int i = 0; str1[i]; i++) {
      if(str1[i] != ' ') {
        str1[posicao++] = toupper(str1[i]);
      }
    }
    str1[posicao] = '\0';
    return(str1);
}
 
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
 
void imprimeVetorIndices(Indice *idx) {
    printf("--------------------------------\n");
    printf(" *** Vetor de Indices *** \n");
    printf("--------------------------------\n");
    int N = numeroRegistros(idx);
    for(int i = 0; i < N; i++) {
        printf("Vetor[%d] = {%s, %d}\n",
          i, idx->vetor[i].chave, idx->vetor[i].RRN);
    }
    printf("--------------\n");
}
 
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
 
void iniciaIndiceArquivo(Indice *idx, char* filename) {
 
    idx->arqDados = fopen(filename, "r+");
    idx->arqIdx   = fopen("arqIdx.txt", "w+");
 
    int N = numeroRegistros(idx);
    printf("Numero de registros = %d\n", N);
    idx->vetor = (ArrayItem*)malloc(N * sizeof(ArrayItem));
 
    int linhas = 0;
    Heroi heroi;
    char string[BUFFER];
    ArrayItem objeto;
 
    // lendo cabeçalho
    fgets(string, BUFFER, idx->arqDados);
    printf("Leitura: %s\n", string);
 
    while(!feof(idx->arqDados)) {
      if(fgets(string, BUFFER, idx->arqDados)!= NULL) {
        heroi = quebraStringEmHeroi(string);
        // printaHeroi(&heroi);
        char* chave = geraChaveRegistro(heroi.primeiroNome, heroi.sobrenome);
       
        strcpy(objeto.chave, chave);
        objeto.RRN = linhas;
        idx->vetor[linhas] = objeto;
        linhas++;
      }
    } 

    qsort(idx->vetor, linhas, sizeof(ArrayItem), comparaChave);
    gravaArquivoIndice(idx);
    rewind(idx->arqDados);
}
 
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
 
void atualizaStatusHeader(Indice *idx, int status) {
  
  int size, top, qtde, oldStatus;
  fseek(idx->arqDados, 0, SEEK_SET); 
  fscanf(idx->arqDados, "SIZE=%d TOP=%d QTDE=%d STATUS=%d\n", &size, &top,
    &qtde, &oldStatus);
  fseek(idx->arqDados, 0, SEEK_SET); 
  fprintf(idx->arqDados, "SIZE=%d TOP=%d QTDE=%d STATUS=%d\n", size, top,
    qtde, status);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
 
int comparaChave(const void *a, const void *b) {
    const ArrayItem *item1 = (const ArrayItem *)a;
    const ArrayItem *item2 = (const ArrayItem *)b;
    return strcmp(item1->chave, item2->chave); // ordem alfabética
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void gravaArquivoIndice(Indice *idx) {
    if (idx->arqIdx == NULL) {
        printf("Erro: arquivo de índice não foi aberto.\n");
        return;
    }

    int N = numeroRegistros(idx);
    for (int i = 0; i < N; i++) {
        fprintf(idx->arqIdx, "%s|%d\n", idx->vetor[i].chave, idx->vetor[i].RRN);
    }

    fflush(idx->arqIdx); // Garante que os dados sejam salvos no arquivo
    printf("Índice gravado com sucesso em arqIdx.txt\n");
}



int main(int argc, const char * argv[]) {
  Indice ed;
  // iniciaIndiceVazio(&ed);
   iniciaIndiceArquivo(&ed, "heroi.txt");
  printf("Criei indice de arquivo\n");
  imprimeVetorIndices(&ed);
 
  return 0;
}