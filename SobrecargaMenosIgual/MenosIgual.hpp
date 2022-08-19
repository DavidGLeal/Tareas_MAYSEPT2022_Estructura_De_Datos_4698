#ifndef MENOSIGUAL_H
#define MENOSIGUAL_H

#include <iostream>

template <typename T, typename N, T defaultT, N defaultN>
	
	class MenosIgual {
		private:
			T valor1;
            N valor2;
		
		public:
			MenosIgual(T vr1 = defaultT, N vr2 = defaultN) 
			{
                this -> valor1 = vr1;
                this -> valor2 = vr2;
            }
			
			T getValor1() {
				return this -> valor1;
			}
			
            N getValor2(){
                return this -> valor2;
            }

            MenosIgual operator -= (MenosIgual mi){
                return MenosIgual(this -> getValor1() - this -> getValor2(), this -> getValor1() - (mi.getValor1() + mi.getValor2()));
            }

			void imprimir() {
				std::cout << this -> valor1 << " y " << this -> valor2 << "\n" << std::endl;
			}
	};
#endif