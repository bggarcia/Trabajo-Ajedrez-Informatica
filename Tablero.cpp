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
	int i = 0, j = 0;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			casilla[i][j].dibuja();

		}
	}
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

Tablero::Tablero()
{
	int i = 0, j = 0;
	//casilla[i][j] = new Casilla();

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			casilla[i][j].inicializa();

		}
	}
}
