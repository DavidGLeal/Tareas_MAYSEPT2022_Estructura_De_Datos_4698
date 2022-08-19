/*
	*Universidad de las Fuerzas Armadas "ESPE"
    *Enunciado del problema:
	    *Programa que realize los diferentes tipos de ordenamientos (internos y externos) y busquedas.
     *Autores:
        *Curso de Estructura de Datos NRC: 4698
	*Fecha de creacion: 
        * 21-06-2022
	*Fecha de modificacion:
        * 28-06-2022
    *GitHub del grupo:	
        *https://github.com/DavidGLeal/4698_Ordenamientos
*/

#pragma once 
#include "2OrdenamientoInterno.h"
#include "0Vector.cpp"


/**
 * Devuelve el vector.
 * 
 * @return el vector
 */
Vector& OrdenamientoInterno::getVector(){
	return this->vector;
}


/**
 * Establece el vector.
 * 
 * @param _vector
 */
void OrdenamientoInterno::setVector(Vector &_vector){
    this->vector = _vector;
} 

void OrdenamientoInterno::copiarVector(Vector &_vector){
    
    vector.vaciar();

    for(int i = 0; i < _vector.size(); i++){
        int num{_vector[i]};
        vector.push_back(num);
    }
} 

void  OrdenamientoInterno::vaciarVector(){
    vector.vaciar();
}

/**
 * Es una función que ordena un vector de números enteros usando el algoritmo de intercambio
 */
void OrdenamientoInterno::ordenarIntercambio(){
    for (int i{}; i < this->vector.size(); i++) {
        for (int j = i; j < this->vector.size(); j++) {
            if (this->vector[i] > this->vector[j]) {
                auto aux = this->vector[i];
                *(this->vector.get(i)) = this->vector[j];
                *(this->vector.get(j)) = aux;
            }
        }
    }
}

/**
* Es una función que ordena un vector de números enteros usando el algoritmo de burbuja
*/
void OrdenamientoInterno::ordenarBurbuja(){ 
    //GRUPO 2 - ORDENAMIENTO BURBUJA
    int aux;
    int i, j;
    for (i = 0 ; i < vector.size() ; i++) {
        for (j = 0 ; j < vector.size() - 1 ; j++) {
            if (*(vector.get(j)) > *(vector.get(j + 1))) {
                aux = *(vector.get(j));
                *(vector.get(j)) = *(vector.get(j + 1));
                *(vector.get(j + 1)) = aux;
            }
        }
    }
}

/**
* Es una función que ordena un vector de enteros usando el algoritmo Quicksort
*/
void OrdenamientoInterno::ordenarQuicksort() {
	ordenarQuick(vector,0,vector.size() - 1); 
}

/**
 * Si el vector está vacío o solo tiene un elemento, regresa. De lo contrario, divida el vector en dos
 * partes, ordene la primera parte, ordene la segunda parte y regrese
 * 
 * @param vector El vector a ordenar.
 * @param inicio el primer índice del vector
 * @param fin el último índice del vector
 * 
 */
void OrdenamientoInterno::ordenarQuick(Vector &vector, size_t inicio, size_t fin) { 
    if (inicio >= fin)
        return;
    auto lim = dividir(vector, inicio, fin);
    ordenarQuick(vector, inicio, lim);
    ordenarQuick(vector, lim + 1, fin);
}

/**
 * Toma un vector, un índice de inicio y un índice final, y devuelve el índice del elemento pivote
 * 
 * @param vector El vector a ordenar.
 * @param inicio el comienzo del vector
 * @param fin el último índice del vector
 * 
 * @return El índice del pivote.
 */
