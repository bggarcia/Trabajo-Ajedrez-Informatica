#include "Figura.h"

#include "freeglut.h"
#include <iostream>
Figura::Figura() {
   
    //altura = 0.1f;
}

Figura::~Figura()
{

}
//void Figura::dibuja()
//{
//    glPushMatrix();
//    glTranslatef(posicion.x, posicion.y, 0);
//    glColor3f(1.0f, 0.0f, 0.0f);
//    glutSolidSphere(altura, 20, 20);
//    glPopMatrix();
//}


Vector2D Figura::getPos()
{
	return posicion;
}

void Figura::setPos(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}
void Figura::setPos(Vector2D pos)
{
	posicion = pos;
}
void Figura::setIdent(int identi) {
	ident = identi;
}

int Figura::getIdent() {
	return ident;
}
