#include "Peon.h"
#include "freeglut.h"

Peon:: Peon()
{
	altura=0.1f;
	primerMov=false;
}
void Peon::SetColor(unsigned char r, unsigned char v, unsigned char a)
{
	rojo = r;
	verde = v;
	azul = a;
}

void Peon::SetPos(float ix, float iy)
{
	x = ix;
	y = iy;
}

void Peon::SetTamaño(float size)
{
	tamaño = size;
}

void Peon::dibuja()
{
	glColor3ub(rojo, verde, azul);
	glTranslatef(x, y, 0);
	glutSolidSphere(tamaño, 20, 20);
	glTranslatef(-x, -y, 0);
}

void Peon::Mueve()
{
	if (primer_movimineto)
	{
		y += 2;
		primer_movimineto = false;
	}
	else
		y += 1;
}
