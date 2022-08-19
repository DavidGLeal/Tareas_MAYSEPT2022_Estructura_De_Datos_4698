#ifndef NUMERO_H
#define NUMERO_H
#include <vector>
#include <string>
using std::vector;
using namespace std;

class Numero{
    private:
        vector<int> nums;
        int euclidesMCD(int, int);
        int MCM(int, int);
    public:
        Numero(string s);
        ~Numero();
        vector<int> creacionVector(string);
        int obtenerMCD();
        int obtenerMCM();
        void imprimirLongitudVector();
        void imprimirDatosVector();
};
#endif 