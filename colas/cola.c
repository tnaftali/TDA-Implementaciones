#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

typedef struct nodo_cola nodo_t;
 
struct nodo_cola{
	void* dato;
	nodo_t* siguiente;
};
 
struct cola{
	nodo_t* prim;
	nodo_t* ult;
};

//función auxiliar para crear nodos
nodo_t* cola_crear_nodo_nuevo(void* dato){
	nodo_t* nodo_nuevo = malloc(sizeof(nodo_t));
	if (!nodo_nuevo)
		return NULL;
	nodo_nuevo->dato = dato;
	nodo_nuevo->siguiente = NULL;
	return nodo_nuevo;
}

// Crea una cola.
// Post: devuelve una nueva cola vacía.
cola_t* cola_crear(void){
	cola_t* cola = malloc(sizeof(nodo_t));
	if (cola == NULL)
		return NULL;
	cola->prim = NULL;
	cola->ult = NULL;
	return cola;
}

// Destruye la cola. Si se recibe la función destruir_dato por parámetro,
// para cada uno de los elementos de la cola llama a destruir_dato.
// Pre: la cola fue creada. destruir_dato es una función capaz de destruir
// los datos de la cola, o NULL en caso de que no se la utilice.
// Post: se eliminaron todos los elementos de la cola.
void cola_destruir(cola_t *cola, void (*destruir_dato)(void*)){
	while (!cola_esta_vacia(cola)){
		void* dato = cola_desencolar(cola);
		if (destruir_dato)
			destruir_dato(dato);
	}
	free(cola);
}


// Devuelve verdadero o falso, según si la cola tiene o no elementos encolados.
// Pre: la cola fue creada.
bool cola_esta_vacia(const cola_t *cola){
	return (!cola->prim);
}

// Agrega un nuevo elemento a la cola. Devuelve falso en caso de error.
// Pre: la cola fue creada.
// Post: se agregó un nuevo elemento a la cola, valor se encuentra al final
// de la cola.
bool cola_encolar(cola_t *cola, void* valor){
	nodo_t* nodo_aux = cola_crear_nodo_nuevo(valor);
	if (!nodo_aux)
		return false;
	if (cola_esta_vacia(cola))
		cola->prim = nodo_aux;
	else 
		cola->ult->siguiente = nodo_aux;
	cola->ult = nodo_aux;
	return true;
}

// Obtiene el valor del primer elemento de la cola. Si la cola tiene
// elementos, se devuelve el valor del primero, si está vacía devuelve NULL.
// Pre: la cola fue creada.
// Post: se devolvió el primer elemento de la cola, cuando no está vacía.
void* cola_ver_primero(const cola_t *cola){
	if (cola_esta_vacia(cola))
		return NULL;
	return cola->prim->dato;
}

// Saca el primer elemento de la cola. Si la cola tiene elementos, se quita el
// primero de la cola, y se devuelve su valor, si está vacía, devuelve NULL.
// Pre: la cola fue creada.
// Post: se devolvió el valor del primer elemento anterior, la cola
// contiene un elemento menos, si la cola no estaba vacía.
void* cola_desencolar(cola_t *cola){
	if (cola_esta_vacia(cola))
		return NULL;
	void* primer_dato = cola->prim->dato;
	nodo_t* nodo_aux = cola->prim;
	if (cola->ult == cola->prim)
		cola->ult = NULL;
	cola->prim = cola->prim->siguiente;
	free(nodo_aux);
	return primer_dato;
}
