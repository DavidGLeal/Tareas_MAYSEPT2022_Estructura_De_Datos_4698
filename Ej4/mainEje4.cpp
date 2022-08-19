/*ESPE
*Enunciado del problema:
*   Realizar los ejercicios de la pagina http://agora.pucp.edu.pe/inf2170681/25.htm
*   Enunciador 4
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


#include "Ejer4.cpp"

int main(){

    Complejo A(1.5,2.3), B(5.2,4.7), C(1.1,0.4), D;
     D= A + B - C;
     cout << "D = " << D.DameR()<<" + "<< D.DameI() << "i"
          << endl;
    return 0;
}
