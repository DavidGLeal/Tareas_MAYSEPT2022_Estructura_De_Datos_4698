#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
#include "t3ConversionInt.h"

//Constructor

ConversionInt::ConversionInt(){
}

//Definicion de metodos

bool ConversionInt::verificar(char c){
    if (c == 46){
        return false;
    }else{
        return true;
    }
}

int ConversionInt::numInt(char* dato){
    return atoi(dato);
}
