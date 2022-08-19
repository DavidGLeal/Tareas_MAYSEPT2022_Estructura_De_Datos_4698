#ifndef BINARIO_H
#define BINARIO_H

class Binario{
    private: 
        long num;
        char* cad;
        void decimalBinario(long num);
    public:
        Binario(long = 0);
        ~Binario();
        void imprimirBinario();
};


#endif 