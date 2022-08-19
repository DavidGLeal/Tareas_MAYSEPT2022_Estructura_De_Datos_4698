#include <iostream>
using namespace std;
#include "Nodo.hpp"

template <typename T>
    class Cola{

        private:
            Nodo<T> *primero = nullptr;
            Nodo<T> *ultimo = nullptr;
  

        public:

           /**
            * un constructor
            */
            Cola(){
            }

            /**
             * El destructor de la clase Cola.
             */
            ~Cola(){
            }

            /**
             * Comprueba si la lista está vacía.
             * 
             * @return un valor booleano.
             */
            bool estaVacia(){
                return primero == nullptr;
            }

            /**
             * Crea un nuevo nodo y, si la lista está vacía, establece el primer y el último nodo en el
             * nuevo nodo. Si la lista tiene un nodo, establece el siguiente nodo del primer nodo en el
             * nuevo nodo y establece el último nodo en el nuevo nodo. Si la lista tiene más de un
             * nodo, establece el siguiente nodo del último nodo en el nuevo nodo y establece el último
             * nodo en el nuevo nodo
             * 
             * @param v es el valor que se almacenará en el nodo
             */
            void pushLast(T v){

                Nodo<T> *n = new Nodo<T>(v);

                if(primero == nullptr){
                    primero = ultimo = n;
                }else if(primero == ultimo){
                    primero ->setNodo(n);
                    ultimo = n;
                }else{
                    ultimo-> setNodo(n);
                    ultimo = n;
                }

            }

            /**
             * Si la lista está vacía, no devuelve nada. Si la lista tiene un elemento, devuelve ese
             * elemento y deja la lista vacía. Si la lista tiene más de un elemento, devolver el primer
             * elemento y establecer el primer elemento en el segundo elemento
             * 
             * @return El valor del primer nodo de la lista.
             */
            T poll(){

                if(primero == nullptr){
                    cout<< "\nNada que borrar. Lista vacia"<<endl;
                    return {};
                }else if(primero == ultimo){
                    //cout << "poll 1" << primero->getValor() <<endl;
                    T retorno {primero->getValor()};
                    primero = ultimo = nullptr;
                    return retorno;
                }else{

                    //cout << "poll 2" << primero->getValor() <<endl;
                    T retorno {primero->getValor()};
                    Nodo<T> *n = primero->getNodo();
                    //primero->~Nodo();
                    primero = n;
                    return retorno;
                }
            }

            /**
             * Si el primer nodo es nulo, la lista está vacía, por lo que devuelve un valor vacío. De
             * lo contrario, devuelve el valor del primer nodo.
             * 
             * @return El valor del primer nodo de la lista.
             */
            T peek(){

                if(primero == nullptr){
                    cout<< "\nNada que borrar. Lista vacia"<<endl;
                    return {};
                }else{

                    //cout << "peek" << primero->getValor() <<endl;
                    T retorno {primero->getValor()};
                    return retorno;
                }

            }

            /**
             * Imprime la lista
             */
            void imprimir(){

                if(primero == nullptr) cout<<"\nNada que imprimir"<<endl;
                else{

                Nodo<T> *n = primero;

                cout<<"\n";
                while(n != nullptr){
                    //cout << "imprimir" <<endl;
                    cout<< n->getValor() << " ";
                    n = n->getNodo();
                }
                }
            }
    };    