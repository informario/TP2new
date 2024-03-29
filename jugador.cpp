#include "jugador.h"

///NECESARIO PARA LEVANTAR CARTA 
#include "tateti.h"

Jugador::Jugador(char ide, string texnom, int fichasIniciales){
  for(int x=0; x<6; x++){
    cartas[x]=0;
  }
  pierdeTurno=false;
  gano=false;
  id=ide;
  fichasPorColocar=fichasIniciales;
  textoNombre=texnom;
}
Jugador::~Jugador(){
}
int Jugador::getCantCartasDeUnTipo(int a){
  return cartas[a];
}
bool Jugador::getPierdeTurno(){
  return pierdeTurno;
}
bool Jugador::getGano(){
  return gano;
}
char Jugador::getId(){
  return id;
}
int Jugador::getFichasPorColocar(){
  return fichasPorColocar;
}
string Jugador::getTextoNombre(){
  return textoNombre;
}

void Jugador::setPierdeTurno(bool a){
  pierdeTurno = a;
}
void Jugador::setGano(bool a){
  gano = a;
}
void Jugador::setId(char nom){
  id = nom;
}
void Jugador::setFichasPorColocar(int cant){
  fichasPorColocar = cant;
}
void Jugador::setTextoNombre(string a){
  textoNombre=a;
}
/*
    PRE: recibe como parametro un puntero a tablero y tiene en cuenta que las variables locales ancho, profundidad y alto esten dentro de las dimensiones del tablero.
    Tambien la casilla a la que se quiere ingresar una ficha no debe estar bloqueada ni ocupada.
    POST: declara tres variables locales, ancho, profundidad y alto y se ingresa una ficha con esas coordenadas.
*/
void Jugador::colocarFicha(Tablero* tablero) {
    tablero->imprimirTablero();
    int ancho, profundidad, alto;
    Casillero* casilleroDondeColoco;

    cout<<"Es el turno del jugador: "<<this->getTextoNombre()<<" su ficha es: "<<this->getId()<<endl<<endl;
    cout << "Seleccione una posicion (ancho, profundidad y altura respectivamente) para ingresar una ficha en esa posicion" << endl;

    this->ingresarVerificandoValores(ancho, profundidad, alto, tablero);

    while (tablero->getCasillero(profundidad, ancho, alto)->getBloqueado() == true || tablero->getCasillero(profundidad, ancho, alto)->getId() != 0) {

        if (tablero->getCasillero(profundidad, ancho, alto)->getBloqueado() == true) {
            cout << "la posicion ingresada esta bloqueada!!!" << endl;
        }

        else {
            cout << "la posicion elegida ya esta ocupada!!!" << endl;
        }
        cout << "Elija otra posicion en la cual ingresar la ficha!!!" << endl << endl;
        tablero->imprimirTablero();
	cout << "Seleccione una posicion (ancho, profundidad y altura respectivamente) para ingresar una ficha en esa posicion" << endl;
	this->ingresarVerificandoValores(ancho, profundidad, alto, tablero);
    }
    casilleroDondeColoco=tablero->getCasillero(profundidad,ancho,alto);
    casilleroDondeColoco->setId(this->getId());
    this->setFichasPorColocar(this->getFichasPorColocar() - 1);

    this->setCasillaPosteriorJugada(casilleroDondeColoco);
    return tablero->esGanador(ancho,alto,profundidad);
}

/*
    PRE: recibe por parametros la direccion de memoria de cada atributo del casillero (ancho, profundidad y alto) y el puntero al tablero,los valores mencionados tienen que estar dentro de las
    dimensiones del tablero y tienen que ser de tipo entero(int).
    POST: le pregunta al usuario sobre los valores de ancho, profundidad y altura y luego se los otorga a las variables que fueron pasadas por referencia.
*/
void  Jugador::ingresarVerificandoValores(int &ancho,int &profundidad,int &alto, Tablero* tablero) {

      cout << "Ancho: ";
      cin >> ancho;

      while (ancho<1 || ancho>tablero->getAncho()) {
          cout << "El ancho ingresado no es valido ingrese otro (el valor debe estar entre 0 y " << tablero->getAncho() << " ): ";
          cin >> ancho;
      }

      cout << "Profundidad: ";
      cin >> profundidad;

      while (profundidad<1 || profundidad>tablero->getProf()) {
          cout << "La profundidad ingresada no es valida ingrese otra (el valor debe estar entre 0 y " << tablero->getAncho() << " ): ";
          cin >> profundidad;
      }

        cout << "Alto: ";
        cin >> alto;

      while (alto<1 || alto>tablero->getAlto()){
          cout << "El alto ingresado no es valido ingrese otro (el valor debe estar entre 0 y " << tablero->getAncho() << " ): ";
          cin >> alto;
      }
 }

