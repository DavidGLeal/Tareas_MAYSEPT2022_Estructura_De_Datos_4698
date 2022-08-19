
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

#include "at3Global.h"

//Constructor
Global::Global(char *dat){
    this -> dato = dat;
}

char* Global::getString(int size){
    return this -> dato = new char[size];
}

char* Global::leerDatos(char *dato){
    this -> ingreso.agregoChars(dato);
}

void Global::imprimirMensaje(char *str){
    printf("%s ", str);
}

void Global::imprimirNumero(){
    if((this -> ingreso.getDet()) == '\0' || (this -> ingreso.getDet()) == 'a'){
		printf("\n Su numero es %i, y es un entero", this -> ingreso.devolverInt(dato));
        
	}else if((this -> ingreso.getDet()) == 'f'){
		printf("\n Su numero es %f, y es un flotante",  this -> ingreso.devolverFloat(dato));
	}else{
		printf("\n No ha ingresado un numero valido, intente de vuelta");
    }
}



