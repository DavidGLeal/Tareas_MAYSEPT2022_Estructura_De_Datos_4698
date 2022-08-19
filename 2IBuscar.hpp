#pragma once

template <typename T>
class Buscar{

     public:
        virtual int buscar(T) = 0; //Método virtual puro o abstracto 
        virtual void imprimirBuscar(T) = 0;
};