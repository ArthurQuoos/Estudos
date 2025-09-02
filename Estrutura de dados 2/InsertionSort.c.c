#include <stdio.h>
#include <stdlib.h>

//1
void insertionSort(int *v, int n) {
 int i, j, chosen;
 int contador = 0;
 for(i = 1; i < n; i++) {
 chosen = v[i];
 j = i-1;
 //procurar os valores que podem trocar uma posição para a frente
 while(j>=0 && chosen < v[j]) {
 v[j+1] = v[j];
 j = j-1;
 contador++;
 }
 // move o elemento para novo lugar
 v[j+1] = chosen;
 
 }
 printf("Numero de trocas: %d.\n",contador);
}

//2
void insertionSortDecrescente(int *v, int n) {
 int i, j, chosen;
 int contador = 0;
 for(i = 1; i < n; i++) {
 chosen = v[i];
 j = i-1;
 //procurar os valores que podem trocar uma posição para a frente
 while(j>=0 && chosen > v[j]) {
 v[j+1] = v[j];
 j = j-1;
 contador++;
 }
 // move o elemento para novo lugar
 v[j+1] = chosen;
 
 }
 printf("Numero de trocas: %d.\n",contador);
}

/*#######################################
Exercicio 3
1. Insertion Sort
2. Selection Sort
3. Bubble sort
-------------------------------------------------
A. Consiste em selecionar o menor item e colocar na primeira posição, selecionar o segundo menor item e colocar na segunda posição, segue estes passos até que reste um único elemento.
B. Consiste em cada passo, a partir do segundo elemento, selecionar o próximo item da sequência e colocá-lo no local apropriado de acordo com o critério de ordenação.
C. Percorre o vetor diversas vezes e, a cada passagem faz flutuar para o topo o maior elemento da sequência
  RESPOSTA: 1B - 2A - 3C.
 -------------------------------------------------
Exercicio 4
Exercício 4) A ordenação é uma operação comum em muitas aplicações. Muitos algoritmos foram desenvolvidos para executá-la. Sobre alguns desses algoritmos, é correto afirmar (somente 1 correta):
-------------------------------------------------
A)  X  o insertion sort troca dois elementos adjacentes se estiverem fora de ordem, repetindo esse procedimento até que os itens estejam ordenados.
B)  X  o selection sort divide os itens em dois segmentos, ordena-os individualmente e depois mescla-os.
C)  C  o quick sort particiona os itens em dois segmentos separados por um elemento pivô e ordena-os recursivamente.
D)  X  o bubble sort busca um elemento fora de ordem em elementos sucessivos, depois insere o item no local apropriado.
  
#########################################*/
int main(){
    
    int vetor[] = {4, 2, 5, 6, 3};
    int vetorDecrescente[] = {2, 3, 4, 5, 6};
    
    insertionSort(vetor,5);
        printf("Vetor ordenado: ");
    for(int i=0;i<5;i++){
        printf("%d, ",vetor[i]);
    }
    printf("\n");
    
    insertionSortDecrescente(vetorDecrescente,5);
    printf("Vetor Decrescente: ");
    for(int i=0;i<5;i++){
        printf("%d, ",vetorDecrescente[i]);
    }
    printf("\n");
    return 0;
}