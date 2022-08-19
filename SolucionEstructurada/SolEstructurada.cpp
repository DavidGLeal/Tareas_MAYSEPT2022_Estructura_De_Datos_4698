#include <iostream>
#include <cstring>

void decimaBinario(int, char*);

void decimaBinario(int val, char *cad){
    if(val >= 1){
        decimaBinario(val/2, cad);
                    //Avanzo en posicion
        itoa(val%2, cad + strlen(cad), 10);
    }
    strcat(cad,"\0");
}

int main(){

    char *cad = new char[10];
    cad[0] = '\0'; 
    decimaBinario(124, cad);

    printf("%s ", cad);

    return 0;
}


