/*ESPE
*Enunciado del problema:
*   Realizar ejercicios sobrecargando operadores
*   Sobrecarga del operador bitwise ~
*Autor 
*   Sebastian Torres ~
*   Shared Tinoco
*   Camila Rivera
*   Mateo Roman
*Fecha de creacion
*   17-05-2022
*Fecha de modificacion
*   18 - 05 -2022
*Grupo #10 y #8
*Github del grupo:
* https://github.com/Grupo8-4698-EstructuraDeDatos/4698-Grupo8-EstructuradeDatos
*/


#include "Bitwise.hpp"
#include <cstdio>

int main(){

    Bitwise<int, 0> uno(7);

    uno.imprimir();

    Bitwise<int, 0> nuevo;

    nuevo = ~uno;

    nuevo.imprimir();
    
    return 0;
}