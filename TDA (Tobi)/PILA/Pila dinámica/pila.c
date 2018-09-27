#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int info;
} DATA;

typedef struct node {
    DATA data;
    struct node *next;
} NODE;

void p_crear(NODE **top) {
    *top = NULL;
}

NODE *crear_nodo(DATA data) {
    NODE *tmp = (NODE *) malloc(sizeof(NODE));
    if (tmp == NULL) { // no hay memoria disponible
        exit(0);
    }
    tmp->next = NULL;
    tmp->data = data;

    return tmp;
}

NODE *p_poner(NODE *top, DATA data) {
    NODE *tmp = crear_nodo(data);
    tmp->next = top;
    top = tmp;
    return top;
}

NODE *p_sacar(NODE *top, DATA *element) {
    NODE *tmp = top;
    *element = top->data;
    top = top->next;
    free(tmp);
    return top;
}

DATA *p_cima(NODE *top) {
    return &top->data;
}

int p_vacia(NODE *top) {
    return (top == NULL) ? 1 : 0;
}

//int main() {
//    NODE *top;
//    DATA element;
//    int size, counter = 0;
//
//    printf("Ingrese tamaño de pila:");
//    scanf("%d", &size);
//
//    printf("Agregando elementos a la pila\n");
//    p_crear(&top);
//    while (counter < size) {
//        element.info = rand();
//        printf("agregando elemento %d a la pila\n", element.info);
//        top = p_poner(top, element);
//        counter++;
//    }
//    printf("\nCima de la pila: %d\n\n", p_cima(top)->info);
//
//    printf("Sacando elementos de la pila\n");
//    while (0 == p_vacia(top)) {
//        top = p_sacar(top, &element);
//        printf("Sacando elemento %d de la pila\n", element.info);
//    }
//
//    int empty = p_vacia(top);
//    if (1 == empty) {
//        printf("Pila está vacía");
//    } else {
//        printf("Pila no está vacía");
//    }
//
//    return (EXIT_SUCCESS);
//}