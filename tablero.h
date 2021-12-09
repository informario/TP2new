#ifndef TABLERO_H_
#define TABLERO_H_
#include "lista.h"
#include "casillero.h"

class Tablero{
  private:
  int ancho;
  int alto;
  int profundidad;
  Lista<Lista<Lista<Casillero*>*>*> *tab; ///el puntero a la estructura de casilleros

  public:
  Tablero(int prof, int anch, int alt);
  ~Tablero();
  int getAncho();
  int getAlto();
  int getProf();
  Casillero *getCasillero(int prof, int anch, int alt);//POST: devuelve un puntero a casillero según las coordenadas que se indiquen
  void imprimirTablero();
  void bmpTablero();
};




#endif /* TABLERO_H_ */
