#include <iostream>
#include <cstring>
#include "Binario.cpp"

int main(){

    //?Ingreso por teclado
    int num;
    std::cout << "\nIngrese el binario que desea convertir: " << std::endl;
    std::cin >> num;
    //?Creo mi VI
    Binario *b = new Binario(num);
    b -> imprimirBinario();
    b -> ~Binario();
    return 0;
}