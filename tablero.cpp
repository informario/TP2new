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
bool Tablero::esGanador(int ancho, int alto, int prof){
	int largoDeCadaVecino[3][3][3] = {{0,0,0},{0,1,0},{0,0,0}};
	for(int i = -1; i< 2 ; i++){
        for(int j = -1; j < 2; j++){
            for(int k = -1; k < 2; k++){//posiciones relativas
                if(i!=0 || j!=0 || k!=0){
                	largoDeCadaVecino[i+1][j+1][k+1] = obtenerCantidadDeFichasAlineadas(prof, ancho, alto, i,j,k);
                }
            }
        }
    }
    return (cumpleCondicionGanadoraEnAlgunaDireccion(largoDeCadaVecino));
}


bool Tablero::existeCasillero(int prof, int ancho, int alto){
    if (ancho > getAncho() || alto > getAlto() ||
         prof > getProf() || ancho < 1 ||
         alto < 1 || prof < 1)
        return false;

    return true;
}
int Tablero::obtenerCantidadDeFichasAlineadas(int prof, int ancho, int alto, int i, int j, int k){
	//cout<<prof+i<<" "<<ancho+j<<" "<<alto+k<<endl;
	if(existeCasillero(prof, ancho, alto)&&existeCasillero(prof+i, ancho+j, alto+k)){
		Casillero*casillero = getCasillero(prof, ancho, alto);
		Casillero*casilleroVecino = getCasillero(prof+i, ancho+j, alto+k);

		if(casillero->getId() == casilleroVecino->getId()){

			//cout<<prof<<" "<<ancho<<" "<<alto<<endl;
			return 1 + obtenerCantidadDeFichasAlineadas(prof+i,ancho+j,alto+k, i, j, k);
		}
		else return 0;
	}
	else return 0;
}

bool Tablero::cumpleCondicionGanadoraEnAlgunaDireccion(int largoDeCadaVecino[][3][3]){

    int sumaDeFichasEnCadaDireccion[13];

    //largoVecino[ancho][alto][profundidad]

    sumaDeFichasEnCadaDireccion[0]= largoDeCadaVecino[0][0][0] + 1 + largoDeCadaVecino[2][2][2];
    sumaDeFichasEnCadaDireccion[1]= largoDeCadaVecino[0][2][0] + 1 + largoDeCadaVecino[2][0][2];
    sumaDeFichasEnCadaDireccion[2]= largoDeCadaVecino[0][2][2] + 1 + largoDeCadaVecino[2][0][0];
    sumaDeFichasEnCadaDireccion[3]= largoDeCadaVecino[0][0][2] + 1 + largoDeCadaVecino[2][2][0];
    sumaDeFichasEnCadaDireccion[4]= largoDeCadaVecino[0][1][0] + 1 + largoDeCadaVecino[2][1][2];
    sumaDeFichasEnCadaDireccion[5]= largoDeCadaVecino[0][1][2] + 1 + largoDeCadaVecino[2][1][0];
    sumaDeFichasEnCadaDireccion[6]= largoDeCadaVecino[1][0][0] + 1 + largoDeCadaVecino[1][2][2];
    sumaDeFichasEnCadaDireccion[7]= largoDeCadaVecino[1][2][0] + 1 + largoDeCadaVecino[1][0][2];
    sumaDeFichasEnCadaDireccion[8]= largoDeCadaVecino[0][2][1] + 1 + largoDeCadaVecino[2][0][1];
    sumaDeFichasEnCadaDireccion[9]= largoDeCadaVecino[0][0][1] + 1 + largoDeCadaVecino[2][2][1];
    sumaDeFichasEnCadaDireccion[10]= largoDeCadaVecino[1][0][1] + 1 + largoDeCadaVecino[1][2][1];
    sumaDeFichasEnCadaDireccion[11]= largoDeCadaVecino[0][1][1] + 1 + largoDeCadaVecino[2][1][1];
    sumaDeFichasEnCadaDireccion[12]= largoDeCadaVecino[1][1][0] + 1 + largoDeCadaVecino[1][1][2];

    for (int i = 0; i < 13; i++) {
    	cout<<sumaDeFichasEnCadaDireccion[i]<<endl;
        if(sumaDeFichasEnCadaDireccion[i] >= 3){
        	cout<<"xd"<<endl;
            return true;
        }
    }
    return false;
}
