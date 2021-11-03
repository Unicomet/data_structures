#include <stdio.h>
#include <conio.h>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <locale.h> // Libreria que contiene la funcion setlocale



using namespace std;


//Almaceno datos de cursos
struct Datos{
    char nombre [20];
    unsigned int anio;
    float calificacion;
    double precio;
};

Datos Ini = {'\0',0,0.0,0.0};

Datos LeerDatos(){
    Datos L;
    cout<<"\nDame el nombre = ";
    cin>>L.nombre;
    cout<<"\nDame el año= ";
    cin>>L.anio;
    cout<<"\nDame la calificacion = ";
    cin>>L.calificacion;
	cout<<"\nDame el precio = ";
	cin>>L.precio;


    return L;
}

class Nodo{
    Datos Dato;
    Nodo *sig; 
    public:
        Nodo(Datos d= Ini, Nodo *s =NULL){
            cout<<"\nMe llama la declaracion del objeto";
            Dato = d;
            sig = s;
        }

        Datos ModDatos(Datos d){ Dato = d;}
        int ModEdad(int e){Dato.anio = e;}
        float ModPeso(float p){Dato.calificacion = p;}
        double ModAlt(double a) {Dato.precio = a;}
        Nodo ModSig(Nodo *s) {sig = s;}
		
		Datos RegDatos(){ return Dato;}
        char *Regnombre(){return (Dato.nombre);}
        int RegEdad(){return (Dato.anio);}
        float RegPeso(){ return (Dato.calificacion);}
        double RegAlt(){ return (Dato.precio); }
        Nodo *RegSig(){ return sig;}
};

class LSE{
    Nodo *st, *ed, *gen;
    public:
        LSE(){st = ed = gen = NULL;}
        void Insertar(Datos x);
        void InsOrd(Datos x);
        void Imprimir();
};

void LSE::Insertar(Datos x){
    if(st == NULL){
        gen = new Nodo(x);
        if(gen == NULL){
            cout<<"No hay memoria";
            exit(1);
        }
        st = ed = gen;

    }else{
        Nodo *p = gen;
        gen = new Nodo(x);
        if(gen == NULL){
            cout<<"No hay memoria";
            exit(1);		
        }
        p->ModSig(gen);
        ed = gen;
    }
}

void LSE::InsOrd(Datos x){
	Nodo *p, *q;
	
	if(st ==NULL){//Cuando la lista esta vacia
		gen = new Nodo(x);
		//codigo seguridad
		st = ed = gen;
	}
	else{
		p = st;
		if( strcmp( x.nombre, p->Regnombre() ) <0 ){//Cuando la lista no este vacia y la anio de Datos sea menor al nodo existente.
			gen = new Nodo(x,p);
			//codigo seguridad
			st = gen;
		}
		else{//La anio de Datos es mayor o igual a la del primer nodo (head).
			p = ed;
			if( strcmp( x.nombre, p->Regnombre() ) > 0 ){//Es mayor al ultimo nodo(ed)
				gen = new Nodo(x);
				//codigo seguridad
				ed = gen;
				p->ModSig(gen);	
			}else{//Es igual al ultimo nodo o NO es mayor al ultimo ni menor al primero (Va en medio)
				p=st;
				while( strcmp( x.nombre, p->Regnombre() ) > 0  ){
					q = p;
					p = p->RegSig();
				}
				gen = new Nodo (x,p);
				//codigo seguridad
				q->ModSig(gen);
			}
		}
	}
	
}

void LSE::Imprimir(){
    Nodo *i;
    cout<<"\nImprime la lista "<<endl;
    for(i = st; i!= NULL; i = i->RegSig() ){
        cout<<"\n"<<setw(10)<<i->Regnombre();
        cout<<"\n"<<setw(10)<<i->RegEdad();
        cout<<"\n"<<setw(10)<<i->RegAlt();
        cout<<"\n"<<setw(10)<<i->RegPeso();
        cout<<endl<<endl;   
    }
}


int main(){

    setlocale(LC_ALL, "spanish");


    LSE R;
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


