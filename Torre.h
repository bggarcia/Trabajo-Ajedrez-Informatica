#pragma once
#include "freeglut.h"
class Torre
{
private:
	float tama�o;
	float x;
	float y;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;

public:
	void SetColor(unsigned char r, unsigned char v, unsigned char a);
	void SetPos(float ix, float iy);
	void SetTama�o(float size);
	void dibuja();
	void Mueve(int tipo);
};

