/*
	*Universidad de las Fuerzas Armadas "ESPE"
    *Enunciado del problema:
	    *Programa que realize los diferentes tipos de ordenamientos (internos y externos) y busquedas.
     *Autores:
        *Curso de Estructura de Datos NRC: 4698
	*Fecha de creacion: 
        * 21-06-2022
	*Fecha de modificacion:
        * 28-06-2022
    *GitHub del grupo:	
        *https://github.com/DavidGLeal/4698_Ordenamientos
*/

#include "4Busqueda.h"

void Busqueda::setVector(Vector &_vector){
    this->vector = _vector;
}

void  Busqueda::vaciarVector(){
    vector.vaciar();
}

void  Busqueda::setDato(int &a){
    this->dato = a;
}


void Busqueda::copiarVector(Vector &_vector){
    
    vector.vaciar();

    for(int i = 0; i < _vector.size(); i++){
        int num{_vector[i]};
        vector.push_back(num);
    }
}

void Busqueda::busquedaBinaria(){

    ordenado.setVector(vector);
    ordenado.ordenarBurbuja();
    copiarVector(ordenado.getVector());

    // for(int u = 0; u < vector.size(); u++){
    //     cout << vector[u] << " " <<endl;
    // }    
    //cout<< "1Entro"<<endl;
    int inf,sup,mitad,i;
    char band='F';//bandera sirve para comprobar si existe o no el elemento


    //Algoritmo de la Busqueda Binaria
    inf=0; //limite inferior del arreglo
    sup=vector.getElementos(); // limite superior del arreglo
    i=0;

    while((inf<=sup)&&(i<vector.getElementos())){
        //cout<< "Entro while"<<endl;
        mitad = (inf+sup)/2;

        // cout << mitad << " mitad"<<endl;
        // cout << vector[mitad] <<" mitad en vector"<<endl;
        // cout << dato <<" dato"<<endl;

        if(vector[mitad] == dato){
            band='V';
            break;
        }
        //cout<< "termino if1"<<endl;

        if(vector[mitad]>dato){
            sup = mitad;
            mitad = (inf+sup)/2;
        }
        //cout<< "termino if2"<<endl;
        if(vector[mitad]<dato){
            inf = mitad;
            mitad = (inf+sup)/2;
        }
        //cout<< "termino if3"<<endl;
        i++;
        //cout<< "termino ifs"<<endl;
    }
    //Enviar mensaje si se encontro o no el dato.
    if(band == 'V'){
        cout<<"El numero se encontro en la pos: "<< mitad <<endl;
    }
    else{
        cout<<"El numero NO se encontro";
    }

}

void Busqueda::busquedaSecuencial(){

    //cout<< "1Entro"<<endl;
	bool encontrado=false; //bandera
    int i=0;

    while (i<vector.getElementos() && encontrado==false){
        if(vector[i]==dato){
            encontrado=true; //cambia a verdadero la bandera si ha encontrado el elemento
        }
        i++;
    }
    if (encontrado==true){ //verificamos el estado de la bandera
        cout<<"El numero "<< dato <<" si se encuentra en el arreglo\n"<<"en la posicion "<<i<<endl;
    }else{
        cout<<"El numero "<<dato <<" no esta en la lista \n"<<endl;
    }    
}

void Busqueda::imprimirInterno(){
    imprimir(vector);
    cout<<"\n";
}