int OrdenamientoInterno::dividir(Vector &vector, size_t inicio,size_t fin) {
    int pivote = *(vector.get(inicio));
    auto i = inicio + 1; //i=izquierda
    auto j = fin; //j=derecha

    while (true) {
        while (i< j && *(vector.get(j)) >= pivote) j--;
        while (i < j && *(vector.get(i)) < pivote) i++;

        if (i == j) break;

        int tmp = *(vector.get(i));
        *(vector.get(i)) = *(vector.get(j));
        *(vector.get(j)) = tmp;
    }

    if (*(vector.get(i)) >= pivote) return inicio;
    *(vector.get(inicio)) = *(vector.get(i));
    *(vector.get(i)) = pivote;
    return i;
}

    
/**
* Es una función que ordena un vector de enteros usando el algoritmo Shell Sort
*/
void OrdenamientoInterno::ordenarShellSort(){
   int j, incremento, aux; // incremento: Tamaño del bloque de separación de los elementos dentro del método Shell.
    incremento = vector.size() / 2; // De acuerdo al algoritmo original, el incremento se divide en 2 en cada iteración.
    while (incremento > 0)
    {
        for (int i = incremento; i < vector.size(); i++)
        {
            j = i - incremento; // j es un índice de secuenciamiento.
            while (j >= 0)
            {
                if (*(vector.get(j)) >= *(vector.get(j + incremento))) // Se comparan los elementos distales a un factor incremental de separación.
                {
                    aux = *(vector.get(j)); // Se intercambian los valores, logrando el ordenamiento.
                    *(vector.get(j)) = *(vector.get(j + incremento));
                    *(vector.get(j + incremento)) = aux;
                }
                else
                {
                    j = 0; // Se retrocede el índice de secuenciamiento del vector.
                }
                j = j - incremento;
            }
        }
        incremento = incremento / 2; // Se divide el bloque de comparación en cada iteración.
    }
}

/**
* Toma una matriz de números enteros y los ordena en orden ascendente con el algoritmo de distribucion
*/
void OrdenamientoInterno::ordenarCountingSort(){

    int tam{vector.size()};
    Vector vN,vP;
    
    for(int i=0; i<tam; i++){
        if(vector[i]<0)
        {
        	vN.push_back(abs(vector[i]));
		}else{
			vP.push_back(vector[i]);
		}
    }
    int auxNCount=0;
    int tamN{vN.size()},tamP{vP.size()};
    if(tamN!=0)
    {
    	
    	int *auxN = new int[tamN];
    	encerar(auxN,tamN);
    	
    	int maxN = getMax(vN);
	    int *countN = new int[maxN+1];
	    encerar(countN,maxN+1);
	    
	    for(int i=0; i<tamN; i++){
	        countN[vN[i]]++;
	    }
	
	    for(int i=1; i<=maxN; i++){
	        countN[i]+=countN[i-1];
	    }
	
	    for(int i=tamN-1; i>=0; i--){
	        auxN[countN[vN[i]]-1]= vN[i];
	        countN[vN[i]]--;
	    }
	    for(int i=tamN-1; i>=0; i--){
	        vector[auxNCount]=-1*(auxN[i]);
	        auxNCount++;
	    }
	    delete[] auxN;
   		delete[] countN;
	}
	if(tamP!=0)
	{
		int *auxP = new int[tamP];
	    encerar(auxP,tamP);
	    
	    int maxP = getMax(vP);
	    int *countP = new int[maxP+1];
	    encerar(countP,maxP+1);
	
	    for(int i=0; i<tamP; i++){
	        countP[vP[i]]++;
	    }
	
	    for(int i=1; i<=maxP; i++){
	        countP[i]+=countP[i-1];
	    }
	
	    for(int i=tamP-1; i>=0; i--){
	        auxP[countP[vP[i]]-1]= vP[i];
	        countP[vP[i]]--;
	    }
	    for(int i=0; i<tamP; i++){
	        vector[auxNCount]=auxP[i];
	        auxNCount++;
	    }
	    delete[] auxP;
   		delete[] countP;
	}
}
void OrdenamientoInterno::encerar(int *vec, int tam){
   for(int i=0; i<tam; i++){
      *(vec+i)=0;
   }
}

void OrdenamientoInterno::encerar(Vector &v){
   for(int i=0; i<v.size(); i++){
      v[i] = 0;
   }
}

