#include <stdio.h>
#include <string.h>

#define FIELD_ROWS 42
#define FIELD_COLS 38
#define NUM_PLAYERS 11

typedef enum { PORTERO, CAMPO } POSICION;

typedef struct {
    char name[25];
    char surname[25];
    int number;
    POSICION posicion;
    int x, y;
} PLAYER;

typedef struct {
    char nameofteam[25];
    PLAYER players[NUM_PLAYERS];
} TEAM;

typedef struct {
    char field[FIELD_ROWS][FIELD_COLS];
    int ball_x, ball_y;
} FIELD;

void init_team(TEAM *team, const char *name) {
    strcpy(team->nameofteam, name);
    for (int i = 0; i < NUM_PLAYERS; i++) {
        sprintf(team->players[i].name, "Player%d", i + 1);
        strcpy(team->players[i].surname, "Apellido");
        team->players[i].number = i + 1;
        team->players[i].posicion = (i == 0) ? PORTERO : CAMPO;
    }
}

void clear_field(FIELD *field) {
    for (int i = 0; i < FIELD_ROWS; i++) {
        for (int j = 0; j < FIELD_COLS; j++) {
            field->field[i][j] = ' ';
        }
    }
}

void place_all(FIELD *field, TEAM *team1, TEAM *team2) {
    // Colocar jugadores equipo 1
    for (int i = 0; i < NUM_PLAYERS; i++) {
        int x = team1->players[i].x;
        int y = team1->players[i].y;
        if (team1->players[i].posicion == PORTERO)
            field->field[x][y] = 'A';
        else
            field->field[x][y] = 'a' + (team1->players[i].number % 26);
    }

    // Colocar jugadores equipo 2
    for (int i = 0; i < NUM_PLAYERS; i++) {
        int x = team2->players[i].x;
        int y = team2->players[i].y;
        if (team2->players[i].posicion == PORTERO)
            field->field[x][y] = 'Z';
        else
            field->field[x][y] = 'z' - (team2->players[i].number % 26);
    }

    // Colocar balón
    field->field[field->ball_x][field->ball_y] = 'B';
}

void place_players_on_field(FIELD *field, TEAM *team, int side) {
    int base_row = (side == 0) ? 1 : FIELD_ROWS - 2;
    int mirror = (side == 0) ? 1 : -1;

    int col_positions[NUM_PLAYERS] = {
        FIELD_COLS / 2,
        FIELD_COLS / 2 - 10, FIELD_COLS / 2 + 10, FIELD_COLS / 2 - 5, FIELD_COLS / 2 + 5,
        FIELD_COLS / 2 - 7, FIELD_COLS / 2 + 7, FIELD_COLS / 2,
        FIELD_COLS / 2 - 10, FIELD_COLS / 2 + 10, FIELD_COLS / 2
    };

    int row_offsets[NUM_PLAYERS] = {
        0, 3, 3, 6, 6,
        10, 10, 13,
        18, 18, 21
    };

    for (int i = 0; i < NUM_PLAYERS; i++) {
        int y = col_positions[i];
        int x = base_row + mirror * row_offsets[i];
        team->players[i].x = x;
        team->players[i].y = y;
    }
}

void place_ball_center(FIELD *field) {
    field->ball_x = FIELD_ROWS / 2;
    field->ball_y = FIELD_COLS / 2;
}

int move_player(FIELD *field, TEAM *team, int player_number, int new_x, int new_y) {
    if (new_x < 0 || new_x >= FIELD_ROWS || new_y < 0 || new_y >= FIELD_COLS)
        return 0;

    for (int i = 0; i < NUM_PLAYERS; i++) {
        if (team->players[i].number == player_number) {
            for (int j = 0; j < NUM_PLAYERS; j++) {
                if (team->players[j].x == new_x && team->players[j].y == new_y)
                    return 0;
            }
            if (field->ball_x == new_x && field->ball_y == new_y)
                return 0;
            team->players[i].x = new_x;
            team->players[i].y = new_y;
            return 1;
        }
    }
    return 0;
}

int move_ball_classic(FIELD *field, int new_x, int new_y) {
    if (new_x < 0 || new_x >= FIELD_ROWS || new_y < 0 || new_y >= FIELD_COLS)
        return 0;

    field->ball_x = new_x;
    field->ball_y = new_y;
    return 1;
}

int move_ball_futbolin(FIELD *field, int target_x, int target_y, TEAM *team) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        if (team->players[i].x == target_x && team->players[i].y == target_y) {
            field->ball_x = target_x;
            field->ball_y = target_y;
            return 1;
        }
    }
    return 0;
}

void print_field(FIELD *field, TEAM *team1, TEAM *team2) {
    clear_field(field);
    place_all(field, team1, team2);

    // Mostrar cabecera de columnas
    printf("   ");
    for (int j = 0; j < FIELD_COLS; j++) {
        printf("%02d", j);
    }
    printf("\n");

    for (int i = 0; i < FIELD_ROWS; i++) {
        printf("%02d ", i);
        for (int j = 0; j < FIELD_COLS; j++) {
            printf(" %c", field->field[i][j]);
        }
        printf("\n");
    }
}

int main() {
    FIELD field = {0};
    TEAM team1, team2;

    init_team(&team1, "Equipo A");
    init_team(&team2, "Equipo B");

    clear_field(&field);
    place_players_on_field(&field, &team1, 0);
    place_players_on_field(&field, &team2, 1);
    place_ball_center(&field);

    print_field(&field, &team1, &team2);

    printf("\nMoviendo jugador 10 del equipo 1...\n");
    move_player(&field, &team1, 10, 20, 20);

    printf("\nMoviendo balon modo futbolin a la nueva posicion...\n");
    move_ball_futbolin(&field, 20, 20, &team1);

    print_field(&field, &team1, &team2);

    return 0;
}
