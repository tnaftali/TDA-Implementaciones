#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cola.h"

struct cola {
    int final;
    t_dato elem[MAX_COLA];
};

// Crea una cola
// Post: devuelve una nueva cola vacía
void c_crear(t_cola *cola) {
    cola->final = MIN_FINAL;
}

// Devuelve verdadero o falso, según si la cola tiene o no elementos
// Pre: la cola fue creada
bool c_vacia(t_cola *cola) {
    return cola->final == MIN_FINAL;
}

// Devuelve verdadero o falso, según si la cola ha alcanzado su máxima capacidad de almacenamiento
// Pre: la cola fue creada
bool c_llena(t_cola *cola) {
    return cola->final == MAX_COLA;
}

// Agrega un nuevo elemento a la cola
// Pre: la cola fue creada
// Post: se agregó un nuevo elemento a la cola, x es el nuevo final
void c_poner(t_cola *cola, t_dato x) {
    cola->final = cola->final + 1;
    cola->elem[cola->final] = x;
}

// Saca un elemento de la cola
// Pre: la cola fue creada
// Post: se sacó el elemento de la cola
void c_sacar(t_cola *cola, t_dato *x) {
    (*x) = cola->elem[INICIO_COLA];
    for (int i = 0; i < cola->final; i++) {
        cola->elem[i] = cola->elem[i] + 1;
    }
    cola->final = cola->final - 1;
}
