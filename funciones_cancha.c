#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"


#define FILAS 38
#define COLUMNAS 42

void inicializar_cancha(Cancha *cancha) {
    
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            cancha->Espacio[i][j] = ' ';
        }
    }

    
    for (int i = 0; i < FILAS; i++) {
        cancha->Espacio[i][0] = '|';
        cancha->Espacio[i][COLUMNAS - 1] = '|';
    }
    for (int j = 0; j < COLUMNAS; j++) {
        cancha->Espacio[0][j] = '-';
        cancha->Espacio[FILAS - 1][j] = '-';
    }

    
    cancha->Espacio[0][0] = '+';
    cancha->Espacio[0][COLUMNAS - 1] = '+';
    cancha->Espacio[FILAS - 1][0] = '+';
    cancha->Espacio[FILAS - 1][COLUMNAS - 1] = '+';

    
    for (int i = 17; i <= 20; i++)
        cancha->Espacio[i][1] = '#';

    
    for (int i = 17; i <= 20; i++)
        cancha->Espacio[i][COLUMNAS - 2] = '#';

    
    cancha->Espacio[FILAS / 2][COLUMNAS / 2] = 'O';
}
