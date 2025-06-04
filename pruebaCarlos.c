
#include <stdio.h>
#include <stdio.h>
#include <string.h>

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


int main() {



    printf("Hello, World!\n");
    return 0;
}