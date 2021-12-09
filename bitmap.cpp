#include <iostream>
#include <stdint.h>
#include "bitmap.h"
using namespace std;

size_t escribir_uint16(uint16_t var, FILE *archivo){
    return fwrite(&var, sizeof(uint16_t), 1, archivo);
}
size_t escribir_uint32(uint32_t var, FILE *archivo){
    return fwrite(&var, sizeof(uint32_t), 1, archivo);
}
size_t escribir_uint8(uint8_t var, FILE *archivo){
    return fwrite(&var, sizeof(uint8_t), 1, archivo);
}
uint32_t calcularAncho(Tablero &tablero){
	return tablero.getAncho();
}
uint32_t calcularAlto(Tablero &tablero){
	return tablero.getAlto()*tablero.getProf();
}


bool escribirImagen(Tablero& tablero, const char* nombreArchivo){

	FILE *archivo = fopen(nombreArchivo, "wb");
	if(archivo==NULL) return false;
	size_t val = 0;
	uint32_t dataOffset =54;
	const string error = "Fallo en la escritura";
	const uint32_t anchura = calcularAncho(tablero);
	const uint32_t altura = calcularAlto(tablero);
	const uint8_t pad [3] = {0,0,0};
	const uint32_t relleno = ((4-(anchura*3)%4)%4);

	uint32_t fileSize = dataOffset+ anchura*altura*3 + relleno*altura;


///HEADER///
	val = fwrite("BM", sizeof(char), 2, archivo);//SIGNATURE
	if(val != 2){
		fclose(archivo);
		cout<<error<<endl;
		return false;
	}
	val = escribir_uint32(fileSize, archivo);//FILESIZE
	if(val != 1){
		fclose(archivo);
		cout<<error<<endl;
		return false;
	}
	val = escribir_uint32(0, archivo);//RESERVED
	if(val != 1){
		fclose(archivo);
		cout<<error<<endl;
		return false;
	}
	val = escribir_uint32(dataOffset, archivo);//DATAOFFSET
	if(val != 1){
		fclose(archivo);
		cout<<error<<endl;
		return false;
	}
/////infoHeader////
	val = escribir_uint32(40, archivo);//SIZE
	if(val != 1){
		fclose(archivo);
		cout<<error<<endl;
		return false;
	}
	val = escribir_uint32(anchura, archivo);//WIDTH
	if(val != 1){
		fclose(archivo);
		cout<<error<<endl;
		return false;
	}
	val = escribir_uint32(altura, archivo);//HEIGHT
	if(val != 1){
		fclose(archivo);
		cout<<error<<endl;
		return false;
	}
	val = escribir_uint16(1, archivo);//PLANES
	if(val != 1){
		fclose(archivo);
		cout<<error<<endl;
		return false;
	}
	val = escribir_uint16(24, archivo);//BITCOUNT
	if(val != 1){
		fclose(archivo);
		cout<<error<<endl;
		return false;
	}
	val = escribir_uint32(0, archivo);//COMPRESSION
	if(val != 1){
		fclose(archivo);
		cout<<error<<endl;
		return false;
	}
	val = escribir_uint32(0, archivo);//IMAGESIZE
	if(val != 1){
		fclose(archivo);
		cout<<error<<endl;
		return false;
	}
	val = escribir_uint32(0, archivo);//XPIXELSPM
	if(val != 1){
		fclose(archivo);
		cout<<error<<endl;
		return false;
	}
	val = escribir_uint32(0, archivo);//YPIXELSPM
	if(val != 1){
		fclose(archivo);
		cout<<error<<endl;
		return false;
	}
	val = escribir_uint32(0, archivo);//COLORSUSED
	if(val != 1){
		fclose(archivo);
		cout<<error<<endl;
		return false;
	}
	val = escribir_uint32(0, archivo);//COLORSIMPORTANT
	if(val != 1){
		fclose(archivo);
		cout<<error<<endl;
		return false;
	}
	/////RASTERDATA/////

	for(size_t y=1; y<=altura; y++){
		for(size_t x=1; x<=anchura; x++){
			Casillero* cas = tablero.getCasillero(((y-1)/tablero.getProf())+1      ,x,   (y-1)%tablero.getProf()+1);
			int h;
			if(cas->getId()==0) h = 0;
			else{
				h = (cas->getId()%8)+1;
			}
			val = escribir_uint8(colores[h][0], archivo);//AZUL
			if(val != 1){
				fclose(archivo);
				cout<<error<<endl;
				return false;
			}
			val = escribir_uint8(colores[h][1], archivo);//VERDE
			if(val != 1){
				fclose(archivo);
				cout<<error<<endl;
				return false;
			}
			val = escribir_uint8(colores[h][2], archivo);//ROJO
			if(val != 1){
				fclose(archivo);
				cout<<error<<endl;
				return false;
			}
		}
		val = fwrite(pad, sizeof(uint8_t), relleno, archivo);//SIGNATURE
		if(val != relleno){
			fclose(archivo);
			cout<<error<<endl;
			return false;
		}
	}
	fclose(archivo);
	return true;
}
