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

