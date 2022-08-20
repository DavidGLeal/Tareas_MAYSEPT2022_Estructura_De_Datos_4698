#pragma once 
#include <iostream>

class NodoCircular
{
    private:
        std::string dato;
        NodoCircular *siguiente;
    public:
        NodoCircular();
        NodoCircular(std::string _dato);
        ~NodoCircular();
        std::string getDato();
        void setDato(std::string _dato);
        NodoCircular *getSiguiente();
        void setSiguiente(NodoCircular* _siguiente);
};