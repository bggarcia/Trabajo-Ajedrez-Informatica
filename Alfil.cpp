#include "Alfil.h"
Alfil::Alfil() {

	lado = 0.1f;
}

void Alfil::dibuja() {
	if (color == 1) {
        sprite1.setCenter(0, 0);
        sprite1.setSize(0.8, 0.8);
        glPushMatrix();
        glTranslatef(posicion.x - 0.25, posicion.y - 0.25, 0.2);
        glColor3f(1.0f, 0.0f, 0.0f);
        sprite1.setState(2);
        sprite1.draw();
        glPopMatrix();
    }
    else {
        sprite2.setCenter(0, 0);
        sprite2.setSize(0.8, 0.8);
        glPushMatrix();
        glTranslatef(posicion.x - 0.25, posicion.y - 0.25, 0.2);
        glColor3f(1.0f, 0.0f, 0.0f);
        sprite2.setState(2);
        sprite2.draw();
        glPopMatrix();
    }

	
}


bool Alfil::movLegal(int ident_) {
   
}
