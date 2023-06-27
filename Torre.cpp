#include "Torre.h"

Torre::Torre() {
	lado = 0.1f;
}

void Torre::dibuja()
{
    if (color == 1) {
        
        sprite1.setCenter(0.0f, 0.0f);
        sprite1.setSize(0.8f, 0.8f);
        glPushMatrix();
        glTranslatef(posicion.x - 0.25f, posicion.y - 0.25f, 0.2f);
        glColor3f(1.0f, 0.0f, 0.0f);
        sprite1.setState(1);
        sprite1.draw();
        glPopMatrix();
    }
    else {
        sprite2.setCenter(0.0f, 0.0f);
        sprite2.setSize(0.8f, 0.8f);
        glPushMatrix();
        glTranslatef(posicion.x - 0.25f, posicion.y - 0.25f, 0.2f);
        glColor3f(1.0f, 0.0f, 0.0f);
        sprite2.setState(1);
        sprite2.draw();
        glPopMatrix();
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
