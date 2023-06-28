#include "Tablero.h"
#include "freeglut.h"

Tablero::Tablero(){
//rojo = verde = azul = 255; //blanco
}



Tablero::Tablero(float x1,float y1){
       this->pos.x=x1;
	this->pos.y=y1;

Tablero::~Tablero()
{
	
}

void Tablero::setColor(Byte r, Byte v, Byte a)
{
    color.set(r, v, a);
}
