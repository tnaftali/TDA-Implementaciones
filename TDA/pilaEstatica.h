#ifndef __PILAS_H_
#include <stdio.h>
//#include "tipos.h" incluiria los 7 proximos renglones

#define MAXPILA 10

typedef int tdato;

typedef struct tpila
{
 int cima;
 tdato elem [MAXPILA];
} tpilaE;

// Definicion de procedimientos
void pcrear();
void pponer();
void psacar();

//Implementaciones desarrolladas

void pcrearE(tpilaE *p)
{
  p->cima= -1;
}

int pllenaE(tpilaE *p)
{
 return (p->cima == MAXPILA);
}

int pvaciaE(tpilaE *p)
{
 return (p->cima ==-1);
}

void pponerE(tpilaE *p, tdato x)
{
 p->cima= p->cima+1;
 p->elem[p->cima]=x;
}

void psacarE(tpilaE *p, tdato x)
{
 x = p->elem [p->cima];
 p->cima= p->cima -1;
}

#endif
