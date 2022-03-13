#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//calcular a gasolina usada pela f�rmula distancia = tempo * velocidade

int main(){
  setlocale(LC_ALL,"Portuguese");
  float temp_min, vel_media, dist, litros, kmporlitro, temp_hora;
  temp_hora = 60;
  temp_min = 35; //35 minutos > converter o tempo em horas > dividir por 60
  vel_media = 80;
  kmporlitro = 12;
  printf("Tempo: %.2f ",temp_min);
  printf("velocidade m�dia: %.2f ", vel_media);
  printf("kilometros por litro: %.2f \n", kmporlitro);
  temp_hora = temp_min / temp_hora;
  dist = temp_hora * vel_media;
  litros = dist / kmporlitro;

  printf("litros usados: %.2f\n", litros);
    return 0;





}
