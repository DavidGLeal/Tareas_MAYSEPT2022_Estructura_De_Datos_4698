#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "Conversion.cpp"
#include "IngresoDatos.h"

using namespace std;

//Constructor
IngresoDatos::IngresoDatos(){
    this -> dato = new char[65]; //Creo un array para almacenar mis datos  
}   
//Destructor
IngresoDatos::~IngresoDatos(){
    delete [] dato; //Lo libero
} 

//Metodos privados

void IngresoDatos::imprimirMensaje(string str){
    cout<< str <<endl;
}

//Metodos publicos

char* IngresoDatos::leerDatosSinString(){
    char c;  //Creo un caracter, con el que voy a recibir el cada input
	int j = 0; //Iterador para la verifiacion del unico punto
	int i = 0; //Iterador para terminar el bucle, y asignar el valor final como nulo

    while(c != 13){ //Bucle hasta que se presion la tecla ENTER
        c=getch(); //Recibo el dato por teclado

        if(c >= '0' && c <= '9' ){
            printf("%c", c);
            dato[i] = c;
            ++i;

        }else if(c == 8){ //Si el input es un back space
			backspaceSinMensaje(&i, &j,  &c); //Funcion para la tecla backspace
            ++i;

        }   			     
    }

    dato[i]='\0';
    return dato;
}

//metodo pincipal
char* IngresoDatos::leerDatos(string mensaje){
    imprimirMensaje(mensaje);
    char c;  //Creo un caracter, con el que voy a recibir el cada input
	int j = 0; //Iterador para la verifiacion del unico punto
	int i = 0; //Iterador para terminar el bucle, y asignar el valor final como nulo

    while(c != 13){ //Bucle hasta que se presion la tecla ENTER
        c=getch(); //Recibo el dato por teclado

        if(c >= '0' && c <= '9' ){
            printf("%c", c);
            dato[i] = c;
            i++;

        }else if(c == 8){ //Si el input es un back space

			backspace(&i, &j,  &c, mensaje); //Funcion para la tecla backspace
            i++;
        }       			     
    }

    dato[i]='\0';
    return dato;
}



void IngresoDatos::backspace(int* i, int* j, char* c, string mensaje){

    if(*c >= '0' && *c <= '9'){
        if(*i != 0) --*i;
    }else {
        system("CLS"); //Limpio pantalla
        cout<< *i <<endl;
        imprimirMensaje(mensaje);
        for(int p = 0; p < *i-1; p++){
            printf("%c", dato[p]); //Imprimo de nuevo hasta el penultimo
        }

        if(*i != 0){ //Verifico que hay valores
            dato[--*i]='\0'; //Borro valor
            --*i; //Disminuto iterador
        }
    }
}

 void IngresoDatos::backspaceSinMensaje(int* i, int* j, char* c){

    if(*c >= '0' && *c <= '9'){
        if(*i != 0) --*i;
    }else {
        system("CLS"); //Limpio pantalla
        cout<< *i <<endl;
        for(int p = 0; p < *i-1; p++){
            printf("%c", dato[p]); //Imprimo de nuevo hasta el penultimo
        }

        if(*i != 0){ //Verifico que hay valores
            dato[--*i]='\0'; //Borro valor
            --*i; //Disminuto iterador
        }
    }
 }

int IngresoDatos::funcionPrincipal(string mensaje){
    return this -> conversion.numInt(leerDatos(mensaje));
}


int IngresoDatos::funcionPrincipal(){
    return this -> conversion.numInt(leerDatosSinString());
}