#include <stdio.h>
#include "estructuras.h"

void mostrar_cancha(const Cancha *cancha) {
    for (int i = 0; i < 38; i++) {
        for (int j = 0; j < 42; j++) {
            printf("%c", cancha->Espacio[i][j]);
        }
        printf("\n");
    }
}
