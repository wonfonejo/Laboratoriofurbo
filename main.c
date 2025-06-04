#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#include "mostrar_cancha.c"
#include "funciones_equipo.c"
#include "funciones_cancha.c"

void inicializar_cancha(Cancha *cancha);
void asignar_equipo(TEAM *equipo, const char *nombre, PLAYER plantilla[], int cantidad);
void posicionar_equipo(Cancha *cancha, int equipoIndex, int invertido);
void mostrar_cancha(const Cancha *cancha);

int main() {
    Cancha cancha;

    
    PLAYER plantilla1[11] = {
        {"Portero1", "", 1}, {"Defensa1", "", 2}, {"Defensa2", "", 3}, {"Defensa3", "", 4}, {"Defensa4", "", 5},
        {"Medio1", "", 6}, {"Medio2", "", 7}, {"Medio3", "", 8},
        {"Delantero1", "", 9}, {"Delantero2", "", 10}, {"Delantero3", "", 11}
    };

    PLAYER plantilla2[11] = {
        {"Portero2", "", 1}, {"Defensa1", "", 2}, {"Defensa2", "", 3}, {"Defensa3", "", 4}, {"Defensa4", "", 5},
        {"Medio1", "", 6}, {"Medio2", "", 7}, {"Medio3", "", 8},
        {"Delantero1", "", 9}, {"Delantero2", "", 10}, {"Delantero3", "", 11}
    };

    
    inicializar_cancha(&cancha);

    
    asignar_equipo(&cancha.equipos[0], "Local FC", plantilla1, 11);
    asignar_equipo(&cancha.equipos[1], "Visitante FC", plantilla2, 11);
    posicionar_equipo(&cancha, 0, 0);  
    posicionar_equipo(&cancha, 1, 1);

    
    mostrar_cancha(&cancha);

    
    free(cancha.equipos[0].players);
    free(cancha.equipos[1].players);

    return 0;
}

// La parte de la cancha se hara en base a el codigo de los laboratorios de ajedrez (coordenas).

// Una persona se encarga de campo de juego,equipos y jugadores; otra de colocar los 11 jugadores en un campo y la ultima de crear el balon y moverlo por el campo

// la cancha debe ser de 38 y 42 metros. Las coordenadas de los jugadores en la cancha funcionan recorriendo un espacio en x,y de 1 m. ]

// 2 idas para mover la bola, ambas con coordenas del campo de juego. La primera es tipo "futbolin", en donde la bola verifica que la en la casilla de la cancha haya un jugador para que el movimiento sea valido; y la otra es tipo "clasico", en donde solo tiene que estar en el la cancha (la matriz de 38x42)

// el main incluye colocar 11 jugadores por equipo en un campo de juego, una funcion que reciba coordenadas para mover los jugadores y una que reciba coordenadas para mover el balon.

//El programa debe tener: formas de crear los 11 jugadores: atributos de equipo y posicion (portero y jugador de campo). Un campo definido como una matriz 38 por 42, formas de asignar jugadores al campo, inicializarlos y moverlos en los terminos de este.

