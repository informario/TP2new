#include "tablero.h"
#include "jugador.h"

#include "tateti.h"
#include "lista.h"
#include "bitmap.h"
#include <iostream>
using namespace std;

int main(){
  int n=0, m=0, z=0, c=0;
  introduccion(n, m, z, c); //el usuario guarda los distintos valores.
  Tablero *tab = new Tablero(n,m,z);
  Lista<Jugador*> *jug = obtenerJugadores();
  jug->reiniciarCursor();
  jug->avanzarCursor();
  procesarJuego(jug, tab, c);


  jug->reiniciarCursor();

  while(jug->avanzarCursor()){
	if(jug->getCursor()->getGano()==true) felicitacion(jug->getCursor());
  }

  const char a[]="file.bmp";
  ///test bitmap
  /*
  const char a[] = "imagen.bmp";
  Tablero *tablero = new Tablero(4,4,4);
  tablero->getCasillero(1,1,1)->setId(4);
  tablero->getCasillero(1,2,2)->setId(4);
  tablero->getCasillero(1,1,3)->setId(4);
  tablero->getCasillero(1,2,4)->setId(4);

  tablero->getCasillero(2,4,1)->setId(5);
  tablero->getCasillero(2,3,2)->setId(5);
  tablero->getCasillero(2,4,3)->setId(5);
  tablero->getCasillero(2,3,4)->setId(5);

  tablero->getCasillero(3,1,1)->setId(4);
  tablero->getCasillero(3,2,2)->setId(4);
  tablero->getCasillero(3,3,3)->setId(4);
  tablero->getCasillero(3,4,4)->setId(4);

  tablero->getCasillero(4,4,1)->setId(5);
  tablero->getCasillero(4,3,2)->setId(5);
  tablero->getCasillero(4,2,3)->setId(5);
  tablero->getCasillero(4,1,4)->setId(5);*/

  escribirImagen(*tab, a);

  delete tab;
	
	
  return 0;
}
