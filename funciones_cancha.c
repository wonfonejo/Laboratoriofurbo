#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"


#define FILAS 38
#define COLUMNAS 42

void inicializar_cancha(Cancha *cancha) {
    
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            strcpy(cancha->Espacio[i][j], "  ");
        }
    }
}
