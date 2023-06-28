#include "Alfil.h"
Alfil::Alfil() {

	lado = 0.1f;
}

void Alfil::dibuja() {
	if (color == 1) {
        sprite1.setCenter(0.0f, 0.0f);
        sprite1.setSize(0.8f, 0.8f);
        glPushMatrix();
        glTranslatef(posicion.x - 0.25f, posicion.y - 0.25f, 0.2f);
        glColor3f(1.0f, 0.0f, 0.0f);
        sprite1.setState(2);
        sprite1.draw();
        glPopMatrix();
    }
    else {
        sprite2.setCenter(0.0f, 0.0f);
        sprite2.setSize(0.8f, 0.8f);
        glPushMatrix();
        glTranslatef(posicion.x - 0.25f, posicion.y - 0.25f, 0.2f);
        glColor3f(1.0f, 0.0f, 0.0f);
        sprite2.setState(2);
        sprite2.draw();
        glPopMatrix();
    }	
}


bool Alfil::movLegal(int ident_) 
{
        Vector2D pos,pos_ini,dif,pos_var;
	Vector2D cont;
	bool flag=true;
	bool aux=true;
	int aux_x,aux_y;
}
