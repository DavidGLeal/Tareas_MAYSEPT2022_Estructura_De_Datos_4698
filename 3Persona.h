#include <iostream>
#include <string>
#include "3Celular.cpp"
#include "1ListaDC.hpp"
#include "2ItoString.h"
#include "2ICedula.h"

using namespace std;

class Persona: public ToString, public Cedula{
    private:
        string nombre;
        string apellido;
        long cedula;
        double presupuesto;
        string correo = "Aun no asignado";
        ListaDobleC<Celular*> *comprados = new ListaDobleC<Celular*>();     

    public:

        Persona(string, string, double, long);
        Persona();
        ~Persona();

        long getCedula(){
            return this->cedula;
        }

        void setCorreo(string c){
            this->correo = c;
        }

        string getApellido(){
            return this->apellido;
        }

        string getCorreo(){
            return this->correo;
        }

        void comprarCelular(Celular*); //Comprar un celular a su nombre
        bool verificarCelular(Celular*);
        void comprarCelular(Celular*, int); 
        bool disminuirPresupuesto();
        void verComprados(); //Ver que celulares ha comprado la persona en cuestion

        //Getter y setters
        string getNombre();
        double getPresupuesto();
        ListaDobleC<Celular*>* getComprados();

        void setNombre(string);
        void setPresupuesto(double);
        void setComprados(ListaDobleC<Celular*>*);
        string toString();

        void generarCorreo();
        void generarCorreoRepetido();
};