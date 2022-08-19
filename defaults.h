#include "3Persona.h"
#include "1ListaDC.h"
#include "3Celular.h"
#include "3Stock.h"
#include "3Tienda.h"

Persona *p1 = new Persona("Matias Manzin", 100);
Persona *p2 = new Persona("Lionel Messi", 5000);
Persona *p3 = new Persona("Edward Tech", 1500);

Celular *c1 = new Celular("Alcatel TCL A3", 40, 100);
Celular *c2 = new Celular("Samsung Galaxy S22", 1000, 30);
Celular *c3 = new Celular("Motorola One 5G Ace", 250, 50);
Celular *c4 = new Celular("Iphone 12", 2000, 3);

ListaDobleC<Persona*> *personas = new ListaDobleC<Persona*>();
ListaDobleC<Celular*> *celulares = new ListaDobleC<Celular*>();

Stock *stock = new Stock();
Tienda *tienda = new Tienda();


