#include <stdio.h>

#include <stdlib.h>




int buscaLinear(int *v, int n, int elem) {

 for(int i = 0; i < n; i++) {

 if(elem == v[i]) {

 return i;

 }

 }

 return -1;

}



int buscaOrdenada(int *v, int n, int elem){

    for (int i = 0; i < n; i++)

    { //achou

        if(elem == v[i]){

            return i;

        }

    if (v[i] > elem){ //achou numero maior do que o desejado

        return -1;

    }

} //percorreu todo o vetor

return -1;

}



int buscaBinaria(int *v, int n, int elem) {

    int inicio = 0, fim = n - 1, meio;

    while(inicio <= fim){

        meio = (inicio+fim)/2;

        if(v[meio] == elem){

            return meio;

        }else if(v[meio] < elem){

            inicio = meio+1;

    }else{

        fim = meio-1;

    }

  }

return -1;

}




int main(int argc, const char * argv[]){

int random[] = {1, 25, 3, 30, 41, 27, 17, 4, 2, 5};

int sorted[] = {1, 2, 4, 5, 17, 25, 27, 30, 31, 41};

int x;



x = buscaLinear(random,10,25);

printf("Resultado da busca linear (random) = %d\n", x);

//x = buscaLinear(sorted,10,25);

//printf("Resultado da busca linear (sorted) = %d\n", x);



//x = buscaOrdenada(random,10, 30);

//printf("Resultado da busca Ordenada (random) = %d\n", x); //geralmente nao funciona

x = buscaOrdenada(sorted,10, 30);

printf("Resultado da busca Ordenada (sorted) = %d\n", x); 



//x = buscaBinaria(random, 10, 30);

//printf("Resultado da busca Binaria (random) = %d\n", x); //geralmente nao funciona

x = buscaBinaria(sorted, 10, 30);

printf("Resultado da busca Binaria (sorted) = %d\n", x);



return 0;

}

 

//===========================================================

/* //python



def busca_linear(v, elem):

    for i in range(len(v)):

        if v[i] == elem:

            return i

    return -1



def busca_ordenada(v, elem):

    for i in range(len(v)):

        if v[i] == elem:

            return i

        if v[i] > elem:

            return -1

    return -1



def busca_binaria(v, elem):

    inicio, fim = 0, len(v) - 1

    while inicio <= fim:

        meio = (inicio + fim) // 2

        if v[meio] == elem:

            return meio

        elif v[meio] < elem:

            inicio = meio + 1

        else:

            fim = meio - 1

    return -1



def main():

    random = [1, 25, 3, 30, 41, 27, 17, 4, 2, 5]

    sorted_v = [1, 2, 4, 5, 17, 25, 27, 30, 31, 41]



    x = busca_linear(random, 25)

    print(f"Resultado da busca linear (random) = {x}")



    # x = busca_linear(sorted_v, 25)

    # print(f"Resultado da busca linear (sorted) = {x}")



    # x = busca_ordenada(random, 30)

    # print(f"Resultado da busca Ordenada (random) = {x}") # geralmente nao funciona

    x = busca_ordenada(sorted_v, 30)

    print(f"Resultado da busca Ordenada (sorted) = {x}")



    # x = busca_binaria(random, 30)

    # print(f"Resultado da busca Binaria (random) = {x}") # geralmente nao funciona

    x = busca_binaria(sorted_v, 30)

    print(f"Resultado da busca Binaria (sorted) = {x}")



if __name__ == "__main__":

    main()

 

*/
