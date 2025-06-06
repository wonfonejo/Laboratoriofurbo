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

void posicionar_equipo(Cancha *cancha, int equipoIndex) {
    
    if (equipoIndex)
    {
        strcpy(cancha->Espacio[37][21], cancha->equipos[1].players->number[0]);

        strcpy(cancha->Espacio[33][10], cancha->equipos[1].players->number[1]);
        strcpy(cancha->Espacio[33][17], cancha->equipos[1].players->number[2]);
        strcpy(cancha->Espacio[33][25], cancha->equipos[1].players->number[3]);
        strcpy(cancha->Espacio[33][32], cancha->equipos[1].players->number[4]);

        strcpy(cancha->Espacio[28][15], cancha->equipos[1].players->number[5]);
        strcpy(cancha->Espacio[28][21], cancha->equipos[1].players->number[6]);
        strcpy(cancha->Espacio[28][27], cancha->equipos[1].players->number[7]);

        strcpy(cancha->Espacio[23][12], cancha->equipos[1].players->number[8]);
        strcpy(cancha->Espacio[23][21], cancha->equipos[1].players->number[9]);
        strcpy(cancha->Espacio[23][30], cancha->equipos[1].players->number[10]);
    
    }else
    {
        strcpy(cancha->Espacio[0][21], cancha->equipos[0].players->number[0]);

        strcpy(cancha->Espacio[4][10], cancha->equipos[0].players->number[1]);
        strcpy(cancha->Espacio[4][17], cancha->equipos[0].players->number[2]);
        strcpy(cancha->Espacio[4][25], cancha->equipos[0].players->number[3]);
        strcpy(cancha->Espacio[4][32], cancha->equipos[0].players->number[4]);

        strcpy(cancha->Espacio[9][15], cancha->equipos[0].players->number[5]);
        strcpy(cancha->Espacio[9][21], cancha->equipos[0].players->number[6]);
        strcpy(cancha->Espacio[9][27], cancha->equipos[0].players->number[7]);

        strcpy(cancha->Espacio[14][12], cancha->equipos[0].players->number[8]);
        strcpy(cancha->Espacio[14][21], cancha->equipos[0].players->number[9]);
        strcpy(cancha->Espacio[14][30], cancha->equipos[0].players->number[10]);
       
    }
    
    
   

    
}
