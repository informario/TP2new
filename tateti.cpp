#include "tateti.h"
#include <iostream>
using namespace std;


void introduccion(int &n, int &m, int &z, int &c){
	///IMPRIMIR INSTRUCCIONES
		  cout<<"ingrese n: ";
	cin>>n;
	cout<<endl<<"ingrese m: ";
	cin>>m;
	cout<<endl<<"ingrese z: ";
	cin>>z;
	cout<<endl<<"ingrese c: ";
	cin>>c;
	cout<<endl;

}
Lista<Jugador*>* obtenerJugadores(){
	Lista<Jugador*> *jug = new Lista<Jugador*>();
	jug->add(new Jugador((char)1, "Juan", 3));
	jug->add(new Jugador((char)2, "Pablo", 3));
	jug->add(new Jugador((char)3, "Carlos", 3));




	/*bool seguir=true;
	int x=1;
	int cantFichas=0;
	cout<<endl<<"Ingrese la cantidad de fichas por jugador: ";
	cin>>cantFichas;
	do{
		char a;
		cout<<endl<<"Desea ingresar un jugador?(y/n):";
		cin>>a;
		if (a=='y'){
			string texnom;
			cout<<endl<<"Ingrese el nombre del jugador: ";
			cin>>texnom;
			jug->add(new Jugador((char)x, texnom, cantFichas));
			x++;
		}
		else{
			seguir=false;
		}

	}while(seguir&&x<127);
	cout<<"hola";*/
	return jug;
}


void felicitacion(Jugador* a){
	cout<<"FELICITACIONES, GANO"<<a->getTextoNombre()<<endl;
}

void procesarJuego(Lista<Jugador*>*jug, Tablero *tab, int c){
	bool hayGanador=0;
	int y=0;
	int x;
	do{
		for(x=1; x<=jug->contarElementos(); x++){
			
			/// SI EL JUGADOR ANULO UNA POSICION DEL TABLERO EN EL ANTERIOR TURNO, YA VUELVE A LA NORMALIDAD
            		jug->get(x)->setCasillaAnulada(NULL);
			
			if(jug->get(x)->getPierdeTurno()){
				jug->get(x)->setPierdeTurno(false);
			}
			else{
				///SE LEVANTA UNA CARTA
			    	cout<<jug->get(x)->getTextoNombre();
                		int cartaRecibida = jug->get(x)->levantarCarta(c);
                		mostrarSiLevantoCarta(cartaRecibida);
				
				if(jug->get(x)->getFichasPorColocar()>0){
					///se colocan las fichas
					jug->get(x)->colocarFicha(tab);
				}
				else{
					//se mueven las fichas
					jug->get(x)->moverFicha(tab);
				}
				if(!hayGanador && jug->get(x)->getCantTotalCartas() > 0){
					char e;
					cout<<"Desea usar una carta? (y/n): "<<endl;
					cin>>e;
					if(e == 'y'){
						jug->get(x)->usarCarta(jug, tab, c);
					}
				}

			}
		y++;
		}
	}while(y<=7);


	/*do{
		cout<<"hola";
		if(jug->getCursor()!=NULL){
			cout<<"hola";
			jug->getCursor()->usarCarta(jug, tab, c);////se esta jugando con el anterior, ojo
		//POST: usarCarta no debe hacer nada si el jugador pasado por parámetro es null
		}
		cout<<"hola";
		jug->avanzarCursor();
		if(jug->getCursor()==NULL)jug->avanzarCursor();
		// se itera la lista de jugadores
		if(jug->getCursor()->getFichasPorColocar()>0){
			///se colocan las fichas
			jug->getCursor()->colocarFicha(tab);
		}
		else{
			jug->getCursor()->moverFicha(tab);
		}
		cout<<"hola";
		tab->imprimirTablero();
	}while (tab->recorrerTablero(jug->getCursor()->getId())==false);
	
	jug->getCursor()->setGano(true);*/
}


///AGREGO IMPLEMENTACION DE FUNC AUXILIAR///
void mostrarSiLevantoCarta(int indiceCarta){

    string nombresCartas[] = {"Hacer perder turno a jugador", "Bloquear ficha de jugador", "Anular casillero", "Volver atras una jugada del turno", "Quitar cartas a jugador", "Renovar cartas"};

    if (indiceCarta == -1){
        cout<<" no pudo levantar carta"<<endl<<"Ya tiene la cantidad maxima permitida de cartas en mano."<<endl;
    }else{
        cout<<" ha levantado una carta: "<<nombresCartas[indiceCarta]<<endl;
    }
}

int generarIndiceCarta(){
    ///PROBABILIDADES DE QUE SALGAN LAS CARTAS:
    /// CARTA TIPO 0 Y 5 -> PROB 5/20
    /// CARTA TIPO 1 Y 4 -> PROB 3/20
    /// CARTA TIPO 2 Y 3 -> PROB 2/20
    int indicesProba[] = {0,0,0,0,0,1,1,1,2,2,3,3,4,4,4,5,5,5,5,5};
    int aleatorio;
    /// SE AGREGARON A TATETI.H BIBLIOTECAS NECESARIAS PARA ESTA FUNCION
    srand(time(NULL));
    aleatorio = rand()%20;
    return indicesProba[aleatorio];
}














