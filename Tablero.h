#pragma once
#include "Casilla.h"
#include <iostream>
#include "Vector2D.h"
#include "ColorRGB.h"

class Tablero
{
private:
	Casilla casilla[8][8];
public:
	Tablero();
	void dibuja();
	void SetColor();
	void SetPos();
};

