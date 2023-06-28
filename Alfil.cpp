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
        Vector2D pos,pos_ini,dif;
	int aux_x,aux_y; //variables utilizadas para la división entera sin decimales.

	aux_x=ident/10;
	aux_y=ident%10;
	pos={(float)aux_x,(float)aux_y};
	pos_ini=this->getPos();
	dif=pos-pos_ini;


	//Si el valor absoluto del movimiento en filas es distinto al de columnas y ninguno de los dos es 0, no es el movimiento del alfil
	//Esto se debe a que el alfil se desplaza siempre en la diagonal, es decir, aumentando a la vez la posición en filas y en columnas en valor absoluto
	if (abs(dif.x)!=abs(dif.y) && dif.x !=0 && dif.y !=0)  
	    return false;
	return true;

		
}
