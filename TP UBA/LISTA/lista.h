#ifndef LISTA_H
#define LISTA_H
#include <stdbool.h>
#include <stddef.h> 


/*DEFINICION DE LOS TIPOS DE DATOS*/

typedef struct lista lista_t;
typedef struct lista_iter lista_iter_t;


/*PRIMITIVAS BASICAS DE LA LISTA*/
	
// Crea una lista.
// Post: devuelve una lista vacia.
lista_t *lista_crear(void);

// Devuelve verdadero o falso, segun si la lista esta vacia o no
// Pre: la lista fue creada.
bool lista_esta_vacia(const lista_t *lista);

// Agrega un nuevo elemento al principio de la lista. Devuelve  
// falso en caso de error.
// Pre: la lista fue creada.
// Post: se agregó un nuevo elemento a la lista, valor se
// encuentra al principio de la lista.
bool lista_insertar_primero(lista_t *lista, void *dato);

// Agrega un nuevo elemento al final de la lista. Devuelve falso  
// en caso de error.
// Pre: la lista fue creada.
// Post: se agregó un nuevo elemento a la lista, valor se  
// encuentra al final de la lista.
bool lista_insertar_ultimo(lista_t *lista, void *dato);

// Saca el primer elemento de la lista. Si la lista tiene  
// elementos, se quita el primero de la lista, y se devuelve 
// su valor, si está vacía, devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolvió el valor del primer elemento anterior, la 
// lista contiene un elemento menos, si no estaba vacía.
void *lista_borrar_primero(lista_t *lista);

// Devuelve el primer elemento de la lista, si está vacía,
// devuelve NULL.
// Pre: la lista fue creada.
void *lista_ver_primero(const lista_t *lista);

// Devuelve el largo de la lista.
// Pre: la lista fue creada.
size_t lista_largo(const lista_t *lista);

// Destruye la lista. Si se recibe la función destruir_dato 
// por parámetro, para cada uno de los elementos de la lista 
// llama a destruir_dato.
// Pre: la lista fue creada. destruir_dato es una función capaz de 
// destruir los datos de la lista, o NULL en caso de que no se 
// la utilice.
// Post: se eliminaron todos los elementos de la lista.
void lista_destruir(lista_t *lista, void destruir_dato(void *));


/* PRIMITIVAS DE ITERACION */

// Crea un iterador.
// Post: devuelve un iterador inicializado en el primer elemento.
lista_iter_t *lista_iter_crear(const lista_t *lista);

// Avanza el iterador una posicion en la lista. Devuelve false
// en caso de error.
// Pre: el iterador y la lista fueron creados.
bool lista_iter_avanzar(lista_iter_t *iter);

// Devuelve el elemento al que apunta el iterador. Devuelve  
// NULL si esta al final.
// Pre: el iterador y la lista fueron creados.
void *lista_iter_ver_actual(const lista_iter_t *iter);

// Devuelve verdadero o falso, segun si el iterador esta 
// al final o no.
// Pre: el iterador y la lista fueron creados.
bool lista_iter_al_final(const lista_iter_t *iter);

// Destruye el iterador.
// Pre: el iterador fue creado.
// Post: se elimino el iterador.
void lista_iter_destruir(lista_iter_t *iter);


/* PRIMITIVAS DE LISTA JUNTO CON ITERADOR */

// Agrega un nuevo elemento en la posicion a la que apunta 
// el iterador. En caso de error devuelve false.
// Pre: el iterador y la lista fueron creados.
// Post: se agrego un nuevo elemento a la lista, dato se encuentra 
// en la posicion actual del iterador, y la lista contiene un 
// elemento mas.
bool lista_insertar(lista_t *lista, lista_iter_t *iter, void *dato);

// Elimina el elemento que esta en la posicion actual del 
// iterador y devuelve su valor, o NULL en caso de error.
// Pre: el iterador y la lista fueron creados;
// Post: se devolvio el valor del elemento en la posicion actual, 
// la lista contiene un elemento menos, si no estaba vacia.
void *lista_borrar(lista_t *lista, lista_iter_t *iter);


/* PRIMITIVAS DEL ITERADOR INTERNO */

// Recorre la lista mientras la funcion visitar devuelva true
// y no se llegue al final de la lista. Visitar recibe un dato
// y un puntero extra, y devuelve true si debe seguir iterando,
// false en caso contrario.
// Pre: la lista fue creada.
void lista_iterar(lista_t *lista, bool (*visitar)(void *dato, void *extra), void *extra);

 
/* PRUEBAS UNITARIAS */

void pruebas_lista_alumno(void);

#endif // LISTA_H
