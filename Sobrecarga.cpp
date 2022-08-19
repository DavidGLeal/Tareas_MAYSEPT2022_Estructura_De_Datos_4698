#include "Sobrecarga.h"

//Constructor

Sobrecarga::Sobrecarga(){

}

//Definicion de metodos

int Sobrecarga::suma(int n){
    return n*5;
}

float Sobrecarga::suma(int n,int m){
    return (float)n*(float)m;
}

double Sobrecarga::suma(int n, double f){
    return (double)n*f;
}

char* Sobrecarga::suma(int a,int b,int c){  
    return "hola mundo";
}
