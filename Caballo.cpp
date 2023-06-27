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
   Vector2D pos_ini,pos,dif,dif_aux; //Posición onicial, posición final, diferencia de posiciones y valores absolutos de la diferencia.
	

}

