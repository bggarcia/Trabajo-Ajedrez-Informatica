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
	int aux_x,aux_y;
	pos_ini=this->getPos();

	//Se procede a la separación de la identidad en variables auxiliares para que la división sea 
	//una división de enteros, pero que luego se pase como float al vector de posición.
	
	aux_x=ident/10;
	aux_y=ident %10;
	pos= {(float)aux_x,(float)aux_y};

	

}

