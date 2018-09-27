#ifndef __PILAS_H_
#include <stdio.h>

typedef int tdato;

typedef struct Nodo
{
    tdato info;
    struct Nodo *sig;
} nodo;

typedef struct tColaD
{
    nodo *frente;
} tcolaD;

// Definicion de procedimientos
void ccrearD(tcolaD *p);
int cllenaD(tcolaD *p);
int cvaciaD(tcolaD *p);
nodo *crearNodo(tdato x);
void cponerD(tcolaD *p, tdato x);
void csacarD(tcolaD *p, tdato *x);

//Implementaciones desarrolladas

void ccrearD(tcolaD *p)
{
    p->frente = NULL;
}

int cllenaD(tcolaD *p)
{
    return 0;
}

int cvaciaD(tcolaD *p)
{
    return(p->frente == NULL);
}

void cponerD(tcolaD *p, tdato x)
{
    nodo *n = crearNodo(x);
    if(p->frente == NULL)
    {
        p->frente = n;
    }
    else
    {
        nodo *aux = p->frente;
        while(aux->sig != NULL)
        {
            aux = aux->sig;
        }
        aux->sig = n;
    }
}

void csacarD(tcolaD *p, tdato *x)
{
    (*x) = p->frente->info;
    nodo *aux = p->frente;
    p->frente = p->frente->sig;
    free(aux);
}

nodo* crearNodo(tdato x)
{
	nodo *nue = (nodo*) malloc(sizeof(nodo));
	nue->sig = NULL;
	nue->info = x;
	return nue;
}

#endif


