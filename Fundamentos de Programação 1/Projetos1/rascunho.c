#include <stdio.h>
#include <stdlib.h>

int main(){
int x;

printf("Oque fazer");
scanf("%d",&x);
int a = x *3;
for(x;x<0;){
printf("Erro");
scanf("%d",&x);
}
if(x % 2==0){
  printf("-1");
}else{
  printf("%d\n",a);
}








  return 0;
}
