#include <iostream>
#include "NodoB+.hpp"
#include "CaminoB+.hpp"
#include "../ColaPila/Cola.hpp"
#include <cmath>
using namespace std;
#pragma once
   
template <typename T>   
class ArbolBmas{
    private:
        int orden;
        int cantidadDatos{0};
        NodoBmas<T>* raiz;
        NodoBmas<T>* primeraHoja;

        /**
         * Devuelve el número mínimo de hijos que puede tener un nodo.
         * 
         * @return El número mínimo de hijos que puede tener un nodo.
         */
        int hijosMin(){
            return this->orden/2;
        }

        /**
         * Devuelve el número máximo de hijos que puede tener un nodo.
         * 
         * @return El número máximo de hijos que puede tener un nodo.
         */
        int hijosMax(){
            return this->orden;
        }

        /**
         * Devuelve el número mínimo de elementos de datos que se pueden almacenar en un nodo.
         * 
         * @return El número de hijos menos 1.
         */
        int datosMin(){
            return hijosMin()-1;
        }

       /**
        * Devuelve el número máximo de elementos de datos que se pueden almacenar en un nodo.
        * 
        * @return El número máximo de hijos que puede tener un nodo.
        */
        int datosMax(){
            return hijosMax()-1;
        }

        /**
         * Esta función devuelve la posición del valor de la mediana en la matriz
         * 
         * @return La posición del valor mediano.
         */
        int getPosMedia(){
            return datosMax()/2;
        }

        /**
         * Marca si un nodo se encuentra a su mínima capacidad
         * 
         * @param nodo el nodo a comprobar
         * 
         * @return su veracidad
         */
        bool alMinimo(NodoBmas<T>* nodo){
            return nodo->cantidadDatos() == datosMin();
        }

        /**
         * 
         * Marca si un nodo se encuentra a su máxima capacidad
         * 
         * @param nodo el nodo a comprobar
         * 
         * @return su veracidad
         */
        bool alMaximo(NodoBmas<T>* nodo){
            return nodo->cantidadDatos() == datosMax();
        }

        /**
         * Comprueba si el nodo tiene menos del número mínimo de datos.
         * 
         * @param nodo el nodo que se está comprobando
         * 
         * @return un valor booleano.
         */
        bool underflow(NodoBmas<T>* nodo){
            return nodo->cantidadDatos() < datosMin();
        }

        /**
         * Comprueba si el nodo tiene más del número máximo de datos.
         * 
         * @param nodo el nodo que se está comprobando para el desbordamiento
         * 
         * @return un valor booleano.
         */
        bool overflow(NodoBmas<T>* nodo){
            return nodo->cantidadDatos() > datosMax();
        }

       /**
        * Crea un nuevo nodo.
        * 
        * @param esHoja verdadero si el nodo es una hoja, falso en caso contrario
        * 
        * @return Un puntero a un objeto NodoBmas.
        */
        NodoBmas<T>* crearNodo(bool esHoja){
            return new NodoBmas<T>(orden, esHoja);
        } 

        void getCamino(T dato, NodoBmas<T>* nodoActual, Camino<T> &camino){
            
            Resultado resultado(nodoActual->buscadorNodo(dato));
            camino.agregarNodo(nodoActual);

            int sigPos = (resultado.datoEncontrado() ? (resultado.getPosBusqueda() + (nodoActual->getEsHoja() ? 0 : 1)) : resultado.getPosInsercion());
            
            camino.agregarIndice(sigPos);

            if(nodoActual->getEsHoja()){

                if(resultado.datoEncontrado())
                    camino.marcarDatos();

            }else{
                getCamino(dato, nodoActual->getHijos()[sigPos], camino);
            }
        }

        void insertarEnHoja(T dato, NodoBmas<T> * nodo, Camino<T>& camino){

            if(!(alMaximo(nodo))){
                nodo->insertarOrdenado(dato);
                return;
            }

            // Hay overflow en el nodo actual
            // En el array temporal, copio todas las claves existentes más la que voy a ingresar

            NodoBmas<T>* nuevoHermano = this->crearNodo(true);
            nodo->setSiguiente(nuevoHermano);

            Vector<T>* buffer = crearBuffer(nodo->getDatos(), dato);

            int posMedia{buffer->longitud()/2};
            nodo->getDatos().setDatos(*(buffer->getSubVector(0,posMedia)));
            nuevoHermano->getDatos().setDatos(*(buffer->getSubVector(posMedia, buffer->longitud())));
            insertarEnPadre((*buffer)[posMedia], camino.siguienteNodo(), camino, nodo, nuevoHermano);

        }

