#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"

void asignar_equipo(TEAM *equipo, const char *nombre, PLAYER plantilla[], int cantidad) {
    strcpy(equipo->nameofteam, nombre);
    equipo->numberofplayers = cantidad;
    equipo->players = malloc(cantidad * sizeof(PLAYER));
    if (equipo->players == NULL) {
        printf("Error al asignar memoria\n");
        exit(1);
    }
    memcpy(equipo->players, plantilla, cantidad * sizeof(PLAYER));
}

void posicionar_equipo(Cancha *cancha, int equipoIndex, int invertido) {
    TEAM *equipo = &cancha->equipos[equipoIndex];
    PLAYER *jugadores = equipo->players;

    // Columnas donde se posicionan los jugadores
    int columnas[] = {5, 12, 21, 30};  // portero, defensas, medios, delanteros

    if (invertido) {
        columnas[0] = 36;
        columnas[1] = 29;
        columnas[2] = 20;
        columnas[3] = 11;
    }

    int fila_portero = 19;
    int filas_def[4] = {13, 16, 22, 25};
    int filas_med[3] = {14, 19, 24};
    int filas_del[3] = {16, 19, 22};

    int idx = 0;

    // Portero
    cancha->Espacio[fila_portero][columnas[0]] = jugadores[idx++].number + '0';
    

    // Defensas
    for (int i = 0; i < 4; i++)
        cancha->Espacio[filas_def[i]][columnas[1]] = jugadores[idx++].number + '0';


    
    // Mediocampistas
    for (int i = 0; i < 3; i++)
        cancha->Espacio[filas_med[i]][columnas[2]] = jugadores[idx++].number + '0';
    
    // Delanteros
    for (int i = 0; i < 3; i++)
        cancha->Espacio[filas_del[i]][columnas[3]] = jugadores[idx++].number + '0';
}
