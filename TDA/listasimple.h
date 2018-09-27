
 #ifndef LISTA_H
#define LISTA_H
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct datolistap
{
	int clave, dato;
}tdato;

typedef struct Nodo
{
    tdato info;
    struct Nodo *sig;
} nodo;

typedef struct lista
{
	nodo *cab;
	nodo*actual;
} tlista;


void lcrear (tlista * l)
{
	l->cab = NULL;

}

int lvacia (tlista * l)
{
	return (l->cab == NULL);
}

void lppio (tlista * l)
{
	l->actual = l->cab;
}

void lsig(tlista * l)
{
	l->actual = l->actual->sig;
}

int  lfin(tlista * l) {
	return (l->actual == NULL);
}

void lmodificar (tlista *l, tdato aux)
{
    l->actual->info=aux;
}

tdato * linfo (tlista * l, tdato *dato)
{
	(*dato) = l->actual->info;
}



nodo* crearNodo(tdato x)
{
	nodo *nue = (nodo*) malloc(sizeof(nodo));
	nue->sig = NULL;
	nue->info = x;
	return nue;
}

void linsertarorden (tlista * l, tdato x, char torden)
{
    nodo *nue, *aux ;
    nue = crearnodo(x);
    if (l->cab == NULL)
       l->cab = nue;
       else
       if ( ((torden=='a') && (l->cab->info.clave>x.clave)) ||
          ((torden=='d') && (l->cab->info.clave<x.clave)) )
          {
              nue->sig=l->cab;
              l->cab=nue;
          }
          else
          {
          aux=l->cab;
          while ((aux->sig !=NULL) && ( ((torden=='a') && (aux->sig->info.clave<x.clave))
            || ((torden=='d') && (aux->sig->info.clave>x.clave)) ))
            {
                aux=aux->sig;
            }

            nue->sig=aux->sig;
            aux->sig=nue;

         }
}




void lborrarppio (tlista *l)
{
    nodo * aux = l->cab;
    l->cab = l->cab->sig;
    free(aux);
}

void linsertarppio(tlista *l, tdato x)
{
   nodo *nue;
   nue=crearnodo(x);
   nue->sig=l->cab;
   l->cab=nue;
   l->cab=nue;
}

void lborrarfin(tlista *l)
{
    nodo *aux,*aux2;
    if (l->cab->sig==NULL)
    {
        aux=l->cab;
        l->cab=NULL;
        free(aux);
    }
    else
    {
        aux=l->cab;
        while (aux->sig->sig !=NULL)
            aux=aux->sig;
        aux2=aux->sig;
        aux->sig=NULL;
        free(aux2);
    }
}
void linsertarfin(tlista*l, tdato x)
{
   nodo *nue,*aux;
   nue=crearnodo(x);
   if (l->cab==NULL)
        l->cab=nue;
   else
    {
        aux=l->cab;
        while (aux->sig !=NULL)
              aux=aux->sig;
        aux->sig=nue;
	}
}

void lborraractual(tlista *l)
{
   nodo *aux,*aux2;

   aux2=l->actual;
   if (l->actual==l->cab)
    {
       l->cab=l->cab->sig;
    }
   else
	{
        aux=l->cab;
        while (aux->sig!=l->actual){
               aux=aux->sig;}
        aux->sig=l->actual->sig;
	}
	free(aux2);
	l->actual=l->actual->sig;
}

#endif
