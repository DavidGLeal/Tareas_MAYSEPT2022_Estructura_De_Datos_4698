
#include "Regex.h"

/**
 * Toma una cadena y devuelve una pila de cadenas
 * 
 * @param s La cadena a analizar
 * 
 * @return Un puntero a un objeto Pila<string>.
 */
Pila<string>* Regex::fragmento(const string &s){
    longitud = 0;
    Pila<string> *frag = new Pila<string>();

   /* Una expresión regular que coincida con lo siguiente: */
    regex r("([0-9]+([.][0-9]*)?|[.][0-9]+|e|pi)|[+\\-~^*/]|arcsin|arcsen|arcos|arctan|cos|tanh|sinh|senh|sin|sen|cosh|tan|csc|sec|ctg|ln|log10|log|[(]|[)]|rt");

    for (
    std::sregex_iterator i = std::sregex_iterator(s.begin(), s.end(), r);
    i != std::sregex_iterator();
    ++i 
    )
    {
        smatch m = *i;
        longitud += m.length();
        //cout << m.str() <<endl;
        frag->push(m.str());
    }

    //frag ->imprimir();
    return frag;
}

bool Regex::excepciones(const string &s){
    const regex r("[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)ln|[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)sen|[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)sin|[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)cos|[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)tan|[+-]?([0-9]+([.][0-9]*)|[.][0-9]+)csc|[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)sec|[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)ctg$|^[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)ln|[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)log10|[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)[(]$|^[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)sinh|[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)senh|[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)tanh|[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)cosh|~~");
    bool existe{true};
    for(sregex_iterator i = std::sregex_iterator(s.begin(), s.end(), r);
                            i != std::sregex_iterator();
                            ++i )
    {
        smatch m = *i;
        cout << m.str() << " error en la posicion " << m.position() << '\n';
        existe = false;
    }

    return existe;
}

bool Regex::excepcionesParentesis(const string &s){
    return parentesisAbiertos(s) == parentesisCerrados(s);
}

int Regex::parentesisAbiertos(const string &s){
    regex const expression("[(]");
    
    ptrdiff_t const match_count(distance(
    sregex_iterator(s.begin(), s.end(), expression),
    sregex_iterator()));

    return  match_count;
}

int Regex::parentesisCerrados(const string &s){
    regex  const expression("[)]");
    
    ptrdiff_t const match_count(distance(
    sregex_iterator(s.begin(), s.end(), expression),
    sregex_iterator()));

    return match_count;
}

bool Regex::excepcionesBinarios(const string &s){
    const regex r("[+-/*^]{2}|[=]");

    bool existe{true};
    for(sregex_iterator i = std::sregex_iterator(s.begin(), s.end(), r);
                            i != std::sregex_iterator();
                            ++i )
    {
        smatch m = *i;
        cout << m.str() << " error en la posicion " << m.position() << '\n';
        existe = false;
    }

    return existe;
}

/**
 * Compara la longitud de la cadena con la longitud de la expresión regular. Sirve para saber si se detecto un error
 * de sintaxis.
 * 
 * @param l longitud de la cadena
 * 
 * @return un valor booleano.
 */
bool Regex::compararLongitudes(int l){
    // cout<< l <<endl;
    // cout << longitud <<endl;
    return l == longitud;
}

/**
 * Devuelve verdadero si la cadena es un número, falso en caso contrario
 * 
 * @param a La cadena a probar.
 * 
 * @return Un valor booleano.
 */
bool Regex::esUnNumero(const string &a){
    const regex r("^[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)$|e|pi");
    return regex_match(a,r);
}

// bool Regex::esUnOperando(const string &a){
//     return esUnMas(a) || esUnMenos(a) || esUnaMultiplicacion(a) || esUnaDivision(a) || esUnExponente(a) || esUnaRaiz(a) ||esUnSeno(a) || esUnCoseno(a) || esUnTangente(a) || esUnCosecante(a) || esUnSecante(a) || esUnCotangente(a) || esUnSenh(a) || esUnCosh(a) || esUnTanh(a) || esUnln(a) || esUnlog10(a) || esUnlog(a);
// }

