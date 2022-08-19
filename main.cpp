/*ESPE
*Enunciado del problema:
*   realizar codigo binario
*Autor 
* Camila Rivera
* Ariel Jara
*Fecha de creacion
*   14-06-2022
*Fecha de modificacion
*   14 - 06 -2022
*Grupo #2 y #17
*Github del grupo:
* https://github.com/Grupo8-4698-EstructuraDeDatos/4698-Grupo8-EstructuradeDatos
*/

#include <iostream>
using namespace std;
#include "Pila.hpp"
#include "5IngresoDatos.hpp"
#include <chrono>
using namespace std::chrono;

int main(){

    Pila<int> *pila = new Pila<int>();
    IngresoDatos<int, float> *i = new IngresoDatos<int, float>();

    int num{0};
    num = i->funcionPrincipalEnteros("Ingrese el numero decimal que desea convertir a binario: ");
    cout<< "\nSu equivalente en binario es: ";
    pila->binarios(num);

    cout<< "\nSu equivalente en binario usando recursion es: ";
    //!Tomo el tiempo
    auto start = high_resolution_clock::now();
    pila->binarioRecursivo(num);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nTiempo de ejecucion de la funcion: "
    << duration.count() << " microsegundos" << endl;

    return 0;
}