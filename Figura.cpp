#include "Figura.h"

#include "freeglut.h"
#include <iostream>
Figura::Figura() {
   
    //altura = 0.1f;
}

Figura::Figura(bool color_, const std::string& tipo_) {
	color = color_;
	tipo = tipo_;
}

Figura::~Figura()
{

}

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

void Figura::setPos(int ident) {
	posicion.x = ident / 10;
	posicion.y = ident % 10;
}

void Figura::setIdent(int identi) {
	ident = identi;
}

int Figura::getIdent() {
	return ident;
}
