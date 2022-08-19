/*ESPE
*Enunciado del problema:
*   Realizar ejercicios sobrecargando operadores
*   Sobrecarga del operador bitwise -=
*Autor 
*   Sebastian Torres 
*   Shared Tinoco
*   Camila Rivera -=
*   Mateo Roman
*Fecha de creacion
*   17-05-2022
*Fecha de modificacion
*   18 - 05 -2022
*Grupo #10 y #8
*Github del grupo:
* https://github.com/Grupo8-4698-EstructuraDeDatos/4698-Grupo8-EstructuradeDatos
*/


#include "MenosIgual.hpp"
#include <cstdio>

int main() {

	MenosIgual<int, int, 0, 0> enteros(5,2);
	MenosIgual<int, int, 0, 0> reales(2,5);
	
	enteros.imprimir();
	reales.imprimir();
    
    MenosIgual<int, int, 0, 0> nuevo;
    nuevo = enteros -= reales;

    nuevo.imprimir();

	return 0;
}