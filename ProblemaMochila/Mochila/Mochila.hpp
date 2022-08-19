#pragma once
#include <iostream>
#include "Objeto.hpp"

using namespace std;

class Mochila{

    private:
        int capacidad{0};
        int cantObjetos{0};
        Objeto* objetos;
        Objeto* resultados;
        int longitudResultado{0};

        bool seRepite(Objeto &m){

            for(int i = 0; i < longitudResultado; i++){
                if(resultados[i] == m){
                    return true;
                }
            }

            return false;
        }

        int max(int x, int y) {
          return (x > y) ? x : y;
        }

    public:

    Mochila(int capacidad, int cantObjetos, Objeto* objetos):capacidad(capacidad), cantObjetos(cantObjetos), objetos(objetos), resultados(new Objeto[cantObjetos]){
    }
    
    Mochila(){
    }

    ~Mochila(){
    }

    int getCapacidad(){
        return this->capacidad;
    }
    
    void setCapacidad(int par){
        this->capacidad = par;
    }

    int solucion(int cantObjetos, int capacidad){

        int resultado;

        if(cantObjetos == 0 || capacidad == 0){
            resultado = 0;

        }else if(objetos[cantObjetos].getPeso() > capacidad){
            resultado = solucion(cantObjetos-1,capacidad);
        }else{
            int aux1 = solucion(cantObjetos-1,capacidad);
            int aux2 = objetos[cantObjetos].getValor() + solucion(cantObjetos-1, capacidad - objetos[cantObjetos].getPeso());
            resultado = max(aux1, aux2);

            if(aux2 > aux1){
              
                if(!(seRepite(objetos[cantObjetos]))){
                    resultados[longitudResultado] = objetos[cantObjetos];
                    longitudResultado++;
                }
                
                cout << objetos[cantObjetos].getPeso() << " " << objetos[cantObjetos].getValor() <<endl;
            }

        }

        return resultado;
    }

    void obtenerBeneficio(){
        cout << "Solucion: " << solucion(cantObjetos, capacidad);

        for(int i = 0; i < longitudResultado; i++){
            cout << "\nSoluciones anexadas: " << resultados[i].getPeso() << " " << resultados[i].getValor() <<endl;
        }
    }

};