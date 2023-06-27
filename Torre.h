#pragma once
#include "Figura.h"
class Torre : public Pieza {
private:
	float lado;
public:
	void SetColor(unsigned char r, unsigned char v, unsigned char a);
	void SetPos(float ix, float iy);
	void SetTamaño(float size);
	void dibuja();
	void Mueve(int tipo);
};

