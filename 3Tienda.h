#pragma once
#include "1ListaDC.hpp"
#include "3Celular.cpp"
#include "3Persona.cpp"
#include "3Stock.cpp"

class Tienda{

    private: 
        Stock *stock = nullptr;
 
    public:    

        Tienda();
        ~Tienda();

        bool estaVacio();
        void setStock( Stock *);
        Stock* getStock();
        ListaDobleC<Celular*>* recomendarCelulares(Persona*); //Recomendar automaticamente a la persona un celular por presupuesto
        ListaDobleC<Celular*>* celularesPorPresupuestoMenor(double); //Devolver los celulares menores o iguales que el presupuesto
        ListaDobleC<Celular*>* celularesPorPresupuestoMayor(double); //Devolver celulares mayores o iguales que el presupuesto

        ListaDobleC<Persona*>* personasPorPresupuestoIgual(double);
		ListaDobleC<Persona*>* personasPorNombreIgual(string);

        ListaDobleC<Celular*>* celularesPorPrecioIgual(double);
		ListaDobleC<Celular*>* celularesPorMarcaIgual(string);
    
};