/*
    PRE: recibe como parametro un puntero a tablero la casilla que se selecciona debe estar dentro de las dimensiones del tablero, no debe estar bloqueada y no puede estar vacia o ocupada por otro jugador,
    la casilla a la que se mueve la ficha debe estar dentro de las dimensiones del tablero, no puede estar bloqueada la casilla y tiene que estar vacia. La eleccion ingresada por el usuario tiene que ser de tipo entero(int).
    POST: mueve una ficha de un casillero a un casillero que se encuentre al lado del mismo (no puede moverse en diagonal).
*/

void Jugador::moverFicha(Tablero* tablero) {
    tablero->imprimirTablero();
    int ancho, profundidad, alto;
    bool seguir=true,volverAEmpezar=false;
    int eleccion,opcion2;
    Casillero *casillero, *casilleroDestino;

    cout<<"Es el turno del jugador: "<<this->getTextoNombre()<<" su ficha es: "<<this->getId()<<endl<<endl;
    cout << "Seleccione una posicion (ancho, profundidad y altura respectivamente) para mover una ficha de esa posicion" << endl;
    this->ingresarVerificandoValores(ancho, profundidad, alto, tablero);

    while (tablero->getCasillero(profundidad, ancho, alto)->getBloqueado() == true || tablero->getCasillero(profundidad, ancho, alto)->getId() != this->getId()) {

            if (tablero->getCasillero(profundidad, ancho, alto)->getBloqueado() == true) {
                cout << "la posicion ingresada esta bloqueada!!!" << endl;
            }

            else {
                cout << "la posicion elegida ya esta ocupada por otra ficha!!!, seleccione un casillero que este ocupado por una de sus fichas" << endl;
            }
            cout << "Elija otra posicion de una ficha para moverla!!!" << endl << endl;
            tablero->imprimirTablero();
    	cout << "Seleccione una posicion (ancho, profundidad y altura respectivamente) para ingresar una ficha en esa posicion" << endl;
    	this->ingresarVerificandoValores(ancho, profundidad, alto, tablero);
    }
    
    casillero=tablero->getCasillero(profundidad,ancho,alto);
    
    tablero->imprimirTablero();
    this->menuDeOpcionesAMover(eleccion);

    while(seguir==true && volverAEmpezar==false){
    	switch(eleccion){
    		case 1:
    			casilleroDestino=tablero->getCasillero(profundidad,ancho,alto+1);
    			break;
    		case 2:
    			casilleroDestino=tablero->getCasillero(profundidad,ancho,alto-1);
    			break;
    		case 3:
    			casilleroDestino=tablero->getCasillero(profundidad,ancho+1,alto);
    			break;
    		case 4:
    			casilleroDestino=tablero->getCasillero(profundidad,ancho-1,alto);
    			break;
    		case 5:
    			casilleroDestino=tablero->getCasillero(profundidad+1,ancho,alto);
    			break;
    		case 6:
    			casilleroDestino=tablero->getCasillero(profundidad-1,ancho,alto+1);
    			break;
    		case 7:
    			volverAEmpezar=true;
    			break;
    		default:
    			cout<<"La opcion elegida no es valida ingrese otra "<<endl;
    			this->menuDeOpcionesAMover(eleccion);

    	}
    	if(casilleroDestino==NULL){
    		seguir=true;
    	}
    	else if(casilleroDestino->getBloqueado()==true){
		cout<<"El casillero seleccionado esta bloqueado!!!"<<endl;
    		seguir=true;
    	}
    	else if(casilleroDestino->getId()!=0){
    		cout<<"el casillero seleccionado esta ocupado!!!"<<endl;
    		seguir=true;
    	}
    	else{
    		seguir=false;
    	}

    	if(seguir==true){
    		cout<<"Elija la opcion que desee"<<endl;
    		cout<<"1-volver a elegir un movimiento de la ficha"<<endl;
    		cout<<"2-elegir otra ficha para moverla"<<endl;
		cout<<"opcion: ";
    		cin>>opcion2;
    		if(opcion2==2){
			seguir=false;
    			volverAEmpezar=true;
    		}else{
    			this->menuDeOpcionesAMover(eleccion);
    		}
    	}
    }
    if(volverAEmpezar==true){
    	this->moverFicha(tablero);
    }
    else{
	this->setCasillaPreviaJugada(casillero);
    	this->setCasillaPosteriorJugada(casilleroDestino);
    	this->intercambiarFichas(casillero,casilleroDestino);
    }
    return tablero->esGanador(anchoDestino,altoDestino,profundidadDestino);

}

