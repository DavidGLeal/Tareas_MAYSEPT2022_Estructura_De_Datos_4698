/* // Universidad_de_las_Fuerzas_Armadas_"ESPE"
//Tarea 6: Hash Abierto.
//Autores: Almeida, Andrés; Hernández Dylan.
//Fecha de Creación: 26/06/2022 10:09:10 AM
//Fecha de Modificación: 26/06/2022 23:26:00
//Grupo: 4 */

#include <iostream>
#include "HashAbierto.cpp"
#include "IngresarDatos.cpp"

using namespace std;

int main()
{
    HashAbierto tablaInt;
    HashAbierto tablaString;
    IngresarDatos* ing;
    int opcion = 0;
    do
    {
        system("cls");
        cout << "Bienvenida/o al Programa de Hashing Abierto!" << endl;
        cout << "1.- Ingresar Datos Enteros." << endl;
        cout << "2.- Ingresar Datos Tipo String." << endl;
        cout << "3.- Eliminar un Entero" << endl;
        cout << "4.- Eliminar un String." << endl;
        cout << "5.- Buscar un Entero." << endl;
        cout << "6.- Buscar un String." << endl;
        cout << "7.- Salir." << endl;
        opcion = ing->ingresarDatos("del menu");
        switch (opcion)
        {   
        case 1:
            system("cls");
            tablaInt.insertarDatoEntero(ing->ingresarDatos("a agregarse en la tabla hash de Enteros"));
            tablaInt.imprimir();
            system("pause");
            break;
        case 2:
            system("cls");
            tablaString.insertarDato(ing->ingresarDatosStringPermisivo("a agregarse en la tabla hash de Strings"));
            tablaString.imprimir();
            system("pause");
            break;
        case 3:
            system("cls");
            tablaInt.eliminarDatoEntero(ing->ingresarDatosStringPermisivo("a eliminarse en la tabla hash de Enteros"));
            tablaInt.imprimir();
            system("pause");
            break;
        case 4:
            system("cls");
            tablaString.eliminarDatoString(ing->ingresarDatosStringPermisivo("a eliminarse en la tabla hash de Strings"));
            tablaString.imprimir();
            system("pause");
            break;
        case 5:
            system("cls");
            tablaInt.buscarDatoEntero(ing->ingresarDatos("a buscarse en la tabla hash de Enteros"));
            tablaInt.imprimir();
            system("pause");
            break;
        case 6:
            system("cls");
            tablaString.buscarDato(ing->ingresarDatosStringPermisivo("a buscarse en la tabla hash de Strings"));
            tablaString.imprimir();
            system("pause");
            break;
        case 7:
            cout << "Ha salido del programa."<<endl;
            system("pause");
            break;
        default:
            cout << "Ingrese un dato valido."<<endl;
            system("pause");
        }
    }
    while (opcion != 7);
    return 0;
}
