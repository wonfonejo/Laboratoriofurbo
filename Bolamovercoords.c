//Codigo para decirle al programa a que coordenadas quiero mover el balon
//Tomando como base nuevamente el codigo funcional

int mover_balon(Cancha *cancha, int nuevo_x, int nuevo_y, Equipo *equipo1, Equipo *equipo2) {
    if (nuevo_x < 0 || nuevo_x >= 42 || nuevo_y < 0 || nuevo_y >= 38)
        return 0;

    cancha->bolax = nuevo_x;
    cancha->bolay = nuevo_y;
    return 1;

    while (1) {
        printf("\nIngresa las coordenadas X Y a donde deseas mover el balón (escribe -1 -1 para salir): ");
        scanf("%d %d", &x, &y);

        if (x == -1 && y == -1) {
            printf("Saliendo del programa...\n");
            break;
        }

        if (mover_balon(&cancha, x, y, &equipo1, &equipo2)) {
            printf("Balón movido a (%d, %d).\n", x, y);
        } else {
            printf("Movimiento inválido. Coordenadas fuera del campo o no permitidas.\n");
        }

        imprimir_cancha(&cancha, &equipo1, &equipo2);
    }

    return 0;
//While para que pregunate las coordenadas y reciba las mismas