
/*
#include <stdio.h>
#include <stdlib.h>
#define maior(x,y)x>y?x:y

  int main(){

    int a = 5, b = 8, valor;
    valor = maior(a,b);
    printf("O maior valor e %d\n",valor);

    //E equivalente a
    valor = a>b?a:b;
    printf("O maior valor e %d\n",valor);

    return 0;
  }
*/

#include <stdio.h>
#include <stdlib.h>
#define macro

int main(){

  #ifdef macro
    printf("A macro ja foi definida\n");
  #else
    printf("A macro nao foi definida\n");
  #endif

  #undef macro

  #ifdef macro
    printf("A macro ja foi definida\n");
  #else
    printf("A macro nao foi definida\n");
  #endif

return 0;
}
