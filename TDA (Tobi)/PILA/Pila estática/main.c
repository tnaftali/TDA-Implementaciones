//
// Created by tobias on 27/09/18.
//
#include "pila.c"

void esta_vacia(PILA *p) {
    int vacia = p_vacia(p);
    if (1 == vacia) {
        printf("Pila vacía\n");
    } else {
        printf("Pila no vacía\n");
    }
}

void esta_llena(PILA *p) {
    int llena = p_llena(p);
    if (1 == llena) {
        printf("Pila llena\n");
    } else {
        printf("Pila no llena\n");
    }
}


int main() {
    PILA *p;
    int elem;
    int cont = 0;

    p_crear(&p);

    esta_vacia(&p);
    esta_llena(&p);

    printf("Agregando elementos a la pila\n");
    while (cont <= CMAX) {
        elem = cont;
        p_poner(&p, elem);
        cont++;
    }

    esta_vacia(&p);
    esta_llena(&p);

    printf("Sacando elementos de la pila\n");
    while (0 == p_vacia(&p)) {
        p_sacar(&p, &elem);
    }

    esta_vacia(&p);
    esta_llena(&p);

    return (EXIT_SUCCESS);
}
