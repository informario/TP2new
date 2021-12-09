/*
 * jugador.h
 *
 *  Created on: 8 dic. 2021
 *      Author: mario
 */
#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "casillero.h"
#include "tablero.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

class Jugador{
  private:
  int cartas[6];
  bool pierdeTurno, gano;
  char id;
  int fichasPorColocar;
  string textoNombre;
  Casillero* casillaPreviaJugada;
  Casillero* casillaPosteriorJugada;
  Casillero* casillaAnulada;

  //METODOS PRIVADOS PARA EL USO DE CARTAS
  int escojerCartaAUtilizar();
  void hacerPerderTurnoAJugador(Lista<Jugador*>* jugadores);
  void bloquearFichaDeJugador(Lista<Jugador*>* jugadores);
  void anularCasilleroDelTablero(Tablero* tablero);
  void revertirJugadaDeJugador(Lista<Jugador*>* jugadores);
  void destruirCartasDeJugador(Lista<Jugador*>* jugadores);
  void renovarCartas(int maximoDeCartas);
  Jugador* pedirJugadorAPerjudicar(Lista<Jugador*>* jugadores);
  int generarIndiceCartaAleatorio();

  public:
  Jugador(char ide, string texnom, int fichas);
  ~Jugador();
  int getCantCartasDeUnTipo(int);//PRE:el tipo de carta debe ser >=0, <6///POST: devuelve cuantas cartas hay de un determinado tipo
  int getCantTotalCartas();
  bool getPierdeTurno();//POST: devuelve si pierde el turno o no
  bool getGano();//POST: devuelve si ganó o no
  char getId();//POST: devuelve char que identifica al jugador
  int getFichasPorColocar();//POST: devuelve la cantidad de fichas que aún no se colocaron
  string getTextoNombre();//POST: devuelve un string con el nombre del jugador
  int levantarCarta(int cantMaxCartas);//POST: devuelve -1 si no pudo levantar carta. Si pudo levantar, devuelve el indice de la carta que levanto. Se sumo +1 la cant de carta corresp
  void setPierdeTurno(bool);//POST: establece si pierde el turno o no
  void setGano(bool);//POST: establece si gano o no
  void setId(char);//POST: identifica a un jugador con un caracter
  void setFichasPorColocar(int);//POST: modifica la cantidad de fichas que aun no se colocaron
  void setTextoNombre(string);//POST: asigna un nombre al jugador
  //////////////
  void colocarFicha(Tablero* tab);
  void ingresarVerificandoValores(int& ancho, int& profundidad, int& alto, Tablero* tablero);

  ///FALTABAN AGREGAR FIRMAS DE METODOS
  void moverFicha(Tablero* tablero);
  void intercambiarFichas(Casillero* casillero, Casillero* casilleroAMover);
  Casillero* encontrarCasillero(Tablero* tablero, int profundidad, int ancho, int alto);
  /////////////////////////////////////

  void usarCarta(Lista<Jugador*>* jugadores, Tablero* tablero, int maximoDeCartas);

  //GETTERS Y SETTERS FALTANTES
  void setCasillaPreviaJugada(Casillero*);
  Casillero* getCasillaPreviaJugada();
  void setCasillaPosteriorJugada(Casillero*);
  Casillero* getCasillaPosteriorJugada();
  void setCasillaAnulada(Casillero*);
  Casillero* getCasillaAnulada();

};
#endif



