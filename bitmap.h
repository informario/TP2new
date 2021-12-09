#ifndef BITMAP_H_
#define BITMAP_H_
#include <iostream>
#include <stdint.h>
#include "tablero.h"

typedef enum {
	BLANCO,
	NEGRO,
	ROJO,
	AZUL,
	VERDE,
	AMARILLO,
	MAGENTA,
	CYAN,
	GRIS
}paleta_t;

const uint8_t colores[9][3] = {  ///B,G,R
	[BLANCO] = {255,255,255},
	[NEGRO] = {0,0,0},
	[ROJO] = {0,0,255},
	[AZUL] = {255,0,0},
	[VERDE] = {0,255,0},
	[AMARILLO] = {0,255,255},
	[MAGENTA] = {255,0,255},
	[CYAN] = {255,255,0},
	[GRIS] = {127,127,127}
};

bool escribirImagen(Tablero& tablero, const char* nombreArchivo);

#endif
