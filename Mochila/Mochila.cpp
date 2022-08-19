/****************************
*          UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
*
* AUTOR(es):  CALAPAQUI GENESIS,JARA ARIEL,RIVERA CAMILA,ROMAN MATEO.
* FECHA DE Inicio:  13 DE AGOSTO DE 2022
* FECHA DE Entrega: 14 DE AGOSTO DE 2022
* Version: 3
* ESTRUCTURA DE DATOS
* NRC: 4698
*****************************/


#include"Mochila.h"
#include <climits>

Mochila::Mochila(int* _peso,int* _beneficio,int _nElementos,int _capacidad){
	this->peso=_peso;
	this->beneficio=_beneficio;
	this->nElementos=_nElementos;
	this->capacidad=_capacidad;
}

int Mochila::capacidadMaxima(int* _beneficio, int* _peso, int _n, int _capacidad){
	// caso base: capacidad negativa
    if (_capacidad < 0) {
        return INT_MIN;
    }
 
    // caso base: no quedan artículos o la capacidad se convierte en 0
    if (_n < 0 || _capacidad == 0) {
        return 0;
    }
 
    // Caso 1. Incluir el ítem actual `v[n]` en la mochila y repetir para
    // elementos restantes `n-1` con capacidad reducida `W-w[n]`
    int include = *(_beneficio+_n) + capacidadMaxima(_beneficio, _peso, _n - 1, _capacidad - *(_peso+_n));
 
    // Caso 2. Excluir el ítem actual `v[n]` de la mochila y repetir para
    // elementos restantes `n-1`
    int exclude = capacidadMaxima(_beneficio, _peso, _n - 1, _capacidad);
 
    // devuelve el valor máximo que obtenemos al incluir o excluir el elemento actual
    return std::max(include, exclude);
}

int Mochila::resolver(){
	return capacidadMaxima(beneficio, peso, nElementos-1, capacidad);
}