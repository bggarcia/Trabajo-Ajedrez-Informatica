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
  Vector2D destino,origen,dif,dif_aux,pos_var;
  //destino y pos son los vectores 2D que almacenanlos valores de las coordenadas según las identidades.
  //dif y dif_aux son las diferencias entre las identidades de destino y origen. Dan las casillas que se tiene que mover una pieza y en qué dirección (a través del signo)
  Vector2D cont={0,0};
  bool aux=true,flag=true;              //Variables auxiliares para comprobaciones 
  float contx,conty;                    //Contadores auxiliares para facilitar el valor absoluto
  int aux_x,aux_y;                      //Variables auxiliares para realizar la división entera
  char id_o[3],id_d[3];                 //Cadenas de caracteres en las que se almacenan las casillas, con formato "letra-numero" ej. "a2"



  
}
