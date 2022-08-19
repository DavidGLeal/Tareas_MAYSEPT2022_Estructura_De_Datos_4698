/*ESPE
*Enunciado del problema:
*   Realizar el codigo de la catedra en clases (POO)
*Autor 
*   Camila Rivera
*Fecha de creacion
*   16-05-2022
*Fecha de modificacion
*   16 - 05 -2022
*Grupo #2
*Github del grupo:
* https://github.com/Grupo8-4698-EstructuraDeDatos/4698-Grupo8-EstructuradeDatos
*/

#include "Sobrecarga.cpp"

int main(){

    Sobrecarga *s = new Sobrecarga();

    printf("%i \n", s -> suma(2));
    printf("%f \n", s -> suma(2,5));
    printf("%f \n", s -> suma(2,4.6));
    printf("%s \n", s -> suma(3,4,5));
  
    return 0;
}