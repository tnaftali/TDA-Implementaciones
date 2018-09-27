#include <stdio.h>
#include <stdlib.h>
#include "pilaEstatica.h"
#include "colaDinamica.h"


int main()
{
    printf("Hello world!\n");
    tcolaD p1;
    ccrearD(&p1);
    int i=0;
    tdato dato;
    while(!cllenaD(&p1)&&(i<12))
    {
        cponerD(&p1, i);
        printf("Elemento %d\n", i);
        i++;
    }
        while(!cvaciaD(&p1)&&(i>-10))
    {
        csacarD(&p1, &dato);
        printf("Sacando Elemento de cola: %d\n orden: %d\n", dato, i);
        i--;
    }

    if(cvaciaD(&p1))
        printf("La cola esta vacia");

    if(!cllenaD(&p1))
        printf("La cola no esta llena");

    getchar();
    return 0;
}
