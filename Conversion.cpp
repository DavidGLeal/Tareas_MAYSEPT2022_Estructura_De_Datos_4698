#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "Conversion.h"

using namespace std;

//Constructor
Conversion::Conversion(){}
//Destructor
Conversion::~Conversion(){}

//Metodos privados
int Conversion::numInt(char* dato){
    return atoi(dato); //String a int
}

void Conversion::convertir(char* dato){
        cout << "\nSu numero es "<< numInt(dato) << " y lo ha agregado a la lista simple" <<endl; //Imprimo entero
}