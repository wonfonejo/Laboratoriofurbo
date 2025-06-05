
#include <stdio.h>
#include <string.h>

typedef enum {
    Portero,
    Campo
} Posicion;

typedef struct {
    char name[20];
    int number;
    Posicion posicion;
    int x, y;
} Player;

typedef struct {
    char teamname[20];
    Player player[11];
} Equipo;

typedef struct {
    char cancha[42][38];
    int bolax, bolay;
} Cancha;

void inicializar_equipo(Equipo *equipo, const char *nombre) {
    strcpy(equipo->teamname, nombre);
    for (int i = 0; i < 11; i++) {
        sprintf(equipo->player[i].name, "Player%d", i + 1);
        equipo->player[i].number = i + 1;
        equipo->player[i].posicion = (i == 0) ? Portero : Campo;
    }
}

void limpiar_cancha(Cancha *cancha) {
    for (int i = 0; i < 42; i++) {
        for (int j = 0; j < 38; j++) {
            cancha->cancha[i][j] = ' ';
        }
    }
}

void colocar_todo(Cancha *cancha, Equipo *equipo1, Equipo *equipo2) {
    for (int i = 0; i < 11; i++) {
        int x = equipo1->player[i].x;
        int y = equipo1->player[i].y;
        cancha->cancha[x][y] = (equipo1->player[i].posicion == Portero) ? 'A' : 'a' + (equipo1->player[i].number % 26);
    }
    for (int i = 0; i < 11; i++) {
        int x = equipo2->player[i].x;
        int y = equipo2->player[i].y;
        cancha->cancha[x][y] = (equipo2->player[i].posicion == Portero) ? 'Z' : 'z' - (equipo2->player[i].number % 26);
    }
    cancha->cancha[cancha->bolax][cancha->bolay] = 'B';
}

void colocar_jugadores(Equipo *equipo, int lado) {
    int fila_base = (lado == 0) ? 1 : 42 - 2;
    int direccion = (lado == 0) ? 1 : -1;

    int columnas[11] = {
        38 / 2,
        38 / 2 - 10, 38 / 2 + 10,
        38 / 2 - 5, 38 / 2 + 5,
        38 / 2 - 7, 38 / 2 + 7,
        38 / 2,
        38 / 2 - 10, 38 / 2 + 10,
        38 / 2
    };

    int filas[11] = {
        0, 3, 3,
        6, 6, 10, 10,
        13, 18, 18, 21
    };

    for (int i = 0; i < 11; i++) {
        equipo->player[i].x = fila_base + direccion * filas[i];
        equipo->player[i].y = columnas[i];
    }
}

void inicializar_bola(Cancha *cancha) {
    cancha->bolax = 42 / 2;
    cancha->bolay = 38 / 2;
}

int mover_jugador(Cancha *cancha, Equipo *equipo, int numero_jugador, int nuevo_x, int nuevo_y) {
    if (nuevo_x < 0 || nuevo_x >= 42 || nuevo_y < 0 || nuevo_y >= 38)
        return 0;

    for (int i = 0; i < 11; i++) {
        if (equipo->player[i].number == numero_jugador) {
            for (int j = 0; j < 11; j++) {
                if (equipo->player[j].x == nuevo_x && equipo->player[j].y == nuevo_y)
                    return 0;
            }
            if (cancha->bolax == nuevo_x && cancha->bolay == nuevo_y)
                return 0;
            equipo->player[i].x = nuevo_x;
            equipo->player[i].y = nuevo_y;
            return 1;
        }
    }
    return 0;
}

int mover_balon(Cancha *cancha, int nuevo_x, int nuevo_y, Equipo *equipo1, Equipo *equipo2) {
    if (nuevo_x < 0 || nuevo_x >= 42 || nuevo_y < 0 || nuevo_y >= 38)
        return 0;

    for (int i = 0; i < 11; i++) {
        if ((equipo1->player[i].x == nuevo_x && equipo1->player[i].y == nuevo_y) ||
            (equipo2->player[i].x == nuevo_x && equipo2->player[i].y == nuevo_y)) {
            return 0;
        }
    }

    cancha->bolax = nuevo_x;
    cancha->bolay = nuevo_y;
    return 1;
}

void imprimir_cancha(Cancha *cancha, Equipo *equipo1, Equipo *equipo2) {
    limpiar_cancha(cancha);
    colocar_todo(cancha, equipo1, equipo2);

    printf("   ");
    for (int j = 0; j < 38; j++) {
        printf("%02d", j);
    }
    printf("\n");

    for (int i = 0; i < 42; i++) {
        printf("%02d ", i);
        for (int j = 0; j < 38; j++) {
            printf(" %c", cancha->cancha[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Cancha cancha = {0};
    Equipo equipo1, equipo2;

    inicializar_equipo(&equipo1, "Equipo A");
    inicializar_equipo(&equipo2, "Equipo B");

    limpiar_cancha(&cancha);
    colocar_jugadores(&equipo1, 0);
    colocar_jugadores(&equipo2, 1);
    inicializar_bola(&cancha);

    imprimir_cancha(&cancha, &equipo1, &equipo2);

    printf("\nMoviendo jugador 10 del equipo 1...\n");
    mover_jugador(&cancha, &equipo1, 10, 20, 20);

    printf("\nMoviendo balón a la posición (20, 21)...\n");
    mover_balon(&cancha, 20, 21, &equipo1, &equipo2);

    imprimir_cancha(&cancha, &equipo1, &equipo2);

    return 0;
}
