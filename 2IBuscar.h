/*ESPE
*Enunciado del problema:
*   Realizar el codigo de la catedra en clases (POO)
*Autor 
* Camila Rivera
* Christian Román
*Fecha de creacion
*   10-06-2022
*Fecha de modificacion
*   10 - 06 -2022
*Grupo #2
*Github del grupo:
* https://github.com/Grupo8-4698-EstructuraDeDatos/4698-Grupo8-EstructuradeDatos
*/
#pragma once

template <typename T>
/**
 * IBuscar implementation
 */

class Buscar{

     public:

        /**
        * @param 
        * @return buscar
        */
        virtual int buscar(T) = 0; //Método virtual puro o abstracto 
        /**
        * @param 
        * @return imprimirBuscar
        */
        virtual void imprimirBuscar(T) = 0;
};