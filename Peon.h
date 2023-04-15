#pragma once
#include "freeglut.h"
class Peon : public Pieza
{
private:
	float tamaño;
	float x;
	float y;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	bool primer_movimiento = true;

public:
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	void SetPos(float ix, float iy);
	void SetTamaño(float size);
	void dibuja();
	void Mueve();
};

