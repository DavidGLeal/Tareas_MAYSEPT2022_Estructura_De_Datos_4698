#include <iostream>
#include "Proceso.h"
#include <sstream>
using namespace std;
#pragma once

    Pila<string>* Proceso::getInfija(){
        return this->infija;
    }

    void Proceso::setInfija(Pila<string> *i) {
        this ->infija = i;
    }

    Pila<string> *Proceso::getPostfija(){
        return postfija;
    }

    void Proceso::setPostfija(Pila<string> *post) {
        postfija = post;
    }

    Pila<string> *Proceso::getPrefija(){
        return prefija;
    }

    void Proceso::setPrefija(Pila<string> *pre) {
        prefija = pre;
    }

    bool Proceso::estaVacia(){
        return infija->estaVacia();
    }

    /**
     * La función recibe una cadena del usuario, luego usa una expresión regular para dividir la cadena en tokens
     * y luego empuja esos tokens en una pila una cadena del usuario. Despues, la pila de cadenas se empuja a otra pila, que 
     * luego se imprime
     * @return un valor booleano.
     */
    bool Proceso::recibirExpresion(){

        string input{"0"};

        /*Obtener la entrada del usuario. */
        getline(cin,input);
        eliminarEspacios(input);
        reemplazoSignos(input);
        //cout<< input <<endl;

        if(!(infija->estaVacia())){
            infija->vaciar();
            postfija->vaciar();
            prefija->vaciar();
        }

        if(!(input.empty())){

            if(r->excepcionesBinarios(input) && r->excepciones(input) && r->excepcionesParentesis(input)){
        
                int longitud = input.length();

                Pila<string> *fragmento= r->fragmento(input);

                /* Empujando los valores de la pila de fragmentos en la pila infija. */
                Nodo<string> *n = fragmento->getPrimero();
                while(n != nullptr){        
                    infija->push(n->getValor());
                    n = n->getNodo();
                }

                /* Comprobando si la longitud de la entrada es la misma que la longitud de la pila. */
                if(r->compararLongitudes(longitud)){
                    cout<< "\nExpresion leida con exito\n"<<endl;
                    reemplazoMenos(input);
                    cout << input <<endl;
                    //infija->imprimirT();
                    return true;
                }else{
                    cout<< "\nOcurrio un error con su expresion. Ha cometido un error de sintaxis"<<endl;
                    infija->vaciar();
                }
            }else{
                cout<< "\nOcurrio un error con su expresion. Ha cometido un error de sintaxis"<<endl;
                if(!(r->excepcionesParentesis(input))){
                    cout<< "El numero de parentesis no se corresponde" <<endl;
                }
                infija->vaciar();
                postfija->vaciar();
                prefija->vaciar();
            }
        }else{
            cout<< "\nOcurrio un error con su expresion. La ha enviado vacia"<<endl;
        }

        return false;
    }

    Pila<string>* Proceso::convertirPostfija(Pila<string> * inf){

        Pila<string> *conversion = new Pila<string>();
        Pila<string> *posf = new Pila<string>();
        Pila<string> *input = new Pila<string>();
        Nodo<string> *n = inf->getPrimero();

        while(n!= nullptr){
            input->push(n->getValor());
            n = n ->getNodo();
        }

        input->revertir();


        /* Comprobando si la pila está vacía. */


        while(!(input->estaVacia())){

            /* Creando una nueva cadena llamada token y asignándole el valor de la parte superior de la
            pila. Ademas, elimino el valor de la pila infija*/
            string token{input->pop()};

            if(r->esUnNumero(token)){
                posf ->push(token);
            }else{

                /**
                * Operador actual 
                * + -> 1
                * - -> 2
                * * -> 3
                * / -> 4
                * ~ (signo) -> 5
                * ^ -> 6
                * rt (raiz) -> 7
                * sin/sen -> 8
                * cos -> 9
                * tan -> 10
                * csc -> 11
                * sec -> 12
                * ctg -> 13
                * sinh -> 14
                * cosh -> 15
                * tanh -> 16
                * ln -> 17
                * log10 -> 18
                * log -> 19
                * ( -> 20
                * ) -> 21
        
                * Prioridades de los operadores respectivos
                *
                * + - -> prioridad 1
                * * / -> prioridad 2
                * ^ rt -> 3
                * Trigonometricas, logaritmicas -> 4
                * ~ -> 5
                * () -> 6
                * 
                */

                /**
                * Si la pila de conversion esta vacia
                * o si el operador en su tope tiene mayor prioridad que el de 
                * token.
                */

                if(r->esUnBinario(token) || r->esUnFormatoEspecial(token)){

                    int cont{0};
                    int comparador{0};

                    while (cont == comparador){
                        if(conversion->estaVacia() || prioridades(operadores(token)) > prioridades(operadores(conversion->tope()))){
                            conversion -> push(token);
                            cont ++;
                        }else if(prioridades(operadores(token)) <= prioridades(operadores(conversion->tope()))){
                            posf->push(conversion->pop());
                        }

                    }

                    comparador++;

                }else if(r->noEsBinario(token)){

                    if(r->esUnNumero(input->tope())){
                        string aux{token};
                        posf->push(input->pop());
                        posf->push(aux);
                    }else{
                        conversion->push(token);
                    }

                }else if(r->esUnParentesisInicial(token)){

                    conversion -> push(token);

                }else if(r->esUnParentesisFinal(token)){

                    while(!(r->esUnParentesisInicial(conversion->tope()))){
                        posf->push(conversion->pop());
                    }

                    conversion->pop();

                    if( !(conversion->estaVacia()) && r->noEsBinario(conversion->tope())){
                        posf->push(conversion->pop());
                    }
                }

            }

        }


        if(!(conversion->estaVacia())){
            while(!(conversion->estaVacia())){
                if(!(r->esUnParentesisInicial(conversion->tope()))){
                    posf->push(conversion->pop());      
                }     
            }

        }

        return posf;
    }

    void Proceso::imprimirNotacion(Pila<string> * p){

        int l{p->getLongitud()};
        Pila<string> *m = new Pila<string>();
        Nodo<string> *n = p->getPrimero();

            while(l > 0){

                if(r->esUnSigno(n->getValor())){
                    m->push("-");
                }else{
                    m->push(n->getValor());
                }    

                n = n ->getNodo();
                l--;
            }
            
        cout << "\n";
        m ->imprimirT();    
    }

    void Proceso::resolverPost(Pila<string> * p){

            int l{p->getLongitud()};
            
            Pila<string> *solucion = new Pila<string>();
            Pila<string> *resultado = new Pila<string>();
            Nodo<string> *n = p->getPrimero();

            while(l > 0){

                solucion->push(n->getValor());

                n = n ->getNodo();
                l--;
            }


        while(!(solucion->estaVacia())){

            string token{solucion->pop()};

            //cout<< "tope " << token<<endl; 

            if(r->esUnNumero(token)){

                if(r->esUnPi(token)){

                    double p = pi();
                    ostringstream aux;
                    aux.precision(6);
                    aux << fixed << p;
                    string r = aux.str();

                    resultado->push(r);

                }else if (r->esUne(token)){

                    double p = e();
                    ostringstream aux;
                    aux.precision(6);
                    aux << fixed << p;
                    string r = aux.str();

                    resultado->push(r);
                }else{
                resultado->push(token);
                }


            }else if(r ->esUnBinario(token)){

                string segundo{resultado->pop()};
                string primero{resultado->pop()};

                double a{stod(primero)};
                double b{stod(segundo)};

                if(r->esUnMas(token)){

                    double p = c->suma(a,b);

                    ostringstream aux;
                    aux.precision(6);
                    aux << fixed << p;
                    string r = aux.str();

                    resultado->push(r);

                }else if(r->esUnMenos(token)){

                    double p = c->resta(a,b);
                   
                    ostringstream aux;
                    aux.precision(6);
                    aux << fixed << p;
                    string r = aux.str();

                    resultado->push(r);

                }else if(r->esUnaMultiplicacion(token)){

                    double p = c->multiplica(a,b);
                    ostringstream aux;
                    aux.precision(6);
                    aux << fixed << p;
                    string r = aux.str();

                    resultado->push(r);

                }else if(r->esUnaDivision(token)){

                    if(b != 0){
                        double p = c->division(a,b);

                        ostringstream aux;
                        aux.precision(6);
                        aux << fixed << p;
                        string r = aux.str();

                        resultado->push(r);
   
                    }else{
                        cout<< "Division por 0" << endl;
                        solucion->setPrimero(nullptr);
                    }

                }else if (r->esUnExponente(token)){

                    double p = c->exponente(a,b);

                    ostringstream aux;
                    aux.precision(6);
                    aux << fixed << p;
                    string r = aux.str();

                    resultado->push(r);

                }else if (r->esUnaRaiz(token)){

                    if(b != 0 ){

                        if(b == 2){
                            if(a >= 0){

                                double p = c->raiz(a,b);

                                ostringstream aux;
                                aux.precision(6);
                                aux << fixed << p;
                                string r = aux.str();

                                resultado->push(r);

                            }else{
                                cout<< "Raiz cuadrada de un negativo." << endl;
                                solucion->setPrimero(nullptr);
                            }
                        }else{

                            double p = c->raiz(b,a);
                        
                            ostringstream aux;
                            aux.precision(6);
                            aux << fixed << p;
                            string r = aux.str();

                            resultado->push(r);
                        }
                
                    }else{
                        cout<< "Raiz de 0. No se permite" << endl;
                        solucion->setPrimero(nullptr);
                    }

                }else if(r->esUnlog(token)){
                    if(a > 0 && b>1){
                        double p = c->logc(a,b);

                        ostringstream aux;
                        aux.precision(6);
                        aux << fixed << p;
                        string r = aux.str();

                        resultado->push(r);
                    }else{
                        cout<< "Logaritmo con bases invalida. No se permite" << endl;
                        solucion->setPrimero(nullptr);
                    }
                }

            }else if (r->noEsBinario(token)){

                string numero{resultado->pop()};
                //cout<< "tope de resultado (numero) " << numero<<endl; 
                double a{stod(numero)};

                if(r->esUnSeno(token)){

                    double p = c->sen(a);

                    ostringstream aux;
                    aux.precision(6);
                    aux << fixed << p;
                    string r = aux.str();

                    resultado->push(r);

                }else if(r->esUnCoseno(token)){

                    double p = c->cs(a);

                    ostringstream aux;
                    aux.precision(6);
                    aux << fixed << p;
                    string r = aux.str();

                    resultado->push(r);
                    
                }else if(r->esUnTangente(token)){

                    if(c->cs(a) != 0){
                        double p = c->tg(a);

                        ostringstream aux;
                        aux.precision(6);
                        aux << fixed << p;
                        string r = aux.str();

                        resultado->push(r);
                    }else{
                        cout<< "Dominio invalido de la tangente" << endl;
                        solucion->setPrimero(nullptr);
                    }
                    
                }else if(r->esUnCosecante(token)){

                    if(c->sen(a) != 0){
                        double p = c->csen(a);

                        ostringstream aux;
                        aux.precision(6);
                        aux << fixed << p;
                        string r = aux.str();

                        resultado->push(r);
                    }else{
                        cout<< "Dominio invalido de la cosecante" << endl;
                        solucion->setPrimero(nullptr);
                    }
                    
                }else if(r->esUnSecante(token)){

                    if(c->cs(a) != 0){
                        double p = c->scs(a);

                        ostringstream aux;
                        aux.precision(6);
                        aux << fixed << p;
                        string r = aux.str();

                        resultado->push(r);
                    }else{
                        cout<< "Dominio invalido de la secante" << endl;
                        solucion->setPrimero(nullptr);
                    }
                    
                }else if(r->esUnCotangente(token)){

                    if(c->sen(a) != 0){
                        double p = c->ctg(a);

                        ostringstream aux;
                        aux.precision(6);
                        aux << fixed << p;
                        string r = aux.str();

                        resultado->push(r);
                    }else{
                        cout<< "Dominio invalido de la cotangente" << endl;
                        solucion->setPrimero(nullptr);
                    }
                    
                }else if(r->esUnln(token)){

                    if(a > 0){
                        double p = c->ln(a);

                        ostringstream aux;
                        aux.precision(6);
                        aux << fixed << p;
                        string r = aux.str();

                        resultado->push(r);
                    }else{
                        cout<< "Dominio invalido del logaritmo neperiano" << endl;
                        solucion->setPrimero(nullptr);
                    }
                    
                }else if(r->esUnlog10(token)){

                    if(a > 0){
                        double p = c->ln10(a);

                        ostringstream aux;
                        aux.precision(6);
                        aux << fixed << p;
                        string r = aux.str();

                        resultado->push(r);
                    }else{
                        cout<< "Dominio invalido del logaritmo base 10" << endl;
                        solucion->setPrimero(nullptr);
                    }
                    
                }else if(r->esUnArcSen(token)){

                    if(a >= -1 && a <=1){
                        double p = c->arcsen(a);

                        ostringstream aux;
                        aux.precision(6);
                        aux << fixed << p;
                        string r = aux.str();

                        resultado->push(r);
                    }else{
                        cout<< "Dominio invalido del arc seno" << endl;
                        solucion->setPrimero(nullptr);
                    }
                    
                }else if(r->esUnArcCos(token)){

                    if(a >= -1 && a <=1){
                        double p = c->arccos(a);

                        ostringstream aux;
                        aux.precision(6);
                        aux << fixed << p;
                        string r = aux.str();

                        resultado->push(r);
                    }else{
                        cout<< "Dominio invalido del arc coseno" << endl;
                        solucion->setPrimero(nullptr);
                    }
                    
                }else if(r->esUnArcTan(token)){

                    if(a >= -1 && a <=1){
                        double p = c->arctan(a);

                        ostringstream aux;
                        aux.precision(6);
                        aux << fixed << p;
                        string r = aux.str();

                        resultado->push(r);
                    }else{
                        cout<< "Dominio invalido del arc tangente" << endl;
                        solucion->setPrimero(nullptr);
                    }
                    
                }

            }else if(r->esUnSigno(token)){
                
                double p{stod(resultado->pop())};
                p = -p;

                ostringstream aux;
                aux.precision(6);
                aux << fixed << p;
                string r = aux.str();

                resultado->push(r);
            }

        }

        resultado->imprimir();
    }

    void Proceso::resolverPre(Pila<string> * p){
        
            int l{p->getLongitud()};
            
            Pila<string> *solucion = new Pila<string>();
            Pila<string> *resultado = new Pila<string>();
            Nodo<string> *n = p->getPrimero();

            while(l > 0){

                solucion->push(n->getValor());

                n = n ->getNodo();
                l--;
            }

        solucion->revertir();


        while(!(solucion->estaVacia())){

            string token{solucion->pop()};


            if(r->esUnNumero(token)){

                if(r->esUnPi(token)){

                    double p = pi();
                    ostringstream aux;
                    aux.precision(6);
                    aux << fixed << p;
                    string r = aux.str();

                    resultado->push(r);

                }else if (r->esUne(token)){

                    double p = e();
                    ostringstream aux;
                    aux.precision(6);
                    aux << fixed << p;
                    string r = aux.str();

                    resultado->push(r);
                }else{
                resultado->push(token);
                }


            }else if(r ->esUnBinario(token)){

                string segundo{resultado->pop()};
                string primero{resultado->pop()};

                double a{stod(primero)};
                double b{stod(segundo)};

                if(r->esUnMas(token)){

                    double p = c->suma(a,b);

                    ostringstream aux;
                    aux.precision(6);
                    aux << fixed << p;
                    string r = aux.str();

                    resultado->push(r);

                }else if(r->esUnMenos(token)){

                    double p = c->resta(a,b);
                   
                    ostringstream aux;
                    aux.precision(6);
                    aux << fixed << p;
                    string r = aux.str();

                    resultado->push(r);

                }else if(r->esUnaMultiplicacion(token)){

                    double p = c->multiplica(a,b);
                    ostringstream aux;
                    aux.precision(6);
                    aux << fixed << p;
                    string r = aux.str();

                    resultado->push(r);

                }else if(r->esUnaDivision(token)){

                    if(b != 0){
                        double p = c->division(a,b);

                        ostringstream aux;
                        aux.precision(6);
                        aux << fixed << p;
                        string r = aux.str();

                        resultado->push(r);
   
                    }else{
                        cout<< "Division por 0" << endl;
                        solucion->setPrimero(nullptr);
                    }

                }else if (r->esUnExponente(token)){

                    double p = c->exponente(a,b);

                    ostringstream aux;
                    aux.precision(6);
                    aux << fixed << p;
                    string r = aux.str();

                    resultado->push(r);

                }else if (r->esUnaRaiz(token)){

                    if(b != 0 ){

                        if(b == 2){
                            if(a >= 0){

                                double p = c->raiz(a,b);

                                ostringstream aux;
                                aux.precision(6);
                                aux << fixed << p;
                                string r = aux.str();

                                resultado->push(r);

                            }else{
                                cout<< "Raiz cuadrada de un negativo." << endl;
                                solucion->setPrimero(nullptr);
                            }
                        }else{

                            double p = c->raiz(b,a);
                        
                            ostringstream aux;
                            aux.precision(6);
                            aux << fixed << p;
                            string r = aux.str();

                            resultado->push(r);
                        }
                
                    }else{
                        cout<< "Raiz de 0. No se permite" << endl;
                        solucion->setPrimero(nullptr);
                    }

                }else if(r->esUnlog(token)){
                    if(a > 0 && b>1){
                        double p = c->logc(a,b);

                        ostringstream aux;
                        aux.precision(6);
                        aux << fixed << p;
                        string r = aux.str();

                        resultado->push(r);
                    }else{
                        cout<< "Logaritmo con bases invalida. No se permite" << endl;
                        solucion->setPrimero(nullptr);
                    }
                }

            }else if (r->noEsBinario(token)){

                string numero{resultado->pop()};
                double a{stod(numero)};

                if(r->esUnSeno(token)){

                    double p = c->sen(a);

                    ostringstream aux;
                    aux.precision(6);
                    aux << fixed << p;
                    string r = aux.str();

                    resultado->push(r);

                }else if(r->esUnCoseno(token)){

                    double p = c->cs(a);

                    ostringstream aux;
                    aux.precision(6);
                    aux << fixed << p;
                    string r = aux.str();

                    resultado->push(r);
                    
                }else if(r->esUnTangente(token)){

                    if(c->cs(a) != 0){
                        double p = c->tg(a);

                        ostringstream aux;
                        aux.precision(6);
                        aux << fixed << p;
                        string r = aux.str();

                        resultado->push(r);
                    }else{
                        cout<< "Dominio invalido de la tangente" << endl;
                        solucion->setPrimero(nullptr);
                    }
                    
                }else if(r->esUnCosecante(token)){

                    if(c->sen(a) != 0){
                        double p = c->csen(a);

                        ostringstream aux;
                        aux.precision(6);
                        aux << fixed << p;
                        string r = aux.str();

                        resultado->push(r);
                    }else{
                        cout<< "Dominio invalido de la cosecante" << endl;
                        solucion->setPrimero(nullptr);
                    }
                    
                }else if(r->esUnSecante(token)){

                    if(c->cs(a) != 0){
                        double p = c->scs(a);

                        ostringstream aux;
                        aux.precision(6);
                        aux << fixed << p;
                        string r = aux.str();

                        resultado->push(r);
                    }else{
                        cout<< "Dominio invalido de la secante" << endl;
                        solucion->setPrimero(nullptr);
                    }
                    
                }else if(r->esUnCotangente(token)){

                    if(c->sen(a) != 0){
                        double p = c->ctg(a);

                        ostringstream aux;
                        aux.precision(6);
                        aux << fixed << p;
                        string r = aux.str();

                        resultado->push(r);
                    }else{
                        cout<< "Dominio invalido de la cotangente" << endl;
                        solucion->setPrimero(nullptr);
                    }
                    
                }else if(r->esUnln(token)){

                    if(a > 0){
                        double p = c->ln(a);

                        ostringstream aux;
                        aux.precision(6);
                        aux << fixed << p;
                        string r = aux.str();

                        resultado->push(r);
                    }else{
                        cout<< "Dominio invalido del logaritmo neperiano" << endl;
                        solucion->setPrimero(nullptr);
                    }
                    
                }else if(r->esUnlog10(token)){

                    if(a > 0){
                        double p = c->ln10(a);

                        ostringstream aux;
                        aux.precision(6);
                        aux << fixed << p;
                        string r = aux.str();

                        resultado->push(r);
                    }else{
                        cout<< "Dominio invalido del logaritmo base 10" << endl;
                        solucion->setPrimero(nullptr);
                    }
                    
                }else if(r->esUnArcSen(token)){

                    if(a >= -1 && a <=1){
                        double p = c->arcsen(a);

                        ostringstream aux;
                        aux.precision(6);
                        aux << fixed << p;
                        string r = aux.str();

                        resultado->push(r);
                    }else{
                        cout<< "Dominio invalido del arc seno" << endl;
                        solucion->setPrimero(nullptr);
                    }
                    
                }else if(r->esUnArcCos(token)){

                    if(a >= -1 && a <=1){
                        double p = c->arccos(a);

                        ostringstream aux;
                        aux.precision(6);
                        aux << fixed << p;
                        string r = aux.str();

                        resultado->push(r);
                    }else{
                        cout<< "Dominio invalido del arc coseno" << endl;
                        solucion->setPrimero(nullptr);
                    }
                    
                }else if(r->esUnArcTan(token)){

                    if(a >= -1 && a <=1){
                        double p = c->arctan(a);

                        ostringstream aux;
                        aux.precision(6);
                        aux << fixed << p;
                        string r = aux.str();

                        resultado->push(r);
                    }else{
                        cout<< "Dominio invalido del arc tangente" << endl;
                        solucion->setPrimero(nullptr);
                    }
                    
                }

            }else if(r->esUnSigno(token)){

                string negado{resultado->pop()};
                negado = "-" + negado;
                resultado->push(negado);

            }

        }

        resultado->imprimir();

    }

    Pila<string>* Proceso::convertirPrefija(Pila<string>* inf){

        // cout<< "infija"<<endl;
        // infija->imprimir();
        // cout<< "prefija"<<endl;
        //pre->imprimir();

        Pila<string> *pre = new Pila<string>();
        Nodo<string> *pos = inf->getPrimero();

        while (pos != nullptr){

            if(r->esUnParentesisInicial(pos->getValor())){

                pre -> push(")");
        
            }else if(r->esUnParentesisFinal(pos->getValor())){

                pre -> push("(");

            }else{
    
                pre -> push(pos->getValor());
            }

            pos = pos ->getNodo();
        }

        // cout<< "prefija"<<endl;
        // pre->imprimir();

        // cout << "\n";
        // pre->imprimirT();
        // cout<< pre->tope()<<endl;

        pre = convertirPostfija(pre);

        // cout << "\n";
        // cout<< "\nprefija luego de convertir"<<endl;
        // pre->imprimir();

        pre -> revertir();

        // cout<< "\nprefija luego de revertir"<<endl;
        // pre->imprimir();
        
        //imprimirNotacion(pre);

        return pre;
    }

    /**
     * Toma una cadena como parámetro y devuelve un número entero
     * + -> 1
     * - -> 2
     * * -> 3
     * / -> 4
     * ~ (signo) -> 5
     * ^ -> 6
     * rt (raiz) -> 7
     * sin/sen -> 8
     * cos -> 9
     * tan -> 10
     * csc -> 11
     * sec -> 12
     * ctg -> 13
     * sinh -> 14
     * cosh -> 15
     * tanh -> 16
     * ln -> 17
     * log10 -> 18
     * log -> 19
     * ( -> 20
     * ) -> 21
     * @param a La cadena a comprobar
     * 
     * @return El valor devuelto es el resultado de la operación.
     */
    int Proceso::operadores(const string &a){

        if(r->esUnMas(a)){
            return 1;
        }else if(r->esUnMenos(a)){
            return 2;
        }else if(r->esUnaMultiplicacion(a)){
            return 3;
        }else if(r->esUnaDivision(a)){
            return 4;
        }else if(r->esUnSigno(a)){
            return 5;
        }else if(r->esUnExponente(a)){
            return 6;
        }else if(r->esUnaRaiz(a)){
            return 7;
        }else if(r->esUnSeno(a)){
            return 8;
        }else if(r->esUnCoseno(a)){
            return 9;
        }else if(r->esUnTangente(a)){
            return 10;
        }else if(r->esUnCosecante(a)){
            return 11;
        }else if(r->esUnSecante(a)){
            return 12;
        }else if(r->esUnCotangente(a)){
            return 13;
        }else if(r->esUnSenh(a)){
            return 14;
        }else if(r->esUnCosh(a)){
            return 15;
        }else if(r->esUnTanh(a)){
            return 16;
        }else if(r->esUnln(a)){
            return 17;
        }else if(r->esUnlog10(a)){
            return 18;
        }else if(r->esUnlog(a)){
            return 19;
        }else if(r->esUnParentesisInicial(a)){
            return 20;
        }else if(r->esUnParentesisFinal(a)){
            return 21;
        }

        return 0;
    }


    /**
     * Devuelve la prioridad del operador
     * 
     * + - -> prioridad 1
     * * / -> prioridad 2
     * ^ rt -> 3
     * Trigonometricas, logaritmicas -> 4
     * () -> -1
     * ~ -> 5
     * 
     * @param operador 1 = +, 2 = -, 3 = *, 4 = /
     * 
     * @return El valor de retorno es la prioridad del operador.
     */
    int Proceso::prioridades(int operador){

        if(operador == 1 || operador == 2){
            return pSumaResta();
        }else if(operador == 3 || operador == 4){
            return pMultiplicacionDivision();
        }else if(operador == 6 || operador == 7){
            return pExponenteRaiz();
        }else if(operador == 8 || operador == 9 || operador == 10 || operador == 11 || operador == 12 || operador == 13 || operador == 14 || operador == 15 || operador == 16 || operador == 17 || operador == 18 || operador == 19){
            return pTrigonometricasLog();
        }else if(operador == 5){
            return pSigno();
        }else if(operador == 20 || operador == 21){
            return pParentesis();
        }

        return 0;
    }

    /**
     * Devuelve el valor de la variable numero.
     * 
     * @return El valor devuelto es el valor de la variable numero.
    */

    int Proceso::pSumaResta(){
        return 1;
    }

    int Proceso::pMultiplicacionDivision(){
        return 2;
    } 

    int Proceso::pExponenteRaiz(){
        return 3;
    }

    int Proceso::pTrigonometricasLog(){
        return 4;
    }

    int Proceso::pSigno(){
        return 5;
    }

    int Proceso::pParentesis(){
        return -1;
    }
 
    /**
     * Reemplaza todas las apariciones de una cadena con otra cadena
     * 
     * @param subject La cadena que se va a buscar y reemplazar.
     * @param search La cadena a buscar.
     * @param replace La cadena con la que reemplazar la cadena de búsqueda.
     */
    void Proceso::reemplazaString(string& subject, const string& search, const string& replace) {
        size_t pos = 0;
        while ((pos = subject.find(search, pos)) != std::string::npos) {
            subject.replace(pos, search.length(), replace);
            pos += replace.length();
        }
    }

    /**
     * Elimina todos los espacios en una cadena.
     * 
     * @param str La cadena que se va a modificar.
     */
    void Proceso::eliminarEspacios(string& str){
        str.erase(remove(str.begin(), str.end(), ' '), str.end());
    }

   /**
    * Reemplaza todas las instancias de la cadena "(-" con la cadena "(~" en la cadena str
    * 
    * @param str La cadena que se va a modificar.
    */
    void Proceso::reemplazoSignos(string& str){
        reemplazaString(str, "(-", "(~");
    }

    void Proceso::reemplazoMenos(string& str){
        reemplazaString(str, "~", "-");
    }

    double Proceso::pi(){
        return 3.14159265;
    }

    double Proceso::e(){
        return 2.71827;
    }