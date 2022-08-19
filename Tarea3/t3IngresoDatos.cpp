#include "t3IngresoDatos.h"
#include "t3ConversionFloat.cpp"
#include "t3ConversionInt.cpp"

//Constructor
IngresoDatos::IngresoDatos(){ 
}

//Definicion de metodos

char* IngresoDatos::agregoChars(char *dato){
	//Creo un caracter, con el que voy a recibir el input
    char c;
	int j = 0; //Iterador para la verifiacion del unico punto
	int i;
	this -> det = 'a';
	for(i=0; c != 13; i++){
		
		c=getch();
		if(c >= '0' && c <= '9' || c == 46){

			if(this -> converFloat.verificar(c)){
				if(j == 1){
					throw std::invalid_argument("Un decimal no puede tener mas de un solo punto");
				}else{
					printf("%c", c);
					dato[i]=c;
					++j;
					this -> det = 'f'; //flotante
				}
			}		else if(this -> converInt.verificar(c)){

						printf("%c", c);
						dato[i]=c;
					
					}	else{
						printf("Ha ocurrido un error");
						}

		} else if(c == 8){
			printf("%c", c);
			if(i != 0){
				dato[i]='\0';
				i--;
			}			
		}
	}

	dato[i]='\0';
	return dato;
}

char IngresoDatos::getDet(){
	return this -> det;
}

int  IngresoDatos::devolverInt(char *dato){
	return this -> converInt.numInt(dato);
}

float  IngresoDatos::devolverFloat(char *dato){
	return this -> converFloat.numFloat(dato);
}



