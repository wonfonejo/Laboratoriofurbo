#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

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

typedef struct {
    TEAM equipos[2];
    char Balon;
    char Espacio[38][42];
} Cancha;

#endif
