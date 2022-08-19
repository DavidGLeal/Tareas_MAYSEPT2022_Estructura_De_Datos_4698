/****************************
*          UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE

* AUTOR(es):  CALAPAQUI GENESIS,JARA ARIEL,RIVERA CAMILA,ROMAN MATEO.
* FECHA DE Inicio:  03 DE AGOSTO DE 2022
* FECHA DE Entrega: 05 DE AGOSTO DE 2022
* Version: 1
* ESTRUCTURA DE DATOS
* NRC: 4698
*****************************/

#include <iostream>
#include <fstream>
using namespace std;
#pragma once
   
class Tablero{
    private:
        char **tablero;
        int longitud;
        int contador{1};
        char relleno;
        fstream archivo;

    public:
        Tablero(int longitud = 8, char relleno= '*') : longitud{longitud}, relleno(relleno), tablero(new char*[longitud]){

            for(int i = 0; i < longitud; i++)
                *(tablero + i) = new char[longitud];

            for(int i = 0; i < longitud; i++){
                for(int j = 0; j < longitud; j++){
                    *(*(tablero + i) + j) = relleno;
                }
            }

            archivo.open("backtraking.txt",fstream::out);

        }

        ~Tablero(){
            delete [] tablero;
        }

        void imprimirSolucion(){

            cout << "Solucion N" << contador <<endl;
            for(int i = 0; i < longitud; i++){
                for(int j = 0; j < longitud; j++){
                    cout<< *(*(tablero + i) + j)<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
            contador++;
        }

        void generarSolucionTxt(){

            archivo.open("backtraking.txt",fstream::app);
            if(archivo.is_open()){

                archivo << "Solucion N" << contador <<endl;
                for(int i=0;i<longitud;i++){
                    for(int j=0;j<longitud;j++){
                        archivo<<*(*(tablero+i)+j)<<" ";
                    }

                    archivo<<endl;
                }
                archivo<<endl;

            }else{
                cout<< "\n Ocurrio un error con el txt" <<endl;
            }
        }

        bool estaReinaEnColumna(int fila, int columna){
            for (int i = 0; i < fila; i++){
                if (*(*(tablero + i) + columna) == 'R'){
                    return true;
                }
            }
            return false;
        }

        bool estaReinaDiagonal(int fila, int columna){
            
            for (int i = fila, j = columna; i >= 0 && j >= 0; i--, j--){
                if (*(*(tablero + i) + j) == 'R') {
                    return true;
                }
            }
        
            // /
            for (int i = fila, j = columna; i >= 0 && j < longitud; i--, j++){
                if (*(*(tablero + i) + j) == 'R') {
                    return true;
                }
            }

            return false;
        } 

        bool esSolucion(int fila, int columna){

            if(!(estaReinaEnColumna(fila,columna)) && !(estaReinaDiagonal(fila,columna))){
                return true;
            }

            return false;
        }       

        void solucionar(int fila){

            //  Si las N reinas estan puestas correctamente, imprimir la solucion.
            if (fila == longitud)
            {   
                generarSolucionTxt();
                imprimirSolucion();
                return;
            }
        
            // Se pone la reina en cada fila 
            //  y luego se checa por lugares correctos
            for (int i = 0; i < longitud; i++){
                // Si dos reinas no se amenazan
                if (esSolucion(fila, i)){
                    // Se coloca a la reina en esa posicion
                    *(*(tablero + fila) + i) = 'R';
        
                    // Se pasa a la siguiente fila
                    solucionar(fila + 1);
        
                    // Se reliza backtracking y se remueve la reina del lugar
                    *(*(tablero + fila) + i) = relleno;
                }
            }

            archivo.close();
        }

};