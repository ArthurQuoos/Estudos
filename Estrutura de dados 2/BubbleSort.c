//1

int* buscaLinear(int *v, int n, int elem,int *qtd) {
int* vetor = (int*)malloc(n * sizeof(int));
   int x = 0;
for(int i = 0; i < n; i++) {
if(elem == v[i]) {
 vetor[x] = i;
 x++;
}
 }
  *qtd = x;
  return vetor;
}

int main(int argc, const char * argv[]){
int qtd;
int random[] = {1, 25, 3, 4, 41, 27, 4, 4, 2, 4};

int* posicoes = buscaLinear(random,10,4,&qtd);


printf("O numero procurado aparece na posicao:\n");
for (int i = 0; i < qtd; i++){
     printf("%d\n", posicoes[i]);
}


return 0;
}

 
/*
//2
void swap(int *a, int *b) {
int tmp = *a;
*a = *b;
*b = tmp;
}
void bubbleSort(int *v, int n) {
bool changed = true;
while(changed) {
  changed = false;
  for(int i = 0; i < n-1; i++) {
    if(v[i] > v[i+1]) {
    swap(&v[i], &v[i+1]);
    changed = true;
      }
    }
  }
}

int main(int argc, const char * argv[]){
int sorted[] = {1, 25, 3, 30, 41, 27, 17, 4, 2, 4};

bubbleSort(sorted,10);
printf("Resultado do BubbleSort\n");
for (int i = 0; i < 10; i++){
  printf("%d, ",sorted[i]);
}
return 0;
}

*/
/*
//3
void swap(int *a, int *b) {
 int tmp = *a;
 *a = *b;
 *b = tmp;
}
int bubbleSort2(int *v, int n,int x) {
 bool changed = true;
 int contadorAlteracoes = 0;
 if(x == 0){
 while(changed) {
    changed = false;
    for(int i = 0; i < n-1; i++) {
        if(v[i] > v[i+1]) {
        swap(&v[i], &v[i+1]);
        changed = true;
        contadorAlteracoes++;
             }
         }
    }
    }else{
         while(changed) {
    changed = false;
    for(int i = 0; i < n-1; i++) {
        if(v[i] < v[i+1]) {
        swap(&v[i], &v[i+1]);
        changed = true;
        contadorAlteracoes++;
             }
         }
    }
    }
    return contadorAlteracoes;
 }
 
 
int main(int argc, const char * argv[]){
int sorted[] = {1, 25, 3, 30, 41, 27, 17, 4, 2, 4};
int contadorAlteracoes = bubbleSort2(sorted,10,0); //0 para crescente, 1 para decrescente
printf("Resultado do BubbleSort\n");
for (int i = 0; i < 10; i++){
    printf("%d, ",sorted[i]);
}
    printf("Quantas alteracoes: %d",contadorAlteracoes);
 
return 0;
}
*/