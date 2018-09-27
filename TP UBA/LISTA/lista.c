#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h> 

/*DEFINICION DE LOS TIPOS DE DATOS*/

typedef struct nodo nodo_t;
 
struct nodo{
    void* dato;
    nodo_t* siguiente;
};
 
struct lista{
    nodo_t* primero;
    nodo_t* ultimo;
    size_t largo;
};

struct lista_iter{
    nodo_t* anterior;
    nodo_t* actual;
};

//función auxiliar para crear nodos
nodo_t* crear_nodo_nuevo(void* dato){
	nodo_t* nodo_nuevo = malloc(sizeof(nodo_t));
	if (!nodo_nuevo)
		return NULL;
	nodo_nuevo->dato = dato;
	nodo_nuevo->siguiente = NULL;
	return nodo_nuevo;
}

/*PRIMITIVAS BASICAS DE LA LISTA*/

// Crea una lista.
// Post: devuelve una lista vacía.
lista_t *lista_crear(void){
	lista_t* lista = malloc(sizeof(lista_t));
	if (!lista)
		return NULL;
	lista->primero = NULL;
	lista->ultimo = NULL;
	lista->largo = 0;
	return lista;
}

// Devuelve verdadero o falso, segun si la lista esta vacía o no
// Pre: la lista fue creada.
bool lista_esta_vacia(const lista_t *lista){
	return (!lista->largo);
}

// Agrega un nuevo elemento al principio de la lista. Devuelve  
// falso en caso de error.
// Pre: la lista fue creada.
// Post: se agregó un nuevo elemento a la lista, valor se 
// encuentra al principio de la lista.
bool lista_insertar_primero(lista_t *lista, void *dato){
	nodo_t* nodo_nuevo = crear_nodo_nuevo(dato);
	if (!nodo_nuevo)
		return false;
	nodo_nuevo->siguiente = lista->primero;
	lista->primero = nodo_nuevo;
	if (lista_esta_vacia(lista))
		lista->ultimo = nodo_nuevo;
	(lista->largo)++;
	return true;
}

// Agrega un nuevo elemento al final de la lista. Devuelve falso  
// en caso de error.
// Pre: la lista fue creada.
// Post: se agregó un nuevo elemento a la lista, valor se  
// encuentra al final de la lista.
bool lista_insertar_ultimo(lista_t *lista, void *dato){
	nodo_t* nodo_nuevo = crear_nodo_nuevo(dato);
	if (!nodo_nuevo)
		return false;
	if (lista_esta_vacia(lista))
		lista->primero = nodo_nuevo;
	else 
		lista->ultimo->siguiente = nodo_nuevo;
	lista->ultimo = nodo_nuevo;
	(lista->largo)++;
	return true;
}

// Saca el primer elemento de la lista. Si la lista tiene  
// elementos, se quita el primero de la lista, y se devuelve 
// su valor, si está vacía, devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolvió el valor del primer elemento anterior, la
// lista contiene un elemento menos, si no estaba vacía.
void *lista_borrar_primero(lista_t *lista){
	if (lista_esta_vacia(lista))
		return NULL;
	void* aux = lista->primero->dato;
	nodo_t* nodo_aux = lista->primero;
	lista->primero = lista->primero->siguiente;
	(lista->largo)--;
	free(nodo_aux);
	return aux;
}

// Devuelve el primer elemento de la lista, si está vacía,
// devuelve NULL.
// Pre: la lista fue creada.
void *lista_ver_primero(const lista_t *lista){
	if (lista_esta_vacia(lista))
		return NULL;
	return lista->primero->dato;
}

// Devuelve el largo de la lista.
// Pre: la lista fue creada.
size_t lista_largo(const lista_t *lista){
	return lista->largo;
}


// Destruye la lista. Si se recibe la función destruir_dato 
// por parámetro, para cada uno de los elementos de la lista 
// llama a destruir_dato.
// Pre: la lista fue creada. destruir_dato es una función capaz de 
// destruir los datos de la lista, o NULL en caso de que no se 
// la utilice.
// Post: se eliminaron todos los elementos de la lista.
void lista_destruir(lista_t *lista, void destruir_dato(void *)){
	while (!lista_esta_vacia(lista)){
		if (destruir_dato)
			destruir_dato(lista_borrar_primero(lista));
		else lista_borrar_primero(lista);
	}
	free(lista);
}


