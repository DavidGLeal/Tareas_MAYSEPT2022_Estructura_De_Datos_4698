#pragma once

template <typename T>

class Insertar{

     public:
        virtual void insertarFinal(T) = 0; //Método virtual puro o abstracto 
        virtual void insertarInicio(T) = 0;
        virtual void insertar(T, int) = 0;
};