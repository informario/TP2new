#include "tablero.h"
#include <iostream>
using namespace std;

Tablero::Tablero(int prof, int anch, int alt){
  ancho = anch;
  alto = alt;
  profundidad = prof;
  tab = new Lista<Lista<Lista<Casillero*>*>*>();
  for(int x=1; x<=prof; x++){
	  tab->add(new Lista<Lista<Casillero*>*>(),x);
	  for(int y=1; y<=anch; y++){
		 tab->get(x)->add(new Lista<Casillero*>(),y);
		 for(int z=1; z<=alt; z++){
			 tab->get(x)->get(y)->add(new Casillero(),z);
		 }
	  }
  }
}

Tablero::~Tablero(){
	do{
		do{
			do{
				delete tab->get(1)->get(1)->get(1);
				tab->get(1)->get(1)->remover(1);
			}while(tab->get(1)->get(1)->vacia()==false);
			delete tab->get(1)->get(1);
			tab->get(1)->remover(1);
		}while(tab->get(1)->vacia()==false);
		delete tab->get(1);
		tab->remover(1);
	}while(tab->vacia()==false);
	delete tab;
}

int Tablero::getAncho(){
  return ancho;
}
int Tablero::getAlto(){
  return alto;
}
int Tablero::getProf(){
  return profundidad;
}

Casillero* Tablero::getCasillero(int prof, int anch, int alt){
  if(prof<1||anch<1||alt<1||prof>getProf()||alt>getAlto()||anch>getAncho()){
	  cout<<"el casillero solicitado se va del rango"<<endl;
	  return NULL;
  }
  return tab->get(prof)->get(anch)->get(alt);
}
void Tablero::imprimirTablero(){
	//cout<<"pendiente programar funcion imprimirTablero()"<<endl;
	for(int z=1; z<=getProf(); z++){

		for(int y=1; y<=getAlto(); y++){
			for(int x=1; x<=getAncho(); x++){
				cout<<(int)getCasillero(z, x, y)->getId();
			}
			cout<<endl;
		}
		cout<<endl;
	}
}