/*
     PRE: recibe como parametro la direccion de memoria de un valor entero que representa la eleccion del usuario en un menu de opciones que va a ser proporsionada por la misma funcion.
     Cuando el usuario ingresa la opcion deseada la misma tiene que ser de tipo entero (int).
     POST:proporciona un menu de opciones el cual muestra todos los posibles movimientos de una ficha.
*/
void Jugador::menuDeOpcionesAMover(int &eleccion){
	cout<<"Es el turno del jugador: "<<this->getTextoNombre()<<" su ficha es: "<<this->getId()<<endl<<endl;
	cout<<"Seleccione la opcion que desee: "<<endl;
	cout<<"1-mover la ficha hacia abajo (en altura)"<<endl;
	cout<<"2-mover la ficha hacia arriba (en altura)"<<endl;
	cout<<"3-mover la ficha hacia la derecha (en ancho)"<<endl;
	cout<<"4-mover la ficha hacia la izquierda (en ancho)"<<endl;
	cout<<"5-mover la ficha hacia adelante (en profundidad)"<<endl;
	cout<<"6-mover la ficha hacia atras (en profundidad)"<<endl<<endl;

	cout << "opcion: ";
	cin>>eleccion;
}

int Jugador::getCantTotalCartas(){

    int totalCartas = 0;

    for(int i=0; i<6; i++){
        totalCartas = totalCartas + this->getCantCartasDeUnTipo(i);
    }
    return totalCartas;
}

int Jugador::levantarCarta(int cantMaxCartas){

    if(this->getCantTotalCartas()>=cantMaxCartas){
        return -1;
    }
    int indiceCarta = generarIndiceCarta();///AHORA ES FUNCION EN TATETI
    this->cartas[indiceCarta]++;
    return indiceCarta;
}

/// PRE: EL JUGADOR DEBE TENER AL MENOS UNA CARTA EN SU MANO. DE SER POSIBLE, SE JUGO LA CARTA Y SE LE QUITA DE LA MANO DEL JUGADOR
void Jugador::usarCarta(Lista<Jugador*>* jugadores, Tablero* tablero, int maximoDeCartas){
	if(jugadores->getCursor()==NULL) return;
    ///SI EL JUGADOR  NO TIENE CARTAS QUE JUGAR, SE LE LANZA UNA EXCEPCION
    if(this->getCantTotalCartas()<=0){
        throw "EL JUGADOR NO TIENE CARTAS QUE JUGAR. EL JUGADOR DEBE TENER AL MENOS UNA CARTA QUE USAR.";
    }
    int indiceCartaUsada = this->escojerCartaAUtilizar();///DEVUELVE EL INDICE DE LA CARTA A USAR O -1

    if(indiceCartaUsada == 0){
        this->hacerPerderTurnoAJugador(jugadores);
    }
    if(indiceCartaUsada == 1){
        this->bloquearFichaDeJugador(jugadores);
    }
    if(indiceCartaUsada == 2){
        this->anularCasilleroDelTablero(tablero);
    }
    if(indiceCartaUsada == 3){
        this->revertirJugadaDeJugador(jugadores);
    }
    if(indiceCartaUsada == 4){
        this->destruirCartasDeJugador(jugadores);
    }
    if(indiceCartaUsada == 5){
        this->renovarCartas(maximoDeCartas);
    }
    //PARA RENOVAR CARTAS SE DESCUENTA LA CARTA ANTES DE LEVANTAR LAS NUEVAS
    if(indiceCartaUsada != -1 && indiceCartaUsada != 5){
        this->cartas[indiceCartaUsada]--;
    }
}

/****METODOS**PRIVADOS**PARA**USAR**CARTA***********************************************************************/

  /// MUESTRA AL JUGADOR LAS CARTAS QUE TIENE DISPONIBLES Y SE LE PIDE QUE INGRESE CUAL QUIERE USAR
  /// PRE: EL JUGADOR DEBE TENER AL MENOS UNA CARTA EN SU MANO
  /// POST: SE DEVUELVE EL INDICE DEL TIPO DE CARTA SELECCIONADA POR EL JUGADOR
