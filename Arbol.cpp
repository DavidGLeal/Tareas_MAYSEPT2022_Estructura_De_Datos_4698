#pragma once
#include "Arbol.h"

/**
 * Establece el valor de la variable privada arbol al valor del parámetro _arbol.
 * 
 * @param _arbol El nodo raíz del árbol.
 */
void Arbol::setArbol(Nodo *_arbol)
{
    arbol = _arbol;
}

/**
 * Devuelve la raíz del árbol.
 * 
 * @return El nodo raíz del árbol.
 */
Nodo *Arbol::getArbol()
{
    return arbol;
}

/**
 * Crea un nuevo nodo con el valor del parámetro.
 * 
 * @param dato El valor del nodo
 * 
 * @return Un puntero a un objeto Nodo.
 */
Nodo *Arbol::crearNodo(int dato)
{
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->setValor(dato);
    nuevoNodo->setDerecha(NULL);
    nuevoNodo->setIzquierda(NULL);
    return nuevoNodo;
}

/**
 * Si el árbol está vacío, cree un nuevo nodo y asígnelo al árbol. De lo contrario, si los datos son
 * menores que la raíz, insértelos en el subárbol izquierdo. De lo contrario, insértelo en el subárbol
 * derecho
 * 
 * @param arbol El árbol
 * @param dato el valor a insertar
 */
void Arbol::insertarNodo(Nodo *&arbol, int dato)
{
    if (arbol == NULL)
    {
        Nodo *nuevoNodo = crearNodo(dato);
        arbol = nuevoNodo;
        cout<<"Dato ingresado correctamente...\n";
    }
    else
    {
        int raiz = arbol->getValor();
        if (dato < raiz)
        {
            insertarNodo(arbol->getIzquierda(), dato);
            cout<<"Dato ingresado correctamente...\n";
        }
        else
        {
            insertarNodo(arbol->getDerecha(), dato);
            cout<<"Dato ingresado correctamente...\n";
        }
    }
}

//Función mostrar
void Arbol::mostrar(Nodo *arbol, int contador)
{
    if (arbol == NULL)
    {
        return;
    }
    else
    {
        mostrar(arbol->getDerecha(), contador + 1);
        for (int i = 0; i < contador; i++)
        {
            cout << "  ";
        }
        cout << arbol->getValor() << endl;
        mostrar(arbol->getIzquierda(), contador + 1);
    }
}

//Calcula el peso de un árbol binario
int Arbol::peso(Nodo *arbol)
{
    if (arbol == NULL)
        return 0;
    else
        return 1 + peso(arbol->getIzquierda()) + peso(arbol->getDerecha());
}

//Calcula la altura (nivel + 1) de un árbol binario
int Arbol::altura(Nodo *aux)
{
	 if (aux == NULL)
	    return 0;
	 if (aux->getIzquierda() == NULL && aux ->getDerecha() == NULL) 
	    return 1;
	 return max (altura (aux->getIzquierda()), altura (aux->getDerecha())) + 1; 
}

//Se complementa con la función "simetrias" y calcula
//si el árbol es perfecto o imperfecto
bool Arbol::simetria(Nodo* X, Nodo* Y){
    if (X == NULL && Y == NULL) {
        return true;
    }
    return (X != NULL && Y != NULL) &&
        simetria(X->getIzquierda(), Y->getDerecha()) &&
        simetria(X->getDerecha(), Y->getIzquierda());
}

bool Arbol::simetrias(Nodo* aux){
    if (aux == NULL) {
        return true;
    }
 
    return simetria(aux->getIzquierda(), aux->getDerecha());
}

//RECORRIDO EN PREORDEN
/**
 * *|CURSOR_MARCADOR|*
 * 
 * @param arbol es la raiz del arbol
 * 
 * @return el valor del nodo.
 */
void Arbol::preOrden(Nodo *arbol)
{
    if (arbol == NULL)
    {
        return;
        cout<<"No se encuentran datos en el arbol, \narbol vacio...\n";
    }
    else
    {
        cout<<arbol->getValor()<<"-";
        preOrden(arbol->getIzquierda());
        preOrden(arbol->getDerecha());
    }
}

/**
 * Recorrido inOrden.
 * 
 * @param arbol Un puntero al nodo de la raíz.
 * 
 * @return Dato entero del nodo.
 */
void Arbol::inOrden(Nodo *arbol)
{
    if (arbol == NULL)
    {
	return;
        cout<<"No se encuentran datos en el arbol"<<endl;
        cout<<"El arbol se encuentra vacio"<<endl;
    }
    else
    {
        inOrden(arbol->getIzquierda());
	cout<<arbol->getValor()<<"->";
        inOrden(arbol->getDerecha());
    }
}

