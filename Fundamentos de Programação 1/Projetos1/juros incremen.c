#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//calcular juros incrementando mes por mes
int main(){
float m, c, e;
c = 500;
e = 1;
m = c * pow (1.01, e);
e = ++e;
printf("resultado: %f\n", m);
m = c * pow (1.01, e);
e = ++e;
printf("resultado: %f\n", m);
m = c * pow (1.01, e);
e = ++e;
printf("resultado: %f\n", m);
m = c * pow (1.01, e);
e = ++e;
printf("resultado: %f\n", m);
m = c * pow (1.01, e);
e = ++e;
printf("resultado: %f\n", m);
m = c * pow (1.01, e);
e = ++e;
printf("resultado: %f\n", m);
m = c * pow (1.01, e);
e = ++e;
printf("resultado: %f\n", m);
printf("expoente: %f \n", e);


return 0;