        void insertarEnPadre(T dato, NodoBmas<T> * padre, Camino<T>& camino, NodoBmas<T>* hermanoIz, NodoBmas<T>* hermanoDer){

            if(padre == nullptr){ //overflow
                this->crearRaiz(dato, hermanoIz, hermanoDer);
                return;
            }

            if(!(alMaximo(padre))){
                padre->insertarOrdenado(dato, hermanoDer);
                return;
            }

            NodoBmas<T> *nuevoHermano = this->crearNodo(false);
            Vector<T>* buffer = crearBuffer(padre->getDatos(), dato);
            Resultado resultado(buffer->buscarOrdenado(dato));

            int posMedia{buffer->longitud()/2};
            T clavePadre{(*buffer)[posMedia]};
            padre->getDatos().setDatos(*(buffer->getSubVector(0,posMedia)));
            nuevoHermano->getDatos().setDatos(*(buffer->getSubVector(posMedia+1, buffer->longitud())));

            Vector<NodoBmas<T>*> &hijosPadre = padre->getHijos();   
            int posInsertar{resultado.getPosBusqueda()+1};
            
            Vector<NodoBmas<T>*> *parteIzquierda = hijosPadre.getSubVector(0,posInsertar);
            Vector<NodoBmas<T>*> *parteDerecha = hijosPadre.getSubVector(posInsertar, hijosPadre.longitud());

            Vector<NodoBmas<T>*> bufferHijos(hijosPadre.longitud()+1);
            bufferHijos.unirVectores(*parteIzquierda);
            bufferHijos.insertarFinal(hermanoDer);
            bufferHijos.unirVectores(*parteDerecha);

            //Reciclo variable
            posMedia = bufferHijos.longitud()/2 + (bufferHijos.longitud() % 2 == 0 ? 0 : 1);

            padre->getHijos().setDatos(*(bufferHijos.getSubVector(0,posMedia)));
            nuevoHermano->getHijos().setDatos(*(bufferHijos.getSubVector(posMedia, bufferHijos.longitud())));

            insertarEnPadre(clavePadre, camino.siguienteNodo(), camino, padre, nuevoHermano);

        }

        void crearRaiz(T dato, NodoBmas<T>* hermanoIz, NodoBmas<T>* hermanoDer){

            this->raiz = crearNodo(false);
            raiz->insertarOrdenado(dato);
            raiz->getHijos().insertarFinal(hermanoIz);
            raiz->getHijos().insertarFinal(hermanoDer);

        }

        void reemplazarRaiz(NodoBmas<T>* raiz){
            this->raiz = raiz;
        }

        Vector<T>* crearBuffer(Vector<T> &datos, T dato){
            Vector<T> *aux = new Vector<T>(datos.longitud()+1);
            aux->unirVectores(datos);
            aux->insertarOrdenado(dato);

            return aux;
        }

        void borrarEnHoja(T dato, NodoBmas<T>* actual, Camino<T> &camino){
            
            actual->getDatos().borrar(camino.siguienteIndice());

            if(!(underflow(actual)) || (raiz->getEsHoja())){
                return;
            }

            int posHijo{camino.siguienteIndice()};
            NodoBmas<T>* padre = camino.siguienteNodo();
            NodoBmas<T>* hermano = getHermano(padre, posHijo);

            int posClavePadre = padre->getPosSepar(posHijo, hermano);
            T clavePadreAct = padre->getDatos()[posClavePadre];

            Vector<NodoBmas<T>*> listaHijos(2);
            listaHijos.insertarFinal(actual);
            listaHijos.insertarFinal(hermano);

            padre->ordenarHijos(listaHijos);
            NodoBmas<T>* hermIzq = listaHijos[0];
            NodoBmas<T>* hermDer = listaHijos[1];

            Vector<T> bufferDatos;
            bufferDatos.insertarOrdenados(hermIzq->getDatos());
            bufferDatos.insertarOrdenados(hermDer->getDatos());

            if (!alMinimo(hermIzq) && !alMinimo(hermDer)) {
                T clavePadreNue = redistribuirEnHojas(hermIzq, hermDer, bufferDatos);
                padre->getDatos()[posClavePadre] = clavePadreNue;
                return;
		    }

            hermIzq->getDatos().setDatos(bufferDatos);
            hermIzq->setSiguiente(hermDer->getSiguiente());
            borrarEnPadre(clavePadreAct, padre, camino);

        }

