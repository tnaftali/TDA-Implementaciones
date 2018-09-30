#include "pila.c"
#include "pila.h"

void esta_vacia(t_nodo *p) {
    int vacia = p_vacia(p);
    if (1 == vacia) {
        printf("Pila vacía\n");
    } else {
        printf("Pila no vacía\n");
    }
}

//void esta_llena(t_nodo *p) {
//    int llena = p_llena(p);
//    if (1 == llena) {
//        printf("Pila llena\n");
//    } else {
//        printf("Pila no llena\n");
//    }
//}


int main() {
    t_dato elem;
    t_nodo *pila;

    //    pila = crear_nodo(1);
    p_crear(&pila);

    esta_vacia(pila);
//    esta_llena(&p);

    int cont = 0;
    printf("Agregando elementos a la pila\n");
    while (cont < 10) {
        elem = cont + 1;
        p_poner(pila, elem);
        cont++;
    }

    esta_vacia(pila);
//    esta_llena(&p);

//    printf("Sacando elementos de la pila\n");
//    while (0 == p_vacia(&pila)) {
//        p_sacar(pila, &elem);
//    }

    //    esta_llena(&p);
//    esta_vacia(pila);

    return (EXIT_SUCCESS);
}
