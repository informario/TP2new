#include "tateti.h"
#include <iostream>
using namespace std;


void introduccion(int &n, int &m, int &z, int &c){
	///IMPRIMIR INSTRUCCIONES
		  cout<<"ingrese n: ";
	cin>>n;
	cout<<endl<<"ingrese m: ";
	cin>>m;
	cout<<endl<<"ingrese z: ";
	cin>>z;
	cout<<endl<<"ingrese c: ";
	cin>>c;
	cout<<endl;

}
Lista<Jugador*>* obtenerJugadores(){
	Lista<Jugador*> *jug = new Lista<Jugador*>();
	jug->add(new Jugador((char)1, "Juan", 3));
	jug->add(new Jugador((char)2, "Pablo", 3));
	jug->add(new Jugador((char)3, "Carlos", 3));




	/*bool seguir=true;
	int x=1;
	int cantFichas=0;
	cout<<endl<<"Ingrese la cantidad de fichas por jugador: ";
	cin>>cantFichas;
	do{
		char a;
		cout<<endl<<"Desea ingresar un jugador?(y/n):";
		cin>>a;
		if (a=='y'){
			string texnom;
			cout<<endl<<"Ingrese el nombre del jugador: ";
			cin>>texnom;
			jug->add(new Jugador((char)x, texnom, cantFichas));
			x++;
		}
		else{
			seguir=false;
		}

	}while(seguir&&x<127);
	cout<<"hola";*/
	return jug;
}


void felicitacion(Jugador* a){
	cout<<"FELICITACIONES, GANO"<<a->getTextoNombre()<<endl;
}

void procesarJuego(Lista<Jugador*>*jug, Tablero *tab, int c){
	bool hayGanador=0;
	int y=0;
	int x;
	do{
		for(x=1; x<=jug->contarElementos(); x++){
			if(jug->get(x)->getPierdeTurno()){
				jug->get(x)->setPierdeTurno(false);
			}
			else{
				if(jug->get(x)->getFichasPorColocar()>0){
					///se colocan las fichas
					jug->get(x)->colocarFicha(tab);
				}
				else{
					//se mueven las fichas
					jug->get(x)->moverFicha(tab);
				}

			}
		y++;
		}
	}while(y<=7);


	/*do{
		cout<<"hola";
		if(jug->getCursor()!=NULL){
			cout<<"hola";
			jug->getCursor()->usarCarta(jug, tab, c);////se esta jugando con el anterior, ojo
		//POST: usarCarta no debe hacer nada si el jugador pasado por parámetro es null
		}
		cout<<"hola";
		jug->avanzarCursor();
		if(jug->getCursor()==NULL)jug->avanzarCursor();
		// se itera la lista de jugadores
		if(jug->getCursor()->getFichasPorColocar()>0){
			///se colocan las fichas
			jug->getCursor()->colocarFicha(tab);
		}
		else{
			jug->getCursor()->moverFicha(tab);
		}
		cout<<"hola";
		tab->imprimirTablero();
	}while (tab->recorrerTablero(jug->getCursor()->getId())==false);
	
	jug->getCursor()->setGano(true);*/
}
















