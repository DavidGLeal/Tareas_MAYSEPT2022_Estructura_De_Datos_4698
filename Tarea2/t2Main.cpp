/*ESPE
*Enunciado del problema:
*   Relizar la funcion ingreso de datos con sus excepciones,
*   habilitar para flotantes, e implementar todo eso en clases
*   abstractas a partir del codigo de clase
*Autor 
*   Camila Rivera
*   Mateo Roman
*Fecha de creacion
*   11-05-2022
*Fecha de modificacion
*   13 - 05 -2022
*Grupo #8
*Github del grupo:
* https://github.com/Grupo8-4698-EstructuraDeDatos/4698-Grupo8-EstructuradeDatos
*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

#include "t2IngresoDatos.cpp"

int main(){
	
	IngresoDatos *a = new IngresoDatos();
	char *dato=new char[50];
	dato = a -> ingresoDatos("Ingrese sus numeritos: ");
	
	if((a -> getDet()) == '\0'){
		printf("\n Su numero es %i, y es un entero", a -> devolverInt(dato));
	}else if((a -> getDet()) == 'f'){
		printf("\n Su numero es %f, y es un flotante", a -> devolverFloat(dato));
	}else{
		printf("No estoy funcionando");
	}

    return 0;
}