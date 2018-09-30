#include "cola.c"
#include "cola.h"

void esta_vacia(t_cola *cola) {
    int vacia = c_vacia(cola);
    if (1 == vacia) {
        printf("Cola vacía\n");
    } else {
        printf("Cola no vacía\n");
    }
}

void esta_llena(t_cola *cola) {
    int llena = c_llena(cola);
    if (1 == llena) {
        printf("Cola llena\n");
    } else {
        printf("Cola no llena\n");
    }
}

int main() {
    t_cola *cola;
    t_dato elem;
    int cont = 0;

    c_crear(cola);

    esta_vacia(cola);
    esta_llena(cola);

    printf("Agregando elementos a la cola\n");
    while (cont < MAX_COLA) {
        elem = cont + 1;
        c_poner(cola, elem);
        cont++;
    }

//    esta_vacia(cola);
//    esta_llena(cola);
//
//    printf("Sacando elementos de la cola\n");
//    while (0 == c_vacia(&cola)) {
//        c_sacar(&cola, &elem);
//    }
//
//    esta_llena(&cola);
//    esta_vacia(&cola);

    return (EXIT_SUCCESS);
}