int OrdenamientoInterno::getMax(Vector &v){
   int max{v[0]};
   for(int i=1; i<v.size(); i++){
      if(v[i] > max){
         max= v[i];
      }
   }
   return max;
}

/**
 * Toma un vector de números enteros y los ordena usando el algoritmo bucket
*/
void OrdenamientoInterno::ordenarBucket(){
    
	// int c = vector.size();
	
	// Vector ordenado;
	// int **matriz = new int*[c];
	// for(int z =0;z<c;z++)
	// {
	// 	matriz[z] = new int[10];
	// }
	
	// int col=10,cnt=0,k=0,d=1,l=0;
	// int *j = new int[c];
	
	// for(int x=0;x<c;x++)
	// {
	// 	for(int w =0;w<10;w++)
	// 	{
	// 		matriz[x][w]=0;
	// 	}
	// }
	
	// cout << "Despues primer for"<<endl;
	// int max= *vector.get(0);
	// for(int a=1;a<c;a++)
    // {
    //     if(*vector.get(a)>max)
    //         max=*vector.get(a);
    // }
	// cout << "Despues 2 for"<<endl;
    // while(max>0)
    // {
    //     cnt++;
    //     max=max/10;
    // }
	
	// int ap = c;
	// for(int m=0;m<cnt;m++)
    // {
    //     for(int i=0;i<c;i++)
    //     {    
	// 		j[i]=0;
	// 	}
	// 	cout << "for1"<<endl;
    //     for(int y=0;y<c;y++)
    //     {
    //         k=(abs(vector[y])/d)%10;
    //         if(k>=c)
    //         {        	
    //         	for(int d = c; d<=k;d++)
    //         	{
    //         		matriz[d] = new int[10];
    //         		j[d] =0;
	// 			}
	// 			ap=k+1;
	// 		}
    //         matriz[k][j[k]]=*vector.get(y);
	// 		cout << matriz[k][j[k]] <<endl;
    //         j[k]++;
    //     }
        
    //      for(int a=0;a<c;a++)
    //     {
    //     	for(int r=0;r<j[a];r++)
    //     	{
        		
    //     		for(int o=r;o<j[a];o++)
    //     		{
    //     		 if(matriz[a][r]>matriz[a][o])
    //     			{
    //     				int aux = matriz[a][r];
    //     			 matriz[a][r] = matriz[a][o];
    //     				matriz[a][o] = aux;					 					 				        				
	// 				}				        			
	// 			}
	// 			cout << "for3.2"<<endl;        		
	// 		}
	// 		cout << "for3.1"<<endl;

	// 	}
	// 	cout << "for3"<<endl;
        
    // 	l=0;
    //     for(int b=0;b<c;b++)
    //     {
    //         for(k=0;k<j[b];k++)
    //         {
    //         	int aux =matriz[b][k];
    //             ordenado.push_back(aux);
    //             l++;
    //         }
	// 		cout << "for4.1"<<endl;
    //     }
	// 	cout << "for4"<<endl;
        
    //    d*=10;
    // }

	// cout << "Despues primer for grande"<<endl;
	// Vector ordenado2;
	
	// for(int m=0;m<ordenado.getElementos();m++){
	// 	if(m>=ordenado.getElementos()-10){
			
	// 		int ele=ordenado[m];
	// 		ordenado2.push_back(ele);
	// 	}
		
	// }
	// cout << "Al menos llego al final"<<endl;
	// imprimir(ordenado2);
    // copiarVector(ordenado2);

}

/**
 * La función toma un vector de números enteros y los ordena usando el algoritmo de clasificación radix
 * 
 */
