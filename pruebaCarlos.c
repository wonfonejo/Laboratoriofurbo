
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILAS 38
#define COLUMNAS 42

typedef struct {
    char name[25];
    char surname[25];
    int number;
} PLAYER;

typedef struct {
    char nameofteam[25];
    int numberofplayers;
    PLAYER *players;
} TEAM;

typedef struct Cancha
{
    TEAM equipos[2];
    char Balon;
    char Espacio[38][42][2];

} Cancha;


void Inicializar_cancha(Cancha *cancha)
{
    
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            strcpy(cancha->Espacio[i][j], "  ");
        }
    }
    
}

void Inicialzando_jugadores()
{
    
}

int main() {
    Cancha cancha;


    printf("Hello, World!\n");
    return 0;
}