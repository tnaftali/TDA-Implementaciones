#include "pila.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>


/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void prueba_pila_alumno() {
	int valor_a = 5;
	char valor_b = 'j';
	int valor_c = 67;
	char valor_d[] = "hola";
	int valor_e[5] = {1,2,3,4,5};
	
	pila_t* pila_prueba = pila_crear();
	
    print_test("Pila vacia creada", pila_prueba!=0);
    print_test("Pila vacia cantidad 0", pila_esta_vacia(pila_prueba)==true);
    print_test("Pila vacia tope null", pila_ver_tope(pila_prueba)==NULL);
    print_test("Pila vacia desapilar null", pila_desapilar(pila_prueba)==NULL);
    print_test("Apilar a true", pila_apilar(pila_prueba, &valor_a)==true);
    print_test("Ver tope pila apilada", pila_ver_tope(pila_prueba)==&valor_a);
    print_test("Apilar b true", pila_apilar(pila_prueba, &valor_b)==true);
    print_test("Ver tope pila apilada", pila_ver_tope(pila_prueba)==&valor_b);
    print_test("Apilar c true", pila_apilar(pila_prueba, &valor_c)==true);
    print_test("Ver tope pila apilada", pila_ver_tope(pila_prueba)==&valor_c);
    print_test("Apilar d true", pila_apilar(pila_prueba, &valor_d)==true);
    print_test("Ver tope pila apilada", pila_ver_tope(pila_prueba)==&valor_d);
    print_test("Apilar e true", pila_apilar(pila_prueba, &valor_e)==true);
    print_test("Desapilar e true", pila_desapilar(pila_prueba)== &valor_e);
    print_test("Ver tope pila apilada", pila_ver_tope(pila_prueba)==&valor_d);

	for (int i=0; i<1000; i++)
		print_test("Apilar 1000 true", pila_apilar(pila_prueba, &valor_a)==true);
	for (int i=0; i<1000; i++)
		print_test("Desapilar 1000 true", pila_desapilar(pila_prueba)==&valor_a);

	print_test("Pila no vacia", pila_esta_vacia(pila_prueba)==false);
    pila_destruir(pila_prueba);
    print_test("La pila fue destruida", true);
    
}
