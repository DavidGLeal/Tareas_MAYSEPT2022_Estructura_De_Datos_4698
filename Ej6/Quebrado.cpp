#include "Quebrado.h"

Quebrado::Quebrado (int n, int d){
    this -> numerador = n;
    this -> denominador = d;
}

Quebrado::Quebrado(){
    this -> numerador = 0;
    this -> denominador = 0;
}

Quebrado Quebrado::operator + (Quebrado &Q)
{    return Quebrado (numerador * Q.DameDen()+ Q.DameNum()* denominador , 
                      denominador * Q.DameDen());
}

void Quebrado::DefineNum (int n){
    this -> numerador = n;
}

void Quebrado::DefineDen (int d){
    this -> denominador = d;
}

int Quebrado::DameNum (void){
    return this -> numerador;
}

int Quebrado::DameDen (void){
    return this -> denominador;
}

void Quebrado::imprimirObjeto(){
    std::cout << this ->  numerador << std::endl;
    std::cout << "\\" << std::endl;
    std::cout << this ->  denominador << std::endl;
}