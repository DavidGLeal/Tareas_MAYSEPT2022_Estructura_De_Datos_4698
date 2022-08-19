#ifndef SOBRECARGA_H
#define SOBRECARGA_H

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

class Sobrecarga{
    public:
    Sobrecarga();
    int suma(int);
    float suma(int,int);
    double suma(int,double);
    char *suma(int,int,int);
};

#endif 