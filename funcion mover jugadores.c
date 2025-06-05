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

   
   
 int main(){
   mover_jugador(&cancha, &equipo1, 10, 20, 20);
 }

