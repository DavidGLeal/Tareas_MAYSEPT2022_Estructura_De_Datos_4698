#pragma once
#include <string>
#include "2ItoString.h"

class Celular: public ToString {
    private:
        string marca;
        double precio;
        int stock;

    public:

            /**
         * @param 
         * @param 
         * @param
         */
        Celular(string, double, int);
        Celular();
        ~Celular();

        //Getters y setters

        string getMarca();
        double getPrecio();
        int getStock();
       
          /**
         * @param string
         */
        void setMarca(string);
          /**
         * @param double
         */
        void setPrecio(double);
        /**
         * @param int
         */
        void setStock(int);
        /**
         * @param int
         */
        void aumentarStock(int);

        bool disminuirStock();

        /**
         * @param int
         */
        bool disminuirStock(int);
        string toString();

        /**
         * @param &Celular
         */
        bool operator ==(Celular&);

         /**
         * @param *Celular
         */
        bool operator ==(Celular*);

        /**
         * @param num1
         * @param num2
         * @param deltaMax
         */
        bool iguales (double num1, double num2, double deltaMax);

};