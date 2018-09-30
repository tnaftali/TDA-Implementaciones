#include "pila.c"
#include "pila.h"

void esta_vacia(t_pila *p) {
    int vacia = p_vacia(p);
    if (1 == vacia) {
        printf("Pila vacía\n");
    } else {
        printf("Pila no vacía\n");
    }
}

void esta_llena(t_pila *p) {
    int llena = p_llena(p);
    if (1 == llena) {
        printf("Pila llena\n");
    } else {
        printf("Pila no llena\n");
    }
}


int main() {
    t_pila *pila;
    t_dato elem;
    int cont = 0;

    p_crear(&pila);

    esta_vacia(&pila);
    esta_llena(&pila);

    printf("Agregando elementos a la pila\n");
    while (cont < MAX_CIMA) {
        elem = cont + 1;
        p_poner(&pila, elem);
        cont++;
    }

    esta_vacia(&pila);
    esta_llena(&pila);

    printf("Sacando elementos de la pila\n");
    while (0 == p_vacia(&pila)) {
        p_sacar(&pila, &elem);
    }

    esta_llena(&pila);
    esta_vacia(&pila);

    return (EXIT_SUCCESS);
}
