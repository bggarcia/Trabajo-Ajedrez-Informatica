#include "Mundo.h"
#include "freeglut.h"

void Mundo::dibuja()
  
{
  gluLookAt(x_ojo, y_ojo, z_ojo,
            0.0, y_ojo, 0.0,
            0.0, 1.0, 0.0);
  
  lt.dibuja(); //dibuja el tablero
  //Peones blancos
  p1b.dibuja();
  p2b.dibuja();
  p3b.dibuja();
  p4b.dibuja();
  p5b.dibuja();
  p6b.dibuja();
  p7b.dibuja();
  p8b.dibuja();
  //torres
  t1b.dibuja();
  t2b.dibuja();
  //caballos
  cb1.dibuja();
  cb2.dibuja();
  //alfiles
  ab1.dibuja();
  ab2.dibuja();
  //reina
  qb.dibuja();
  //rey
  kb.dibuja();
 }

void Mundo::inicializa()
{
  x_ojo=0;
  y_ojo=7.5;
  z_ojo=30;
  //

  
  
  
 }
