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
    t_pila *p;
    t_dato elem;
    int cont = 0;

    p_crear(&p);

    esta_vacia(&p);
    esta_llena(&p);

    printf("Agregando elementos a la pila\n");
    while (cont < MAX_CIMA) {
        elem = cont + 1;
        p_poner(&p, elem);
        cont++;
    }

    esta_vacia(&p);
    esta_llena(&p);

    printf("Sacando elementos de la pila\n");
    while (0 == p_vacia(&p)) {
        p_sacar(&p, &elem);
    }

    esta_llena(&p);
    esta_vacia(&p);

    return (EXIT_SUCCESS);
}
