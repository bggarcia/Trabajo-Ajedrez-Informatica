#include "Casilla.h"
#include "freeglut.h"

void Casilla::SetColor(unsigned char r, unsigned char v, unsigned char a)
{
	rojo = r;
	verde = v;
	azul = a;
	glColor3ub(rojo, verde, azul);
}

void Casilla::SetPos(float ix, float iy)
{
	x = ix;
	y = iy;
}

void Casilla::SetTamaño(float size)
{
	lado = size;
}

void Casilla::dibuja()
{
	//glColor3ub(255, 255, 255); 
	glBegin(GL_POLYGON);
	glVertex3f(x - lado / 2, y - lado / 2, 0);
	glVertex3f(x + lado / 2, y - lado / 2, 0);
	glVertex3f(x + lado / 2, y + lado / 2, 0);
	glVertex3f(x - lado / 2, y + lado / 2, 0);
	glEnd();
}

Casilla::Casilla()
{
	x = 0, y = 0;
	rojo = azul = verde = 0;
	lado = 0;
}

void Casilla::inicializa()
{
	x = 0, y = 0;
	rojo = azul = verde = 0;
	lado = 0;
}