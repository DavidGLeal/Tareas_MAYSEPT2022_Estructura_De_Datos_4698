/*ESPE
*Enunciado del problema:
*   Realizar los ejercicios de la pagina http://agora.pucp.edu.pe/inf2170681/25.htm
*   Enunciado 1
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

#include "Reloj.cpp"

int main(){

    Reloj R(10,59,56);
    for (int i=0; i<10; i++, ++R)
    cout <<setw(4)<< R.Hora() <<setw(4)<< R.Minuto() 
         <<setw(4)<< R.Segundo() << endl;
         
    return 0;
}