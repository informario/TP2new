#ifndef CASILLERO_H_
#define CASILLERO_H_

class Casillero{
  private:
  char id;
  bool bloqueado;

  public:
  Casillero();
  ~Casillero();
  char getId();//POST: devuelve el char correspondiente al jugador que ocupa la casilla
  bool getBloqueado();//POST: devuelve si el casillero fue bloqueado o no
  void setId(char);//POST: asigna un char a un casillero, propio del dueño
  void setBloqueado(bool);//POST: asigna si fue bloqueado o no
  bool getOcupado();//POST: devuelve true si !=0
};





#endif /* CASILLERO_H_ */