        T redistribuirEnHojas (NodoBmas<T>* hermanoIzq, NodoBmas<T>* hermanoDer, Vector<T> &bufferDatos) {
            int posMedia = bufferDatos.longitud()/2;
            
            hermanoIzq->getDatos().setDatos(*(bufferDatos.getSubVector(0, posMedia)));
            hermanoDer->getDatos().setDatos(*(bufferDatos.getSubVector(posMedia, bufferDatos.longitud())));
            
            return bufferDatos[posMedia];
	    }

        bool borrarClave(T ingr, Camino<T> &camino){

            // Si la clave no existe, no hago nada
            if(!camino.getEncontreDato()){
                return false;
            }

            this.borrarEnHoja(ingr, camino.siguienteNodo(), camino);
			--this.numDatos;
			return true;

        }

        NodoBmas<T>* getHermano(NodoBmas<T>* padre, int posHijo){
            return padre->getHermanoIzq(posHijo);
        }

        void borrarEnPadre(T ingr, NodoBmas<T>* actual, Camino<T> camino) {
            Resultado borrado(actual -> getDatos().borrarOrdenado(ingr));
            actual -> getHijos().borrar(borrado.getPosBusqueda() + 1);
            
            // Borré la clave. Si la hoja no está en underflow, no hago nada más
            if (!underflow(actual))
                return;
            
            // Tampoco hago nada si el actual es la raíz, aunque esté en "underflow"
            // Si ahora tiene 1 solo hijo, ese hijo pasa a ser la nueva raíz
            if (camino.fin()) {
                if (this -> raiz -> cantidadHijos() == 1)
                    this -> reemplazarRaiz(this -> raiz -> getHijos()[0]);
                
                return;
            }
            
            // Sino, según la política, selecciono el hermano a usar
            int posHijo = camino.siguienteIndice();
            NodoBmas<T>* padre = camino.siguienteNodo();
            NodoBmas<T>* hermano = this -> getHermano (padre, posHijo);
            
            int posClavePadre = actual -> getPosSepar(posHijo, hermano);
            T clavePadreNue, clavePadreAct = padre -> getDatos()[posClavePadre];
            
            // Entre los nodos actual y hermano, determino cuál es el hijo
            // izquierdo y cuál es el derecho
            Vector<NodoBmas<T>*> listaHijos(2);
            listaHijos.insertarFinal(actual);
            listaHijos.insertarFinal(hermano);

            padre->ordenarHijos(listaHijos);
            NodoBmas<T>* hermIzq = listaHijos[0];
            NodoBmas<T>* hermDer = listaHijos[1];
            
            Vector<T> bufferDatos;
            bufferDatos.insertarOrdenados(hermIzq->getDatos());
            bufferDatos.insertarOrdenados(hermDer->getDatos());
            bufferDatos.insertarOrdenado(clavePadreAct);
            
            Vector<NodoBmas<T>*> bufferHijos;
            bufferHijos.unirVectores(hermIzq->getHijos());
            bufferHijos.unirVectores(hermDer->getHijos());
            
            // Si el hermano derecho no está al mínimo, entonces redistribuyo
            if (!alMinimo(hermDer)) {
                //bufferHijos = this.crearBuffer(hermIzq.getHijos(), hermDer.getHijos()); // Borrar?
                
                clavePadreNue = this -> redistribuir(hermIzq, hermDer, bufferDatos, bufferHijos);
                padre -> getDatos()[posClavePadre] = clavePadreNue;

                return;
            }
            
            // Está al mínimo, entonces fusiono en el hermano izquierdo y borro el derecho
            hermIzq -> getDatos().setDatos(bufferDatos);
            hermIzq -> getHijos().setDatos(bufferHijos);
            
            // Sigo recursivamente con el siguiente
            this -> borrarEnPadre (clavePadreAct, padre, camino);
        }

