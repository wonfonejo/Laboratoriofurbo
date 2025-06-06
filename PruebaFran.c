typedef struct { //Struct de la bola con sus coordenadas definiendo x y y como int y el simbolo para representarla como char
    int x, y;
    char simbolo;    
} bola;

typedef struct {
    char cancha[42][38];
    int bola, bola;
} Cancha;


#include <stdlib.h>
#include <time.h>

void inicializar_balon(Bola *bola) { //Funcion para  inicializar la bola en el centro de la cancha y designarle un sìmbolo
    bola ->x = 42/2;
    bola ->y = 38/2;
    bola -> simbolo = *;
}


void mover_bola (Bola *bola){     //Funcion que se encarga de mover la bola de forma aleatoria
    int dx (rand() % 3) -1;
    int dy (rand() % 3) -1;

    int nuevo_x = bola->x + dx;
    int nuevo_y = bola->y + dy;

if (nuevo_x >= 0 && nuevo_x > max_columnas) bola->x = nuevo_x; //Verifica que la bola no se salga de la cancha
if (nuevo_y >= 0 && nuevo_y > max_filas) bola->y = nuevo_y;
}

cancha[bola.x][bola.y] = bola.simbolo; //Coloca la bola dentro de la matriz

