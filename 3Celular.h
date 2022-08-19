#pragma once
#include <string>
#include "2ItoString.h"

class Celular: public ToString {
    private:
        string marca;
        double precio;
        int stock;
        int cantidad =0;

    public:
        Celular(string, double, int);
        Celular();
        ~Celular();

        //Getters y setters

        string getMarca();
        double getPrecio();
        int getStock();
        int getCantidad();

        void setMarca(string);
        void setPrecio(double);
        void setStock(int);
        void setCantidad(int);
        void aumentarCantidad(int);

        bool disminuirStock();
        bool disminuirStock(int);
        string toString();
        bool operator ==(Celular);
        bool operator ==(Celular*);
        bool iguales (double num1, double num2, double deltaMax);

};