bool Regex::esUnBinario(const string &a){
    // cout<< esUnMas(a) << " mas"<<endl;
    // cout<< esUnMenos(a) << " menos"<<endl;
    // cout<< esUnaMultiplicacion(a) << " multi"<<endl;
    // cout<< esUnaDivision(a) << " div"<<endl;
    // cout<< esUnExponente(a) << " exp"<<endl;
    // cout<< esUnaRaiz(a) << " raiz"<<endl;
    // cout<< esUnlog(a) << " log"<<endl;

    return esUnMas(a) || esUnMenos(a) || esUnaMultiplicacion(a) || esUnaDivision(a) ||  esUnExponente(a) || esUnaRaiz(a) || esUnlog(a); 
}

bool Regex::noEsBinario(const string &a){
    return esUnSeno(a) || esUnCoseno(a) || esUnTangente(a) || esUnCosecante(a) || esUnSecante(a) || esUnCotangente(a) || esUnSenh(a) || esUnCosh(a) || esUnTanh(a) || esUnln(a) || esUnlog10(a) || esUnArcSen(a) || esUnArcCos(a) || esUnArcTan(a);
}

bool Regex::esUnFormatoEspecial(const string &a){
    return esUnSigno(a);
}

bool Regex::esUnParentesisInicial(const string &a){
    const regex r("[(]");
    return regex_match(a,r);
}

bool Regex::esUnParentesisFinal(const string &a){
    const regex r("[)]");
    return regex_match(a,r);
}

bool Regex::esUnMas(const string &a){
    const regex r("[+]");
    return regex_match(a,r);
}

bool Regex::esUnMenos(const string &a){
    const regex r("[-]");
    return regex_match(a,r);
}

bool Regex::esUnSigno(const string &a){
    const regex r("[~]");
    return regex_match(a,r);
}

bool Regex::esUnaDivision(const string &a){
    const regex r("[/]");
    return regex_match(a,r);
}

bool Regex::esUnaMultiplicacion(const string &a){
    const regex r("[*]");
    return regex_match(a,r);
}

bool Regex::esUnExponente(const string &a){
    const regex r("[\\^]");
    return regex_match(a,r);
}

bool Regex::esUnaRaiz(const string &a){
    const regex r("rt");
    return regex_match(a,r);
}

bool Regex::esUnSeno(const string &a){
    const regex r("sin|sen");
    return regex_match(a,r);
}

bool Regex::esUnCoseno(const string &a){
    const regex r("cos");
    return regex_match(a,r);
}

bool Regex::esUnTangente(const string &a){
    const regex r("tan");
    return regex_match(a,r);
}

bool Regex::esUnCosecante(const string &a){
    const regex r("csc");
    return regex_match(a,r);
}

bool Regex::esUnSecante(const string &a){
    const regex r("sec");
    return regex_match(a,r);
}

bool Regex::esUnCotangente(const string &a){
    const regex r("ctg");
    return regex_match(a,r);
}

bool Regex::esUnSenh(const string &a){
    const regex r("sinh|senh");
    return regex_match(a,r);
}

bool Regex::esUnCosh(const string &a){
    const regex r("cosh");
    return regex_match(a,r);
}

bool Regex::esUnTanh(const string &a){
    const regex r("tanh");
    return regex_match(a,r);
}

bool Regex::esUnArcSen(const string &a){
    const regex r("arcsin|arcsen");
    return regex_match(a,r);
}

bool Regex::esUnArcCos(const string &a){
    const regex r("arcos");
    return regex_match(a,r);
}

bool Regex::esUnArcTan(const string &a){
    const regex r("arctan");
    return regex_match(a,r);
}

bool Regex::esUnln(const string &a){
    const regex r("ln");
    return regex_match(a,r);
}

bool Regex::esUnlog10(const string &a){
    const regex r("log10");
    return regex_match(a,r);
}

bool Regex::esUnlog(const string &a){
    const regex r("log");
    return regex_match(a,r);
}

bool Regex::esUnPi(const string &a){
    const regex r("pi");
    return regex_match(a,r);
}

bool Regex::esUne(const string &a){
    const regex r("e");
    return regex_match(a,r);
}