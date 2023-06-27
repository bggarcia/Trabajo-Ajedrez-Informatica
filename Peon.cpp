#include "Peon.h"
#include "freeglut.h"

Peon:: Peon()
{
	altura=0.1f;
	primerMov=false;
}


void Peon::dibuja()
{
	if (color == 1) {
		sprite1.setCenter(0, 0);
		sprite1.setSize(0.8, 0.8);
		glPushMatrix();
		glTranslatef(posicion.x-0.25f, posicion.y-0.25f, 0.2);
		glColor3f(1.0f, 0.0f, 0.0f);
		sprite1.setState(0);
		sprite1.draw();

		glPopMatrix();
	}
	else {
		sprite2.setCenter(0, 0);
		sprite2.setSize(0.8, 0.8);
		glPushMatrix();
		glTranslatef(posicion.x - 0.25f, posicion.y - 0.25f, 0.2);
		glColor3f(1.0f, 0.0f, 0.0f);
		sprite2.setState(0);
		sprite2.draw();
		glTranslatef(-posicion.x + 0.25f, -posicion.y + 0.25f, -0.2f);

		glPopMatrix();
	}
}

std::string Peon::getName() {
	return tipo;
}

bool Peon::movLegal(int ident_) {
	Vector2D pos, pos_ini, dif,dif_aux;
	//Vector2D cont = {0,0};
	bool flag = true;
	bool aux=true;
	pos_ini = this->getPos();
	int aux_x, aux_y;
	aux_x = ident_ / 10;
	aux_y = ident_ % 10;
	pos = { (float)aux_x,(float)aux_y };


	dif_aux=dif.absoluto(pos,pos_ini); 

	

	if (dif_aux.y>2 || dif_aux.x>1)
	{
		return false;
	}

	
	
	if (movLineal(pos_ini, pos) || movDiagonal(pos_ini, pos)) //Tiene que conocer el tablero
		flag = true;
	else
		flag = false;

	return flag;

}

bool Peon::movDiagonal(Vector2D inicial,Vector2D final)
{
	int cont = 0;

	if (this->color)//si es blanca
		cont = 1;
	else
		cont = -1;//negra
	
	
	if ((final.y - inicial.y) == cont && abs(final.x - inicial.x) == 1)
		return true;
	else
		return false;
}

bool Peon::movLineal(Vector2D inicial, Vector2D final)
{
	int cont = 0;
	if (this->color)//si es blanca
		cont = 1;
	else                //negra
		cont = -1;

	if (primerMov && (final.y - inicial.y == cont * 2) && (final.x - inicial.x == 0))
		return true;
	if ((final.y - inicial.y == cont) && (final.x - inicial.x == 0))
		return true;
	else
		return false;
}