int Jugador::escojerCartaAUtilizar(){

    bool seleccionValida = false;
    int entrada;

    do{
        cout<<"Seleccione el tipo de carta que desee utilizar:"<<endl<<endl
        <<"1. Hacer perder un turno a un jugador >> cartas disponibles: "<<this->getCantCartasDeUnTipo(0)<<endl
        <<"2. Bloquear ficha de un jugador >> cartas disponibles: "<<this->getCantCartasDeUnTipo(1)<<endl
        <<"3. Anular posicion del tablero >> cartas disponibles: "<<this->getCantCartasDeUnTipo(2)<<endl
        <<"4. Volver atras una jugada del turno >> cartas disponibles: "<<this->getCantCartasDeUnTipo(3)<<endl
        <<"5. Quitar cartas a un jugador >> cartas disponibles: "<<this->getCantCartasDeUnTipo(4)<<endl
        <<"6. Renovar cartas en mano >> cartas disponibles: "<<this->getCantCartasDeUnTipo(5)<<endl
        <<"7. CANCELAR ACCION"<<endl
        <<"Ingresar opcion: ";

        cin>>entrada;

        if(entrada == 7){
            return -1;
        }

        if(entrada >=1 && entrada<=6 && this->cartas[entrada-1]>0){
            seleccionValida = true;
        }
        if(!seleccionValida){
            cout<<"La opcion ingresada no es valida"<<endl<<endl;
        }
    }while(!seleccionValida);

    return entrada-1;
}

void Jugador::hacerPerderTurnoAJugador(Lista<Jugador*>* jugadores){

    Jugador* jugadorAfectado = this->pedirJugadorAPerjudicar(jugadores);///AUXILIAR QUE DEVUELVE PUNTERO DE JUGADOR
    if(jugadorAfectado){
        jugadorAfectado->setPierdeTurno(true);
    }
}

void Jugador::bloquearFichaDeJugador(Lista<Jugador*>* jugadores){

    Jugador* jugadorAfectado = this->pedirJugadorAPerjudicar(jugadores);

    /// VERIFICO QUE EL JUGADOR TENGA UNA FICHA EN TABLERO,
    /// SI LA TIENE SERA LA QUE CORRESPONDA AL CASILLERO DE SU JUGADA POSTERIOR
    if(jugadorAfectado && jugadorAfectado->getCasillaPosteriorJugada() && jugadorAfectado->getFichasPorColocar()==0){
        jugadorAfectado->getCasillaPosteriorJugada()->setBloqueado(true);
    }
}

///PRE: LA POSICION A ANULAR EN EL TABLERO DEBE SER UNA POSICION EXISTENTE VALIDA.
///PRE: EL CASILLERO EN DICHA POSICION DEBE DE ESTAR VACIO
///POST: EL CASILLERO EN DICHA POSICION QUEDA INHABILITADO Y NO PODRÁ SER OCUPADO HASTA EL SIGUIENTE TURNO
///      DEL JUGADOR QUE ANULO DICHO CASILLERO.
void Jugador::anularCasilleroDelTablero(Tablero* tablero){
    int prof, ancho, alto;
    bool casillaValida = false;

    do{
        cout<< "Seleccione una posicion libre del tablero (ancho, profundidad y altura) que desee anular" << endl;

        this->ingresarVerificandoValores(ancho, prof, alto, tablero);

        if(!tablero->getCasillero(prof, ancho, alto)->getOcupado()){
            casillaValida = true;

        }if(!casillaValida){
            cout<<"No se puede anular una posición ya ocupada. Ingrese una posición libre a anular."<<endl<<endl;
        }

    }while(!casillaValida);

    ///BLOQUEO LA CASILLA PARA QUE NO PUEDAN COLOCAR FICHAS EN ELLA Y SE LA ASIGNO AL JUGADOR
    /// PARA PODER DESBLOQUEARLA CUANDO SEA NUEVAMENTE SU TURNO.
    tablero->getCasillero(prof, ancho, alto)->setBloqueado(true);
    this->setCasillaAnulada(tablero->getCasillero(ancho, alto, prof));
}


