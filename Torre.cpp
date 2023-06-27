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

std::string Torre::getName() {
    return tipo;
}

void Torre::movLegal(int ident_)
{
    Vector2D pos, pos_ini, dif, dif_aux;
    pos_ini = this->getPos();
    int aux_x, aux_y;
    aux_x = ident_ / 10;
    aux_y = ident_ % 10;
    pos = {(float)aux_x,(float)aux_y};
    
    dif = pos - pos_ini;

    if ((dif.x == 0 && dif.y != 0) || (dif.x != 0 && dif.y == 0)) //comprobar que la ident destino es realizable
    {
        return true;
   
    }
    else
        return false;
}