void Arbol::buscar(Nodo* arbol, int dato){	
if(arbol == NULL){	 
   cout<<"No se encuentran datos en el arbol\n";
}
else if(arbol->getValor() == dato){
	cout<<arbol->getValor()<<"\t "<<"Dato encontrado correctamente...\n";
}
else if(dato < arbol->getValor()){
buscar(arbol->getIzquierda(), dato);
}
else{
buscar(arbol->getDerecha(), dato);
}
}

//Es una función para buscar datos que cuenta con dos parámetros

void Arbol ::buscarporNivel(Nodo* arbol, int num){

    int nivel = 0;
    while(arbol != NULL){
        if(arbol->getValor() == num){
            cout<<"El numero "<<num<<" se encuentra en el nivel "<<nivel<<endl;
            return;
        }
        else if(num < arbol->getValor()){
            arbol = arbol->getIzquierda();
        }
        else{
            arbol = arbol->getDerecha();
        }
        nivel++;
    }
    cout<<"El numero "<<num<<" no se encuentra en el arbol"<<endl;
}

//Es una función para buscar datos que cuenta con dos parámetros

/**
 * Imprime el árbol en orden posterior.
 * 
 * @param arbol El nodo raíz del árbol.
 * 
 * @return Dato entero del nodo.
 */
void Arbol::postOrden(Nodo *arbol){
	
	 if (arbol == NULL)
    {
        return;
        cout<<"No se encuentran datos en el arbol, \narbol vacio...\n";
    }
    else
    {
        postOrden(arbol->getIzquierda());
        postOrden(arbol->getDerecha());
		cout<<arbol->getValor()<<"->";
    }
}

/**
 *  Imprimir nodos en un nivel actual
 * 
 * @param arbol Un puntero al nodo de la raíz.
 */
void Arbol::imprimirNivelActual(Nodo* arbol, int nivel)
{
    if (arbol == NULL)
        return;
    if (nivel == 1)
        cout << arbol->getValor()<< " ";
        
    else if (nivel > 1) {
        imprimirNivelActual(arbol->getIzquierda(), nivel - 1);
        imprimirNivelActual(arbol->getDerecha(), nivel - 1);
    }
}


void Arbol::sumarPorNivel(Nodo* arbol, int nivel){

    if (arbol == NULL)
        return;
    if (nivel == 1){

        suma += arbol->getValor();
        sumaNivl += arbol->getValor();
        return;

    }else if (nivel > 1) {
        
        sumarPorNivel(arbol->getIzquierda(), nivel - 1);
        sumarPorNivel(arbol->getDerecha(), nivel - 1);
    }
       
}


/**
 * Imprime Recorrido por Amplitud del nodo.
 * 
 * @param arbol El nodo raíz del árbol
 * 
 * @return valor del Nodo.
 */
void Arbol::recorridoNivel(Nodo* arbol)
{
	if (arbol == NULL)
    {
        cout<<"No se encuentran datos en el arbol"<<endl;
        cout<<"El arbol se encuentra vacio"<<endl;
        return;
    }

    int h = altura(arbol);
    int i;
    cout<< "\n";
    for (i = 1; i <= h; i++){
        imprimirNivelActual(arbol, i);
        sumarPorNivel(arbol, i);
        cout << "\nLa suma en este nivel es: " << sumaNivl << " " <<endl;
        sumaNivl = 0;
    }
}

Nodo *Arbol::eliminarNodo(Nodo* raiz, int dato){
	
    if (raiz == NULL)
        return raiz;
    if (dato < raiz->getValor())
        raiz->setIzquierda(eliminarNodo(raiz->getIzquierda(), dato));

    else if (dato > raiz->getValor())
        raiz->setDerecha(eliminarNodo(raiz->getDerecha(), dato));
    else {
        if (raiz->getIzquierda() == NULL) {
            Nodo* temp = raiz->getDerecha();
            delete(raiz);
            return temp;
        }
        else if (raiz->getDerecha() == NULL) {
            Nodo* temp = raiz->getIzquierda();
            delete(raiz);
            return temp;
        }else{
        	auto getmax = [](Nodo* raiz){
			Nodo* aux = new Nodo();
		    	aux=raiz;		
		    	while (aux && aux->getDerecha()) {
		        aux = aux->getDerecha();
		    	}
		    return aux;	
		};
		
        	Nodo* temp = getmax(raiz->getIzquierda());

        	raiz->setValor(temp->getValor());
        	raiz->setIzquierda(eliminarNodo(raiz->getIzquierda(), temp->getValor()));	
		}        
    }
    return raiz;
}
