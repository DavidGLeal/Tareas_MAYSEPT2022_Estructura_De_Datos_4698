#pragma once
#include "1ListaDC.h"
#include "3Celular.h"
#include "3Persona.cpp"


class Stock{

    private:
    
        ListaDobleC<Celular*> *lista = new ListaDobleC<Celular*>();
        ListaDobleC<Persona*> *personas = new ListaDobleC<Persona*>();  
        
    public:

        //Constructor y destructor
        Stock();
        ~Stock();

        //Setter y getters
        void setPersonas(ListaDobleC<Persona*>*);
        ListaDobleC<Persona*>* getPersonas();

        void setCelulares(ListaDobleC<Celular*>*); //Agregar una lista de celulares
        ListaDobleC<Celular*>* getCelulares();

        //Exepciones

        bool compararCelulares(Celular*);
        bool compararPersona(Persona*);
        void ordenarPorPrecio();
        double menorPrecioCelular();


        //Metodos
        bool eliminarCelular(Celular*);
        bool eliminarPersona(Persona*);
        Celular* retornarCelularporNombre(string);
        Persona* retornarPersonaporNombre(string, string, double, unsigned long);
        Persona* retornarPersonaporNombre(string, string, unsigned long);

        //Funciones impresion
        void verCelulares(); //Celulares disponibles
        void verStock(); // ver que celulares estan a la venta y su cantidad
        void verStock(Celular*); //Ver cuantos celulares hay de la isntancia
        void verPersonas();
        void informeCompraCelulares(); //Ver usuario y la compra de celulares que ha hecho

        //Funciones de dinamica de lista
        void agregarAlStock(Celular*); //Agregar un celular a la venta
        void agregarStockRepetido(Celular*);
        void agregarStockRepetido(Celular*,int);

        //Funcion de correo
        string generarCorreo(string, string);
        string generarCorreo(string, string, int);
       
};