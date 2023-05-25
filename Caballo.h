#pragma once
#include "Figura.h"
class Caballo : public Figura {
private:
	float lado;
	Tablero* posicionesLegales[NUM];
	Vector2D max, min;
public:
	Caballo(bool color_) :Figura(color, 'c') { lado = 0.1f; }
	Caballo();
	void dibuja();
	bool movLegal(int ident_);
};


