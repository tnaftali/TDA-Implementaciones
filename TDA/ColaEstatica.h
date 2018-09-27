#include<stdio.h>

#define MAXCOLA 100
#define PRIMERPOS 1

typedef int tdato;

typedef struct tcola
{
    tdato elem[MAXCOLA];
    int frente;
} cola;

void ccrear(cola *q);

int cvacia(cola *q);

int cllena(cola *q);

void cponer(cola *q, tdato dato);

void csacar(cola *q, tdato *dato);

void ccrear(cola *q)
{
	q->frente=-1;
}

int cvacia(cola *q)
{
	return(q->frente==0);
}

int cllena(cola *q)
{
	return (q->frente==MAXCOLA);
}


void cponer (cola *q, tdato dato)
{
    q->frente=q->frente+1;
    q->elem[q->frente]=dato;
}

void csacar (cola *q, tdato *dato)
{
	(*dato)=q->elem[PRIMERPOS];
	for(int i=0; i<q->frente;i++)
    {
        q->elem[i]=q->elem[i]+1;
    }
    q->frente=q->frente-1;
}
