#pragma once 
#include <iostream>
#include "Nodo.cpp"

class HashAbierto
{
    private:
        NodoCircular** tablaHash;
    public:
        HashAbierto();
        ~HashAbierto();
        int hashEntero(int _dato);     
        int hash(std::string _dato);     
        void insertarDato(std::string _dato);
        void insertarDatoEntero(int _dato);
        void buscarDatoEntero(int _dato);
        void buscarDato(std::string _dato);
        void eliminarDatoEntero(std::string _dato);
        void eliminarDatoString(std::string _dato);
        void imprimir();
};