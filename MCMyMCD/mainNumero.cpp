#include "Numero.cpp"
#include <iostream>
#include <vector>
using std::vector;
using namespace std;

int main(){

    // !Funciona bien
    Numero *c = new Numero("Ingrese los numeros con los que desea trabajar");

    //?Funciones de MCM y MCD
    std::cout << "\nEl maximo comun divisor de los numeros" << std::endl;
    c -> imprimirDatosVector();
    std::cout << "\nes: " << c -> obtenerMCD() <<std::endl;

    std::cout << "\nEl minimo comun multiplo de los numeros" << std::endl;
    c -> imprimirDatosVector();
    std::cout << "\nes: " << c -> obtenerMCM() <<std::endl;

    c ->~Numero();
    
    return 0;
}

