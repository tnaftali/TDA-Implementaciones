#ifndef __PILAS_H_
#include <stdio.h>

typedef int tdato;

typedef struct Nodo
{
    tdato info;
    struct Nodo *sig;
} nodo;

typedef struct tpilaD
{
    nodo *cima;
} tpilaD;

// Definicion de procedimientos
void pcrear();
void pponer();
void psacar();
nodo *crearNodo(tdato x);

//Implementaciones desarrolladas

void pcrearD(tpilaD *p)
{
  p->cima = NULL;
}

int pllenaD(tpilaD *p)
{
 return 0;
}

int pvaciaD(tpilaD *p)
{
    return(p->cima == NULL);
}

void pponerD(tpilaD *p, tdato x)
{
    nodo *n;
    n = crearNodo(x);
    n->sig = p->cima;
    p->cima=n;
}

void psacarD(tpilaD *p, tdato *x)
{
 (*x) = p->cima->info;
 p->cima= p->cima->sig;
 free(p->cima);
}

nodo* crearNodo(tdato x)
{
	nodo *nue = (nodo*) malloc(sizeof(nodo));
	nue->sig = NULL;
	nue->info = x;
	return nue;
}

#endif

