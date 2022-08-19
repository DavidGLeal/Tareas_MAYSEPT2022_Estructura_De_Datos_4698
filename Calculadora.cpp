#include <iostream>
#include "Calculadora.h"

using namespace std;
#pragma once
   
double Calculadora::suma(double a, double b){
    return a + b;
}

double Calculadora::resta(double a, double b){
    return a - b;
}

double Calculadora::multiplica(double a, double b){
    return a * b;
}

//!exepcion de 0
double Calculadora::division(double a, double b){
    return a / b;
}

double Calculadora::exponente(double a, double b){
    return pow(a,b);
}

//!exepcion de 0
double Calculadora::raiz(double a, double b){
    // cout << 1/b <<endl;
    // cout << a << endl;

    // cout <<  pow(a,1/b) <<endl;
    // system("pause");
    return pow(a,1/b);
}

//?Trigonometricas
//!en radianes

double Calculadora::sen(double a){
    return sin(a);
}

double Calculadora::cs(double a){
    return cos(a);
}

double Calculadora::tg(double a){
    return tan(a);
}

//!excepciones de 0

double Calculadora::csen(double a){
    return 1/sin(a);
}

double Calculadora::scs(double a){
    return 1/cos(a);
}

double Calculadora::ctg(double a){
    return 1/tan(a);
}

//?Hiperbolicas

double Calculadora::senh(double a){
    return sinh(a);
}

double Calculadora::csh(double a){
    return cosh(a);
}

double Calculadora::tgh(double a){
    return tanh(a);
}

double Calculadora::arcsen(double a){
    //cout<< "arcsin " << asin(a)<<endl; 
    return asin(a);
}

double Calculadora::arccos(double a){
    //cout<< "arccos " << acos(a)<<endl; 
    return acos(a);
}

double Calculadora::arctan(double a){
    //cout<< "arctan " << atan(a)<<endl; 
    return atan(a);
}

//? Logaritmos

// //!manejo de excepcion > 0

double Calculadora::ln(double a){
    return log(a);
}

double Calculadora::ln10(double a){
    return log10(a);
}

// //!manejo excepcion log b = 0
double Calculadora::logc(double a, double b){
    return log(a)/log(b);
}

//?Excepciones

bool Calculadora::esCero(double a){
    return a == 0;
}

bool Calculadora::esMenorQueCero(double a){
    return a < 0;
}

bool Calculadora::rangoArc(double a){
    return a >= -1 && a<=1;
}
