#pragma once
class Casilla
{
private:
	float x;
	float y;
	float lado;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
public:
	Casilla();
	void SetColor(unsigned char r, unsigned char v, unsigned char a);
	void SetPos(float ix, float iy);
	void SetTamaño(float size);
	void dibuja();
	void inicializa();
};

