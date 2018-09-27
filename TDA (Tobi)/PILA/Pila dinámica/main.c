//
// Created by tobias on 27/09/18.
//
#include "pila.c"

int main() {
    NODE *top;
    DATA element;
    int size, counter = 0;

    printf("Ingrese tamaño de pila:");
    scanf("%d", &size);

    printf("Agregando elementos a la pila\n");
    p_crear(&top);
    while (counter < size) {
        element.info = rand();
        printf("agregando elemento %d a la pila\n", element.info);
        top = p_poner(top, element);
        counter++;
    }
    printf("\nCima de la pila: %d\n\n", p_cima(top)->info);

    printf("Sacando elementos de la pila\n");
    while (0 == p_vacia(top)) {
        top = p_sacar(top, &element);
        printf("Sacando elemento %d de la pila\n", element.info);
    }

    int empty = p_vacia(top);
    if (1 == empty) {
        printf("Pila está vacía");
    } else {
        printf("Pila no está vacía");
    }

    return (EXIT_SUCCESS);
}