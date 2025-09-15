#include <stdio.h>
#include <stdlib.h>
/*
void criaHeap(int *v, int inicio, int fim){
    int aux = v[inicio];
    int filho = 2*inicio + 1;
    while(filho >= fim){
        if(filho < fim){
            if(v[filho] < v[filho + 1]){
                filho = filho + 1;
            }
        }
        if(aux > v[filho]){
            v[inicio] = v[filho];
            inicio = filho;
            filho = 2*inicio + 1;
        }else{
            filho = fim + 1;
        }
    }
    v[inicio] = aux;
}*/

void criaHeap(int *v, int inicio, int fim, int x){
    int aux = v[inicio];
    int filho = 2*inicio + 1;

    if(x==1){ // 1 para decrescente (min-heap)
        while(filho <= fim){
            if(filho < fim){
                if(v[filho] > v[filho + 1]){ // menor filho
                    filho = filho + 1;
                }
            }
            if(aux > v[filho]){ // min-heap: pai maior que filho
                v[inicio] = v[filho];
                inicio = filho;
                filho = 2*inicio + 1;
            }else{
                break;
            }
        }
        v[inicio] = aux;
    }else if(x==0){ // 0 para crescente (max-heap)
        while(filho <= fim){
            if(filho < fim){
                if(v[filho] < v[filho + 1]){ // maior filho
                    filho = filho + 1;
                }
            }
            if(aux < v[filho]){ // max-heap: pai menor que filho
                v[inicio] = v[filho];
                inicio = filho;
                filho = 2*inicio + 1;
            }else{
                break;
            }
        }
        v[inicio] = aux;
    }
}

void heapSort(int *v, int n,int x){
    int i, aux, y = x;
    for(i = (n-1)/2; i >= 0; i--){
        criaHeap( v, i, n-1,y);
    }
    for (i = n-1;i >= 1; i--){
        aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        criaHeap(v, 0, i-1,x);
    }
    
}

int main(){
int sorted[] = {1, 25, 3, 30, 41, 27, 17, 4, 2, 4};
heapSort(sorted,10,0);
printf("Vetor ordenado em ordem decrescente (heapSort):\n");  
for (size_t i = 0; i < 10; i++)
{
    printf("%d ",sorted[i]);
}

heapSort(sorted,10,1);
printf("Vetor ordenado em ordem crescente (heapSort):\n");  
for (size_t i = 0; i < 10; i++)
{
    printf("%d ",sorted[i]);
}



    return 0;
}