
#include <stdio.h>
#include <stdlib.h>

//NoArvo -> PtrNoArvo
typedef struct NoArvo *PtrNoArvo;
//NoArvore
typedef struct NoArvore{
    //information (int)
    int chave;
    //filho a esquerda 
    PtrNoArvo esquerda;
    //Filho a direita
    PtrNoArvo direita;
}NoArvo;

PtrNoArvo raiz; // main

/*
76 -17 15 50 -90 36 -62 29 38 71 2 25 91 6 84 -3 -96 -47 -88 8

-57 -61 33 -6 -38 38 -44 -7 21 60 22 -3 76 -75 -20 6 65 52 -98 -96
https://portaldoprofessor.fct.unesp.br/projetos/cadilag/apps/structs/arv_binaria.php

*/