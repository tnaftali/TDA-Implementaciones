#include "lista.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>

void pruebas_lista_alumno(void){
	
	//variables para la lista
	int a=1;
	int b=2;
	int c=3;
	int d=4;
	int e=5;
	int f=6;
	int g=7;
	int h=8;
	int i=9;
	int j=10;
	
	lista_t* lista_prueba = lista_crear();
	
	//pruebas con lista vacia
	print_test("Lista vacia creada ok", lista_prueba);
	print_test("Lista esta vacia true",lista_esta_vacia(lista_prueba));
	print_test("Lista vacia borrar primero",!lista_borrar_primero(lista_prueba));
	print_test("Lista vacia ver primero",!lista_ver_primero(lista_prueba));
	print_test("Lista vacia largo",!lista_largo(lista_prueba));
	
	//pruebas insertar y borrar lista
	print_test("Lista insertar primero 2",lista_insertar_primero(lista_prueba, &a));
	print_test("Lista insertar ultimo 7",lista_insertar_ultimo(lista_prueba, &b));
	print_test("Lista insertar primero 1",lista_insertar_primero(lista_prueba, &a));
	print_test("Lista insertar primero 3",lista_insertar_primero(lista_prueba, &c));
	print_test("Lista esta vacia false",!lista_esta_vacia(lista_prueba));
	print_test("Lista borrar primero 3", lista_borrar_primero(lista_prueba)==&c);
	print_test("Lista ver primero 1", lista_ver_primero(lista_prueba)==&a);
	print_test("Lista ver largo", lista_largo(lista_prueba)==3);
	
	//vaciar lista
	print_test("Lista vaciar ok", lista_borrar_primero(lista_prueba)==&a);
	print_test("Lista vaciar ok", lista_borrar_primero(lista_prueba)==&a);
	print_test("Lista vaciar ok", lista_borrar_primero(lista_prueba)==&b);	
	
	print_test("Lista esta vacia", lista_esta_vacia(lista_prueba));
	
	//funcion aux para iterador interno
	bool sumar (void* dato, void* extra){
		printf("Lista antes de sumar: %d \n",*((int*)dato));
		printf("Lista despues de sumar: %d \n",((*((int*)dato) + (*(int*)extra))));
		return true;
	}

	print_test("Lista insertar primero",lista_insertar_primero(lista_prueba, &j));
	print_test("Lista insertar primero",lista_insertar_primero(lista_prueba, &i));
	print_test("Lista insertar primero",lista_insertar_primero(lista_prueba, &g));
	print_test("Lista insertar primero",lista_insertar_primero(lista_prueba, &f));
	print_test("Lista insertar primero",lista_insertar_primero(lista_prueba, &e));
	print_test("Lista insertar primero",lista_insertar_primero(lista_prueba, &d));
	print_test("Lista insertar primero",lista_insertar_primero(lista_prueba, &c));
	print_test("Lista insertar primero",lista_insertar_primero(lista_prueba, &b));
	print_test("Lista insertar primero",lista_insertar_primero(lista_prueba, &a));
		
	//multiplica por 10 a cada elemento y imprime
	lista_iterar(lista_prueba, sumar, &j);
	
	
	//pruebas con iterador externo
	lista_iter_t* iter_prueba = lista_iter_crear(lista_prueba);
	print_test("Iterador creado",iter_prueba);
	print_test("Iterador ver actual", lista_iter_ver_actual(iter_prueba)==&a);
	print_test("Iterador al final false", !lista_iter_al_final(iter_prueba));
	
	while (lista_iter_ver_actual(iter_prueba)!=&i){
		print_test("Avanzar iterador", lista_iter_avanzar(iter_prueba));
	}
	
	print_test("Insertar con iterador",lista_insertar(lista_prueba, iter_prueba, &h));
	print_test("Ver actual iterador", lista_iter_ver_actual(iter_prueba)==&h);
	
	while (lista_borrar(lista_prueba, iter_prueba)){
		print_test("Borrar hasta el final", true);
	}
	
	print_test("Iterador al final true", lista_iter_al_final(iter_prueba)==true);

	
	//inserto 100 veces
	int m;
	for(m=1;m<100;m++)
		print_test("Insertar primero 100 veces",lista_insertar_primero(lista_prueba, &a)==true);
	
	//borro 100 veces
	int n;
	for(n=1;n<100;n++)
		print_test("Borrar primero 100 veces",lista_borrar_primero(lista_prueba)==&a);
	
	//destruyo iterador y lista
	lista_iter_destruir(iter_prueba);
	print_test("Se destruyo el iterador", true);
	lista_destruir(lista_prueba, NULL);
	print_test("Se destruyo la lista", true);
}

