/*ESPE
*Enunciado del problema:
*   A partir del codigo de clase, separar las funciones principales
*   en clases.
*Autor 
*   Camila Rivera
*   Mateo Roman
*Fecha de creacion
*   11-05-2022
*Fecha de modificacion
*   13 - 05 -2022
*Grupo #8
*Github del grupo:
* https://github.com/Grupo8-4698-EstructuraDeDatos/4698-Grupo8-EstructuradeDatos
*/
#include "t1IngresoDatos.cpp"

int main(){
    
    Dato *dat = new Dato(); //instanciar un objeto
    int valor=0;
    char *dato;

    dato = dat->ingresarDatosEnteros("Ingrese el dato");
    valor = dat -> convertirEntero(dato);
    valor = dat -> getDoble(valor);

    printf("\nresultado %d......",valor);
    

    return 0;
}