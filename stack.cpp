	#include <iostream>

using namespace std;

//Creando una pila

class Nodo{
    int dato;
    Nodo *siguiente;

    public:
        Nodo(int d=0, Nodo *s =NULL){
            dato = d;
            siguiente = s;
        }
        void modDato(int d){
            dato =d;
        }
        void modSig(Nodo *s){
            siguiente = s; //para que "siguiente" apunte a donde apunta "s"
        }
        int regDato(){
            return dato;
        }
        Nodo *regSig(){
            return siguiente;
        }

};

class Pila{

    Nodo *st, *gen, *tope;
    public:
        Pila(){st = gen = tope =NULL;}
        void push(int dato);
        int pop();
        void imprimir();
};

void Pila::push(int dato){
    if(tope == NULL){
        st = tope = new Nodo(dato);
        //Add security verification
    }else{
        gen = new Nodo(dato,tope);
        tope = gen;
    }
}

int Pila::pop(){
    if(tope ==NULL){
        // return NULL;
        return -1;
    }   

    Nodo *q = tope;
    int valor_tope = tope ->regDato();
    tope = q->regSig();
    q->modSig(NULL);
    delete q;

}

void Pila::imprimir(){
    Nodo *i = tope;

    while( i != NULL){
        cout<<i->regDato();
        i = i->regSig();
    }
}


int main(){
    setlocale(LC_ALL, "spanish");

    Pila R;
    Datos G;
    int ent, opc, opc1;

    do{
        system("cls");    
        cout<<"\t\tM E N U Canción \n";
        cout<<"\n\t1.- Insertar";
        cout<<"\n\t2.- Insertar Ordenado";
        cout<<"\n\t3.- Imprimir";
        cout<<"\n\t4.- Salir";
        cout<<"\n\n\t Opcion: ";
        cin>>opc;

        switch(opc){
            
            case 1:
                cout<<"\n Dame los valores \n ";
                G = LeerDatos();
                R.Insertar(G);
                break;
            case 2:
            	cout<<"\n Dame los valores \n ";
                G = LeerDatos();
                R.InsOrd(G);
            	break;
            case 3:
                cout<<"\n Los valores de la lista \n ";
                R.Imprimir();
                getch();
                break;
            default:
                cout<<"\n\n\n Gracias por usar este software";
                getch();
				exit(1);//Extra
        }
        system("cls");
        cout<<"\n\t\t�Desea hacer otra operacion?:\n\t\t1= si\n\t\t2=no\n\t\t\t ";//Fprecioa...
        cin>>opc1;

    }while(opc1 ==1);

    getch();

    return 0;
}
