#include "pila.h"
#include <stdlib.h>

/* Definición del struct pila proporcionado por la cátedra.
 */
struct pila {
    void **datos;
    size_t capacidad;
    size_t cantidad;
};

const size_t k = 10;
/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/

//funcion auxiliar para redimensionar
bool redimensionar(pila_t* pila){
	void** aux = realloc(pila->datos, pila->capacidad*sizeof(void*));
	if (aux == NULL)
		return false;
	pila->datos = aux;
	return true;
}
 

// Crea una pila.
// Post: devuelve una nueva pila vacía.
pila_t* pila_crear(){
	pila_t* pila = malloc(sizeof(pila_t));
	if (!pila)
		return NULL;
	pila->datos = malloc(sizeof(void*));
	if (!(pila->datos)){
		free(pila);
		return NULL;
	}
	pila->cantidad = 0;
	pila->capacidad = 0;
	return pila;
}

// Destruye la pila.
// Pre: la pila fue creada.
// Post: se eliminaron todos los elementos de la pila.
void pila_destruir(pila_t *pila){
	free(pila->datos);
	free(pila);	
}

// Devuelve verdadero o falso, según si la pila tiene o no elementos apilados.
// Pre: la pila fue creada.
bool pila_esta_vacia(const pila_t *pila){
	return (!pila->cantidad);
}

// Agrega un nuevo elemento a la pila. Devuelve falso en caso de error.
// Pre: la pila fue creada.
// Post: se agregó un nuevo elemento a la pila, valor es el nuevo tope.
bool pila_apilar(pila_t *pila, void* valor){
	if (pila->capacidad == pila->cantidad){
		pila->capacidad += k;	
		if (!(redimensionar (pila)))
			return false;
	}
	((pila->datos)[pila->cantidad]) = valor;
	pila->cantidad ++;
	return true;
}

// Obtiene el valor del tope de la pila. Si la pila tiene elementos,
// se devuelve el valor del tope. Si está vacía devuelve NULL.
// Pre: la pila fue creada.
// Post: se devolvió el valor del tope de la pila, cuando la pila no está
// vacía, NULL en caso contrario.
void* pila_ver_tope(const pila_t *pila){
	void* ultimo;
	if (pila_esta_vacia(pila))
		return NULL;
	ultimo = ((pila->datos)[pila->cantidad-1]);
	return ultimo;
}

// Saca el elemento tope de la pila. Si la pila tiene elementos, se quita el
// tope de la pila, y se devuelve ese valor. Si la pila está vacía, devuelve
// NULL.
// Pre: la pila fue creada.
// Post: si la pila no estaba vacía, se devuelve el valor del tope anterior
// y la pila contiene un elemento menos.
void* pila_desapilar(pila_t *pila){
	void* tope = pila_ver_tope(pila);
	if (!tope)
		return NULL;
	if (pila->capacidad - pila->cantidad == k){
		pila->capacidad -= k;
		if (!redimensionar(pila))
			return NULL;
	}
	pila->cantidad --;
	return tope;
}
	
