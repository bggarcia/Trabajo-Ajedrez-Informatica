#include "Tablero.h"
#include "freeglut.h"

Tablero::Tablero(){
//rojo = verde = azul = 255; //blanco
}

/*Tablero::Tablero(int identi, float x1, float y1) {
    ident = identi;
    this->pos.x =x1;
    this->pos.y = y1;
}*/

Tablero::Tablero(float x1,float y1){
       this->pos.x=x1;
	this->pos.y=y1;

Tablero::~Tablero()
{
	
}
	
	
	
void Tablero::SetColor()
{
	
	for (int i=0;i<8;i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i + j)%2 == 0)
			{
				casilla[i][j].SetColor(255, 255, 255);
			}
			else
			{
				casilla[i][j].SetColor(255, 0, 0);
			}
		}
	}
}

void Tablero::dibuja()
{
    glDisable(GL_LIGHTING);
    color.ponColor();
    glBegin(GL_POLYGON);
    glVertex3d(limite1.x, limite1.y,0);
    glVertex3d(limite2.x, limite1.y,0);
    glVertex3d(limite2.x, limite2.y,0);
    glVertex3d(limite1.x, limite2.y,0);
    glEnd();
    glEnable(GL_LIGHTING);
}

void Tablero::SetPos()
{
	int i = 0, j = 0;
	for ( i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			casilla[i][j].SetPos(j, i);
	
		}
	}
}