/* PRIMITIVAS DE ITERACION */

// Crea un iterador.
// Post: devuelve un iterador inicializado en el primer elemento.
lista_iter_t *lista_iter_crear(const lista_t *lista){
	lista_iter_t* iter = malloc(sizeof(lista_iter_t));
	if (!iter)
		return false;
	iter->anterior = NULL;
	iter->actual = lista->primero;
	return iter;
}

// Avanza el iterador una posicion en la lista. Devuelve false
// en caso de error.
// Pre: el iterador y la lista fueron creados.
bool lista_iter_avanzar(lista_iter_t *iter){
	if (lista_iter_al_final(iter))
		return false;
	iter->anterior = iter->actual;
	iter->actual = iter->actual->siguiente;
	return true;
}

// Devuelve el elemento al que apunta el iterador. Devuelve  
// NULL si esta al final.
// Pre: el iterador y la lista fueron creados.
void *lista_iter_ver_actual(const lista_iter_t *iter){
	if (lista_iter_al_final(iter))
		return NULL;
	return iter->actual->dato;
}

// Devuelve verdadero o falso, segun si el iterador esta 
// al final o no.
// Pre: el iterador y la lista fueron creados.
bool lista_iter_al_final(const lista_iter_t *iter){
	return (!iter->actual);
}

// Destruye el iterador.
// Pre: el iterador fue creado.
// Post: se elimino el iterador.
void lista_iter_destruir(lista_iter_t *iter){
	free(iter);
}


/* PRIMITIVAS DE LISTA JUNTO CON ITERADOR */

// Agrega un nuevo elemento en la posicion a la que apunta 
// el iterador. En caso de error devuelve false.
// Pre: el iterador y la lista fueron creados.
// Post: se agrego un nuevo elemento a la lista, dato se encuentra 
// en la posicion actual del iterador, y la lista contiene un 
// elemento mas.
bool lista_insertar(lista_t *lista, lista_iter_t *iter, void *dato){
	nodo_t* nodo_nuevo = crear_nodo_nuevo(dato);
	if (!nodo_nuevo)
		return false;
	nodo_nuevo->siguiente = iter->actual;
	if (!iter->anterior)
		lista->primero = nodo_nuevo;
	else if (lista_iter_al_final(iter)){
			lista->ultimo = nodo_nuevo;
			iter->anterior->siguiente = nodo_nuevo;
		}
	else iter->anterior->siguiente = nodo_nuevo;
	lista->largo ++;
	iter->actual = nodo_nuevo;
	return true;
}

// Elimina el elemento que esta en la posicion actual del 
// iterador y devuelve su valor, o NULL en caso de error.
// Pre: el iterador y la lista fueron creados;
// Post: se devolvio el valor del elemento en la posicion actual, 
// la lista contiene un elemento menos, si no estaba vacia.
void *lista_borrar(lista_t *lista, lista_iter_t *iter){
	if (lista_esta_vacia(lista) || lista_iter_al_final(iter)) 
		return NULL;
	nodo_t* nodo_aux = iter->actual;
	void* dato_aux = nodo_aux->dato;
	iter->actual = iter->actual->siguiente;
	if (!iter->anterior) 
		lista->primero = iter->actual;
	else{
		iter->anterior->siguiente = iter->actual;
		if (lista_iter_al_final(iter)) 
			lista->ultimo = iter->anterior;
	}
	(lista->largo)--;
	free(nodo_aux);
	return dato_aux;
}


/* PRIMITIVAS DEL ITERADOR INTERNO */

// Recorre la lista mientras la funcion visitar devuelva true
// y no se llegue al final de la lista. Visitar recibe un dato
// y un puntero extra, y devuelve true si debe seguir iterando,
// false en caso contrario.
// Pre: la lista fue creada.
void lista_iterar(lista_t *lista, bool (*visitar)(void *dato, void *extra), void *extra){
	if (lista_esta_vacia(lista)) 
		return;
	nodo_t* nodo_aux = lista->primero;
	while (nodo_aux && visitar(nodo_aux->dato, extra))
		nodo_aux = nodo_aux->siguiente;
}
