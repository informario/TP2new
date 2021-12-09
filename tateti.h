#ifndef TATETI_H_
#define TATETI_H_

#include "jugador.h"
#include "tablero.h"
#include "lista.h"
#include <iostream>

void introduccion(int &n, int &m, int &z, int &c);
Lista<Jugador*> *obtenerJugadores();
void procesarJuego(Lista<Jugador*>*jug, Tablero *tab, int c);
void felicitacion(Jugador* a);    







#endif
