#include "Mundo.h"
#include "freeglut.h"

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
      case 'a': return 1*10 + static_cast<int>(id[1]); break;        //Se utiliza el static_cast<int> para convertir el segundo caracter a un número.
      case 'b': return 2*10 + static_cast<int>(id[1]); break; 
      case 'c': return 3*10 + static_cast<int>(id[1]); break; 
      case 'd': return 4*10 + static_cast<int>(id[1]); break; 
      case 'e': return 5*10 + static_cast<int>(id[1]); break; 
      case 'f': return 6*10 + static_cast<int>(id[1]); break; 
      case 'g': return 7*10 + static_cast<int>(id[1]); break; 
      case 'h': return 8*10 + static_cast<int>(id[1]); break; 
      default: return 99; break;    //Si la letra no es ninguna de la "a" a la "h", retorna 99 para que entre en lt.cumpleLimites() y retorne false
    }
}
