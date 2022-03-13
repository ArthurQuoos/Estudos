#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*Faça um programa com 2 variáveis, A e B, onde A terá
o valor 40 e B terá o valor -1. Imprima o valor de A+B, A-B,
AxB e A/B. Em seguida, faça B incrementar de uma
unidade e repita as 4 operações. */

int main(){
  float a, b, c;
  a = 40;
  b = -1;
  c = a + b;
  printf("%.2f\n", c);
  c = a - b;
  printf("%.2f\n", c);
  c = a * b;
  printf("%.2f\n", c);
  c = a / b;
  printf("%.2f\n", c);
  b = ++b;
  printf("%.2f\n", b);

  c = a + b;
  printf("%.2f\n", c);
  c = a - b;
  printf("%.2f\n", c);
  c = a * b;
  printf("%.2f\n", c);
  c = a / b;
  printf("%.2f\n", c);
  b = ++b;
  printf("%.2f\n", b);
  return 0;







}
