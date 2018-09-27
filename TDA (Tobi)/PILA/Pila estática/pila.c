#include <stdio.h>
#include <stdlib.h>

int CMAX = 9;

typedef struct pila {
    int cima;
    int elem[10];
} PILA;

void p_crear(PILA *p) {
    printf("Se crea pila \n");
    p->cima = -1;
}

_Bool p_llena(PILA *p) {
    return p->cima == CMAX;
}

_Bool p_vacia(PILA *p) {
    return p->cima == -1;
}

void p_poner(PILA *p, int x) {
    printf("Se inserta valor %d en pila \n", x);
    p->cima = p->cima + 1;
    p->elem[p->cima] = x;
}

void p_sacar(PILA *p, int *x) {
    *x = p->elem[p->cima];
    p->cima = p->cima - 1;
    printf("Se saca valor %d de la pila \n", *x);
}