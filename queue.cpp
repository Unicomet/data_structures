
#include <conio.h>
#include <stdio.h>

using namespace std;

class Nodo{
    int dato;
    Nodo *siguiente;

    public:
        Nodo(int d = 0, Nodo* s =NULL){
            dato = d;
            siguiente = s;
        }
        void modDato(int d){
            dato = d;
        }
        void modSiguiente(Nodo *s){
            siguiente =s;
        }
        int regDato(){
            return dato;
        }
        Nodo *regSiguiente(){
            return siguiente;
        }

}

class Cola{
    Nodo *frente,*final,*gen;
    public:
        Cola(){
            frente=final=gen= NULL;
        }
        void Insertar(int dato){
            if(frente == NULL){
                gen = new Nodo();
                frente = final = gen; 
            }else{
                gen = new Nodo(dato, final);
                final = gen;
            }
        }
}


int main(){


    return 0;
}