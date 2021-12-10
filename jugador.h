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
  void menuDeOpcionesAMover(int &eleccion);
  /////////////////////////////////////
  
  /*
 * PRE:  - Para anular una casilla del tablero, esta debe de estar vacia, en caso contrario, dicha carta no
 *         tendra efecto y se descontara igualmente de la mano del usuario.
 *       - Para revertir una jugada del turno, el jugador debe de haber colocado todas sus fichas en el tablero,
 *         y la casilla anterior que ocupaba la ultima ficha del jugador al cual se le aplican los efectos de dicha
 *         carta, debe de estar vacía, en caso contrario, dicha carta no tendra efecto y se descontara igualmente de
 *         la mano del usuario.
 *
 * POST: - Se efectua el efecto correspondiente según la acción de la carta elegida por el usuario y se resta
 *         dicha carta de la mano del jugadornque la utilzo.
 *       - Hacer perder el turno de un jugador implica saltearse al jugador contra el que se uso esa carta.
 *         Si el jugador la utiliza contra si mismo, se quitara su siguiente turno.
 *       - Bloquear la ficha de un determinado jugador implica que dicho jugador no podra mover la ultima
 *         ficha movida correspondiente a su anterior turno.
 *       - Anular una casilla del tablero deja inhabilitada dicha casilla hasta que el jugador que la anulo
 *         vuelva a jugar.
 *         Si la casilla estaba ocupada, dicha carta no tuvo efecto.
 *       - Volver atras una jugada del turno implica revertir el ultimo movimiento realizado por el jugador
 *         contra el cual se utiliza dicha carta una vez que todas sus fichas se encuentran en el tablero.
 *         Si la casilla que ocupaba anteriormente dicha ficha afectada por la carta estaba ocupada o bloqueada,
 *         esta carta no tuvo efecto.
 *         Si otro jugador afecta al mismo jugador al cual se le habia revertido la jugada en el mismo turno, no
 *         tendra efecto.
 *       - Destruir las cartas del jugador deja la mano vacía de cartas del jugador afectado.
 *         Si el jugador afectado no tenia cartas e igualmente se uso esta carta contra el, se quita esta carta de
 *         las manos del usuario.
 *       - Renovar las cartas del usuario dejo la mano vacia de cartas de quien uso dicha carta para volver a levantar
 *         nuevas cartas.
 *         Se renovaron la misma cantidad de cartas que el usuario descarto.
 *         Si el usuario no tenia cartas (ademas de la que uso para renovar) el usuario se quedo sin cartas y se le quito
 *         de su mano la carta usada.
 */
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



