#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "t1IngresoDatos.h"


//char ingresoDatos(char);
char* Dato::ingresarDatosEnteros(char *msj){
    char *dato=new char[10],c;
    int i=0;
    printf("%s ",msj);
    while((c=getch())!=13){
        if(c>='0'&& c<='9'){
            printf("%c",c);
            dato[i++]=c;
        }
    }
    dato[i]='\0';
    return dato;
}


int Dato::convertirEntero(char* c){
	return atoi(c);
}

int Dato::getDoble(int num){
    return num*2;
}