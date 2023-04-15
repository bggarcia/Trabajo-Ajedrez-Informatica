#pragma once
#include "Casilla.h"
#include <iostream>

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

