#include <iostream>
#include "Numero.h"
#include <vector>
#include <string>
using std::vector;
using namespace std;

Numero::Numero(string s){
    this -> nums = creacionVector(s);
}

Numero::~Numero(){
}

vector<int> Numero::creacionVector(string s){
    vector<int> nums;
    int num = 1;
    std::cout << "\n"<< s << std::endl;
    std::cout << "Si ha terminado, escriba \"0\" " << std::endl;
    
    while (num != 0){
        std::cin >> num;
        if (num != 0){
            nums.push_back(num);
        }
    }

    return nums;
}

int Numero::euclidesMCD(int A, int B){

    if (A == 0){
        return B;
    }else if (B == 0){
        return A;
    }else{
        return euclidesMCD(B, A%B);
    }

}

int Numero::MCM(int A, int B){
    return (A*B)/euclidesMCD(A,B);
}

int Numero::obtenerMCD(){
    auto i = nums.begin();
    int total = *i;
    ++i;
    
    for ( i; i != nums.end(); ++i) {
        total = euclidesMCD(total, *i); 
    }

    return total;
}

int Numero::obtenerMCM(){
    auto i = nums.begin();
    int total = *i;
    ++i;
    
    for ( i; i != nums.end(); ++i) {
        total = MCM(total, *i); 
    }

    return total;
}


void Numero::imprimirLongitudVector(){
    std::cout << "Longitud del vector: " << nums.size() << std::endl;
}

void Numero::imprimirDatosVector(){
    for (auto i = nums.begin(); i != nums.end(); ++i)
        std::cout << *i << " ";
}
