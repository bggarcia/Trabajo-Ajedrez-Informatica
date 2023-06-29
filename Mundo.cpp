#include "Mundo.h"
#include "freeglut.h"
#include <math.h>
#include <iostream>

void Mundo::dibuja()
  
{
  gluLookAt(x_ojo, y_ojo, z_ojo,
            0.0, y_ojo, 0.0,
            0.0, 1.0, 0.0);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,ETSIDI::getTexture("bin/imagenes/madera.png").id); //Textura del fondo

  glDisable(GL_LIGHTING);
  glBegin(GL_POLYGON);
  glColor3f(1,1,1);
  glTexCoord2d(0,1); glVertex3f(-14.5f,-3.4f,-0.1f);
  glTexCoord2d(1,1); glVertex3f(14.5f,-3.4f,-0.1f);
  glTexCoord2d(1,0); glVertex3f(14.5f,18.5f,-0.1f);
  glTexCoord2d(0,0); glVertex3f(-14.5f,18.5f,-0.1f);
  glEnd();
  glEnable(GL_LIGHTING);
  glDisable(GL_TEXTURE_2D);

  lt.dibuja();
 }

void Mundo::inicializa()
{
  x_ojo=0;
  y_ojo=7.5;
  z_ojo=30;
  turno=true; //Empiezan siempre las piezas blancas
  //
 }


void Mundo::mueve() {
 bool flag_medio,flag_mov; //flags distintas para pieza en medio y movimiento legal
	do{
		flag_medio=true; //set para que al principio de cada bucle no influya el valor del bucle anterior
		flag_mov=false;
		introducirCasilla();
		if (lt.getCasillaPos(ident)->getPieza()->movLegal(pos)) { 
			flag_mov = true;//Si la casilla destino es un movimiento legal de la figura://comprobar piezas en medio
		}
		else
		{
			cout << "Movimiento no realizable, introduzca la casilla otra vez." << endl;
			flag_mov = false;
		}
		if (flag_mov && lt.getCasillaPos(ident)->getPieza()->getName() != "c" && lt.getCasillaPos(ident)->getPieza()->getName() != "k")
			flag_medio = piezaEnMedio(); //Solo entra en piezaEnMedio si no es un caballo o un rey ya que en rey no es necesario y caballo no tiene que entrar
		else
			flag_medio = true;
		if (flag_mov && flag_medio) { //si las dos flags son true, se puede realizar el movimiento
			if (lt.getCasillaPos(ident)->getPieza()->getName() == "p") //Si la pieza además es un peón, se mueve y primerMov se pone a false
				lt.getCasillaPos(ident)->getPieza()->setPrimerMov(false);
			realizarMovimiento();
		}
		
	}while (flag_mov==false || flag_medio==false);

    



  
}

bool Mundo::piezaEnMedio()
{
	Vector2D destino, origen, dif, dif_aux, pos_var;
	//destino y pos son los vectores 2D que almacenan los valores de las coordenadas según las identidades.
	//dif y dif_aux son las diferencias entre las identidades de destino y origen. Dan las casillas que se tienen que mover y en qué dirección (signo)

	Vector2D cont = { 0,0 };
	bool aux = true, flag = true;
	float contx, conty;
	int aux_x, aux_y;

	aux_x = pos / 10;
	aux_y = pos % 10;
	destino = { (float)aux_x,(float)aux_y };
	origen = lt.getCasillaPos(ident)->getPieza()->getPos(); //Se le pasa a origen la posición de la pieza.
	dif = destino - origen;
	dif_aux = dif.absoluto(destino, origen); //Almacena en dif_aux el valor absoluto de cada elemento.

	
}
void Mundo::realizarMovimiento()
{
	
		if (lt.getCasillaPos(pos) != nullptr) //Pieza destino distinta de nullptr
			lt.eliminarPieza(pos);
		lt.getCasillaPos(pos)->setPieza(lt.getCasillaPos(ident)->getPieza());
		lt.getCasillaPos(pos)->getPieza()->setPos(pos);
		lt.getCasillaPos(pos)->getPieza()->setIdent(pos);
		lt.eliminarPieza(ident); //se pone la pieza del origen en null

		coronardatos(pos); // Si al realizarse el movimiento coronardatos detecta un peón en el final de su recorrido, coronación.
}

