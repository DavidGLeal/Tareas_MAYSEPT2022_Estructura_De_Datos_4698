#pragma once
#include "1ListaDC.h"
#include "3Celular.cpp"
#include "3Persona.cpp"
#include "3Stock.cpp"
#include <fstream>
#include <string>


class Tienda{

    private: 
        Stock *stock = nullptr;
 
    public:    

        Tienda();
        ~Tienda();
        bool estaVacio();

        void setStock( Stock *);
        Stock* getStock();

        //Recomendaciones de compra        
        ListaDobleC<Celular*>* recomendarCelulares(Persona*); //Recomendar automaticamente a la persona un celular por presupuesto
        ListaDobleC<Celular*>* celularesPorPresupuestoMenor(double); //Devolver los celulares menores o iguales que el presupuesto
        ListaDobleC<Celular*>* celularesPorPresupuestoMayor(double); //Devolver celulares mayores o iguales que el presupuesto

        //Devuelven listas de objetos que cumplan con ciertos requisitos
        ListaDobleC<Persona*>* personasPorPresupuestoIgual(double);
		ListaDobleC<Persona*>* personasPorNombreIgual(string, string);
        ListaDobleC<Persona*>* personasIgual(string, string, double, int);
        ListaDobleC<Persona*>* personasIgual(string nombre, string apellido, unsigned long cedula);

        ListaDobleC<Celular*>* celularesPorPrecioIgual(double);
		ListaDobleC<Celular*>* celularesPorMarcaIgual(string);

        //Funciones para el menu

        void agregarCelularTienda(Celular*);
        void agregarCelularTiendaSinString(Celular*);

        void eliminarCelularTienda(Celular*);
        void buscarPorNombreCelular(string);
        void buscarPorPrecioCelular(double);

        void agregarPersonaTienda(Persona*);
        void agregarPersonaSinString(Persona*);
        void eliminarPersonaTienda(Persona*);
        void buscarPorNombrePersona(string, string);
        void buscarPorPresupuestoPersona(double);

        void comprarCelular(string, string, string, double, long);
        void comprarCelular(string, string, string, double, int, long);
        void comprarCelular(string, string, string, long);
        void comprarCelular(string, string, string, int, long);
        void comprarCelular(Persona*, Celular*);
        void comprarCelular(Persona*, Celular*, int);

        bool recomendarAutomatico(string, string, double, int);
        bool recomendarMenores(double);
        bool recomendarMayores(double);
        void establecerCorreos();

        //Validaciones
        bool cedulaCorrecta(unsigned long);
        bool stockCorrecto(int);
        bool presupuestoCorrecto(double);

        //Leer txts
        void importarCelulares(string);
        void importarPersonas(string);

        void exportarCelulares(string);
        void exportarPersonas(string);
        void exportarInforme(string);



    
};
