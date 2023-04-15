#pragma once
#include "freeglut.h"
class Torre : public Pieza
{
private:
	float tamaño;
	float x;
	float y;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;

public:
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	void SetPos(float ix, float iy);
	void SetTamaño(float size);
	void dibuja();
	void Mueve(int tipo);
};

