#include "Torre.h"
#include "freeglut.h"

void Torre::SetColor(unsigned char r, unsigned char v, unsigned char a)
{
	rojo = r;
	verde = v;
	azul = a;
}

void Torre::SetPos(float ix, float iy)
{
	x = ix;
	y = iy;
}

void Torre::SetTamaño(float size)
{
	tamaño = size;
}

void Torre::dibuja()
{
	glColor3ub(rojo, verde, azul);
	glTranslatef(x, y, 0);
	glutSolidCube(tamaño);
	glTranslatef(-x, -y, 0);
}

void Torre::Mueve(int tipo)
{
	if (tipo == 0)
	{
		x += 5;
	}
	if (tipo == 1)
	{
		x -= 5;
	}
	if (tipo == 2)
	{
		y += 5;
	}
	if (tipo == 3)
	{
		y -= 5;
	}
}