/****************************
*          UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
*
* AUTOR(es):  CALAPAQUI GENESIS,JARA ARIEL,RIVERA CAMILA,ROMAN MATEO.
* FECHA DE Inicio:  13 DE AGOSTO DE 2022
* FECHA DE Entrega: 14 DE AGOSTO DE 2022
* Version: final
* ESTRUCTURA DE DATOS
* NRC: 4698
*****************************/

#include <iostream>
#include <fstream>
#include <string.h>
#include <cmath>
#include <cstdio>
#include "Moneda.hpp"
using namespace std;
#pragma once
   
class Cambio{
  private:
    float cambio;
    Moneda *dinero;
    Moneda *resultado;
    int longitudResultado{0};
    int longitudDinero{0};

    bool hayDineroSuficiente(){

      float aux{0};

      for(int i = 0; i < 11; i++){
        aux += dinero[i].getCantidad()*dinero[i].getValor();
      }

      return cambio <= aux;
    }

   /**
   * Comprueba si una moneda ya está en la matriz de resultados
   * 
   * @param m es la moneda que se está comprobando si se repite.
   * 
   * @return un valor booleano.
   */
    bool seRepite(Moneda &m){

      for(int i = 0; i < longitudResultado; i++){
          if(resultado[i] == m){
              return true;
          }
      }

      return false;
    }

    /**
     * Devuelve el índice de la primera aparición de la Moneda m en el arreglo dinero, o -1 si m no
     * está en dinero
     * 
     * @param m Moneda &
     * 
     * @return La posición de la moneda en la matriz.
     */
    int posRepetidoDinero(Moneda &m){

      for(int i = 0; i < 11; i++){
          if(dinero[i] == m){
              return i;
          }
      }

      return -1;
    }

    /**
     * Devuelve la posición de la primera aparición de una moneda en la matriz de resultados, o -1 si
     * la moneda no está en la matriz.
     * 
     * @param m es un objeto Moneda
     * 
     * @return La posición del elemento repetido en la matriz.
     */
    int posRepetidoResultado(Moneda &m){

      for(int i = 0; i < longitudResultado; i++){
          if(resultado[i] == m){
              return i;
          }
      }

      return -1;
    }

    /**
     * Toma un flotante, lo multiplica por 100, le suma 0.5, lo convierte en un int y luego lo divide
     * por 100
     * 
     * @param var La variable a redondear
     * 
     * @return el valor redondeado de la variable.
     */
    float redondear(float var){
      float value = (int)(var * 100 + .5);
      return (float)value / 100;
    }

    bool sumaCorrecta(){
      float suma{0};

      for(int i =0; i < longitudResultado; i++){
        suma += resultado[i].getValor()*resultado[i].getCantidad();
      }

      return esIgual(suma,cambio);
    }

    bool esIgual(float a, float b, float delta = 0.01){
      return abs(a-b) < delta;
    }
    

  public:

    Cambio(float cambio): cambio(redondear(cambio)), dinero(new Moneda[12]), resultado(new Moneda[10]){
      leerArchivo();
    }
    
    Cambio(): dinero(new Moneda[12]), resultado(new Moneda[10]){
      leerArchivo();
    }

    ~Cambio(){
    }

    void setCambio(float num){
      this->cambio = redondear(num);
    }

    void reiniciarCambio(){
      this->longitudResultado = 0;

    }

    void guardarArchivo(){
      
      fstream F;
      F.open("Registro/registroDinero.txt", ios::out);

      if (F.is_open()){
          
        for(int i =0; i < longitudDinero; i++){

          if(dinero[i].getCantidad() != 0)
            F << dinero[i].getValor() << " " << dinero[i].getCantidad() << endl;

        }

      }else{
        cout << "Error al leer datos" << endl;
      }

      F.close();

    }

    void leerArchivo(){

      string nombre{"Registro/registroDinero.txt"};

      ifstream archivo(nombre);

      float valor;
      int cantidad;
      int contador{0};

      if (archivo.is_open()){
          
          while(archivo >> valor >> cantidad){
              
              Moneda m(valor, cantidad);

              dinero[contador] =  m;
              
              contador++;
          }

      }else{
          cout << "Error al leer datos" << endl;
      }

      longitudDinero = contador;

      archivo.close();
    }

