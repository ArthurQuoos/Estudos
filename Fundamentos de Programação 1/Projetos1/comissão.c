/*
@file: comissão.c
@date: 29/06/2021
@author: Arthur Albert Schmaiske Quoos
@brief: Aula 05 Exercício 03
*/
/*
Tendo como entrada de dados o total vendido por um funcionário no mês,
 calcule a sua comissão e o salário bruto no mês.
 Para isso, considere um salário base de R$1.200,00
 e comissão de 10% sobre o total vendido.
 */
 #include <stdio.h>
 #include <stdlib.h>

int main(){
float salario_base = 1200.00;
float vendido;
float comissao;
printf("Qual foi o total de vendas deste mes?");
scanf("%f", &vendido);
comissao = vendido / 10;
comissao = comissao + salario_base;
printf("%.2f\n",comissao);

return 0;
}
