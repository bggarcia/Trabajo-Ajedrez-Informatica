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
	int ident;
public:
	Tablero();
	void dibuja();
	void SetColor();
	void SetPos();
};