void Jugador::revertirJugadaDeJugador(Lista<Jugador*>* jugadores){

    Jugador* jugadorAfectado =this->pedirJugadorAPerjudicar(jugadores);///AUXILIAR QUE DEVUELVE PUNTERO DE JUGADOR

    /// VERIFICO QUE EL JUGADOR TENGA UNA JUGADA PREVIA, SI LA TIENE, TMB TIENE UNA POSTERIOR(SU ULTIMO MOVIMIENTO)
    if(jugadorAfectado && jugadorAfectado->getCasillaPreviaJugada()){
        ///SI ESA CASILLA QUE CORRESPONDE A LA JUGADA PREVIA ESTA VACIA
        ///ENTONCES PODEMOS INTERCAMBIARLA POR LA JUGADA POSTERIOR
        if(!jugadorAfectado->getCasillaPreviaJugada()->getOcupado()){
            jugadorAfectado->getCasillaPreviaJugada()->setId(jugadorAfectado->getId());
            jugadorAfectado->getCasillaPosteriorJugada()->setId(0);
            //LA CASILLA POSTERIOR AHORA ES LA ANTERIOR
            jugadorAfectado->setCasillaPosteriorJugada(jugadorAfectado->getCasillaPreviaJugada());
            jugadorAfectado->setCasillaPreviaJugada(NULL);
        }///SI LA CASILLA DE JUGADA PREVIA ESTABA OCUPADA POR OTRO JUGADOR, LA CARTA NO TUVO EFECTO
    }
}

void Jugador::destruirCartasDeJugador(Lista<Jugador*>* jugadores){

    Jugador* jugadorAfectado = this->pedirJugadorAPerjudicar(jugadores);

    if(jugadorAfectado){
        for(int i=0; i<6; i++){
            jugadorAfectado->cartas[i] = 0;
        }
    }
}
///POST: SE DESCONTO EN -1 EL TIPO DE CARTA Y SE RENUEVAN LAS CARTAS DE LA MANO DEL JUGADOR QUE USO LA CARTA
void Jugador::renovarCartas(int maximoDeCartas){
	
    ///COMO TENIA ESTA CARTA SE LE DESCUENTA AQUI, NO EN USAR CARTA
    this->cartas[5]--;

    int cantidadDeCartas = this->getCantTotalCartas();
    for(int i=0; i<6; i++){
        this->cartas[i] = 0;
    }

    for(int i=0; i<cantidadDeCartas; i++){
        this->levantarCarta(maximoDeCartas);
    }
}

Jugador* Jugador::pedirJugadorAPerjudicar(Lista<Jugador*>* jugadores){

    int id;
    /// EL ID DEL JUGADOR SE CORRESPONDE CON EL ORDEN EN LISTA DEL JUGADOR -> id == posicionDelJugadorEnLaLista
    /// DE EXISTIR EL JUGADOR, EL ID TIENE QUE SER MAYOR A CERO Y MENOR O IGUAL A LA CANTIDAD DE ELEMENTOS DE LA LISTA

    bool idExistente = false;

    do{
        cout<<"Favor de ingresar un ID válido del jugador al cual aplicar los efectos de la carta."<<endl<<endl;
        cin>>id;
        if(id <= (int)jugadores->contarElementos() && id > 0){
            idExistente = true;
        }
        if(!idExistente){
            cout<<"El ID ingresado no se corresponde a un ID existente válido"<<endl<<endl;
        }

    }while(!idExistente);

    ///YA SE QUE EXISTE Y SU POSICION EN LA LISTA SE CORRESPONDE AL ID
    ///DEVUELVO EL PUNTERO QUE OCUPA ESA POSICION EN LA LISTA
    return jugadores->get(id);

}


/****************************************************************************************************************/

/// GETTERS Y SETTERS QUE FALTAN

void Jugador::setCasillaPreviaJugada(Casillero* casillero){
    if(!casillero){
	    this->casillaPreviaJugada = NULL;
    }else{
	    this->casillaPreviaJugada = casillero;
    }
}
Casillero* Jugador::getCasillaPreviaJugada(){
    return this->casillaPreviaJugada;
}
void Jugador::setCasillaPosteriorJugada(Casillero* casillero){
    if(!casillero){
	    this->casillaPosteriorJugada = NULL;
    }else{
	    this->casillaPosteriorJugada = casillero;
    }
}
Casillero* Jugador::getCasillaPosteriorJugada(){
    return this->casillaPosteriorJugada;
}
void Jugador::setCasillaAnulada(Casillero* casillero){
    if(!casillero){
	    this->casillaAnulada = NULL;
    }else{
	    this->casillaAnulada = casillero;
    }
}
Casillero* Jugador::getCasillaAnulada(){
    return this->casillaAnulada;
}