void OrdenamientoInterno::ordenarRadix(){

    int tam{vector.size()};
    Vector vN,vP;
    
    for(int i=0; i<tam; i++){
        if(vector[i]<0)
        {
        	vN.push_back(abs(vector[i]));
		}else{
			vP.push_back(vector[i]);
		}
    }
    int auxNCount=0;
    if(vN.size()!=0)
    {
    	auto maximoN = [&] (){
		int mxN = *(vN.get(0)); 
	    	for (int i = 1; i < vN.size(); i++) 
	        if (*(vN.get(i)) > mxN) 
	        mxN = *(vN.get(i)); 
	    	return mxN;
		};
		
	    int mN = maximoN(); 
	
	    auto SortN = [&] (int expN){	
		    Vector salidaN,contadorN; 
		    for (int i = 0; i < 10; i++){	        	
		        contadorN.push_back(0);
		    }
		    for (int i = 0; i < vN.size(); i++){	        	
		        salidaN.push_back(0);
		    } 		  
		    for (int i = 0; i < vN.size(); i++){		
		        *(contadorN.get((*(vN.get(i)) / expN) % 10))=*(contadorN.get((*(vN.get(i)) / expN) % 10))+1;
	        }		  
		    for (int i = 1; i < 10; i++) {		    	
				*(contadorN.get(i)) += *(contadorN.get(i-1)); 
		    }
		    for (int i = vN.size()-1; i >= 0; i--) {
				*(salidaN.get(*(contadorN.get((*(vN.get(i))/expN)%10))-1))=*(vN.get(i)) ;				
				*(contadorN.get((*(vN.get(i)) / expN) % 10))=*(contadorN.get((*(vN.get(i)) / expN) % 10))-1;		
	        }   
		    for (int i = vN.size()-1; i>=0; i--){
				*(vN.get(i)) = *(salidaN.get(i)); 
		    }	        
	    };
	    
	    for (int expN = 1; mN / expN > 0; expN *= 10) 
	        SortN(expN);
	}
	
	
	if(vP.size()!=0)
	{
		auto maximoP = [&] (){
			int mxP = *(vP.get(0)); 
	    	for (int i = 1; i < vP.size(); i++) 
	        if (*(vP.get(i)) > mxP) 
	        mxP = *(vP.get(i)); 
	    	return mxP;
		};
		
	    int mP = maximoP(); 
	
	    auto SortP = [&] (int expP){	
		    Vector salidaP,contadorP; 
		    for (int i = 0; i < 10; i++){	        	
		        contadorP.push_back(0);
		    }
		    for (int i = 0; i < vP.size(); i++){	        	
		        salidaP.push_back(0);
		    } 		  
		    for (int i = 0; i < vP.size(); i++){		
		        *(contadorP.get((*(vP.get(i)) / expP) % 10))=*(contadorP.get((*(vP.get(i)) / expP) % 10))+1;
	        }		  
		    for (int i = 1; i < 10; i++) {		    	
				*(contadorP.get(i)) += *(contadorP.get(i-1)); 
		    }
		    for (int i = vP.size()-1; i >= 0; i--) {
				*(salidaP.get(*(contadorP.get((*(vP.get(i))/expP)%10))-1))=*(vP.get(i)) ;				
				*(contadorP.get((*(vP.get(i)) / expP) % 10))=*(contadorP.get((*(vP.get(i)) / expP) % 10))-1;		
	        }   
		    for (int i = 0; i < vP.size(); i++){
				*(vP.get(i)) = *(salidaP.get(i)); 
		    }	        
	    };
	    
	    for (int expP = 1; mP / expP > 0; expP *= 10) 
	        SortP(expP);	
	}
	if(vN.size()!=0)
    {
		for (int i = vN.size()-1; i >=0; i--){
			*(vector.get(auxNCount)) = *(vN.get(i)); 
			vector[auxNCount]=-1*(vector[auxNCount]);
			auxNCount++;
		}
	}
	if(vP.size()!=0)
    {
		for (int i = 0; i < vP.size(); i++){
			*(vector.get(auxNCount)) = *(vP.get(i)); 
			auxNCount++;
		}
	}
} 

void OrdenamientoInterno::imprimirInterno(){
    imprimir(vector);
    cout<<"\n";
}

