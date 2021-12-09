#include "casillero.h"
Casillero::Casillero(){
  id = 0;
  bloqueado = false;
}
Casillero::~Casillero(){
}
char Casillero::getId(){
  return id;
}
bool Casillero::getBloqueado(){
  return bloqueado;
}
void Casillero::setId(char a){
  id = a;
}
void Casillero::setBloqueado(bool a){
  bloqueado = a;
}
bool Casillero::getOcupado(){
	return (id!=0);
}