        T redistribuir (NodoBmas<T>* hermanoIzq, NodoBmas<T>* hermanoDer, Vector<T> &bufferDatos, Vector<NodoBmas<T>*> &bufferHijos) {
            T salida = this -> redistribuirEnHojas(hermanoIzq, hermanoDer, bufferDatos);
            int posMedia = bufferHijos.longitud() / 2 + ((bufferHijos.longitud() % 2 == 1) ? 1 : 0);
            
            hermanoIzq -> getHijos().setDatos(*(bufferHijos.getSubVector(0, posMedia)));
            hermanoDer -> getHijos().setDatos(*(bufferHijos.getSubVector(posMedia, bufferHijos.longitud())));
            
            return salida;
        }

        bool esPrimo(int N){
            bool a{true};
            
            for (int i =2; i <= ceil(sqrt(N)); i++){
                if(N%i==0){
                    a = false;
                    break;
                } 
            }
            return a;
        }
		

    public:
    
    /**
     * Crea un nuevo árbol B+ con el orden dado.
     * 
     * @param orden El orden del árbol.
     */
    ArbolBmas(int orden) : orden{orden}, raiz{crearNodo(true)}, primeraHoja{raiz}{}

    ~ArbolBmas(){}

    int getCantidadDatos(){
        return this->cantidadDatos;
    }
    
    bool insertarEnOrden(T ingresar){

        Camino<T> camino;
        this->getCamino(ingresar, raiz, camino);

        if(camino.getEncontreDato()){
            return false;
        }

        this->insertarEnHoja(ingresar, camino.siguienteNodo(), camino);
        cantidadDatos++;
        return true;

    }

    bool buscar(T ingresar){
        Camino<T> camino;
        this->getCamino(ingresar, raiz, camino);

        return camino.getEncontreDato();
    }

    bool borrarClave(T ingr){
        Camino<T> camino;
        this->getCamino(ingr, raiz, camino);
        
        // Si la clave no existe, no hago nada
        if(!camino.getEncontreDato()){
            return false;
        }

        this -> borrarEnHoja(ingr, camino.siguienteNodo(), camino);
        --(this -> cantidadDatos);
        return true;
    }

    void imprimir(){

        NodoBmas<T>* it = primeraHoja;

        while(it != nullptr){

            cout << " [ ";
            it->getDatos().imprimir();
            cout << " ] ";

            it = it->getSiguiente();
        }


    }  

    void imprimirNiveles(){

			Cola<NodoBmas<T>*> cola;
			cola.pushLast(this->raiz);
			cola.pushLast(nullptr);

			while (!(cola.estaVacia())) {
				NodoBmas<T>* aux{ cola.poll() };

				if (aux != nullptr) {

					cout << " [ ";
					for (int i = 0; i < aux->getDatos().longitud(); ++i) {
						cout << "|" << aux->getDatos()[i] << "|" << " ";
					}
					cout << " ] ";

	
					
                    for (int i = 0; i < aux->getHijos().longitud(); ++i) {
                        cola.pushLast(aux->getHijos()[i]);
                    }
					

				}

				else if (!(cola.estaVacia())) {
					cola.pushLast(nullptr);
					cout << endl;
				}


			}
    }  

    void sumaPrimos(){
     
            NodoBmas<T>* it = primeraHoja;
            T suma{0};
            int cont{0};

            while(it != nullptr){
                
            
                for(int i = 0; i < it->getDatos().longitud(); i++){
                    T primo(it->getDatos()[i]);
                    if(esPrimo(primo)){
                        cont++;
                        suma += primo;
                    }
                    
                }

                it = it->getSiguiente();
            }

            cout << "\n \t" << suma <<endl;  
            cout << "Se encontraron " << cont << " numero primos" <<endl;        

    } 

   
};
