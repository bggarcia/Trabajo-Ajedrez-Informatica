#pragma once
#include "Casilla.h"
#include <iostream>
#include "Vector2D.h"
#include "ColorRGB.h"

class Tablero
{
private:
	Vector2D limite1;
	Vector2D limite2;
	ColorRGB color;
	Vector2D pos;
	int ident;
public:
	//Tablero(int identi,float x1,float y1);
	Tablero(float x1,float y1);
	virtual ~Tablero();
	void dibuja();
	void SetColor();
	void SetPos();
};

