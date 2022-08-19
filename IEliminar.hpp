#pragma once

template <typename T>
class Eliminar{

     public:
        virtual void eliminarInicio() = 0; //Método virtual puro o abstracto 
        virtual void eliminarFinal() = 0;
        virtual void eliminar(int) = 0;
};