    void imprimirBilletes(){
      for(int i = 0; i < longitudDinero; i ++){
        
        if(dinero[i].getValor() >= 1){
          cout << "Billete de valor: " << dinero[i].getValor() << "$ y con una cantidad de items de: " << dinero[i].getCantidad() <<endl;
        }

      }
    }

    void imprimirMonedas(){
      for(int i = 0; i < longitudDinero; i ++){
        
        if(dinero[i].getValor() < 1){
          cout << "Moneda de valor: " << dinero[i].getValor()*100 << " ctvs y con una cantidad de items de: " << dinero[i].getCantidad() <<endl;
        }

      }
    }

    void imprimirCambios(){

      cout << "\n ~ Billetes ~"<<endl;
      imprimirBilletes();
      cout << endl;
      cout << "\n ~ Monedas ~"<<endl;
      imprimirMonedas();

    }

    void hacerCambio(){

      leerArchivo();
      float valor = cambio;
      float parteEntera;
      float parteFlotante = modf(valor, &parteEntera);
      parteFlotante = redondear(parteFlotante); //Obtengo la parte flotante y entera. Redondeo a la parte flotante con dos decimales.
      int cont{0};

      cout << valor << " = " << parteEntera << " + " << parteFlotante << endl;

      if(!(hayDineroSuficiente())){
        cout << "\n ~~ No existe el dinero suficiente para realizar su cambio. Vuelva otro dia :D ~~";
        return;
      }

      //Si la parte entera es mayor que 0
      //cout << parteEntera << endl;
      if(parteEntera > 0){

        for(int i = 0; i < 6; i++){
          
          //Mientras la parte entera sea mayor que el billete en donde nos encontremos
          //Y los items de dinero sean mayor  que 0, osea existan.
          while(parteEntera >= dinero[i].getValor() && !(dinero[i].estaAgotado())){
            
            //Reduzco ese billete a mi valor
            parteEntera -= dinero[i].getValor();
            //Chequeo si esta repetido
            bool repetido{seRepite(dinero[i])};

            if(repetido){

              int pos = posRepetidoDinero(dinero[i]);
              int posr = posRepetidoResultado(dinero[i]);

              if(pos != -1 && posr != -1){
                dinero[pos].disminuirCantidad();
                resultado[posr].aumentarCantidad();

              }else{
                cout << "Algo raro paso aca"<<endl;
              }

            }else{

              int pos = posRepetidoDinero(dinero[i]);
              dinero[pos].disminuirCantidad();
              resultado[cont] = dinero[i];
              resultado[cont].reiniciarCantidad();
              resultado[cont].aumentarCantidad();
              longitudResultado++;
              cont++;

            }

          }
        }
      }

      // cout << parteEntera << endl;
      // cout << parteFlotante << endl;

      if(parteFlotante > 0){

         for(int i = 6; i < 11; i++){
          
          //Mientras la parte entera sea mayor que el billete en donde nos encontremos
          //Y los items de dinero sean mayor  que 0, osea existan.
          while(parteFlotante >= dinero[i].getValor() && !(dinero[i].estaAgotado())){
            
            //Reduzco ese billete a mi valor
            parteFlotante -= dinero[i].getValor();
            parteFlotante = redondear(parteFlotante);
            //Chequeo si esta repetido
            bool repetido{seRepite(dinero[i])};

            if(repetido){

              int pos = posRepetidoDinero(dinero[i]);
              int posr = posRepetidoResultado(dinero[i]);

              if(pos != -1 && posr != -1){
                dinero[pos].disminuirCantidad();
                resultado[posr].aumentarCantidad();

              }else{
                cout << "Algo raro paso aca"<<endl;
              }

            }else{

              int pos = posRepetidoDinero(dinero[i]);
              dinero[pos].disminuirCantidad();
              resultado[cont] = dinero[i];
              resultado[cont].reiniciarCantidad();
              resultado[cont].aumentarCantidad();
              longitudResultado++;
              cont++;

            }

          }
        }
      }

      if(!(sumaCorrecta())){
        cout << "~~ Ocurrio un error con su cambio. No se poseen los items suficientes para realizarlo ~~" <<endl;
        leerArchivo();
        return;
      }

      cout << "\nPara el cambio de: " << cambio << " se encontro que la minima de billetes y monedas disponibles es: \n" <<endl;
      for(int i = 0; i < longitudResultado; i++){

        cout << resultado[i].getValor() << " con " <<  resultado[i].getCantidad() << " repeticiones" <<endl;

      }

      guardarArchivo();

    }


};