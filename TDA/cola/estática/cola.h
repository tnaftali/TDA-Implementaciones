#include<stdio.h>
#include <stdlib.h>

#define INICIO_COLA 1
#define MAX_COLA 10
#define MIN_FINAL -1

typedef void* t_dato;

struct cola;
typedef struct cola t_cola;

// Crea una cola
// Post: devuelve una nueva cola vacía
void c_crear(t_cola *cola);

// Devuelve verdadero o falso, según si la cola tiene o no elementos
// Pre: la cola fue creada
bool c_vacia(t_cola *cola);

// Devuelve verdadero o falso, según si la cola ha alcanzado su máxima capacidad de almacenamiento
// Pre: la cola fue creada
bool c_llena(t_cola *cola);

// Agrega un nuevo elemento a la cola
// Pre: la cola fue creada
// Post: se agregó un nuevo elemento a la cola, x es el nuevo final
void c_poner(t_cola *cola, t_dato x);

// Saca un elemento de la cola
// Pre: la cola fue creada
// Post: se sacó el elemento de la cola
void c_sacar(t_cola *cola, t_dato *x);