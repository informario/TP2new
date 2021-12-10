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

  const char a[]="file.bmp";

  escribirImagen(*tab, a);

  delete tab;
	
  return 0;
}
