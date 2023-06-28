#include "Figura.h"

#include "freeglut.h"
#include <iostream>
#include<string>

Figura::Figura() {
   max.x=8.0;
   max.y=8.0;
   min.x=1.0;
   min.y=1.0;
}

Figura::Figura(bool color_, const std::string& tipo_,int identidad,bool vida_) {
	color = color_;
	tipo = tipo_;
	identidad=identidad_;
}

Figura::Figura(bool color_,int identidad_)
{
	color=color_;
	identidad=identidad_;
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

bool Figura::coronacion(int ident_)
{
	if (tipo=="p" && color && getPos().y == 8)//blancas
		return true;
	if (tipo == "p" && !color && getPos().y == 1)//negras
		return true;
	return false;
}
