#include "Nodo.h"

class ListaEnlazada{

    private:
        Nodo *primero = nullptr;
        Nodo *ultimo = nullptr;
    public:

        ListaEnlazada();
        ~ListaEnlazada();
        void agregarFinal(int);
        void imprimirCabeza();
};