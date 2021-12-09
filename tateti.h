#ifndef TATETI_H_
#define TATETI_H_

#include "jugador.h"
#include "tablero.h"
#include "lista.h"
#include <iostream>

///PARA GENERAR CARTA ALEATORIA////
#include <cmath>
#include <ctime>
#include <cstdlib>

void introduccion(int &n, int &m, int &z, int &c);
Lista<Jugador*> *obtenerJugadores();
void procesarJuego(Lista<Jugador*>*jug, Tablero *tab, int c);
void felicitacion(Jugador* a);    



///AGREGO FUNCION A TATETI (AUXILIAR PARA procesarJuego)///

/*
 * PRE:  - indiceCarta debe ser un entero entre -1 y 5.
 *
 * POST: - Se muestra en pantalla si el jugador actual ha levantado carta.
 *       - Si su mano no estaba llena y pudo levantar carta, le indica el nombre de la carta que le toco.
 *       - Si su mano estaba llena, le indica que no pudo levantar carta.
 */
void mostrarSiLevantoCarta(int indiceCarta);

///GENERAR UNA CARTA PASA A SER UNA FUNCION DE TATETI Y YA NO ES UN METODO DE JUGADOR

/*
 * POST: - Devuelve un entero entre 0 y 5 representando el indice del tipo de carta
 */
int generarIndiceCarta();






#endif
