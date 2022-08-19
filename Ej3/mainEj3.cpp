/*ESPE
*Enunciado del problema:
*   Realizar los ejercicios de la pagina http://agora.pucp.edu.pe/inf2170681/25.htm
*   Enunciador 3
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


#include "Cadena.cpp"

int main ()
{    Cadena C1("Juan ") , C2("Lopez");
     C1+C2;
     cout << "Atributo de C1 = " << C1.DameCadena() << endl;

    return 0;
}
