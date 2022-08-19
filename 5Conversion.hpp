#pragma once

template <typename T, typename N>

    class Conversion{
        private:
            bool numero;
            int verificador = 0;

        public:
            Conversion(){} //Constructor
            ~Conversion(){} //Destructor

            T numInt(char* dato){ //Convertir a entero
                return atoi(dato); //String a int
            } 

            N numFloat(char* dato){ //Convertir a flotante 
                return std::stof(dato);
            }

            void verificar(char c){ //Metodo para verificar flotante o entero  
                if (c == 46){ // 46 codigo ASCII del punto (.)
                    this -> numero = true; //Asigno verdadero si es un flotante, pues tiene punto
                } else{
                    this -> numero = false; //Asigno falso si es un entero. Pues no posee punto
                }
            }

            bool getNumero(){
                return this -> numero;
            }

            void setVerificador(int v){
                this -> verificador = v;
            }

            int getVerificador(){
                return this->verificador;
            }
    };
