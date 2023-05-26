#pragma once
#include "Figura.h"
#include <iostream>
#include <string>
class Peon : public Figura {
	float tamaño;
	float x;
	float y;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	bool primer_movimineto = true;

public:
	void SetColor(unsigned char r, unsigned char v, unsigned char a);
	void SetPos(float ix, float iy);
	void SetTamaño(float size);
	void dibuja();
	void Mueve();
};

