/*ESPE
*Enunciado del problema:
*   Realizar los ejercicios de la pagina http://agora.pucp.edu.pe/inf2170681/25.htm
*   Enunciador 6
*Autor 
*   Sebastian Torres
*   Shared Tinoco
*   Camila Rivera
*   Mateo Roman
*Fecha de creacion
*   17-05-2022
*Fecha de modificacion
*   18 - 05 -2022
*Grupo #10 y #8
*Github del grupo:
* https://github.com/Grupo8-4698-EstructuraDeDatos/4698-Grupo8-EstructuradeDatos
*/


#include "Quebrado.cpp"

int main(){

    Quebrado A(2,3), B(5,6), C, D;
    C = A+B;
    C.imprimirObjeto();
    return 0;
}