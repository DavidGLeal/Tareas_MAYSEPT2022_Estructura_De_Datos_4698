#include <iostream>
#include <fstream>
using namespace std;

class Reina{
	public:
		bool **validar;
		char **tablero;
		fstream archivo;
		int contador;
		int n;

		/**
		 * Crea un nuevo tablero y establece todos los valores en falso y '*'
		 */
		void encerarTablero(){
			for(int i=0;i<n;i++){
				validar[i]=new bool[n];
				tablero[i]=new char[n];
				for(int j=0;j<n;j++){
					*(*(validar+i)+j)=false;
					*(*(tablero+i)+j)='*';
				}
			}
		}

	/**
	 * Crea un archivo llamado exaustivo.txt y escribe la solución del problema de las n-reinas.
	 */
	void crearArchivo(){
		archivo.open("exaustivo.txt",fstream::out);
		archivo<<"solucion "<<n<<"x"<<n<<endl<<endl;
		contador=0;
	}

	Reina(int n1){
		n=n1;
		validar=new bool *[n];
		tablero=new char *[n];
		encerarTablero();
		crearArchivo();
	}

	void bloquear(int x, int y){
		int aux1,aux2;
		aux2=y;
		aux1=0;
		while(aux1<n){//vertical
			*(*(validar+aux1)+aux2)=true;
			aux1++;
		}
		aux2=0;
		aux1=x;
		while(aux2<n){
			*(*(validar+aux1)+aux2)=true;
			aux2++;
		}
		aux2=y;//diagonal
		aux1=x;
		while(aux1>0&&aux2>0){
			aux1--;
			aux2--;
		}
		aux2=y;
		aux1=x;
		while(aux1<n && aux2>0){
			aux1++;
			aux2--;
		}
		aux1--;
		aux2++;
		while(aux1>=0 && aux2<n){
			*(*(validar+aux1)+aux2)=true;
			aux1--;
			aux2++;
		}
	}

	void mostrar(){
		contador++;
		archivo<<"solucion N "<<contador <<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				archivo<<*(*(tablero+i)+j)<<" ";
			}
			archivo<<endl;
		}
		archivo<<endl;
	}

	void quitarRelleno(int x, int y){
		*(*(tablero +x)+y)='*';
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				*(*(validar +i)+j)=false;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(*(*(tablero +i)+j)=='R')
				bloquear(i,j);
			}	
		}
	}

	
	void solucion(int x, int y, int n1){
		*(*(tablero +x)+y)='R';
		bloquear(x,y);
		if(n1==n){
			mostrar();
		}else{
			for(int i=0;i<n;i++){
				if(*(*(validar +i )+ y+1)==false){
					solucion(i,y+1,n1+1);
				}
			}
		}
		quitarRelleno(x,y);
	}
	void solucionReinas(){
		for(int i=0;i<n;i++){
			solucion(i,0,1);
		}
		archivo.close();	
	}
};

int main(int argc, char** argv) {
	int n;
	cout<<"\tIngrese el numero de Reinas"<<endl;
	cin>>n;
	Reina *obj=new Reina(n);
	obj->solucionReinas();
	cout<<"Se creo el archivo txt"<<endl;
	return 0;
}