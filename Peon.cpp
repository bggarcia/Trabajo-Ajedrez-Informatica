#include "Peon.h"
#include "freeglut.h"

void Peon::setColor(unsigned char r, unsigned char v, unsigned char a)
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

void Peon::SetTama�o(float size)
{
	tama�o = size;
}

void Peon::dibuja()
{
	glColor3ub(rojo, verde, azul);
	glTranslatef(x, y, 0);
	glutSolidSphere(tama�o, 20, 20);
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