//Idea de codigo para mover la bola diciendo a que jugador quiero que vaya 
//Tomando como base el codigo funcional 

int mover_balon(Cancha *cancha, int nuevo_x, int nuevo_y, Equipo *equipo1, Equipo *equipo2) {
    if (nuevo_x < 0 || nuevo_x >= 42 || nuevo_y < 0 || nuevo_y >= 38)
        return 0;

    cancha->bolax = nuevo_x;
    cancha->bolay = nuevo_y;
    return 1;

// Funcion para  mover el balon sin la restriccion de que vaya a la posicion donde ya se encuentra un jugador 

}

 while (1) {
        printf("\n¿A qué jugador del equipo 1 deseas pasarle el balón? (1-11, 0 para salir): ");
        scanf("%d", &numero_jugador);

        if (numero_jugador == 0) {
            printf("Saliendo del programa...\n");
            break;
        }

        int destino_x = -1, destino_y = -1;
        for (int i = 0; i < 11; i++) {
            if (equipo1.player[i].number == numero_jugador) {
                destino_x = equipo1.player[i].x;
                destino_y = equipo1.player[i].y;
                break;
            }
        }

        if (destino_x != -1 && destino_y != -1) {
            printf("Moviendo balón al jugador %d en posición (%d, %d)...\n", numero_jugador, destino_x, destino_y);
            mover_balon(&cancha, destino_x, destino_y, &equipo1, &equipo2);
            imprimir_cancha(&cancha, &equipo1, &equipo2);
        } else {
            printf("Jugador %d no encontrado en el equipo 1.\n", numero_jugador);
        }
    }

    return 0;

    //While que pregunta a que jugador le quiero enviar el balon y recibe un numero del 1-11
    //Si el numero es 0 se sale del programa y si es diferente de los permitidos da error. 

