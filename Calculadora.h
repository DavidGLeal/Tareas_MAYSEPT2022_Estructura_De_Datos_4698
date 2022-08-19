#include <iostream>
#include <math.h> 
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
#pragma once
   
class Calculadora{
    private:
        
    public:
        Calculadora(){
        }

        ~Calculadora(){
        }

        //?Operaciones

        double suma(double a, double b);

        double resta(double a, double b);

        double multiplica(double a, double b);

        double division(double a, double b);

        double exponente(double a, double b);

        double raiz(double a, double b);

        //?Trigonometricas

        double sen(double a);

        double cs(double a);

        double tg(double a);

        double csen(double a);

        double scs(double a);

        double ctg(double a);

        double senh(double a);

        double csh(double a);

        double tgh(double a);

        //?Logaritmicas

        double ln(double a);

        double ln10(double a);

        double logc(double a, double b);

        bool esCero(double a);

        bool esMenorQueCero(double a);

        bool rangoArc(double a);

        double arcsen(double a);

        double arccos(double a);

        double arctan(double a);
};