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

// La parte de la cancha se hara en base a el codigo de los laboratorios de ajedrez (coordenas).

// Una persona se encarga de campo de juego,equipos y jugadores; otra de colocar los 11 jugadores en un campo y la ultima de crear el balon y moverlo por el campo

// la cancha debe ser de 38 y 42 metros. Las coordenadas de los jugadores en la cancha funcionan recorriendo un espacio en x,y de 1 m. ]

// 2 idas para mover la bola, ambas con coordenas del campo de juego. La primera es tipo "futbolin", en donde la bola verifica que la en la casilla de la cancha haya un jugador para que el movimiento sea valido; y la otra es tipo "clasico", en donde solo tiene que estar en el la cancha (la matriz de 38x42)

// el main incluye colocar 11 jugadores por equipo en un campo de juego, una funcion que reciba coordenadas para mover los jugadores y una que reciba coordenadas para mover el balon.

//El programa debe tener: formas de crear los 11 jugadores: atributos de equipo y posicion (portero y jugador de campo). Un campo definido como una matriz 38 por 42, formas de asignar jugadores al campo, inicializarlos y moverlos en los terminos de este.

