#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "stdbool.h"

struct pila {
    int cima;
    t_dato elem[MAX_CIMA];
};

// Crea una pila
// Post: devuelve una nueva pila vacía
void p_crear(t_pila *p) {
    printf("Se crea pila \n");
    p->cima = MIN_CIMA;
}

// Devuelve verdadero o falso, según si la pila tiene o no elementos apilados
// Pre: la pila fue creada.
bool p_vacia(t_pila *p) {
    return p->cima == MIN_CIMA;
}

// Devuelve verdadero o falso, según si la pila ha alcanzado su máxima capacidad de almacenamiento
// Pre: la pila fue creada
bool p_llena(t_pila *p) {
    return p->cima == MAX_CIMA;
}

// Agrega un nuevo elemento a la pila
// Pre: la pila fue creada
// Post: se agregó un nuevo elemento a la pila, x es la nueva cima
void p_poner(t_pila *p, t_dato *x) {
    printf("Se inserta valor %d en pila \n", x);
    p->cima = p->cima + 1;
    p->elem[p->cima] = x;
}

// Saca un elemento de la pila
// Pre: la pila fue creada
// Post: se sacó el elemento de la pila
void p_sacar(t_pila *p, t_dato *x) {
    *x = p->elem[p->cima];
    p->cima = p->cima - 1;
    printf("Se saca valor %d de la pila \n", *x);
}