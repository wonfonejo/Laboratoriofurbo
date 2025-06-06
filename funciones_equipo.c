#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"

void asignar_equipo(TEAM *equipo, const char *nombre, PLAYER Equipo[], int cantidad) {
    strcpy(equipo->nameofteam, nombre);
    equipo->numberofplayers = cantidad;
    equipo->players = malloc(cantidad * sizeof(PLAYER));
    if (equipo->players == NULL) {
        printf("Error al asignar memoria\n");
        exit(1);
    }
    memcpy(equipo->players, Equipo, cantidad * sizeof(PLAYER));
}

void posicionar_equipo(Cancha *cancha, int equipoIndex) {
    
    if (equipoIndex)
    {
        strcpy(cancha->Espacio[37][21], cancha->equipos[1].players[0].number);

        strcpy(cancha->Espacio[33][10], cancha->equipos[1].players[1].number);
        strcpy(cancha->Espacio[33][17], cancha->equipos[1].players[2].number);
        strcpy(cancha->Espacio[33][25], cancha->equipos[1].players[3].number);
        strcpy(cancha->Espacio[33][32], cancha->equipos[1].players[4].number);

        strcpy(cancha->Espacio[28][15], cancha->equipos[1].players[5].number);
        strcpy(cancha->Espacio[28][21], cancha->equipos[1].players[6].number);
        strcpy(cancha->Espacio[28][27], cancha->equipos[1].players[7].number);

        strcpy(cancha->Espacio[23][12], cancha->equipos[1].players[8].number);
        strcpy(cancha->Espacio[23][21], cancha->equipos[1].players[9].number);
        strcpy(cancha->Espacio[23][30], cancha->equipos[1].players[10].number);

    }else
    {
        strcpy(cancha->Espacio[0][21], cancha->equipos[0].players[0].number);

        strcpy(cancha->Espacio[4][10], cancha->equipos[0].players[1].number);
        strcpy(cancha->Espacio[4][17], cancha->equipos[0].players[2].number);
        strcpy(cancha->Espacio[4][25], cancha->equipos[0].players[3].number);
        strcpy(cancha->Espacio[4][32], cancha->equipos[0].players[4].number);

        strcpy(cancha->Espacio[9][15], cancha->equipos[0].players[5].number);
        strcpy(cancha->Espacio[9][21], cancha->equipos[0].players[6].number);
        strcpy(cancha->Espacio[9][27], cancha->equipos[0].players[7].number);

        strcpy(cancha->Espacio[14][12], cancha->equipos[0].players[8].number);
        strcpy(cancha->Espacio[14][21], cancha->equipos[0].players[9].number);
        strcpy(cancha->Espacio[14][30], cancha->equipos[0].players[10].number);

    }



}
