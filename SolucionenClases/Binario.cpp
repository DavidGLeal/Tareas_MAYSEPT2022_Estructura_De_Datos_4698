#include "Binario.h"
#include <iostream>
#include <cstring>

Binario::Binario(long numero){
    this -> num = numero;
    this -> cad = new char[65];   
}

Binario::~Binario(){
    delete [] cad;
}
    
void Binario::decimalBinario(long num){
     if(num >= 1){
        decimalBinario(num/2);
                    //Avanzo en posicion
        itoa(num%2, cad + strlen(cad), 10);
    }
    strcat(cad,"\0");
}

void Binario::imprimirBinario(){
    cad[0] = '\0'; 
    decimalBinario(this -> num);
    printf("%s ", cad);
}