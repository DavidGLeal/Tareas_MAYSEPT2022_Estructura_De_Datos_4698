#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
#include "t2ConversionFloat.h"

//Constructor

ConversionFloat::ConversionFloat(){
}

//Definicion de metodos

bool ConversionFloat::verificar(char c){
    if (c == 46){ // 46 codigo ASCII del punto (.)
        return true;
    }else{
        return false;
    }
}

float ConversionFloat::numFloat(char* dato){
    return std::stof(dato);
}
