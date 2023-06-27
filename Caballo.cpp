#include "Caballo.h"


Caballo::Caballo(){

	lado = 0.1f;
}

void Caballo::dibuja() {
	

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glutSolidSphere(lado, 20, 20);
	glPopMatrix();
}

bool Caballo::movLegal(int ident_) {
    Vector2D pos, pos_ini,doble_plus,doble_less,simple_plus,simple_less;

    pos_ini.x = this->getPos().x;
    pos_ini.y = this->getPos().y;

   

    pos.x = ident_ / 10;
    pos.y = ident_ % 10;
    //
    doble_plus.y = pos_ini.y + 2.0;
    doble_plus.x = pos_ini.x + 2.0;
    //
    doble_less.y = pos_ini.y - 2.0;
    doble_less.x = pos_ini.x - 2.0;
    //
    simple_plus.y = pos_ini.y + 1.0;
    simple_plus.x = pos_ini.x + 1.0;
    //
    simple_less.y = pos_ini.y - 1.0;
    simple_less.x = pos_ini.x - 1.0;
    int cont = 0;
    //arriba
    if (doble_plus.y <= max.y) {
       // posicionesLegales[cont++] = new Tablero(pos_ini.x, pos_ini.y + 1);
        if(simple_plus.x<=max.x)
            posicionesLegales[cont++] = new Tablero(simple_plus.x,doble_plus.y );
        if (simple_less.x >= min.x)
            posicionesLegales[cont++] = new Tablero(simple_less.x, doble_plus.y);
    }
    //abajo
    if (doble_less.y >= min.y) {
        // posicionesLegales[cont++] = new Tablero(pos_ini.x, pos_ini.y + 1);
        if (simple_plus.x <= max.x)
            posicionesLegales[cont++] = new Tablero(simple_plus.x, doble_less.y);
        if (simple_less.x >= min.x)
            posicionesLegales[cont++] = new Tablero(simple_less.x, doble_less.y);
    }
    //derecha
    if (doble_plus.x <= max.x) {
        // posicionesLegales[cont++] = new Tablero(pos_ini.x, pos_ini.y + 1);
        if (simple_plus.y <= max.y)
            posicionesLegales[cont++] = new Tablero(doble_plus.x, simple_plus.y);
        if (simple_less.y >= min.y)
            posicionesLegales[cont++] = new Tablero(doble_plus.x, simple_less.y);
    }
    //izquierda
    if (doble_less.x >= min.x) {
        // posicionesLegales[cont++] = new Tablero(pos_ini.x, pos_ini.y + 1);
        if (simple_plus.y <= max.y)
            posicionesLegales[cont++] = new Tablero(doble_less.x, simple_plus.y);
        if (simple_less.y >= min.y)
            posicionesLegales[cont++] = new Tablero(doble_less.x, simple_less.y);
    }
    


    bool bandera2 = false;

    for (int i = 0; i < cont; i++) {
        if (posicionesLegales[i]->getPosX() == pos.x && posicionesLegales[i]->getPosY() == pos.y)
            bandera2 = true;
    }

    //if (bandera2 == true)
        //this->setPos(pos.x, pos.y);

    return bandera2;
}

