#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pila.h"

struct t_nodo {
    t_dato info;
    struct t_nodo *sig;
};

struct t_nodo t_pila;

//struct t_pila {
//    t_nodo nodo;{
//    t_nodo nodo;
//};
//} pila;

//typedef struct {
//    int info;
//} DATA;
//
//typedef struct node {
//    DATA data;
//    struct node *next;
//} NODE;

// Crea una pila
// Post: devuelve una nueva pila vacía
void p_crear(t_nodo **cima) {
    printf("Se crea pila \n");
    *cima = NULL;
}

//t_dato *p_cima(t_pila *cima) {
//    return &cima->info;
//}

// Devuelve verdadero o falso, según si la pila tiene o no elementos apilados
// Pre: la pila fue creada
bool p_vacia(t_nodo *cima) {
    return cima == NULL;
}

t_nodo *crear_nodo(t_dato x) {
    t_nodo *tmp = (t_nodo *) malloc(sizeof(t_nodo));
    if (tmp == NULL) { // no hay memoria disponible
        exit(0);
    }
    tmp->sig = NULL;
    tmp->info = x;

    return tmp;
}


// Agrega un nuevo elemento a la pila
// Pre: la pila fue creada
// Post: se agregó un nuevo elemento a la pila, x es la nueva cima
void p_poner(t_nodo *cima, t_dato x) {
    printf("Se inserta valor %d en pila \n", x);
    t_nodo *tmp = crear_nodo(x);
    tmp->sig = cima;
    cima = tmp;
}

// Saca un elemento de la pila
// Pre: la pila fue creada
// Post: se sacó el elemento de la pila
void p_sacar(t_nodo *top, t_dato *x) {
    t_nodo *tmp = top;
    *x = top->info;
    top = top->sig;
    free(tmp);
    printf("Se saca valor %d de la pila \n", x);
}