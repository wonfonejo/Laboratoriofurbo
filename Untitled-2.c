
typedef enum{
    Portero,
    campo
} posicion;

typedef struct {
    char name {20};
    int number;
    Posicion posicion;
    int x, y; 
} Player;

typedef struct{
    char teamname{20};
    Player player[11];
} Equipo;

typedef struct {

    char cancha[38][42];
    int bolax, bolay
} cancha



void incializar_equipo(Equipo *equipo, const char *){

}


void inicializar_jugadores(){

}

void inicializar_bola(){

}

int mover_jugador(){

}

int mover_balon(){

}

void imprimir_juego(){
    
}
int main(){
    
}