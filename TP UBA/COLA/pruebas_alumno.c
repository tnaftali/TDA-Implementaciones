#include "cola.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>

/* *****************************************************************
 *                      PRUEBAS UNITARIAS
 * *****************************************************************/

// Realiza pruebas sobre la implementación del alumno.
//
// Las pruebas deben emplazarse en el archivo ‘pruebas_alumno.c’, y
// solamente pueden emplear la interfaz pública tal y como aparece en cola.h
// (esto es, las pruebas no pueden acceder a los miembros del struct cola).
//
// Para la implementación de las pruebas se debe emplear la función
// print_test(), como se ha visto en TPs anteriores.
void pruebas_cola_alumno(void){
	
	int a = 5;
	int b = 6;
	int c = 7;
	int d = 8;
	int e = 100;
	cola_t* cola_prueba1 = cola_crear();
	print_test("Cola vacia creada", cola_prueba1!=0);
	print_test("Cola vacia esta vacia", cola_esta_vacia(cola_prueba1)==true);
	print_test("Ver primero cola vacia", cola_ver_primero(cola_prueba1)==NULL);
	print_test("Desencolar cola vacia", cola_desencolar(cola_prueba1)==NULL);
	print_test("Encolar a", cola_encolar(cola_prueba1, &a)==true);
	print_test("Desencolar a", cola_desencolar(cola_prueba1)==&a);
	print_test("Encolar b", cola_encolar(cola_prueba1, &b)==true);
	print_test("Ver primero b", cola_ver_primero(cola_prueba1)==&b);
	print_test("Encolar c", cola_encolar(cola_prueba1, &c)==true);
	print_test("Encolar d", cola_encolar(cola_prueba1, &d)==true);
	print_test("Ver primero b", cola_ver_primero(cola_prueba1)==&b);
	print_test("Encolar e", cola_encolar(cola_prueba1, &e)==true);
	print_test("Desencolar b", cola_desencolar(cola_prueba1)==&b);
	print_test("Desencolar c", cola_desencolar(cola_prueba1)==&c);
	print_test("Desencolar d", cola_desencolar(cola_prueba1)==&d);
	print_test("Ver primero e", cola_ver_primero(cola_prueba1)==&e);
	print_test("Encolar a", cola_encolar(cola_prueba1, &a)==true);
	print_test("Encolar a", cola_encolar(cola_prueba1, &a)==true);
	print_test("Encolar b", cola_encolar(cola_prueba1, &b)==true);
	print_test("Encolar a", cola_encolar(cola_prueba1, &a)==true);
	print_test("Desencolar e", cola_desencolar(cola_prueba1)==&e);
	print_test("Ver primero a", cola_ver_primero(cola_prueba1)==&a);
	
	while (cola_esta_vacia(cola_prueba1)!=true)
		print_test("Vaciar cola", cola_desencolar(cola_prueba1)!=NULL);
	
	
	for (int i=1; i<100; i++){
		print_test("Encolar 100 a", cola_encolar(cola_prueba1, &a)==true);
		print_test("Encolar 100 b", cola_encolar(cola_prueba1, &b)==true);
	}
		
	for (int i=1; i<100; i++){
		print_test("Desencolar 100 a", cola_desencolar(cola_prueba1)==&a);
		print_test("Desencolar 100 b", cola_desencolar(cola_prueba1)==&b);
	}
	
	cola_destruir(cola_prueba1,NULL);
} 
