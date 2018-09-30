#include <stdio.h>
#include <stdlib.h>

#define MIN_CIMA 0
#define MAX_CIMA 10

typedef void* t_dato;

struct pila;
typedef struct pila t_pila;

// Crea una pila
// Post: devuelve una nueva pila vacía
void p_crear(t_pila *p);

// Devuelve verdadero o falso, según si la pila contiene o no algún elemento
// Pre: la pila fue creada
_Bool p_vacia(t_pila *p);

// Devuelve verdadero o falso, según si la pila ha alcanzado su máxima capacidad de almacenamiento
// Pre: la pila fue creada
_Bool p_llena(t_pila *p);

// Agrega un nuevo elemento a la pila
// Pre: la pila fue creada
// Post: se agregó un nuevo elemento a la pila, x es la nueva cima
void p_poner(t_pila *p, t_dato *x);

// Saca un elemento de la pila y lo devuelve
// Pre: la pila fue creada
// Post: se sacó el elemento de la pila
void p_sacar(t_pila *p, t_dato *x);