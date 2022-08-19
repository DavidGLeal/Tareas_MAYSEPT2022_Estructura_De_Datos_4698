#ifndef BITWISE_H
#define BITWISE_H

#include <iostream>

template <typename T, T defaultT>
	
	class Bitwise {
		private:
			T valor;
		
		public:
			Bitwise(T vr = defaultT) 
			{
                this -> valor = vr;
            }
			
			T getValor() {
				return this -> valor;
			}

            Bitwise operator~ (){
                return Bitwise(this -> getValor() * (-1) );
            }

			void imprimir() {
				std::cout << this -> valor << "\n" << std::endl;
			}
	};
#endif
