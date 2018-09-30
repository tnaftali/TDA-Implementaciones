#include <stdio.h>

typedef void* t_dato;

struct t_nodo;
typedef struct t_nodo t_nodo;

//struct pila;
//typedef struct pila t_pila;

void p_crear(t_nodo **cima);

t_nodo *crear_nodo(t_dato x);

void p_poner(t_nodo *cima, t_dato x);

void p_sacar(t_nodo *cima, t_dato *x);

//t_dato *p_cima(t_nodo *cima);

bool p_vacia(t_nodo *cima);