int Mundo::conversion(char id[3] {          //Función que se encarga de convertir la letra de la casilla en la identidad utilizada
  switch (id[0])
    {
         //Minusculas
      case 'a': return 1*10 + static_cast<int>(id[1]- '0'); break;        //Se utiliza el static_cast<int> para convertir el segundo caracter a un número.
      case 'b': return 2*10 + static_cast<int>(id[1]- '0'); break; 
      case 'c': return 3*10 + static_cast<int>(id[1]- '0'); break; 
      case 'd': return 4*10 + static_cast<int>(id[1]- '0'); break; 
      case 'e': return 5*10 + static_cast<int>(id[1]- '0'); break; 
      case 'f': return 6*10 + static_cast<int>(id[1]- '0'); break; 
      case 'g': return 7*10 + static_cast<int>(id[1]- '0'); break; 
      case 'h': return 8*10 + static_cast<int>(id[1]- '0'); break; 
	// Mayusculas
      case 'A': return 1*10 + static_cast<int>(id[1]- '0'); break;      
      case 'B': return 2*10 + static_cast<int>(id[1]- '0'); break; 
      case 'C': return 3*10 + static_cast<int>(id[1]- '0'); break; 
      case 'D': return 4*10 + static_cast<int>(id[1]- '0'); break; 
      case 'E': return 5*10 + static_cast<int>(id[1]- '0'); break; 
      case 'F': return 6*10 + static_cast<int>(id[1]- '0'); break; 
      case 'G': return 7*10 + static_cast<int>(id[1]- '0'); break; 
      case 'H': return 8*10 + static_cast<int>(id[1]- '0'); break; 
      default: return 99; break;    //Si la letra no es ninguna de la "a" a la "h", retorna 99 para que entre en lt.cumpleLimites() y retorne false
    }
}

void Mundo::coronardatos(int pos)
{
	int coronar;
	Figura* aux= lt.getCasillaPos(pos)->getPieza();
	if (lt.getCasillaPos(pos)->getPieza()->coronacion(pos)) ////////////////////////coronacion
	{
		cout << "Has coronado el peon, elige a qué tipo de pieza lo quieres convertir: " << endl;
		do
		{
			cout << "(0=REINA) (1=TORRE) (2=CABALLO) (3=ALFIL)" << endl;
			cin >> coronar;
		} while (coronar < 0 && coronar > 3);

		lt.eliminarPieza(pos);

		switch (coronar)
		{
		case 0: lt.getCasillaPos(pos)->setPieza(new Reina(aux->getColor(), pos)); break;
		case 1: lt.getCasillaPos(pos)->setPieza(new Torre(aux->getColor(), pos)); break;
		case 2: lt.getCasillaPos(pos)->setPieza(new Caballo(aux->getColor(), pos)); break;
		case 3: lt.getCasillaPos(pos)->setPieza(new Alfil(aux->getColor(), pos)); break;
		default:break;
		}
		lt.getCasillaPos(pos)->getPieza()->setPos(pos);
	}
}

void Mundo::introducirCasilla()
{
	char id_o[3], id_d[3];
	if (turno) {
		//Si es el turno de blancas
		//do {
		do {
			cout << "Introduzca la casilla de origen:";
			cin >> id_o;
			ident = conversion(id_o);

		} while ((lt.getColor(ident) == false && lt.getCasillaPos(ident)->getPieza() != nullptr) || lt.getCasillaPos(ident)->getPieza() == nullptr || lt.cumpleLimites(ident) == false);
		//Se repite el bucle siempre que el color seleccionado es distinto al turno, la casilla seleccionada esté vacia o si está fuera de límites (casilla no existe)

		do {
			cout << "Introduzca la casilla que quieres llegar:";
			cin >> id_d;
			pos = conversion(id_d);

		} while (((lt.getColor(pos) && lt.getCasillaPos(pos)->getPieza() != nullptr)) || lt.cumpleLimites(ident) == false || pos == ident);
		
		//Se repite el bucle siempre que en el destino exista una pieza y sea del mismo color o si está fuera de límites.
	}
	else {
		//Si es el turno de negras
				//do {
		do {
			cout << "Introduzca la casilla de origen:";
			cin >> id_o;
			ident = conversion(id_o);

		} while ((lt.getColor(ident) == true && lt.getCasillaPos(ident)->getPieza() != nullptr) || lt.getCasillaPos(ident)->getPieza() == nullptr || lt.cumpleLimites(ident) == false);
		//Se repite el bucle siempre que el color seleccionado es distinto al turno, la casilla seleccionada esté vacia o si está fuera de límites (casilla no existe)

		do {
			cout << "Introduzca la casilla que quieres llegar:";
			cin >> id_d;
			pos = conversion(id_d);

		} while (((lt.getColor(pos) == false && lt.getCasillaPos(pos)->getPieza() != nullptr)) || lt.cumpleLimites(ident) == false || pos == ident);
	
		//Se repite el bucle siempre que en el destino exista una pieza y sea del mismo color o si está fuera de límites.
	}
}

Mundo::~Mundo()
{
}

void Mundo::tecla(unsigned char key)
{

}

void Mundo::teclaEspecial(unsigned char key)
{

}
