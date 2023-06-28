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
  //

  
  
  
 }
