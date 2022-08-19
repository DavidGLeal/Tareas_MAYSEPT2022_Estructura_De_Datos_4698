/*ESPE
*Enunciado del problema:
*   Realizar los ejercicios de la pagina http://agora.pucp.edu.pe/inf2170681/25.htm
*   Enunciador 8
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


#include "claseB.cpp"

int main()
{    B Ob;

     cout << "Ingrese datos :" << endl;
     while (1)
     {    int p;
          cin >> p;
          if (p<=0) break;
          Ob.Ingresa(p);
     }
     cout << "Datos leidos :" << endl;
     for (int i=0; i<Ob.DameCant(); i++)
     cout << Ob[i] << endl;

     return 0;
}
