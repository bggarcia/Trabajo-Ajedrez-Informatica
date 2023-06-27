#include "Rey.h"

Rey::Rey() {
	lado = 0.1f;
}

void Rey::dibuja() {
    if (color == 1) {

        sprite1.setCenter(0.0f, 0.0f);
        sprite1.setSize(0.8f, 0.8f);
        glPushMatrix();
        glTranslatef(posicion.x - 0.25f, posicion.y - 0.25f, 0.2f);
        glColor3f(1.0f, 0.0f, 0.0f);
        sprite1.setState(5);
        sprite1.draw();
        glPopMatrix();
    }
    else {
        sprite2.setCenter(0.0f, 0.0f);
        sprite2.setSize(0.8f, 0.8f);
        glPushMatrix();
        glTranslatef(posicion.x - 0.25f, posicion.y - 0.25f, 0.2f);
        glColor3f(1.0f, 0.0f, 0.0f);
        sprite2.setState(5);
        sprite2.draw();
        glPopMatrix();

    }
}

std::string Rey::getName() {
    return tipo;
}
bool Rey::movLegal(int ident_) {
    Vector2D pos, pos_ini, dif, dif_aux;

    pos_ini = this->getPos();
    int aux_x, aux_y;
    aux_x = ident_ / 10;
    aux_y = ident_ % 10;
    pos = { (float)aux_x,(float)aux_y };
    dif = pos - pos_ini;
    dif_aux = dif.absoluto(pos, pos_ini);

    if (dif_aux.x > 1.0 || dif_aux.y > 1.0) //movimientos correctos
        return false;
    return true;
}
