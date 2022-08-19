/****************************
*          UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
* AUTOR(es):  CALAPAQUI GENESIS,JARA ARIEL,RIVERA CAMILA,ROMAN MATEO.
* FECHA DE Inicio:  9 DE AGOSTO DE 2022
* FECHA DE Entrega: 10 DE AGOSTO DE 2022
* Version: 3
* ESTRUCTURA DE DATOS
* NRC: 4698
*****************************/

#include <iostream>
#include <fstream>
#include<math.h>
using namespace std;
#pragma once

class CuadradoMagico{

    private:

        int** cuadrado; 
        fstream archivo;
        int n; //n
        int centinela;
        int patron;

       
        //! Metodos Generales
        /**
         * Establece todos los valores en la matriz a 0
         */
        void encerar(){

            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    *(*(cuadrado + i) + j) = 0;
                }
            }

        }

        /**
         * Imprime el contenido de la matriz.
         */
        void imprimir(){

            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    if(j==n-1) printf("%4d\n",cuadrado[i][j]);
                    else printf("%4d",cuadrado[i][j]);
        }

       /**
        * Abre un archivo, escribe en él y lo cierra.
        * 
        * @param metodo Numero de metodo
        */
        void exportarTxt(int metodo){

            archivo.open("cuadradoMagico.txt", fstream::app);
            if(archivo.is_open()){

                archivo << "Metodo " << metodo <<endl;

                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        archivo<< *(*(cuadrado+i)+j) << " ";
                    }

                    archivo<<endl;
                }
                archivo<<endl;

            }else{
                cout<< "\n Ocurrio un error con el txt" <<endl;
            }

            archivo.close();
        }

    

    public:

    CuadradoMagico(int n, int centinela, int patron): cuadrado(new int*[n]), n(n), centinela(centinela), patron(patron){

        for(int i = 0; i < n+1; i++)
                *(cuadrado + i) = new int[n];

        encerar();
        archivo.open("cuadradoMagico.txt",fstream::out);
        archivo.close();
    }
    
    ~CuadradoMagico(){
        delete [] cuadrado;
    }

   void impar(){
        int x=0, y=n/2;
        int aux{centinela};
        for(int i=1; i<=n*n; i++)
        {
            cuadrado[x][y]=aux;
            aux = aux + patron;
            x--;                                 // Completa la esquina superior derecha a su vez
            y++;
            if(x<0 && y>n-1) {x=x+2; y=y-1;}     // Exceder diagonalmente
            else if(x<0) x=x+n;                  // Exceder a lo largo del límite superior
            else if(y>n-1) y=y-n;                // Exceder a lo largo del límite derecho
            else if(cuadrado[x][y]!=0) {x=x+2; y=y-1;}  // La esquina superior derecha está llena
        }
    }

    bool confirmar(){
        int cnt=n*(n*n+1)/2;                                // Suma de cada fila, columna y diagonal
        for(int i=0; i<n; i++)
        {
            int sum_row=0,sum_line=0;
            for(int j=0; j<n; j++)
                {
                    sum_row+=cuadrado[i][j];                       // Revisa las líneas
                    sum_line+=cuadrado[j][i];                      // Revisa las columnas
                }
            if(sum_row!=cnt || sum_line!=cnt) return false;
        }
        int sum_left=0,sum_right=0;
        for(int i=0; i<n; i++)
        {
            sum_left+=cuadrado[i][i];                              // Comprueba la diagonal izquierda
            sum_right+=cuadrado[n-i-1][i];                         // Comprueba la diagonal derecha
        }
        if(sum_left!=cnt || sum_right!=cnt) return false;
        return true;

    }

    void resolver(){
        ios::sync_with_stdio(false);
        impar();
        imprimir();

    }

};